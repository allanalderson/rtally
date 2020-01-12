

/*
  New calibration freq.
  CHANGES TO REF TRACKING
  Superfast ADC reads. ( MAX SAMPLING_FREQUENCY 61656 )
  Code tidy.
  slowdown sample
  More plot options
  Now using 128 point fft
  smoother ref averaging
  Plot Camera ID

  No Signal Noise fixing with averaging soon

  ref tone bandwith narrowing if refLocked

  added toneAperature
  Refactoring
  Requires a ref tone prior to tone detection before switching
  31 Camera Booleans,Refactoring,Killtallys bug fixed
  32 Killtallys bug fixed
  50 Start:
  51 8 tones (or !tones) are sent  between each ref tone: R+--+--R+--+--R+--+--R+--+--
  Expecting corrected tone frequencies

  Using tone list

  Need to implement: If peak not legal, then wait for a while. or Polite.
  Polite OK

*/

#include <arduinoFFT.h>
#include <movingAvg.h>



#define T1  11114
#define T2  11760
#define T3  12372
#define T4  13043
#define T5  13758
#define T6  14572
#define T7  15541
#define T8  16545
#define SAMPLES 128             //Must be a power of 2. TYP: 64
/*Although the SAMPLING_FREQUENCY is auto-tracking via the 10kHz reference tone, on first powerup
  this Ref tone should at least be somewhere in the ballpark. An initial value of of around 43180
  when using a microsecond delay of 8 in the sampling routine.
  Note: It is not possible to transmit Zero*/
double SAMPLING_FREQUENCY = 42560; //Hz, Ref at 10kHz . 1Vpp: at ADC input.

int toneAperature = 260; // Width 260



arduinoFFT FFT = arduinoFFT();
double vReal[SAMPLES];
int vIntReal[SAMPLES];
double vImag[SAMPLES];
#define FASTADC 1
// defines for setting && clearing register bits
#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif
int previousTone_ID = 99;
int refTone = 10000;
int refSearchBandwidth = 400;
int  peak;
int peakRefAverage;
bool refFound = true;
int RefDetectionConfidence;
bool tally1 = false;
bool tally2 = false;
bool tally3 = false;
bool tally4 = false;
bool tally5 = false;
bool tally6 = false;
bool tally7 = false;
bool tally8 = false;
bool tally1mem = false;
bool tally2mem = false;
bool tally3mem = false;
bool tally4mem = false;
bool tally5mem = false;
bool tally6mem = false;
bool tally7mem = false;
bool tally8mem = false;
bool tallysEmpty = true;
movingAvg AV(30); // Too low && jitter, too high && heavy oscillation.


void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(19200);
  int start;
  int i;
  AV.begin();

#if FASTADC
  // set prescale to 16
  sbi(ADCSRA, ADPS2) ;
  cbi(ADCSRA, ADPS1) ;
  cbi(ADCSRA, ADPS0) ;
#endif
  Serial.println();
  Serial.println("rTallyRX v01 ");
  clearTallyMemories();
  clearTallys();
}





void loop()
{
  TCCR0B = 0;//Disable Timer
  takeSample();
  //plotCRO();//******
  computeFFT();
  TCCR0B = 1; // Enable Timer}
  // -------------------
  //plotFFT();//******
  //printBins();//******
  plotTones();//******
  searchForRefTone();
  //plotRefTrack();//******
  updateSampleFreqUsingRef();
  //plotSampleFreq();//******
  searchForTallyTones();
  //printTallyByte();


}


void clearTallyMemories()
{

  tally1mem = false;
  tally2mem = false;
  tally3mem = false;
  tally4mem = false;
  tally5mem = false;
  tally6mem = false;
  tally7mem = false;
  tally8mem = false;
}


void clearTallys()
{
  tally1 = false;
  tally2 = false;
  tally3 = false;
  tally4 = false;
  tally5 = false;
  tally6 = false;
  tally7 = false;
  tally8 = false;
}

void sleep()
{
  // looking for that lovely 10 k tone
  refFound = false;
  delay(7000);
  while (refFound = false)
  {
    TCCR0B = 0;//Disable Timer
    takeSample();
    computeFFT();
    TCCR0B = 1; // Enable Timer}
    searchForRefTone();
  }
  clearTallyMemories();
  clearTallys();
  peak = 0;
  delay(7000);
}


void searchForTallyTones()
{

  if (peak >= T1 - toneAperature && peak <= T1 + toneAperature) {
    tally1mem = true;
  }
  else if (peak >= T2 - toneAperature && peak <= T2 + toneAperature) {
    tally2mem = true;
  }
  else if (peak >= T3 - toneAperature && peak <= T3 + toneAperature) {
    tally3mem = true;
  }
  else if (peak >= T4 - toneAperature && peak <= T4 + toneAperature) {
    tally4mem = true;
  }
  else if (peak >= T5 - toneAperature && peak <= T5 + toneAperature) {
    tally5mem = true;
  }
  else if (peak >= T6 - toneAperature && peak <= T6 + toneAperature) {
    tally6mem = true;
  }
  else if (peak >= T7 - toneAperature && peak <= T7 + toneAperature) {
    tally7mem = true;
  }
  else if (peak >= T8 - toneAperature && peak <= T8 + toneAperature) {
    tally8mem = true;
  }
  else if (peak < 9000 && refSearchBandwidth < 200) // sounds like the director is talking
  {
    Serial.println("No valid Tones");
    sleep();
    return;
  }
}




void memoriesToTallys()
{
  int x = tally1mem + tally2mem + tally3mem + tally4mem + tally5mem + tally6mem + tally7mem + tally8mem;
  if (x == 0)
  {
    tallysEmpty = true;
  }
  else
  {
    tallysEmpty = false;
  }

  tally1 = tally1mem;
  tally2 = tally2mem;
  tally3 = tally3mem;
  tally4 = tally4mem;
  tally5 = tally5mem;
  tally6 = tally6mem;
  tally7 = tally7mem;
  tally8 = tally8mem;

}
