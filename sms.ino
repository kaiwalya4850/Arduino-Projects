int timesTosend = 1;
int count = 0;
char phone_no[]="";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
delay(2000);
Serial.println("AT+CMGF=1");
delay(200);
}

void loop() {
  // put your main code here, to run repeatedly:
while(count<timesTosend){
delay(1500);
Serial.print("AT+CMGS=\"");
Serial.print(phone_no);
Serial.println("\"");
float avg_val = 350;
while(Serial.read()!='>');
{
  Serial.print("The value of is as given and,");
  Serial.print(avg_val);
  Serial.print(" The value of is as given,");
  Serial.print(avg_val);
  Serial.print(" The value of is as given: ");
  Serial.print(avg_val);
  delay(500);
  Serial.write(0x1A);
  Serial.write(0x0D);
  Serial.write(0x0A);
  delay(500);
}
count++;
}
}
