String input = "";

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void loop() {
  Serial.print("Sending code: ");
  Serial.print("0xEEE");
  Serial.print(" for 15 seconds.");
  
  int i;

  for (i = 1; i < 30; ++i)
  {
    Serial.print(".");
    //IrSender.sendNEC(array[index].code, 32);
    delay(500);
  }
  Serial.println();
}
