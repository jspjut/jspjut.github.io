// Josef Spjut
// January 15, 2015

// A twin stick joypad for mouse+keyboard inputs to control FPS games
// Based on the JoystickMouseControl code by Tom Igoe
// Also inspired by Tom's KeyboardAndMouseControl

// set pin numbers for switch, joystick axes, and LED:
const int leftButton = 10;    // inddput pin for mouse click
const int rightButton = 11;    // input pin for space bar
const int switchPin = 3;
// buttons: 4 (sel) 5 (start)
// 3 switch 
// 6 square, 7 cross, 8 circle, 9 triangle
// 10 R, 11 L, 12 R3, 13 L3
const int xAxis = A2;         // joystick X axis  
const int yAxis = A4;         // joystick Y axis
const int xAxisleft = A1;    // left stick x
const int yAxisleft = A3;    // left stick y
const int ledPin = 5;         // Mouse control LED 

// parameters for reading the d:
int range = 18;               // output range of X or Y movement (12 default)
int responseDelay = 5;        // response delay of the mouse, in ms
int threshold = range/4;      // resting threshold
int center = range/2;         // resting position value

boolean mouseIsActive = false;    // whether or not to control the mouse
int lastSwitchState = LOW;        // previous switch state

// key mapping for left stick
const char leftup = 'w';
const char leftleft = 'a';
const char leftdown = 's';
const char leftright = 'd';

void setup() {
  pinMode(leftButton, INPUT_PULLUP);       // the switch pin
  pinMode(rightButton, INPUT_PULLUP);   
  pinMode(switchPin, INPUT_PULLUP);     
  pinMode(12, INPUT_PULLUP);  //shift   
  pinMode(13, INPUT_PULLUP);   
  pinMode(ledPin, OUTPUT);         // the LED pin  
 // take control of the mouse:
  Mouse.begin();
  // be a keyboard!
  Keyboard.begin();
}

void loop() {

  // read and scale the two axes:
  int invertY = digitalRead(switchPin);
  int xReading = readAxis(xAxis, 0)*2;
  int yReading = readAxis(yAxis, !invertY);
  int leftx = readAxis(xAxisleft, 0);
  int lefty = readAxis(yAxisleft, 1);

  // Keyboard left stick
  if (leftx > 0) { 
    Keyboard.press(leftright);
    Keyboard.release(leftleft);
    Serial.print("right\n");
  }
  if (leftx < 0) {
    Keyboard.release(leftright);
    Keyboard.press(leftleft);
  }
  if (leftx == 0) {
    Keyboard.release(leftright);
    Keyboard.release(leftleft);
  }
  if (lefty > 0) {
    Keyboard.press(leftdown);
    Keyboard.release(leftup);
  }
  if (lefty < 0) {
    Keyboard.release(leftdown);
    Keyboard.press(leftup);
  }
  if (lefty == 0) {
    Keyboard.release(leftdown);
    Keyboard.release(leftup);
  }
  
  // Move the mouse
  Mouse.move(xReading, yReading, 0);

  // read the mouse button and click 
  if (digitalRead(leftButton) == LOW) {
    // A single click
    if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT);
    }
  } else {
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT);
    }
  } 
  
  if (digitalRead(rightButton) == LOW) {
    Keyboard.press(' ');
  } else {
    Keyboard.release(' ');
  }

  // Shift is right stick
  if (digitalRead(12) == LOW || digitalRead(13) == LOW) {
    Keyboard.press(KEY_LEFT_SHIFT);
  } else {
    Keyboard.release(KEY_LEFT_SHIFT);
  }

  delay(responseDelay);
}

/*
  reads an axis (0 or 1 for x or y) and scales the 
 analog input range to a range from 0 to <range>
 */

int readAxis(int thisAxis, int isY) { 
  // read the analog input:
  int reading = analogRead(thisAxis);

  // map the reading from the analog input range to the output range:
  reading = map(reading, 0, 1023, 0, range);

  if (isY) reading = range-reading; // invert y axis

  // if the output reading is outside from the
  // rest position threshold,  use it:
  int distance = reading - center;

  if (abs(distance) < threshold) {
    distance = 0;
  } 

  // return the distance for this axis:
  return distance;
}


