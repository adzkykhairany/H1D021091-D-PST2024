#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266WiFi.h>

// ssid & pass access point, connect ke wifi yang sama
const char *ap_ssid = "rumah";
const char *ap_password = "ayahbunda2002"; //minimal 8

// ssid & pass access point, nodemcu sebagai hotspot
const char *sta_ssid = "TEKNIK UNSOED D3";
const char *sta_password = ""; //gak pakai password karena yang penting terhubung aja ke jaringan

AsyncWebServer server(80); //buat port
String webpage; //untuk naruh html

int led1 = D0, led2 = D1, led3 = LED_BUILTIN;

// // put function declarations here:
// int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600); //untuk komunikasi antara nodemcu dengan perangkat lain klo di sini dengan platform io, 9600 untuk frekuensi nya
  delay(10);
  
  // // setting mode access point, connect ke wifi yang sama
  // Serial.println("Configuring access point...");
  // WiFi.mode(WIFI_AP); //wifi_ap untuk access point
  // WiFi.softAP(ap_ssid, ap_password); //klo gamau ada password nanti ap_password bisa dihapus aja
  // Serial.print("Wifi: ");
  // Serial.println(ap_ssid);
  // Serial.print("IP address: ");
  // Serial.println(WiFi.softAPIP());

  // setting mode station, nodemcu sebagai hotspot
  Serial.print("Connecting to ");
  Serial.println(sta_ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(sta_ssid, sta_password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Isi dari Webpage -------------------------------------------------------
  webpage+= "<h1> Web Control ESP8266</h1>";
  webpage+= "<p>LED 1: ";
  webpage+= "<a href=\"LED1ON\"\"><button>ON</button></a><a href=\"LED1OFF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p>LED 2: ";
  webpage+= "<a href=\"LED2ON\"\"><button>ON</button></a><a href=\"LED2OFF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p>LED 3: ";
  webpage+= "<a href=\"LED3ON\"\"><button>ON</button></a><a href=\"LED3OFF\"\"><button>OFF</button></a></p>";

  //ini routing, end point end point nya
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", webpage);
  });
  
  server.on("/LED1ON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led1, HIGH);
    request->send(200, "text/html", webpage);
  });
  
  server.on("/LED2ON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led2, HIGH);
    request->send(200, "text/html", webpage);
  });

  server.on("/LED3ON", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led3, LOW);
    request->send(200, "text/html", webpage);
  });

  server.on("/LED1OFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led1, LOW);
    request->send(200, "text/html", webpage);
  });
  
  server.on("/LED2OFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led2, LOW);
    request->send(200, "text/html", webpage);
  });

  server.on("/LED3OFF", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(led3, HIGH);
    request->send(200, "text/html", webpage);
  });

  server.begin();
}

void loop() {
  //karena gak mantau data jadi loop nya dikosongin
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}