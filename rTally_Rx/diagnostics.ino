

void plotCRO()
{
  for (int i = 0; i < SAMPLES; i++)
  {
    Serial.println(vReal[i]) ;
  }
}


void plotTones()
{
  if (peak > 10500)
  {
    Serial.println(peak);
  }
}



void plotRefTrack()
{
  if (peakRefAverage > 8000)
  {
    Serial.println(peakRefAverage); // Converging to 10KHz
  }
}


void plotSampleFreq()
{
  Serial.println(SAMPLING_FREQUENCY);
}



void printBins()
{
  for (int i = 2; i < (SAMPLES / 2); i++)
  {
    Serial.print((i * 1.0 * SAMPLING_FREQUENCY) / SAMPLES, 1);
    Serial.print("\t");
    Serial.println(vReal[i], 1);    //View only this line in serial plotter to visualize the bins
  }
  Serial.println();
  Serial.println();
  Serial.println();
}


void plotFFT()
{
  for (int i = 2; i < (SAMPLES / 2); i++)
  {
    Serial.println(vReal[i], 1);    //View only this line in serial plotter to visualize the bins
  }
}




void printTallyByte()
{
  if (tallysEmpty == false)
  {
    Serial.print(tally8, BIN);
    Serial.print(tally7, BIN);
    Serial.print(tally6, BIN);
    Serial.print(tally5, BIN);
    Serial.print(tally4, BIN);
    Serial.print(tally3, BIN);
    Serial.print(tally2, BIN);
    Serial.println(tally1, BIN);
  }
}


void printTallyDecimals()
{
  if (tallysEmpty == false)
  {
    { int x = tally8 * 128 + tally7 * 64 + tally6 * 32 + tally5 * 16 + tally4 * 8 + tally3 * 4 + tally2 * 2 + tally1 * 1  ;
      Serial.println (x);
    }
  }
}
