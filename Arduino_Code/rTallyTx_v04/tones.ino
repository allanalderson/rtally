// Output pin is D12 
// -------------------------------------------
void playToneREF()  // for about half a second
{
//Serial.println ("REF_TONE");
  TCCR0B = 0;//Disable Timer
  for (int i = 0; i < 1400; i++) // Use 1400
  {
    PORTB = B11010000; //make pin  high
    delayMicroseconds(51 + freqAdjust); // 51 10khz
    PORTB = B11000000; //make pin  low
    delayMicroseconds(51 + freqAdjust);
  }
  TCCR0B = 1; // Enable Timer
  
}


void playLongToneREF()
{
  //Serial.println ("REF_TONE (LONG)");
  TCCR0B = 0;//Disable Timer
  for (int i = 0; i < 16000; i++) 
  {
    PORTB = B11010000; //make pin  high
    delayMicroseconds(51 + freqAdjust); 
    PORTB = B11000000; //make pin  low
    delayMicroseconds(51 + freqAdjust);
  }
  TCCR0B = 1; // Enable Timer
  
}
// -------------------------------------------
// -------------------------------------------
void playTone1()  // for about half a second
{ 
  TCCR0B = 0;//Disable Timer
  for (int i = 0; i < 900+toneDurationAdjust; i++) // 900=80mS
  {
    PORTB = B11010000; //make pin  high
    delayMicroseconds(46 + freqAdjust); // 46 = 11.1khz
    PORTB = B11000000; //make pin  low
    delayMicroseconds(46 + freqAdjust);
  }
  TCCR0B = 1; // Enable Timer
}
// -------------------------------------------
void playTone2()  // for about half a second
{ 
  TCCR0B = 0;//Disable Timer
  for (int i = 0; i < 950+toneDurationAdjust; i++) // 950=80mS
  {
    PORTB = B11010000; //make pin  high
    delayMicroseconds(43 + freqAdjust); // 43 = 12khz
    PORTB = B11000000; //make pin  low
    delayMicroseconds(43 + freqAdjust);
  }
  TCCR0B = 1; // Enable Timer
}
// -------------------------------------------
void playTone3()  // for about half a second
{ 
  TCCR0B = 0;//Disable Timer
  for (int i = 0; i < 1000+toneDurationAdjust; i++) // 1000=80mS
  {
    PORTB = B11010000; //make pin  high
    delayMicroseconds(41 + freqAdjust); //41  = 12.5khz
    PORTB = B11000000; //make pin  low
    delayMicroseconds(41 + freqAdjust);
  }
  TCCR0B = 1; // Enable Timer 
}
// -------------------------------------------
void playTone4()  // for about half a second
{
  TCCR0B = 0;//Disable Timer
  for (int i = 0; i < 1060+toneDurationAdjust; i++) // 1050=80mS
  {
    PORTB = B11010000; //make pin  high
    delayMicroseconds(39 + freqAdjust); // 39 = 13.2khz
    PORTB = B11000000; //make pin  low
    delayMicroseconds(39 + freqAdjust);
  }
  TCCR0B = 1; // Enable Timer 
}
// -------------------------------------------
void playTone5()  // for about half a second
{
  TCCR0B = 0;//Disable Timer
  for (int i = 0; i < 1125+toneDurationAdjust; i++) // 1150=80mS
  {
    PORTB = B11010000; //make pin  high
    delayMicroseconds(37 + freqAdjust); // 37 = 14khz
    PORTB = B11000000; //make pin  low
    delayMicroseconds(37 + freqAdjust);
  }
  TCCR0B = 1; // Enable Timer 
}
// -------------------------------------------
void playTone6()  // for about half a second
{
  TCCR0B = 0;//Disable Timer
  for (int i = 0; i < 1190+toneDurationAdjust; i++) // 1190=80mS
  {
    PORTB = B11010000; //make pin  high
    delayMicroseconds(35 + freqAdjust); // 35 = 14.8khz
    PORTB = B11000000; //make pin  low
    delayMicroseconds(35 + freqAdjust);
  }
  TCCR0B = 1; // Enable Timer
}
// -------------------------------------------
void playTone7()  // for about half a second
{
  TCCR0B = 0;//Disable Timer
  for (int i = 0; i < 1255+toneDurationAdjust; i++) // 1250=80mS
  {
    PORTB = B11010000; //make pin  high
    delayMicroseconds(33 + freqAdjust); //   33 = 15.7khz
    PORTB = B11000000; //make pin  low
    delayMicroseconds(33 + freqAdjust);
  }
  TCCR0B = 1; // Enable Timer
}
// -------------------------------------------
void playTone8()  // for about half a second
{
  TCCR0B = 0;//Disable Timer
  for (int i = 0; i < 1320+toneDurationAdjust; i++) // 1320=80mS
  {
    PORTB = B11010000; //make pin  high
    delayMicroseconds(31 + freqAdjust); //  31 = 16.6khz
    PORTB = B11000000; //make pin  low
    delayMicroseconds(31 + freqAdjust);
  }
  TCCR0B = 1; // Enable Timer 
}
