float receivedTemperature;
byte receivedBytes[sizeof(float)];
const float setpoint = 29.00;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  delay(2000);
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
      digitalWrite(2, HIGH);
      Serial.println("Fan turn on...");
    }
    else{
      digitalWrite(2, LOW);
      Serial.println("Fan turn off...");
    }
  }
  else {
    Serial.println("No data received!");
  }
}