
byte RedLED = 6; 
byte GrnLED = 3; 
byte BluLED = 5;

void setup()
{
    pinMode(RedLED, OUTPUT);
    pinMode(BluLED, OUTPUT);
    pinMode(GrnLED, OUTPUT);
}

void rgb(byte c[])
{
    analogWrite(RedLED, 255-c[0]);
    analogWrite(GrnLED, 255-c[1]);
    analogWrite(BluLED, 255-c[2]);
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
