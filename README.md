# 💡 Dual LED Alternating Blink

A beginner-friendly embedded systems project that blinks two LEDs one after the other using an Arduino. It is a clean demonstration of digital output control, timing with `delay()`, and using named variables instead of hard-coded numbers.

![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=flat-square&logo=cplusplus&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Arduino-00979D?style=flat-square&logo=arduino&logoColor=white)
![Status](https://img.shields.io/badge/Status-Working-00D4AA?style=flat-square)

---

## 📖 Overview

The program turns two LEDs on and off in a repeating sequence. Only one LED is lit at a time, with a short dark gap between each step.

| Step | Action | Duration |
|:--:|:--|:--:|
| 1 | LED on **pin 2** turns ON | 700 ms |
| 2 | LED on **pin 2** turns OFF | 700 ms |
| 3 | **Red LED** on **pin 8** turns ON | 700 ms |
| 4 | **Red LED** on **pin 8** turns OFF | 700 ms |

One full cycle takes **2.8 seconds**, then it repeats forever.

---

## 🧰 Hardware Required

- 1 × Arduino board (Uno, Nano or any compatible board)
- 1 × LED (any colour)
- 1 × Red LED
- 2 × 220 Ω resistors (one per LED)
- Breadboard and jumper wires
- USB cable

---

## 🔌 Wiring

| Arduino Pin | Connects to |
|:--:|:--|
| Digital **2** | 220 Ω resistor → LED anode (long leg) |
| Digital **8** | 220 Ω resistor → Red LED anode (long leg) |
| **GND** | Both LED cathodes (short leg) |

```
Pin 2 ──[220Ω]──►|── GND      (LED)
Pin 8 ──[220Ω]──►|── GND      (Red LED)
```

> ⚠️ Always use a current-limiting resistor with each LED to protect both the LED and the board.

---

## ⚙️ Configuration

All settings are at the top of the file, so you can change the behaviour without touching the logic:

| Variable | Default | Purpose |
|:--|:--:|:--|
| `ledpin` | `2` | Pin for the first LED |
| `redledpin` | `8` | Pin for the red LED |
| `delaytime` | `700` | Time in milliseconds for each ON/OFF step |

Lower `delaytime` for faster blinking, or raise it for slower blinking.

---

## 🧠 How It Works

```cpp
#include <Arduino.h>

int redledpin = 8;
int ledpin = 2;
int delaytime = 700;

void setup() {
  pinMode(ledpin, OUTPUT);     // configure both pins as outputs
  pinMode(redledpin, OUTPUT);
}

void loop() {
  digitalWrite(ledpin, HIGH);  // LED 1 on
  delay(delaytime);
  digitalWrite(ledpin, LOW);   // LED 1 off
  delay(delaytime);

  digitalWrite(redledpin, HIGH); // red LED on
  delay(delaytime);
  digitalWrite(redledpin, LOW);  // red LED off
  delay(delaytime);
}
```

- **`setup()`** runs once at power-up and sets both pins as outputs with `pinMode()`.
- **`loop()`** runs continuously. `digitalWrite(pin, HIGH)` sends 5 V to the pin to light the LED, and `LOW` sends 0 V to turn it off.
- **`delay(ms)`** pauses the program for the given number of milliseconds.

---

## 🚀 Getting Started

### Option 1: Arduino IDE
1. Open the Arduino IDE and create a new sketch.
2. Paste the code above (the `#include <Arduino.h>` line is optional in the IDE).
3. Select your board and port under **Tools**.
4. Click **Upload**.

### Option 2: PlatformIO (VS Code)
1. Create a new project and choose your board.
2. Put the code in `src/main.cpp`.
3. Example `platformio.ini`:
```ini
   [env:uno]
   platform = atmelavr
   board = uno
   framework = arduino
```
4. Click **Upload** in the PlatformIO toolbar.

---

## 🛠️ Troubleshooting

| Problem | Likely cause |
|:--|:--|
| LED never lights | LED is the wrong way round. The long leg (anode) must face the pin. |
| LED is very dim | Resistor value is too high. Try 220 Ω to 330 Ω. |
| Upload fails | Wrong board or port selected, or a faulty USB cable. |
| Using
