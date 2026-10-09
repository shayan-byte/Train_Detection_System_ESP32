int Redled=16;
int Greenled=17;
int Blueled=18;


void setup() 
{
  pinMode(Redled, OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(18,OUTPUT);

}

void loop() 
{
  digitalWrite(Redled, HIGH);
  delay(1000);
  digitalWrite(17, HIGH);
  delay(1000);
  digitalWrite(Blueled, HIGH);
  delay(1000);
  digitalWrite(Redled, LOW);
  delay(1000);
  digitalWrite(17, LOW);
  delay(1000);
  digitalWrite(Blueled, LOW);
  delay(1000);
}
