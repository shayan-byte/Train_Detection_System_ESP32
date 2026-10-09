// -------- OUTPUT PINS --------
int Redled   = 16;
int Greenled = 17;
int Blueled  = 18;
int Whiteled = 21;
int Relay  = 19;
int Hooter = 25;


void setup()
{
  pinMode(Redled, OUTPUT);
  pinMode(Greenled, OUTPUT);
  pinMode(Blueled, OUTPUT);
  pinMode(Whiteled, OUTPUT);
  pinMode(Hooter, OUTPUT);
  pinMode(Relay, OUTPUT);

  allOff();   
}

void loop() 
{
  // ---- RED ----
  allOff();
  digitalWrite(Redled, HIGH);
  digitalWrite(Relay, HIGH);   // Relay ON (if needed)
  delay(3000);

  allOff();
  delay(200);

  // ---- GREEN ----
  allOff();
  digitalWrite(Greenled, HIGH);
  delay(3000);

  allOff();
  delay(200);

  // ---- BLUE ----
  allOff();
  digitalWrite(Blueled, HIGH);
  digitalWrite(Hooter, HIGH);   // When Blue then Hooter ON
  delay(3000);

  allOff();
  delay(200);
   
  //----WHITE----
  alloff();
  digitalWrite(Whiteled,HIGH);
  digitalWrite(Hooter, HIGH);  //When White then Hooter ON
  delay(3000);

  alloff();
  delay(200);
}

// -------- FUNCTION --------
void allOff()
{
  digitalWrite(Redled, LOW);
  digitalWrite(Greenled, LOW);
  digitalWrite(Blueled, LOW);
  digitalWrite(Whiteled, LOW);
  digitalWrite(Hooter, LOW);
  digitalWrite(Relay, LOW);
}
