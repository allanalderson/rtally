

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
  generateTallyByteFromTallys();
}





void readTally_binaryCountUp()
{
  generateTallysFromTallyByte();
  tallyByte ++;
}




void readTally_oneHotChase()
{
  if (tallyByte == 0)
  {
    tallyByte = 1;
  }
  else
  {
    tallyByte = tallyByte << 1;
  }
}



void readTally_decimal(byte decimal)
{
  tallyByte = decimal;
}
