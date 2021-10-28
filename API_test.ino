#include <WiFi.h>
#include <HTTPClient.h>
#include <LiquidCrystal_I2C.h>

const char* ssid = "TheFredness";

const char* password = "Muldvarp123";


String Oppenheimer = "I am become death, destroyer of pussy";
String Space = " ";
LiquidCrystal_I2C lcd (0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 1);
  lcd.init();
  lcd.backlight();
  // lcd.print("Hey Mofo");



  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");

  }

  Serial.println("Connected to the network");
}

void loop() {


  if ((WiFi.status() == WL_CONNECTED)) {

    HTTPClient http;
    String endpoint = "http://api.openweathermap.org/data/2.5/weather?q=Copenhagen,dk&APPID=";
    String key = "ded0bea51652ebb1268bf98a98e98be2";

    http.begin(endpoint + key);

    int httpCode = http.GET();
    if (httpCode > 0)
    { String payload = http.getString();
      Serial.println(httpCode);
      
      Serial.println(payload);

      

      for (int posCounter = 0; posCounter < 16; posCounter++) {

  lcd.scrollDisplayLeft();
        
        
        lcd.print(payload);
        delay(250);
      }
    }

    else {
      Serial.println("Error motherfucker");
    }
    delay(3000);
  }




}
