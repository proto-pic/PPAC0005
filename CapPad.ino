// Use any 2 pins you like - this is NOT I2C ;-)
#define SCL_PIN 8
#define SDO_PIN 9
byte Key;
void setup()
{
  Serial.begin(9600);
  Serial.println("Cap key board");
  pinMode(SCL_PIN, OUTPUT);
  pinMode(SDO_PIN, INPUT);
}
void loop()
{
  Key = Read_Keypad();
  if (Key)
  {
    Serial.println(Key);
    delay(200);
  }
}
byte Read_Keypad(void)
{
  byte pinCount;
  byte KeyCount = 0;
  for (pinCount = 1; pinCount <= 16; pinCount++)
  {
    digitalWrite(SCL_PIN, LOW);
    if (digitalRead(SDO_PIN) == LOW)
    {
      KeyCount = pinCount;
    }
    digitalWrite(SCL_PIN, HIGH);
  }
  return KeyCount;
}
