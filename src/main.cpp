#include <Arduino.h>
#include <ArduinoJson.h>

void setLamp(int no){
    long timestamp = millis();
    StaticJsonDocument<200> doc;
    doc["lampu no."] = no;
    doc["status"] = "ON";
    doc["update"] = timestamp;
    serializeJson(doc,Serial);
    Serial.println();
    //Serial.print("Lampu no. ");
    //Serial.println(no);
}

void setup() {
 Serial.begin(19200);
}

void loop() {

    if (Serial.available() > 0)
    {
        int lampNumber = Serial.read()- '0';

        switch (lampNumber)
        {
        case 1:
            setLamp(1);
            break;
        case 2:
            setLamp(2);
            break;
        case 3:
            setLamp(3);
            break;
        
        default:
            break;
        }
    }
    
   
}