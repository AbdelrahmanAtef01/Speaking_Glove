## Speaking Glove 🤖🧤
A speaking glove project for the speechless that translates sign language into readable, listenable sequences based on AtMega32 and KNN Algorithm


## 👥 Contributors
| <img src="https://avatars.githubusercontent.com/u/109768834?s=400&u=b1286f34b7952b23ef706ef8d02e48fd0fb78751&v=4" width="150px;"/><br /><sub><b>[Abdelrahman Atef](https://github.com/AbdelrahmanAtef01)</b></sub><br /> | <img src="https://avatars.githubusercontent.com/u/136843019?v=4" width="150px;"/><br /><sub><b>[Hanin Sherif](https://github.com/HaninSh)</b></sub><br /> | <img src="https://avatars.githubusercontent.com/u/146020869?v=4" width="150px;"/><br /><sub><b>[Andrew Tanas](https://github.com/andrew-tanas)</b></sub><br /> |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |



---

## 📑 Table of Contents
1. [Introduction](#introduction)
2. [🎥 Demo Video](#demo-video)
3. [✨ Features](#features)
4. [🛠️ Dataset Preparation](#dataset-preparation)
5. [🔌 Required Components](#required-components)
6. [⚙️ System Architecture](#system-architecture)
   - [📚 Libraries](#libraries)
   - [🔋 MCAL (Microcontroller Abstraction Layer)](#mcal)
   - [🖥️ HAL (Hardware Abstraction Layer)](#hal)
   - [🧩 Services](#services)
7. [🤝 Connect & Collaborate](#connect--collaborate)

---

## 📝 Introduction
The Speaking Glove is designed to improve the lives of people with speech disabilities. This is achieved by translating sign language into a text sequence, which is displayed on LCD screen, and spoken words displayed through an audio speaker. The glove interprets hand gestures and converts them to the corresponding text and audio using Embedded AI.

## 🎥 Demo Video
[🔗 Watch the demo video here](#)

## ✨ Features
- **Scalability** 🌍: Unlike many similar projects limited to a simple set of predefined words, this project is highly scalable. We've integrated AI with embedded systems and implemented a simple K-Nearest Neighbors (KNN) algorithm. The KNN algorithm maps sensor readings to the closest matching word.
- **Customizable Vocabulary** 🗣️: To expand the vocabulary, you can simply add the sound files for new words to the M16P sound module and update the "sensor reads-to-word" dataset in the `get_word_sound` configuration file.
- **Sentence Handling** 📝: The project can interpret sentences by detecting a **STOPPING_WORD** or reaching a maximum sentence length. Once a sentence is complete, it displays and resets for the next one.
- **Efficient Scheduling** ⏳: Although it’s not built on an RTOS, the project schedules tasks using timers and flags, ensuring efficient parallel processing for reading and displaying without interference.

## 🛠️ Dataset Preparation
To create or expand the dataset:
1. Change the main configuration to "test mode," which displays sensor readings on the LCD.
2. Perform the gesture for a new word and record the sensor readings.
3. Add these readings to the configuration file, update the total word count, and the system is ready with the new vocabulary.

## 🔌 Required Components
- Atmega32 microcontroller
- 5 Flex sensors
- 2 KY020 tilt sensors
- M16P sound module
- SD card
- Speaker
- LED
- 16x2 LCD
- 1k resistors
- 8M crystal oscillator
- 10nF capacitors
- Wiring

## ⚙️ System Architecture

### 📚 Libraries
- **Standard Types** 📏: Defines standard data types for consistency.
- **Bit Math** 🔢: Provides utilities for bit-level operations.

### 🔋 MCAL (Microcontroller Abstraction Layer)
- **DIO Driver**: Manages digital input/output, used by LCD and LED.
- **ADC (Analog-to-Digital Converter)**: Converts analog signals from flex sensors to digital values.
- **Global Interrupt**: Manages interrupt routines, used by timers and USART.
- **Timers**:
  - **Timer0** 🕰️: Manages display-related tasks.
  - **Timer1** ⏲️: Manages sensor reading and conversion tasks.
- **USART** 🔗: Enables UART communication, used to send commands to the M16P sound module.

### 🖥️ HAL (Hardware Abstraction Layer)
- **LCD** 📺: Controls the LCD display for showing text.
- **LED** 💡: Provides visual feedback, toggling when a reading is taken.
- **M16P Sound Module** 🔊: Plays audio for corresponding words.
- **Flex Sensor** ✋: Reads and converts sensor data, indicating each finger's position.
- **Tilt Sensor** 🎛️: Detects hand angle to add contextual information.

### 🧩 Services
- **Get Glove Read** 📜: Collects sensor readings in an array format.
- **Get Word Sound** 🎤: Uses KNN to map sensor readings to the closest matching word.
- **Show** 🖥️🔊: Manages display and sound output, both on the LCD and through audio.

---

## 🤝 Connect & Collaborate
We’d love for you to connect and collaborate on this project! Whether you're interested in contributing to the codebase or expanding the dataset, your help is welcome. 

👀 Feel free to reach out!
