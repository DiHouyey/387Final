#include <UTFT.h>
#include <URTouch.h>
#include <Wire.h>

UTFT    myGLCD(CTE32_R2,38,39,40,41);
URTouch  myTouch( 6, 5, 4, 3, 2);


extern uint8_t BigFont[];

int x, y;
String val;
void drawButtons()
{

  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (70, 10, 120, 60);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (70, 10, 120, 60);
  myGLCD.print("U", 87, 27);
  
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (70, 70, 120, 120);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (70, 70, 120, 120);
  myGLCD.print("D", 87, 87);
   
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (10, 70, 60, 120);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (10, 70, 60, 120);
  myGLCD.print("L", 27, 87);
   
  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (130, 70, 180, 120);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (130, 70, 180, 120);
  myGLCD.print("R", 147, 87);

  myGLCD.setColor(0, 0, 255);
  myGLCD.fillRoundRect (50, 130, 140, 180);
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (50, 130, 140, 180);
  myGLCD.print("STOP", 60, 147);
  
  myGLCD.setBackColor (0, 0, 0);
}
  
void waitForIt(int x1, int y1, int x2, int y2){
  
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
  while (myTouch.dataAvailable())
    myTouch.read();
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
}

void setup()
{
// Initial setup
  myGLCD.InitLCD();
  myGLCD.clrScr();

  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);
  
  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(0, 0, 255);
  drawButtons();  

}

void loop() {
  while (true){
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
      
       if ((y>=10) && (y<=60)) 
      {
       
        if ((x>=70) && (x<=120))  
        {
          waitForIt(70, 10, 120, 60);
          Wire.beginTransmission(5);
          Wire.write('w');
          Wire.endTransmission();
        }
      }
       if ((y>=70) && (y<=120))  
      {
        if ((x>=10) && (x<=60))  
        {
          waitForIt(10, 70, 60, 120);
          Wire.beginTransmission(5);
          Wire.write('a');
          Wire.endTransmission();
        }
        if ((x>=70) && (x<=120)) 
        {
          waitForIt(70, 70, 120, 120);
          Wire.beginTransmission(5);
          Wire.write('s');
          Wire.endTransmission();
        }
        if ((x>=130) && (x<=180)) 
        {
          waitForIt(130, 70, 180, 120);
          Wire.beginTransmission(5);
          Wire.write('d');
          Wire.endTransmission();
        }
      }
       if ((y>=130) && (y<=180)) 
      {
        if ((x>=50) && (x<=140)) {
         waitForIt(50, 130, 140, 180);
         Wire.beginTransmission(5);
          Wire.write('0');
          Wire.endTransmission();
      }
    }
  }
}
}
