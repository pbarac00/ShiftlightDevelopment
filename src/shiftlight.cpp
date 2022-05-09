#include "shiftlight.h"
#include <arduino.h>

Shiftlight::Shiftlight(){
    assignRpmPoints();
}

//dodjeljuje rpmPoint svakoj LEDici
void Shiftlight::assignRpmPoints(){
    int i  = 0;
  for(i=0; i < LED_NUM; i++){
    configuration[i].rpmPoint = rpmPoints[i];
  }
}

//provjerava je li dosegnuta konstanta REV_LIMIT
bool Shiftlight::revLimitCheck(int rpm){
  if(rpm > REV_LIMIT)
    return true;
  else
    return false;
}
void Shiftlight::createLedConfiguration(int rpm){

  //if it hits more rpm than REV_LIMIT all LEDs become blue
  if(revLimitCheck(rpm)){
    memcpy(&curr_conf, &blue_conf, sizeof curr_conf);  //write rev limit configuration
  }


// Petlja se izvršava za svaku ledicu, ako je configuration.rpmPoint manji
//  od rpm-a dodijeli ledici pripadajuću boju iz color_patterna
  else{
    for (int i = 0; i < LED_NUM; i++) {
        if (configuration[i].rpmPoint < rpm) {
            curr_conf[i]= color_pattern[i];         
        } 
// LEDICA[i] postaje ugašena
        else {
            curr_conf[i] = OFF;
        }
    }
  }
}



void Shiftlight::writeToStrip(struct color curr_conf[10]){
  Serial1.write(0x73); //message start
  
  for (int i = 0; i < 10; i++) {
    Serial1.write(curr_conf[i].red);
    Serial1.write(curr_conf[i].green);
    Serial1.write(curr_conf[i].blue);
  }
}