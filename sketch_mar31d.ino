// ----- esp32 and 4-led and relay and hooter and MQTT server protocol combination code both side 2 ----- //


#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "PLUMULE-WIFI-2.4GHZ";
const char* password = "Plumule@321";

const char* mqtt_server = "119.18.62.146";
const int mqtt_port=1883;
const char* topic = "t/pub";


WiFiClient espClient;
PubSubClient client(espClient);

// Pins
int Redled = 16;
int Greenled = 17;
int Blueled = 18;
int Whiteled = 21;   // NEW LED (Train from Left)

int Hooter = 25;
int RelayPin = 19;

void setup_wifi()
{
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }
}

void callback(char* topic, byte* payload, unsigned int length)
{
  String message = "";

  for (int i = 0; i < length; i++)
  {
    message += (char)payload[i];
  }

  allOff();

  if(message == "r1")
  {
    // Train coming from RIGHT
    digitalWrite(Blueled, HIGH);
    digitalWrite(Hooter, HIGH);
    digitalWrite(RelayPin, HIGH);
  }

  else if(message == "l1")
  {
    // Train coming from LEFT
    digitalWrite(Whiteled, HIGH);
    digitalWrite(Hooter, HIGH);
    digitalWrite(RelayPin, HIGH);
  }

  else if(message == "error")
  {
    // System fault
    digitalWrite(Redled, HIGH);
  }

  else if(message == "0")
  {
    // System OK / No train
    digitalWrite(Greenled, HIGH);
  }
}

void reconnect()
{
  while (!client.connected())
  {
    if (client.connect("ESP32_Client"))
    {
      client.subscribe(topic);
    }
    else
    {
      delay(2000);
    }
  }
}

void setup()
{
  pinMode(Redled, OUTPUT);
  pinMode(Greenled, OUTPUT);
  pinMode(Blueled, OUTPUT);
  pinMode(Whiteled, OUTPUT);   // NEW

  pinMode(Hooter, OUTPUT);
  pinMode(RelayPin, OUTPUT);

  setup_wifi();

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  allOff();
}

void loop()
{
  if (!client.connected())
  {
    reconnect();
  }

  client.loop();
}

void allOff()
{
  digitalWrite(Redled, LOW);
  digitalWrite(Greenled, LOW);
  digitalWrite(Blueled, LOW);
  digitalWrite(Whiteled, LOW);   // NEW

  digitalWrite(Hooter, LOW);
  digitalWrite(RelayPin, LOW);
}