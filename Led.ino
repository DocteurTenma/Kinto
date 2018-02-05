const int LED = 13;

int incomingByte = 0;   // for incoming serial data

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);  
  Serial1.begin(9600);

  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while (Serial1.available() > 0) {
    incomingByte = Serial1.read();

    Serial.print("I received : ");
    Serial.println(incomingByte, DEC);
  }

  if (incomingByte == 89) {
    digitalWrite(LED, HIGH);  
  } else if (incomingByte == 78) {
    digitalWrite(LED, LOW);
  }

}
