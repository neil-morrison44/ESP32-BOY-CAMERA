#include <Adafruit_GFX.h>
#include <Adafruit_SharpMem.h>

#define SHARP_SCK 2
#define SHARP_MOSI 14
#define SHARP_CS 15

Adafruit_SharpMem display(SHARP_SCK, SHARP_MOSI, SHARP_CS, 400, 240);

#define BLACK 0
#define WHITE 1

#define WHITE_POINT 64
#define BLACK_POINT 200

#define SHADE_STEP ((BLACK_POINT - WHITE_POINT) / 5)

void drawShadeSquare(int x, int y, int shade1, int shade2, int shade3, int shade4)
{
  display.drawPixel(x, y, shade1);
  display.drawPixel(x + 1, y, shade2);

  display.drawPixel(x, y + 1, shade3);
  display.drawPixel(x + 1, y + 1, shade4);
}

void drawPixel(byte shade, int x, int y)
{
  if ((shade - WHITE_POINT) < SHADE_STEP)
  {
    drawShadeSquare(x * 2, y * 2, BLACK, BLACK, BLACK, BLACK);
  }
  else if ((shade - WHITE_POINT) < (SHADE_STEP * 2))
  {
    drawShadeSquare(x * 2, y * 2, BLACK, WHITE, BLACK, BLACK);
  }
  else if ((shade - WHITE_POINT) < (SHADE_STEP * 3))
  {
    drawShadeSquare(x * 2, y * 2, BLACK, WHITE, BLACK, WHITE);
  }
  else if ((shade - WHITE_POINT) < (SHADE_STEP * 4))
  {
    drawShadeSquare(x * 2, y * 2, BLACK, WHITE, WHITE, WHITE);
  }
  else
  {
    drawShadeSquare(x * 2, y * 2, WHITE, WHITE, WHITE, WHITE);
  }
}

void refreshDisplay()
{
  display.refresh();
}

void displaySetup(void)
{
  display.begin();
  display.clearDisplay();

  display.fillRect(0, 0, 400, 240, BLACK);

  display.fillRect(10, 10, 400 - 20, 240 - 20, WHITE);
  display.refresh();
}
