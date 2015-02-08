This is a collection of random Arduino projects, mostly blinking lights
and the other usual stuff.  All of these were tested on an Arduino Micro,
which is supposedly compatible with an Arduino Leonardo.  For other Arduino
models, you may need to change the pin numbers.

### Projects

* `blink`: Blink a single diode in a distinctive pattern, mostly to verify
  that the board is working correctly.
* `colors`: Animate the colors of a Radio Shark
  [T-1 3/4 5MM FULL COLOR LED][rgbled] in a endless, gradual RGB loop using
  the PWM output pins.
* `radioshack_leds`: A horrible RadioShack
  [tricolor LED strip][rsledstrip].  This code must be compiled on Windows.
  See the notes in the source.
* `dotstar_leds`: A very nice LED strip from Adafruit.  These are a bit
  picky about the power circuit, so see the Fritzing file for details.  The
  330K resistor is a carry-over from the Neopixel docs, and should probably
  either be eliminated, or having a matching resister on the clock line.

### Developing Arduino code on Raspberry Pi

My Arduino development system is a Raspberry Pi with a NetGear G54/N150 USB
wifi adapter.  This is a bit slow, but it provides total electrical
isolation between my laptop and my dodgy electronics experiments.  Total
electrical isolation is great—I once killed a $700 embedded system back in
the day while mounting it in a robot chasis.  And I've seen too many people
accidentally brush a pair of needlenose pliers against two wires on a live
breadboard, shorting out their system.

I do **not** power the Arduino over the Raspberry Pi's USB port.  This is
theoretically possible, but it risks drawing too much power through the
Pi's USB ports if I mess up.  So I provide ~10V of DC power to the Arduino
using 8 old AA cells.  Yes, my setup is paranoid: My laptop talks to the
Raspberry Pi via wifi, and the Raspberry Pi talks to the Arduino over USB,
and the Arduino is running off separate DC power.

### Building from the command line

First, let's install the Arduino IDE and the [Ino][] command line tools:

```sh
sudo apt-get install arduino
wget https://bootstrap.pypa.io/get-pip.py
python get-pip.py
sudo pip install ino
```

Alterantively, if you want a more recent version of the Arduino tools, see
these [Arduino 1.6 Raspberry Pi instructions][arduino16] and
[this patched version of ino][inopr].

[arduino16]: https://nicohood.wordpress.com/2015/01/24/installing-avr-gcc-4-8-1-and-arduino-ide-1-6-on-raspberry-pi/
[inopr]: https://github.com/amperka/ino/pull/226

Then, from inside a project directory, we can build and upload an image
over USB:

```
ino build -m leonardo
ino upload -m leonardo
```

We specify the Arduino model `leonardo`, because that seems to work well
with the Raspberry Pi.

### Circuit diagrams

Each of these projects should include a [Fritzing][] file with breadboard
diagrams and circuit diagrams.  These are just working notes, so **use the
circuit diagrams at your own risk**. In particular, the resistors are not
necessary well-sized, and I may have made errors when translating things to
electronic format.  Pay particular attention to your power leads, and make
sure the Molex connectors are correctly oriented for your power source.
It's entirely possible to fry your Arduino or other parts if you don't
understand what's going on.

[rgbled]: http://www.radioshack.com/t-1-3-4-5mm-full-color-led/2760028.html
[Ino]: http://inotool.org/
[Fritzing]: http://fritzing.org/home/
[rsledstrip]: http://www.radioshack.com/radioshack-tricolor-led-strip/2760339.html
