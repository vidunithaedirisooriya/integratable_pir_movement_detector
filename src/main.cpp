// Transmitter is connected to Arduino Pin #10
// pir out on pin 8
// passive 5v buzzer on 6
#include <Arduino.h>
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
unsigned int previousMillis = 0;
// const unsigned int beepTime = 1200;
void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
  pinMode(6, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  mySwitch.enableTransmit(10);
  mySwitch.setRepeatTransmit(3);
}

void loop() {
  unsigned long currentMillis = millis();
  if (digitalRead(8) == HIGH) {
    mySwitch.send(MESSAGE_CORRESPONDING_TO_YOUR_SECURITY_SYSTEM, CORRESPONDING_LENGTH);
    digitalWrite(6, HIGH);
    delay(200);
    digitalWrite(6, LOW);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }
}

//vidunithaedirisooriya 2025