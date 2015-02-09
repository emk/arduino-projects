// Based on http://arduino.cc/en/Tutorial/AnalogInput

#define ANALOG_IN A0
#define LED_PIN 13

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(ANALOG_IN);
  Serial.println(value);
  digitalWrite(LED_PIN, HIGH);
  delay(value);
  digitalWrite(LED_PIN, LOW);
  delay(value);
}
