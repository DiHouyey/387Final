//motorA
int motorA1 = 3; 
int motorA2 = 4; 
int enablePin1 = 5; 
//motorB
int motorB1 = 2; 
int motorB2 = 6; 
int enablePin2 = 7; 
char val;
int show=0;    
 
void setup() {

    Serial.begin(9600);
    //setup motorA
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(enablePin1, OUTPUT);
    //setup motorB
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);
    pinMode(enablePin2, OUTPUT);
 
    digitalWrite(enablePin1, HIGH);
    digitalWrite(enablePin2, HIGH);

    
}
 
void loop() {

    if(Serial.available() > 0){     
      val = Serial.read();   
      show=0;
    }   
    if ('w' == val) {
        digitalWrite(motorA1, LOW); 
        digitalWrite(motorA2, HIGH);
        digitalWrite(motorB1, LOW); 
        digitalWrite(motorB2, HIGH);  
        if(show == 0){
          Serial.println("GO UP");
          show=1;
        }
    }

    else if ( 'a' == val) {
        digitalWrite(motorA1, HIGH); 
        digitalWrite(motorA2, LOW); 
        digitalWrite(motorB1, LOW); 
        digitalWrite(motorB2, HIGH);
        delay(500);
        if(show == 0){
          Serial.println("GO LEFT");
          show=1;
        }
    }
      else  if ('d' == val) {
        digitalWrite(motorA1, LOW); 
        digitalWrite(motorA2, HIGH); 
        digitalWrite(motorB1, HIGH); 
        digitalWrite(motorB2, LOW); 
        delay(500);
        if(show == 0){
          Serial.println("GO RIGHT");
          show=1;
        }
    }
    else if ('s' == val) {
        digitalWrite(motorA1, HIGH); 
        digitalWrite(motorA2, LOW); 
        digitalWrite(motorB1, HIGH); 
        digitalWrite(motorB2, LOW);
        if(show == 0){
          Serial.println("GO DOWN");
          show=1;
        }
    }
 
    else if ('0' == val) {
        digitalWrite(motorA1, LOW); 
        digitalWrite(motorA2, LOW);
        digitalWrite(motorB1, LOW); 
        digitalWrite(motorB2, LOW); 
        if(show == 0){
          Serial.println("STOP");
          show=1;
        }
    }
     
}
