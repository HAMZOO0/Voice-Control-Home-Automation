# 🌟 Home Automation System with ESP32 and Alexa Echo Dot 🌟

![Home Automation](https://img.shields.io/badge/Home%20Automation-ESP32%20%2B%20Alexa-blueviolet)
![License](https://img.shields.io/badge/license-MIT-green)
![Status](https://img.shields.io/badge/status-Active-brightgreen)

Welcome to the Home Automation System project! This project enables you to control home appliances using an ESP32 microcontroller and voice commands via Amazon Alexa Echo Dot.

 ### Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Demo](#demo)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Configuration](#configuration)
- [Usage](#usage)
- [Troubleshooting](#troubleshooting)
- [License](#license)
- [Contributing](#contributing)
- [Acknowledgments](#acknowledgments)

### 1. Introduction

This project integrates an ESP32 microcontroller with Amazon Alexa to create a voice-controlled home automation system. Using the Alexa Skills Kit (ASK) and AWS IoT, you can control various home appliances seamlessly.

### 2. Features

- 🔌 **Voice Control**: Control home appliances using simple voice commands.
- 🌐 **Remote Access**: Manage your devices from anywhere via Wi-Fi.
- ⚡ **Easy Setup**: Quick and straightforward installation process.
- 🛠️ **Customizable**: Easily extend and modify the project to suit your needs.


![Home Automation Demo](demo.gif)

### 3 Hardware Requirements

- **ESP32 Microcontroller**
- **Relay Module** (for controlling appliances)
- **Amazon Alexa Echo Dot**
- **Jumper Wires** and **Breadboard**
- **Home Appliances** (e.g., lights, fans)

### 4. Software Requirements

- **Arduino IDE**
- **ESP32 Board Support** for Arduino IDE
- **Amazon Developer Account** (for Alexa Skill)
- **AWS Account** (for AWS IoT)

### 5.  Installation

#### 1. Set up ESP32 with Arduino IDE

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Set up the ESP32 board in Arduino IDE. Follow the [ESP32 setup guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html).

### 6. Clone this Repository

```bash
git clone https://github.com/yourusername/home-automation-esp32-alexa.git
cd home-automation-esp32-alexa

Install Required Libraries
Open Arduino IDE and install the following libraries via the Library Manager:
•	ESP DEV
•	AsyncTCP
•	ArduinoJson
. Set Up AWS IoT
1.	Create an AWS account if you don't have one.
2.	Set up AWS IoT and create a new Thing. Follow the AWS IoT setup guide.
3.	Download the security certificates for the Thing.
4.	Attach an IoT policy to the Thing.
 Configure Alexa Skill
1.	Create an Amazon Developer account if you don't have one.
2.	Create a new Alexa Skill. Follow the Alexa Skills Kit guide.
3.	Set up the endpoint for your skill to interact with AWS IoT.
. Flash the ESP32
1.	Open the home_automation.ino file in Arduino IDE.
2.	Modify the config.h file with your Wi-Fi credentials, AWS IoT endpoint, and security certificate details.
3.	Connect the ESP32 to your computer and upload the sketch.
Configuration
1.	Wi-Fi Configuration: Ensure the ESP32 is connected to your Wi-Fi network.
2.	AWS IoT Configuration: Update the config.h file with the AWS IoT endpoint and certificates.
3.	Alexa Skill Configuration: Ensure the Alexa skill is properly configured to communicate with your AWS IoT endpoint.
Usage
1.	Plug in the ESP32 and ensure it connects to your Wi-Fi network.
2.	Use the Alexa app to discover new devices.
3.	Once the ESP32 is discovered, you can control the connected appliances using voice commands, such as:
o	"Alexa, turn on the light."
o	"Alexa, turn off the fan."
Troubleshooting
•	ESP32 not connecting to Wi-Fi: Ensure the Wi-Fi credentials in config.h are correct.
•	Alexa not discovering devices: Ensure the skill is correctly configured and the ESP32 is online.
•	AWS IoT connection issues: Verify the security certificates and endpoint details.
License
This project is licensed under the MIT License. See the LICENSE file for more details.
