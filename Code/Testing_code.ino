#include <WiFi.h>
#include <Espalexa.h>

Espalexa espalexa;

#define RelayPin1 27  // D27
#define RelayPin2 26  // D26
#define RelayPin3 25  // D25
#define RelayPin4 33  // D33
#define RelayPin5 32  // D32

// WiFi Credentials
const char* ssid = "gp4";
const char* password = "hunza123";

// Device names
String Device_1_Name = "Room 1";
String Device_2_Name = "Room 2";
String Device_3_Name = "Room 3";
String Device_4_Name = "Room 4";
String Device_5_Name = "Charging Switch";

// WiFi LED pin
#define wifiLed 2 // D2

boolean wifiConnected = false;

// Callback functions for device control
void firstLightChanged(uint8_t brightness) {
  // Control the device connected to RelayPin1
  if (brightness == 255) {
    digitalWrite(RelayPin1, LOW);
    Serial.println("Bedroom Lamp ON");
  } else {
    digitalWrite(RelayPin1, HIGH);
    Serial.println("Bedroom Lamp OFF");
  }
}

void secondLightChanged(uint8_t brightness) {
  // Control the device connected to RelayPin2
  if (brightness == 255) {
    digitalWrite(RelayPin2, LOW);
    Serial.println("Desk Lamp ON");
  } else {
    digitalWrite(RelayPin2, HIGH);
    Serial.println("Desk Lamp OFF");
  }
}

void thirdLightChanged(uint8_t brightness) {
  // Control the device connected to RelayPin3
  if (brightness == 255) {
    digitalWrite(RelayPin3, LOW);
    Serial.println("Ceiling Light ON");
  } else {
    digitalWrite(RelayPin3, HIGH);
    Serial.println("Ceiling Light OFF");
  }
}

void fourthLightChanged(uint8_t brightness) {
  // Control the device connected to RelayPin4
  if (brightness == 255) {
    digitalWrite(RelayPin4, LOW);
    Serial.println("Floor Lamp ON");
  } else {
    digitalWrite(RelayPin4, HIGH);
    Serial.println("Floor Lamp OFF");
  }
}

void fifthLightChanged(uint8_t brightness) {
  // Control the device connected to RelayPin5
  if (brightness == 255) {
    digitalWrite(RelayPin5, LOW);
    Serial.println("Charging Switch ON");
  } else {
    digitalWrite(RelayPin5, HIGH);
    Serial.println("Charging Switch OFF");
  }
}

boolean connectWifi() {
  boolean state = true;
  int i = 0;

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi");

  // Wait for connection
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 20) {
      state = false;
      break;
    }
    i++;
  }
  Serial.println("");
  if (state) {
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Connection failed.");
  }
  return state;
}

void addDevices() {
  espalexa.addDevice(Device_1_Name, firstLightChanged);
  espalexa.addDevice(Device_2_Name, secondLightChanged);
  espalexa.addDevice(Device_3_Name, thirdLightChanged);
  espalexa.addDevice(Device_4_Name, fourthLightChanged);
  espalexa.addDevice(Device_5_Name, fifthLightChanged); // Adding the fifth device
  espalexa.begin();
}

void setup() {
  Serial.begin(115200);

  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
  pinMode(RelayPin5, OUTPUT); // Initialize the new relay pin

  pinMode(wifiLed, OUTPUT);  

  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);
  digitalWrite(RelayPin3, HIGH);
  digitalWrite(RelayPin4, HIGH);
  digitalWrite(RelayPin5, HIGH); // Ensure all relays are initially off

  wifiConnected = connectWifi();

  if (wifiConnected) {
    addDevices();
  } else {
    Serial.println("Cannot connect to WiFi. So in Manual Mode");
    delay(1000);
  }
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    digitalWrite(wifiLed, LOW);
  } else {
    digitalWrite(wifiLed, HIGH);
    if (wifiConnected) {
      espalexa.loop();
    } else {
      wifiConnected = connectWifi();
      if (wifiConnected) {
        addDevices();
      }
    }
  }

  // Check for Serial input
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    // Check the received command
    if (input == "turn on all devices") {
      turnOnAllDevices();
    } else if (input == "turn off all devices") {
      turnOffAllDevices();
    }
  }
}

void turnOnAllDevices() {
  digitalWrite(RelayPin1, LOW);
  digitalWrite(RelayPin2, LOW);
  digitalWrite(RelayPin3, LOW);
  digitalWrite(RelayPin4, LOW);
  digitalWrite(RelayPin5, LOW);
}

void turnOffAllDevices() {
  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);
  digitalWrite(RelayPin3, HIGH);
  digitalWrite(RelayPin4, HIGH);
  digitalWrite(RelayPin5, HIGH);
}
