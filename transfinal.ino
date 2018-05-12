#include<Wire.h>

void setup() {

  // put your setup code here, to run once:

  Wire.begin(5);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
char val1="w";
Serial.println(val1);
delay(1000);
}

void receiveEvent(int howMany){
  while(Wire.available()){
    char val = Wire.read();
    if(val == 'w'){
      Serial.println("w");
    }
    else if(val == 'a'){
      Serial.println("a");
    }else if(val == 's'){
      Serial.println("s");
    }else if(val == 'd'){
      Serial.println("d");
    }else if(val == '0'){
      Serial.println("0");
    }
  }
}

