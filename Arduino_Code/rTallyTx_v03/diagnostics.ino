void tallyScheduleTest255()
{
  tally1 = true;
  tally2 = true;
  tally3 = true;
  tally4 = true;
  tally5 = true;
  tally6 = true;
  tally7 = true;
  tally8 = true;
  generateTallyByteFromTallys();
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


void readTally_binaryCountUp()
{
  generateTallysFromTallyByte();
  tallyByte ++;
}


void readTally_oneHotChase() // Lots of magic numbers here.
{
  if (tallyByte == 0)
  {
    tallyByte = 1;
  }
  generateTallysFromTallyByte();
  tallyByte = tallyByte << 1;
}
