//int pin8  = 8;
int sensor = A12;
int sensorValue = 0;

const float r1 = 20000.0;

void setup() {
  // put your setup code here, to run once:
 // pinMode [pin8, OUTPUT];
  Serial.begin(9600);
}

void loop() {
  /*sensorValue = analogRead(sensor);
  Serial.println(sensorValue,DEC);
  if (sensorValue > 500) {
    digitalWrite(pin8, HIGH);
  }
  else {
    digitalWrite(pin8,LOW);
  }*/

  sensorValue = analogRead(sensor);
  /*float rs = r1 * ((1023.0 / sensorValue) - 1.0);
  const float ro = sensorValue*3.4;
  int ppm = rs/ro;*/

  float rs = r1 * ((1023.0 / sensorValue) - 1.0);
  const float ro = rs/r1;
  float lgppm = (log10(ro)* (-2.6)+ 2.7);
  int ppm = pow(10,lgppm);
  


  Serial.print("resistansi sensor : ");
  Serial.println(sensorValue,DEC);
  Serial.print("nilai ppm :");
  Serial.println (ppm, DEC);
  delay(1000);
  

}
