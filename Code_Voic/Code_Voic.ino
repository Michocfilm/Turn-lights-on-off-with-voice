byte com = 0;
#define LED1 8
#define LED2 9
#define LED3 10
#define LED4 11
#define LED5 12

  

void setup() {
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
 pinMode(LED3, OUTPUT);
 pinMode(LED4, OUTPUT);
 pinMode(LED5, OUTPUT);
 Serial.begin(9600);
 Serial.write(0xAA);
 Serial.write(0x37);
 delay(1000);
 Serial.write(0xAA);
 Serial.write(0x21);
         ;
}
boolean led[5] ;
void loop() {

  while(Serial.available()) {

  com = Serial.read();

  switch(com) {

      case 0x11:   //command 1 is for Green LED 
         led[0] = !led[0];
         digitalWrite(LED1, led[0]);
         delay(1000);
        
      break;

      case 0x12:  //command 2 is for Red LED
          led[1] = !led[1];
         digitalWrite(LED2, led[1]);
         delay(1000);
      

      break;

      case 0x13:  //command 3 is for Yellow LED
             led[2] = !led[2];
         digitalWrite(LED3, led[2]);
         delay(1000);

      break;

      case 0x14:  //command 4 is for Servo motor
             led[3] = !led[3];
         digitalWrite(LED4, led[3]);
         delay(1000);
        

      break;

      case 0x15:  //command 5 is for Servo Motor
           led[4] = !led[4];
         digitalWrite(LED5, led[4]);
         delay(1000);
      

      break;

            }
      }
}
