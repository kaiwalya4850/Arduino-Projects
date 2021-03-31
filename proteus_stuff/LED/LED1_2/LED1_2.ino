
void setup()
{ 
  int i;
  for(i=0;i<8;i++)
  {
    pinMode(i,OUTPUT);
  }
}
void loop()
{
  PORTD=0xaa;
  delay(1000);
  PORTD=0x55;
  delay(1000);
}


