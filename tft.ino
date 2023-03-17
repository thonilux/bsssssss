//library TFTLCD-Library-Master
#include <Adafruit_TFTLCD.h>
#include <pin_magic.h>
#include <registers.h>

//library adafruit GFX
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> // Hardware-specific library
#include "img.h"

#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft;


void setup() {
  Serial.begin(9600);
  Serial.println(F("TFT LCD test"));
  tft.reset();
  tft.begin(0x8357);
  tft.setRotation(1);
  tft.fillScreen(BLACK);


}

void loop() {
  tombol();
  masuk();
  idbat();
  delay(5000);
  scan();
  delay(5000);
  info();
  delay(5000);
  ambil();
  delay(5000);
}

void tombol() {
  tft.fillScreen(BLACK);
  tft.setCursor(20, 40);
  tft.setTextColor(WHITE);  tft.setTextSize(4);
  tft.println("Tekan Tombol");
  tft.setCursor(33, 80);
  tft.println("Untuk Tukar");
  tft.setCursor(83, 120);
  tft.println("Baterai");
  for (int k = 0; k < 10; k++) {
    tft.drawBitmap(140, 160, push, 50, 50, GREEN);
    delay(500);
    tft.drawBitmap(140, 160, push, 50, 50, BLACK);
  }
}

void masuk() {
  tft.fillScreen(BLACK);
  tft.drawBitmap(0, 30, batstat, 180, 180, RED);
  tft.setCursor(190, 105);
  tft.setTextColor(WHITE);  tft.setTextSize(3);
  tft.println("MASUKAN");
  tft.setCursor(190, 145);
  tft.println("BATERAI");
  for (int k = 0; k < 10; k++) {
    tft.drawBitmap(0, 30, battin, 180, 180, GREEN);
    delay(500);
    tft.drawBitmap(0, 30, battin, 180, 180, BLACK);
  }
}

void idbat() {
  tft.fillScreen(BLACK);
  tft.fillRect(165, 65, 130, 40, WHITE);
  tft.setCursor(170, 75);
  tft.setTextColor(BLACK);  tft.setTextSize(2);
  tft.println("ID BATERAI");
  tft.drawBitmap(0, 30, bat, 180, 180, RED);
  tft.setTextColor(GREEN);  tft.setTextSize(7);
  tft.setCursor(200, 125);
  tft.println("99");
  tft.drawBitmap(0, 30, bat, 180, 180, GREEN);
}

void scan() {
  tft.fillScreen(BLACK);
  tft.drawBitmap(60, 5, kartu, 200, 200, GREEN);
  tft.setCursor(70, 210);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("SCAN KARTU ANDA");
}

void info() {
  tft.fillScreen(BLACK);
  tft.setCursor(100, 10);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("INFO KARTU");
  tft.drawBitmap(15, 65, user, 50, 50, RED);
  tft.drawBitmap(15, 155, duit, 50, 50, CYAN);
  tft.setCursor(80, 75);
  tft.setTextColor(RED);  tft.setTextSize(4);
  tft.println("NAMA USER");
  tft.setCursor(80, 165);
  tft.setTextColor(CYAN);  tft.setTextSize(4);
  tft.print("Rp. ");
  tft.println("99999");
}

void ambil() {
  tft.fillScreen(BLACK);
  tft.drawBitmap(60, 2, ambilbat, 200, 200, GREEN);
  tft.setCursor(75, 205);
  tft.setTextColor(WHITE);  tft.setTextSize(2);
  tft.println("SILAHKAN AMBIL");
  tft.setCursor(85, 225);
  tft.println("BATERAI ANDA");
}
