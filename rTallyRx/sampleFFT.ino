

void takeSample()
{
  int dummy = analogRead(0); // dummy read
  for (int i = 0; i < SAMPLES; i++)
  {
    delayMicroseconds(8);// 8=4250, min 1.8Khz;
    vIntReal[i] = analogRead(0);
  }
  for (int i = 0; i < SAMPLES; i++)
  {
    vReal[i] = vIntReal[i];
    vImag[i] = 0;
  }
}



void computeFFT()
{
  
  FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
  FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
  peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
}
