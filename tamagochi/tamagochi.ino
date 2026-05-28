#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#include <imagens.h>

#define TFT_CS    15
#define TFT_DC     2
#define TFT_RST    4

#define TFT_MOSI  23
#define TFT_SCLK  18

Adafruit_ST7735 tft = Adafruit_ST7735(
  TFT_CS,
  TFT_DC,
  TFT_RST
);

int sensorUmidade = 34;
int sensorLuz = 35;

void setup() {
  Serial.begin(115200);

  SPI.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);

  tft.initR(INITR_BLACKTAB);

  tft.setRotation(2);

  tft.fillScreen(ST77XX_BLACK);
}

void rodarAnimacaoFrente() {

  for (int i = 0; i < frenteallArray_LEN; i++) {

    tft.fillRect(
      0,
      0,
      128,
      160,
      ST77XX_BLACK
    );

    tft.drawRGBBitmap(

      0,
      0,

      frenteallArray[i],

      128,
      160
    );

    delay(frenteDelay[i]);
  }
}

void rodarAnimacaoagua() {

  for (int i = 0; i <aguaallArray_LEN; i++) {

    tft.fillRect(
      0,
      0,
      128,
      160,
      ST77XX_BLACK
    );

    tft.drawRGBBitmap(

      0,
      0,

      aguaallArray[i],

      128,
      160
    );

    delay(aguaDelay[i]);
  }
}

void rodarAnimacaofrio() {

  for (int i = 0; i <frioallArray_LEN; i++) {

    tft.fillRect(
      0,
      0,
      128,
      160,
      ST77XX_BLACK
    );

    tft.drawRGBBitmap(

      0,
      0,

      frioallArray[i],

      128,
      160
    );

    delay(frioDelay[i]);
  }
}

void rodarAnimacaoquente() {

  for (int i = 0; i <quenteallArray_LEN; i++) {

    tft.fillRect(
      0,
      0,
      128,
      160,
      ST77XX_BLACK
    );

    tft.drawRGBBitmap(

      0,
      0,

      quenteallArray[i],

      128,
      160
    );

    delay(quenteDelay[i]);
  }
}

void rodarAnimacaoseco() {

  for (int i = 0; i <secoallArray_LEN; i++) {

    tft.fillRect(
      0,
      0,
      128,
      160,
      ST77XX_BLACK
    );

    tft.drawRGBBitmap(

      0,
      0,

      secoallArray[i],

      128,
      160
    );

    delay(secoDelay[i]);
  }
}

void loop() {

  int umidade = analogRead(sensorUmidade);
  int luz = analogRead(sensorLuz);

  Serial.print("Umidade: ");
  Serial.print(umidade);

  Serial.print(" | Luz: ");
  Serial.println(luz);

  // ===== PRIORIDADE: ÁGUA =====

  if (umidade <= 1800) {

    Serial.println("💧 Muita água!");
    rodarAnimacaoagua();

  } 
  else if (umidade > 3000) {

    Serial.println("🌵 Pouca água!");
    rodarAnimacaoseco();

  } 
  else {

    // ===== ÁGUA NORMAL → VERIFICAR LUZ =====

    if (luz <= 1000) {

      Serial.println("🌑 Pouca luz!");
      rodarAnimacaofrio();

    } 
    else if (luz > 3200) {

      Serial.println("☀️ Muita luz!");
      rodarAnimacaoquente();

    } 
    else {

      Serial.println("✅ Planta feliz!");
      rodarAnimacaoFrente();

    }
  }

  Serial.println("-------------------");

  delay(2000);
}