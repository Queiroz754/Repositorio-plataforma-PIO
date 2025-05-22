#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include "internet.h"
#include <ArduinoJson.h>
#include <Bounce2.h>
#include <ezTime.h>
#include <DHT.h>

#define PIN_LED 2
#define pinBotao 0
#define DHTpin 21
#define DHTTYPE DHT22

WiFiClient espClient;
PubSubClient client(espClient);
Bounce botao;
Timezone temp;
DHT dht(DHTpin, DHTTYPE);

const char *mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char *mqtt_id = "esp32-senai134-allan754";
const char *mqtt_topic_sub = "senai134/mesa2/esp_inscrito";
const char *mqtt_topic_pub = "senai134/mesa2/esp_publicando";

bool estadoLed = 0;
bool modoPisca = 0;
bool enviomqtt = false;
int velPisca = 300;

void callback(char *, byte *, unsigned int);
void mqttConnect(void);
void controleLed();

void setup()
{
  Serial.begin(9600);
  conectaWiFi();
  dht.begin();

  pinMode(PIN_LED, OUTPUT);
  botao.attach(pinBotao, INPUT_PULLUP);
  botao.interval(50);

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  waitForSync();
  temp.setLocation("America/Sao_Paulo");

  pinMode(DHTpin, OUTPUT);
}
void loop()
{
  botao.update();
  checkWiFi();

  if (!client.connected())
    mqttConnect();

  client.loop();

  JsonDocument doc;

  String mensagem;

  if (botao.changed())
  {
    doc["botao"] = !botao.read();
    doc["timestamp"] = temp.now();
    enviomqtt = true;
  }
  if (enviomqtt)
  {
    serializeJson(doc, mensagem);
    Serial.println(mensagem);
    client.publish(mqtt_topic_pub, mensagem.c_str());
    enviomqtt = false;
  }

  serializeJson(doc, mensagem);
  client.publish(mqtt_topic_pub, mensagem.c_str());

  controleLed();

  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  if (isnan(temperatura) || isnan(umidade))
  {
    Serial.println("Erro no sensor");
    return;
  }
  unsigned long agora = millis();
  static unsigned long ultimaMudanca = 0;
  if (agora - ultimaMudanca >= 5000)
  {
    doc["temperatura"] = temperatura;
    doc["umidade"] = umidade;
     doc["timestamp"] = temp.now();

    String mensagem;
    serializeJson(doc, mensagem);

    Serial.print("Enviando dados MQTT: ");
    Serial.println(mensagem);
  }
}

void callback(char *topic, byte *payLoad, unsigned int length)
{
  Serial.printf("mensagem recebida em %s: ", topic);

  String mensagem = "";
  for (unsigned int i = 0; i < length; i++)
  {
    char c = (char)payLoad[i];
    mensagem += c;
  }
  Serial.println(mensagem);
}

void mqttConnect()
{
  while (!client.connected())
  {
    Serial.println("Conectando ao MQTT...");

    if (client.connect(mqtt_id))
    {
      Serial.println("COnectado com sucesso");
      client.subscribe(mqtt_topic_sub);
    }
    else
    {
      Serial.println("falha, rc=");
      Serial.println(client.state());
      Serial.println("tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void controleLed()
{
  static unsigned long ultimaMudanca = 0;
  unsigned long tempoAtual = millis();

  if (modoPisca)
  {
    if (tempoAtual - ultimaMudanca > velPisca)
    {
      estadoLed = !estadoLed;
      ultimaMudanca = tempoAtual;
    }
  }
  digitalWrite(PIN_LED, estadoLed);
}