int Redled   = 16;
int Greenled = 17;
int Blueled  = 18; 
int Whiteled =21;

void setup() 
{
  pinMode(Redled, OUTPUT);
  pinMode(Greenled, OUTPUT);
  pinMode(Blueled, OUTPUT);
  pinMode(Whiteled, OUTPUT);

}

void loop() 
{
  // ---- RED ----
  allOff();
  digitalWrite(Redled, HIGH);
  delay(3000);   // blink time
  digitalWrite(Redled, LOW);
  delay(200);   // small gap

  // ---- GREEN ----
  allOff();
  digitalWrite(Greenled, HIGH);
  delay(3000);
  digitalWrite(Greenled, LOW);
  delay(200);

  // ---- BLUE ----
  allOff();
  digitalWrite(Blueled, HIGH);
  delay(3000);
  digitalWrite(Blueled, LOW);
  delay(200);

   // ---- WHITE ----
  allOff();
  digitalWrite(Whiteled, HIGH);
  delay(3000);
  digitalWrite(Whiteled, LOW);
  delay(200);
}

// Function to turn all OFF
void allOff()
{
  digitalWrite(Redled, LOW);
  digitalWrite(Greenled, LOW);
  digitalWrite(Blueled, LOW);
  digitalWrite(Whiteled, LOW);
}
