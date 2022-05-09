#include "canHandler.h"

canHandler can0(7,SS);  //set INT and CS pin: 2,10- za UNO ;  7,SS - za MICRO
// !!! neznan sta je sa assignRpmPoints !!!

void setup()
{
  Serial.begin(115200);
  Serial.println("Application started...");
  can0.initCANDevice();
  Serial1.begin(115200);
}
  
void loop()
{
  // nema nigdi delay(x), neznan jel Serial.flush() dovoljno!?
  can0.recieveMessages();  //recieve CAN messages and display them in the serial monitor
  can0.sendRpmToLED();
}

//IDEJA: napravit sendRpmToLED u shiftlight klasi