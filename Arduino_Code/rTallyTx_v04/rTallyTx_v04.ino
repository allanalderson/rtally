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
  v0.5 Prints ID @ 1200 baud. Various refactoring.
  V01 Tally to and from byte.
  v02 decimal()
  v03 removed unused counters.
  v04 Code Tidy/ Baud 9600




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
int toneDurationAdjust = -100; // Use -100 ; 0 (80mS).
byte tallyByte = 0;


void setup()
{
  Serial.begin(9600);
  Serial.println("");
  Serial.println("rTallyTx v04");
  Serial.println("");

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

  for (int i = 0; i <= 7; i++)
  {
    readTally_oneHotChase();
    //readTally_binaryCountUp();
    sendTallyTones();
    delay(20000); // not twenty seconds!
  }
  readTally_decimal(0);
  sendTallyTones();
}


//THE POSSIBILITIES ARE ENDLESS :)
//readTallyPins();
//readTally_binaryCountUp();
//readTally_oneHotChase();
//readTally_decimal(170); // (85) (x) force the byte
//printTallys();
//sendTallyTones();



void loop()
{
  readTallyPins();
  sendTallyTones();
}






void sendTallyTones()
{
  playToneREF();
  generateTallysFromTallyByte();
  printTallys();
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




void printTallys()
{
  Serial.print(tally8);
  Serial.print(tally7);
  Serial.print(tally6);
  Serial.print(tally5);
  Serial.print(tally4);
  Serial.print(tally3);
  Serial.print(tally2);
  Serial.println(tally1);
}





void generateTallyByteFromTallys() //
{
  tallyByte = tally8 * 128 + tally7 * 64 + tally6 * 32 + tally5 * 16 + tally4 * 8 + tally3 * 4 + tally2 * 2 + tally1 * 1;
}




void generateTallysFromTallyByte()
{
  tally1 = tallyByte & 1;
  tally2 = tallyByte & 2;
  tally3 = tallyByte & 4;
  tally4 = tallyByte & 8;
  tally5 = tallyByte & 16;
  tally6 = tallyByte & 32;
  tally7 = tallyByte & 64;
  tally8 = tallyByte & 128;
}
