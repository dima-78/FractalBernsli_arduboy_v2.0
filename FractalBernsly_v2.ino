//FractalBernsly v2
//created @dima-78
//2023_09_19

#include <Arduboy2.h>

Arduboy2 arduboy;

bool rotateScreen = false; // Флаг для определения, нужно ли поворачивать экран
int iterations = 1; // Количество итераций для построения фрактала
int iterationCount = 1;
int scaleFactorCount = 1;
uint8_t scaleFactor = 32;
uint8_t iterationsChange = 2;
float x, y; // Координаты текущей точки

void setup() {
  arduboy.begin();
  arduboy.clear();
  arduboy.setFrameRate(60);
  arduboy.initRandomSeed();
  x = arduboy.width() ;
  y = arduboy.height() ;
  arduboy.flipHorizontal(true);
  //arduboy.flipVertical(true);

  //Serial.begin(115200);
}

//float x = 0; // Начальная координата
//float y = 0;

void loop() {
  if (!arduboy.nextFrame()) {
    return;
  }
  arduboy.pollButtons();

  int minScaleFactor = 2;
  int maxScaleFactor = 32;
  bool notPressKey = false;

  if (arduboy.pressed(UP_BUTTON)) {
    iterations += iterationsChange;
    arduboy.clear();
  }
  if (arduboy.pressed(DOWN_BUTTON)) {
    if (iterations > 1) {
      iterations -= iterationsChange;
    }
    arduboy.clear();
  }

  if (arduboy.pressed(LEFT_BUTTON)) {
    if (scaleFactor > minScaleFactor) {
      scaleFactor--;
      arduboy.clear();
    }
  }
  if (arduboy.pressed(RIGHT_BUTTON)) {
    if (scaleFactor < maxScaleFactor) {
      scaleFactor++;
      arduboy.clear();
    }
  }

  if (arduboy.justPressed(A_BUTTON)) {
    rotateScreen = !rotateScreen; // Изменяем значение флага при нажатии кнопки A
    arduboy.flipVertical(rotateScreen); // Устанавливаем поворот экрана в соответствии с флагом
  }

  if (arduboy.justPressed(B_BUTTON)) {
    rotateScreen = !rotateScreen; // Изменяем значение флага при нажатии кнопки A
    arduboy.flipHorizontal(rotateScreen); // Устанавливаем поворот экрана в соответствии с флагом
  }



  for (int i = 0; i < iterations; i++) {

    //if (iterationCount == iterations) {
      arduboy.drawPixel(y * scaleFactor, x * scaleFactor, WHITE);

      // if (scaleFactorCount > maxScaleFactor) {
      //   scaleFactorCount = minScaleFactor;
      // }

      int r = random(100);
      if (r < 1) {
        float x1 = 0;
        float y1 = 0.16 * y; //0.16 * y;
        x = x1;
        y = y1;
      }
      else if (r < 86) {
        float x1 = (0.85 * x) + (0.04 * y);
        float y1 = (-0.04 * x) + (0.85 * y) + 1.6;
        x = x1;
        y = y1;
      }
      else if (r < 93) {
        float x1 = (0.2 * x) - (0.26 * y);
        float y1 = (0.23 * x) + (0.22 * y) + 1.6;
        x = x1;
        y = y1;
      }
      else {
        float x1 = (-0.15 * x) + (0.28 * y);
        float y1 = (0.26 * x) + (0.24 * y) + 0.44;
        x = x1;
        y = y1;
      }

      scaleFactorCount++;
      iterationCount++;
    //}
    //iterationCount++;
  }
  /*
      if (iterationCount == iterations) {
        scaleFactorCount++;

        if (scaleFactorCount > maxScaleFactor) {
          scaleFactorCount = minScaleFactor;
        }

        scaleFactor = scaleFactorCount;
        iterations += iterationsChange;
        //arduboy.clear();
       // break;
      }
      iterationCount++;
    }
  */

  //debug();

  arduboy.display();
}


void debug() {
  Serial.print(millis()); Serial.print("\t");
  Serial.print("iterationCount: "); Serial.print(iterationCount); Serial.print("\t");
  Serial.print("iterations: "); Serial.print(iterations); Serial.print("\t");
  Serial.print("scaleFactorCount: "); Serial.print(scaleFactor); Serial.print("\t");
  Serial.print("scaleFactor: "); Serial.print(scaleFactorCount); Serial.print("\t");
  Serial.print("\r\n");
}
