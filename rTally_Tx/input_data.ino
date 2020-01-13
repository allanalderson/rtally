

void readTallyPins()
{
  tally1 = !digitalRead(11);
  tally2 = !digitalRead(2);
  tally3 = !digitalRead(3);
  tally4 = !digitalRead(4);
  tally5 = !digitalRead(5);
  tally6 = !digitalRead(6);
  tally7 = !digitalRead(7);
  tally8 = !digitalRead(8);

  if (tally1 == false && tally2 == false && tally3 == false && tally4 == false && tally5 == false && tally6 == false && tally7 == false && tally8 == false)
  {
    readTally_oneHotChase();
    delay(10000); // not really this long!
  }
  else
  {
    generateTallyByteFromTallys();
  }
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
