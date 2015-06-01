/* 
 Keyboard Message to send Enter/Return code (0xB0) across the USB.
 
 For the Arduino Leonardo and Micro.
 
 Sends a text string when a button is pressed.

 The circuit:
 * pushbutton attached from pin 4 to +5V
 * 10-kilohm resistor attached from pin 4 to ground

 created 24 Oct 2011
 modified 27 Mar 2012
 by Tom IgoeYou pressed the button 1 times.

 modified 11 Nov 2013
 by Scott Fitzgerald

 modified 31 May 2015
 by Amy Lee
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/KeyboardMessage
 */

const int keyToSend = KEY_RETURN;
const int buttonPin = 4;
int previousButtonState = HIGH;
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 500;    // the debounce time; increase if the output flickers

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  // read the pushbutton:
  int buttonState = digitalRead(buttonPin);

  // if the button state has changed,
  if ((buttonState != previousButtonState)
      // and it's currently pressed:
      && (buttonState == HIGH)) {
    int delta = millis() - lastDebounceTime;
    if ( delta > debounceDelay ) {
      lastDebounceTime = millis();
      
      // type out a message
      Keyboard.press(KEY_RETURN);
      delay(100);
      Keyboard.releaseAll();
    }
  }

  // save the current button state for comparison next time:
  previousButtonState = buttonState;
}

