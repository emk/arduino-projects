// Based on the code at: http://inotool.org/quickstart

// This pin is an excellent choice for a "heartbeat" diode, because there's
// actually a built-in diode connected to this pin on the board.
#define LED_PIN 13

void setup()
{
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(900);
}
