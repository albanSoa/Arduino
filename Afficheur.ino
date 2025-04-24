#include <Wire.h>
#include <LiquidCrystal.h>
#include <math.h>
// LCD Keypad Shield broches : RS=8, E=9, D4=4, D5=5, D6=6, D7=7
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

const int MPU_ADDR = 0x68; // Adresse I2C par défaut du MPU6050

int16_t acc_x, acc_y, acc_z;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Initialisation...");

  // Activation du MPU6050
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B); // Registre PWR_MGMT_1
  Wire.write(0);    // Réveil
  Wire.endTransmission(true);

  delay(1000);
  lcd.clear();
}

void loop() {
  // Lire les données de l'accéléromètre
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); // Adresse ACCEL_XOUT_H
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6, true);

  acc_x = Wire.read() << 8 | Wire.read();
  acc_y = Wire.read() << 8 | Wire.read();
  acc_z = Wire.read() << 8 | Wire.read();

  // Calcul du pitch et du roll (en degrés)
  float ax = acc_x / 16384.0;
  float ay = acc_y / 16384.0;
  float az = acc_z / 16384.0;

  float pitch = atan2(-ay, sqrt(ax * ax + az * az)) * 180.0 / PI;
  float roll  = atan2(ax, az) * 180.0 / PI;
  
  // Affichage sur l'écran LCD
  lcd.setCursor(0, 0);
  lcd.print("Pitch: ");
  lcd.print(pitch, 1); // 1 décimale
  lcd.print(" deg");

  lcd.setCursor(0, 1);
  lcd.print("Roll:  ");
  lcd.print(roll, 1);
  lcd.print(" deg ");

  delay(300); // Delai de 300ms pour avoir des informations lisibles sur l'écran
}
