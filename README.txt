# ColorDetection

This code enables to detect a color by using a LEGO NXT sensor and a Arduino UNO


You have to connect the color sensor on sensor port 3, with a jumper on pins 3-4
If you use a button, you have to connect the button on sensor port 2 (no jumper).
Do not connect anything on motor port 2

The output could be read on digital pins 3 and 4

If pin 3 is high (= 5V), it means that the yellow color has been detected
Otherwise pin 3 is low

If pin 4 is high (= 5V), it means that the blue color has been detected
Otherwise pin 4 is low

Make sure that the digital pins which are used to output the read color are not used by an other sensor
So pay attention to where you connect your sensors


Just to remember (for a Arduino UNO) :

Bricktronics Shield (all versions)

    0 – RX
    1 – TX
    2 – Motor 1 encoder input 1
    3 – Motor 2 encoder input 1
    4 – Motor 2 encoder input 2
    5 – Motor 1 encoder input 2
    6 – Sensor 4
    7 – Sensor 4
    8 – Sensor 3
    9 – Motor 2 PWM (speed)
    10 – Motor 1 PWM (speed)
    11 – TIP120 1 base input
    12 – Sensor 3
    13 – not used
    A0 – Sensor 1
    A1 – Sensor 2
    A2 – Sensor 3
    A4 – Sensor 4
    A5 – I2C SDA to the IO expander
    A6 – I2C SCL to the IO expander
