// Based on http://fritzing.org/projects/full-color-led-random-color-generator
// but we replace the random colors with smooth transitions.
//
// Unfortunately, driving this diode with PWM signals produces very visible
// flashing and beats.  This can be improved using a filter circuit on each
// of the color pins:
// http://www.instructables.com/id/Analog-Output-Convert-PWM-to-Voltage/

byte RED_PIN = 6; 
byte GREEN_PIN = 3; 
byte BLUE_PIN = 5;

void setup()
{
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
}

void rgb(byte c[])
{
    analogWrite(RED_PIN, 255-c[0]);
    analogWrite(GREEN_PIN, 255-c[1]);
    analogWrite(BLUE_PIN, 255-c[2]);
}

void glide(byte b[], byte e[])
{
    for (int16_t i = 0; i < 256; i++)
    {
	byte blend[3];
	for (byte j = 0; j < 3; j++)
        {
            blend[j] = b[j] + (e[j]-b[j]) * i / 255;
	}
        rgb(blend);
	delay(4);
    }   
}

void loop()
{
    byte red[3] = { 255, 0, 0 };
    byte green[3] = { 0, 255, 0 };
    byte blue[3] = { 0, 0, 255 };
    glide(red, green);
    glide(green, blue);
    glide(blue, red);
}
