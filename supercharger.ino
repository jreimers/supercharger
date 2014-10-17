
void setup() {                
  pinMode(13, OUTPUT);
  Serial.begin(9600);  
}
int charging = 0; // are we currently charging
void loop() {
  int reading = analogRead(A0);
  double voltage = reading * 5.0 / 1024.0; // convert ADC reading to voltage
  Serial.print(charging ? "Charging, current voltage: " : "Charge complete, voltage: ");
  Serial.println(voltage);
  if(voltage < 2.8 && !charging) {
    digitalWrite(13, HIGH);
    charging = 1;
  } else if(voltage > 2.8 && charging) {
    digitalWrite(13, LOW);
    charging = 0;
  }
  delay(1000);
}
