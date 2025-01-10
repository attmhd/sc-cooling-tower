float receivedTemperature;
byte receivedBytes[sizeof(float)];
const float setpoint = 29.00;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() >= sizeof(float)) {
    // Read the bytes into the array
    for (int i = 0; i < sizeof(float); i++) {
      receivedBytes[i] = Serial.read();
    }

    // Reconstruct the float from bytes using memcpy
    memcpy(&receivedTemperature, receivedBytes, sizeof(float));

    // Use the received float (e.g., print it)
    Serial.println(receivedTemperature);

    if (receivedTemperature > setpoint){
      Serial.println("Kipas menyalaa...");
    }
    else{
      Serial.println("Kipas mati");
    }
  }
}