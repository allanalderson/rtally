/*
  Ready to  test the reciever's ref tracking system
  Fast wide staircase
  Fast narrow staircase
  Single Wide tone staircase with ref
  25 step back to V21
  40 Combined test OK
  41 adding camera switch scheudle test
  50 Start:
  8 tones (or !tones) are sent  between each ref tone: R+--+--R+--+--R+--+--R+--+--
  Suitable for binary transmittion (with some errors).
  Tone frequencies are adjusted and documented
  Tone pulsewidths set to 80mS
  Zero not available, only 1-255




*/
const int freqAdjust = 0; // 1?
bool tally1 = false;
bool tally2 = false;
bool tally3 = false;
bool tally4 = false;
bool tally5 = false;
bool tally6 = false;
bool tally7 = false;
bool tally8 = false;
bool tally9 = false;
byte b;
int toneDurationAdjust = -100; // Use -100 ; 0 (80mS).  
int tallyCount = 0;
unsigned long testScheduleCounter = 0;



void setup()
{
  Serial.begin(19200);
  
  pinMode(10, INPUT_PULLUP); // sync
  pinMode(11, INPUT_PULLUP); // 1
  pinMode(2, INPUT_PULLUP);  // 2
  pinMode(3, INPUT_PULLUP);  // 3
  pinMode(4, INPUT_PULLUP);  // 4
  pinMode(5, INPUT_PULLUP);  // 5
  pinMode(6, INPUT_PULLUP);  // 6
  pinMode(7, INPUT_PULLUP);  // 7
  pinMode(8, INPUT_PULLUP);  // 8
  pinMode(9, INPUT_PULLUP);  // 9


  DDRB = B11010000; //tone pin  is in output mode
  TCCR0A = 0;
  playLongToneREF();

}

void loop()
{
  //readTallyPins();
  //tallyScheduleTestSWITCH();
  //tallyScheduleTestCOUNT();
  tallyScheduleTest170();
  //printTallys();
  //printTallyTones();
  sendTallyTones();
  tallyScheduleTest85();
  sendTallyTones();
}

void sendTallyTones()
{
  
  playToneREF();

  if (tally8 == true)
  {
    playTone8();
  }
  if (tally7 == true)
  {
    playTone7();
  }
  if (tally6 == true)
  {
    playTone6();
  }
  if (tally5 == true)
  {
    playTone5();
  }
  if (tally4 == true)
  {
    playTone4();
  }
  if (tally3 == true)
  {
    playTone3();
  }
  if (tally2 == true)
  {
    playTone2();
  }
  if (tally1 == true)
  {
    playTone1();
  }


}



void readTallyPins()
{
  tally1 = digitalRead(11);
  tally2 = digitalRead(2);
  tally3 = digitalRead(3);
  tally4 = digitalRead(4);
  tally5 = digitalRead(5);
  tally6 = digitalRead(6);
  tally7 = digitalRead(7);
  tally8 = digitalRead(8);
  tallyCount = 0;
  if (tally1 == true)
  {
    tallyCount++;
  }
  if (tally2 == true)
  {
    tallyCount++;
  }
  if (tally3 == true)
  {
    tallyCount++;
  }
  if (tally4 == true)
  {
    tallyCount++;
  }
  if (tally5 == true)
  {
    tallyCount++;
  }
  if (tally6 == true)
  {
    tallyCount++;
  }
  if (tally7 == true)
  {
    tallyCount++;
  }
  if (tally8 == true)
  {
    tallyCount++;
  }
}
