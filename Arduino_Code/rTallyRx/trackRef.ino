

void searchForRefTone()
{
  if (peak < refTone + refSearchBandwidth && peak > refTone - refSearchBandwidth) // A wide aperature to find the Ref tone.
  {
    refFound = true;
    peakRefAverage = AV.reading(peak); // UPDATE AVERAGING
    memoriesToTallys();
    clearTallyMemories();
    //printTallyByte();
    printTallyDecimals();
    clearTallys();
  }

  if (peakRefAverage < 10004 && peakRefAverage > 9996)
  {
    // Ref. Locked, so narrow ref search bandwidth...
    refSearchBandwidth = 40;
  }
  else
    refFound = false;

}



void updateSampleFreqUsingRef()
{
  if (peakRefAverage > 10000 + 99)
  {
    SAMPLING_FREQUENCY = SAMPLING_FREQUENCY - 5;
  }
  if (peakRefAverage < 10000 - 99)
  {
    SAMPLING_FREQUENCY = SAMPLING_FREQUENCY + 15 ;
  }
  // --------
  if (peakRefAverage > 10000 + 49)
  {
    SAMPLING_FREQUENCY = SAMPLING_FREQUENCY - 2;
  }
  if (peakRefAverage < 10000 - 49)
  {
    SAMPLING_FREQUENCY = SAMPLING_FREQUENCY + 2 ;
  }
  // --------
  if (peakRefAverage > 10000 + 6)
  {
    SAMPLING_FREQUENCY = SAMPLING_FREQUENCY - 1;
  }
  if (peakRefAverage < 10000 - 6)
  {
    SAMPLING_FREQUENCY = SAMPLING_FREQUENCY + 1;
  }

}
