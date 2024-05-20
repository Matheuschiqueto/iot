#include <Wire.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SparkFun_MAX3010x.h>

#define BUZZER_PIN D0

const char* ssid = "Chiqueto";
const char* password = "67Anjs6FG9caj32Wjve";
const char* mqtt_server = "test.mosquitto.org";
const char* mqtt_topic = "/matheus/iot";

WiFiClient espClient;
PubSubClient client(espClient);
MAX30105 particleSensor;

void callback(char* topic, byte* payload, unsigned int length) {
  // Handle incoming messages
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  client.setKeepAlive(60);

  if (connectMQTT()) {
    Serial.println("MQTT connected");
  } else {
    Serial.println("MQTT connection failed");
  }

  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) {
    Serial.println("MAX30105 was not found. Please check wiring/power.");
    while (1);
  }

  particleSensor.setup();
  particleSensor.setPulseAmplitudeRed(0x0A);
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

bool connectMQTT() {
  Serial.print("Attempting MQTT connection to ");
  Serial.println(mqtt_server);
  if (client.connect("ESP8266Client")) {
    Serial.println("connected");
    client.subscribe(mqtt_topic);
    return true;
  } else {
    Serial.print("failed, rc=");
    Serial.print(client.state());
    Serial.println(" try again later");
    return false;
  }
}

void reconnect() {
  if (!client.connected()) {
    Serial.print("Attempting MQTT reconnection...");
    if (client.connect("ESP8266Client")) {
      Serial.println("reconnected");
      client.subscribe(mqtt_topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long irValue = particleSensor.getIR();

  if (checkForBeat(irValue)) {
    float beatsPerMinute = 60.0 / getTimeBetweenBeats();
    Serial.print("Frequência Cardiaca: ");
    Serial.println(beatsPerMinute);

    if (beatsPerMinute > 100) {
      tone(BUZZER_PIN, 2000);
      delay(500);
      noTone(BUZZER_PIN);

      if (client.publish(mqtt_topic, "ATENÇÃO: Seu batimento está acima de 100 BPM")) {
        Serial.println("ATENÇÃO: Seu batimento está acima de 100 BPM");
      } else {
        Serial.println("Falha ao publicar a mensagem MQTT");
      }
    }
  }

  delay(1000);
}
