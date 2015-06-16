
#include "AButton.h"

AButton blueButton(18, 1);

void setup()
{
  Serial.begin(9600);
}

void loop()
{

  blueButton.read();

  if (blueButton.pushed())
  {
    Serial.print("pushed\n");
  }

  if (blueButton.pressed())
  {
    Serial.print("pressed\n");
  }

  if (blueButton.released())
  {
    Serial.print("released\n\n");
  }





}
