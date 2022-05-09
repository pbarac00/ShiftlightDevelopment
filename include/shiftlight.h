class Shiftlight{

public:
    #define LED_NUM 10
#define REV_LIMIT 11200

//definira blueprint boja crvena, plava, zelena
struct color{
  unsigned char red;
  unsigned char green;
  unsigned char blue;
};

//this structure connects a color to a rpm point
struct color_rpm{
  struct color rgb;
  int rpmPoint;
};

  //color definition
  struct color RED{0x01,0x00,0x00};
  struct color GREEN{0x00,0x01,0x00};
  struct color BLUE{0x00,0x00,0x01};
  struct color OFF{0x00,0x00,0x00};

  //color and rpm configurations
  int rpmPoints[LED_NUM] = {7600, 8000, 8400, 8800, 9200, 9600, 10000, 10400, 10800, REV_LIMIT};
  struct color blue_conf[LED_NUM] = {BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE,BLUE};
  struct color color_pattern[LED_NUM] = {RED,RED,RED,RED,RED,GREEN,GREEN,GREEN,GREEN,GREEN};  //this configuration represents the color pattern which is used
  struct color curr_conf[LED_NUM]; //this configuration is the display configuration which is calculated in real time
    
  struct color_rpm configuration[LED_NUM];

  //init utility variables
  const int i = 0;
  // static int k = 1;
  const int rpm = 0;


    void assignRpmPoints();
    bool revLimitCheck(int rpm);
    void writeToStrip(struct color curr_conf[10]);
    void createLedConfiguration(int rpm);


    Shiftlight();
};