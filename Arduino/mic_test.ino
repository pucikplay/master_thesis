#include <Arduino.h>

#define MIC_PIN 3

int state = LOW;
bool sync = false;
unsigned long sync_time;

void setup() {
    Serial.begin(115200);
    pinMode(MIC_PIN, INPUT);
}

void loop() {
    state = digitalRead(MIC_PIN);
    if (state == HIGH) {
        if (!sync) {
            sync_time = micros();
            sync = true;
        }
        Serial.println(micros());
    }
}