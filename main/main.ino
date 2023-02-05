#include <vector>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <string>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

const int micPin = 13;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// function to parse the text data until we reach a period
String parseTextData(String &text) {
  // string to return
  String want = "";
  // loop through the chars in the string
  for(int i=0; i < text.length(); i++) {
    // check if the string is at a punctuation
    if (!(ispunct(text[i]))) {
      // create the sentence we want until we reach a punctuation
      want += text[i];
    }
    // else we at punctuation
    else {
      // delete the sentence + the punctuation
      text.remove(0, i + 1);

      // delete extra space
      if (text.length() != i) {
        text.remove(0, 01);
      }

      return want;
    }
  }

  return want;

}

// function to print the text
void printText(String text) {
  // reset the display to be clear
  display.clearDisplay();

  // set the text color
  display.setTextColor(WHITE);
  
  // position the display
  display.setCursor(0,28);

  // get rid of text wrapping
  // display.setTextWrap(false);
  // display.wrap_text_to_lines(text, 4);

  // set the text size to be displayed on the screen
  display.setTextSize(1);
  
  Serial.println(text);
  // print the text out onto the screen
  display.println(text);
  display.display();

  // delay to give time to read about three seconds to read the sentence
  delay(4000);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin(14, 15);


  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  pinMode(micPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  const int soundVal = analogRead(micPin);
  Serial.println(soundVal);
  // Serial.write(soundVal);

  // get the string to read from
  // String text = Serial.readString();
  String dataDisplay = "";
  // parse the text
  String text = "I really want to eat food. I have no time for things. Everyday is suffering. Why is pain poop.";
  while (text.length() != 0) {
    dataDisplay = parseTextData(text);
    // Serial.println(dataDisplay);
    printText(dataDisplay);
  }

}
