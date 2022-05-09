#include "user_functions.h"





void setup()
{
  Serial.begin(115200);//uspostavlja serijsku komunikaciju sa MCP2515
  Serial.println("Application started...");
  initCANDevice(); //inicijalizira MCP2515, paziti na frekvenciju kristala -> default 16MHz
  Serial1.begin(115200);//uspostavlja serijsku komunikaciju na pinu 1, za transmitanje na ledicu 
}

void loop()
{
  recieveMessages();  //recieve CAN messages and display them in the serial monitor
 



 
}


