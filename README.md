 Third Eye For Blind Person
 
<img width="1227" height="620" alt="image" src="https://github.com/user-attachments/assets/cd5aaf4b-af4b-4682-8c26-804a5611604e" />

# Third Eye for Blind Person 👓

An Arduino-based assistive device designed to help visually impaired people detect obstacles and receive immediate alerts through sound and vibration.

## 📌 Introduction

The **Third Eye for Blind Person** is a wearable assistive device that uses an ultrasonic sensor to detect obstacles in the user's path.

When an obstacle is detected within a certain distance, the system provides feedback through:

- 🔊 Sound using a speaker or buzzer
- 📳 Vibration using a DC vibration motor

The device can be worn on different parts of the body, such as glasses, shoes, or a belt.

## 🎯 Objectives

- Detect obstacles in real time.
- Alert the user immediately when an obstacle is detected.
- Provide multiple feedback modes for accessibility.
- Create a wearable and hands-free assistive solution.
- Improve mobility and obstacle awareness for visually impaired users.

## ⚙️ Feedback Modes

| Mode | Alert |
|---|---|
| Alarm Only | 🔊 Sound |
| Vibration Only | 📳 Vibration |
| Alarm + Vibration | 🔊 Sound + 📳 Vibration |

## 🛠️ Hardware

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- Buzzer/Speaker
- DC Vibration Motor
- Supporting electronic components

## 💻 Technology

- C++
- Arduino

## 📂 Project Files

- `Third_Eye_for_The_Blind_Person.ino` — Arduino source code
- `Third Eye For Blind Person .pdsprj` — Proteus project

## 🔄 How It Works

1. The HC-SR04 ultrasonic sensor measures the distance to nearby objects.
2. The Arduino processes the measured distance.
3. When an obstacle is detected within the configured range, the system activates the selected feedback mode.
4. The user receives a sound alert, vibration alert, or both.

## 📚 Project Context

This project was developed as an academic/educational project focused on embedded systems and assistive technology.

## 📄 License

This project is for educational purposes.
