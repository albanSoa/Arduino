# 📄 Afficheur de Pitch et Roll avec MPU6050 + LCD Keypad Shield

## 🎯 Description

Ce projet utilise un capteur **MPU6050** (accéléromètre + gyroscope) connecté à un Arduino pour **mesurer l'inclinaison** (`pitch` et `roll`) en temps réel.  
Les valeurs sont affichées sur un **écran LCD 16x2** à l'aide d'un **LCD Keypad Shield**.

---

## 🛠 Matériel nécessaire

- 1 × Arduino Uno (ou compatible)
- 1 × Capteur MPU6050
- 1 × LCD Keypad Shield (ou écran LCD 16x2 compatible)
- Câbles de connexion
- (Optionnel) Breadboard

---

## 🔌 Schéma de connexion

| Module         | Arduino         |
|:---------------|:----------------|
| VCC (MPU6050)  | 5V               |
| GND (MPU6050)  | GND              |
| SDA (MPU6050)  | A4 (I2C data)    |
| SCL (MPU6050)  | A5 (I2C clock)   |

Le LCD Keypad Shield se branche **directement** sur l'Arduino Uno.

---

## 📚 Librairies utilisées

- **Wire.h** → pour la communication I2C avec le MPU6050
- **LiquidCrystal.h** → pour contrôler l'afficheur LCD

Ces librairies sont **incluses d'origine** avec l'IDE Arduino.

---

## ⚙️ Fonctionnement du programme

1. **Initialisation** de la communication I2C et de l'écran LCD.
2. **Réveil** du capteur MPU6050 (sortie du mode veille).
3. **Lecture des valeurs** d'accélération sur les axes X, Y et Z.
4. **Calcul** du **pitch** (inclinaison avant/arrière) et du **roll** (inclinaison latérale) en degrés.
5. **Affichage** en temps réel des deux angles sur l'écran LCD.

---

## 🧠 Notes techniques

- Les calculs de `pitch` et `roll` utilisent uniquement l'accéléromètre.
- Les valeurs sont **normalisées** (`/16384.0`) car 16384 LSB = 1g pour le MPU6050 en configuration standard.
- L’affichage est mis à jour toutes les **300 ms** pour faciliter la lecture.
- Le MPU6050 est utilisé à son adresse I2C par défaut `0x68`.

---

## 📸 Aperçu d'affichage

