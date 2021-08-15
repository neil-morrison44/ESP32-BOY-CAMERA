#include <Arduino.h>
#include "display.h"
#include "camera.h"

void setup()
{
  Serial.begin(115200);
  Serial.setDebugOutput(true);

  setupCamera();
  displaySetup();

  printf("Setup Complete?");

  delay(100);
}

void loop()
{
  takePictureAndRunForEachPixel(drawPixel);
  refreshDisplay();
}
