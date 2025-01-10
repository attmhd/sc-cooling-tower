#include <DHT.h>

// Define the pin used for the DHT11 sensor
#define DHTPIN 2 // Digital pin connected to the DHT11

// Select the sensor type: DHT11
#define DHTTYPE DHT11

// Initialize the DHT object
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Start the DHT sensor
  dht.begin();
}

void loop() {
  // Wait a few seconds between readings
  delay(2000);

  // Read temperature
  float temperature = dht.readTemperature();

  // Check if the reading failed
  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT11 sensor!");
    return;
  }

  // Send temperature as bytes
  byte* bytePtr = (byte*)&temperature;  // Convert float to byte pointer
  for (int i = 0; i < sizeof(float); i++) {
    Serial.write(bytePtr[i]);  // Send each byte of the float
  }
}