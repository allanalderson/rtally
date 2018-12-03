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
}



void tallyScheduleTest170()
{
  tally1 = false;
  tally2 = true;
  tally3 = false;
  tally4 = true;
  tally5 = false;
  tally6 = true;
  tally7 = false;
  tally8 = true;
}

void tallyScheduleTest85()
{
  tally1 = true;
  tally2 = false;
  tally3 = true;
  tally4 = false;
  tally5 = true;
  tally6 = false;
  tally7 = true;
  tally8 = false;
}





void printTallyTones()
{
  Serial.println();

  if (tally8 == true)
  {
    Serial.print("1");
  }

  else
  {
    Serial.print("0");
  }
  if (tally7 == true)
  {
    Serial.print("1");
  }

  else
  {
    Serial.print("0");
  }
  if (tally6 == true)
  {
    Serial.print("1");
  }

  else
  {
    Serial.print("0");
  }
  if (tally5 == true)
  {
    Serial.print("1");
  }

  else
  {
    Serial.print("0");
  }
  if (tally4 == true)
  {
    Serial.print("1");
  }

  else
  {
    Serial.print("0");
  }
  if (tally3 == true)
  {
    Serial.print("1");
  }

  else
  {
    Serial.print("0");
  }
  if (tally2 == true)
  {
    Serial.print("1");
  }

  else
  {
    Serial.print("0");
  }

  if (tally1 == true)
  {
    Serial.print("1");
  }

  else
  {
    Serial.print("0");
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


void tallyScheduleTestCOUNT()
{
  tally1 = b & 1;
  tally2 = b & 2;
  tally3 = b & 4;
  tally4 = b & 8;
  tally5 = b & 16;
  tally6 = b & 32;
  tally7 = b & 64;
  tally8 = b & 128;
  b++;
}


void tallyScheduleTestSWITCH()
{
  if (testScheduleCounter == 20)
  {
    tally1 = true;
  }
  if (testScheduleCounter == 22)
  {
    tally1 = true;
    tally2 = true;
  }
  if (testScheduleCounter == 24)
  {
    tally1 = false;
    tally2 = true;
  }
  if (testScheduleCounter == 26)
  {
    tally2 = true;

    tally3 = true;
  }
  if (testScheduleCounter == 28)
  {
    tally2 = false;
    tally3 = true;
  }
  if (testScheduleCounter == 30)
  {
    tally3 = true;
    tally4 = true;
  }
  if (testScheduleCounter == 32)
  {
    tally3 = false;
    tally4 = true;
  }
  if (testScheduleCounter == 34)
  {
    tally4 = true;
    tally5 = true;
  }

  if (testScheduleCounter == 36)
  {
    tally4 = false;
    tally5 = true;
  }


  if (testScheduleCounter == 38)
  {
    tally5 = true;
    tally6 = true;
  }
  if (testScheduleCounter == 40)
  {
    tally5 = false;
    tally6 = true;
  }
  if (testScheduleCounter == 42)
  {
    tally6 = true;
    tally7 = true;

  }
  if (testScheduleCounter == 44)
  {
    tally6 = false;
    tally7 = true;
  }
  if (testScheduleCounter == 46)
  {
    tally7 = true;
    tally8 = true;
  }
  if (testScheduleCounter == 48)
  {
    tally7 = false;
    tally8 = true;

  }
  if (testScheduleCounter == 50)
  {
    tally8 = false;
    testScheduleCounter = 15;
  }


  testScheduleCounter ++;
}
