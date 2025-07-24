#include <Servo.h>
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h> 

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // initialization for the used OLED display


Servo servo1;  
Servo servo2;
Servo servo3;
Servo servo4; 
int pos = 0;
int sv1 = 90;
int sv2 = 93;
int sv3 = 90;
int sv4 = 90;

int i ; 
char data;  
void setup() {
  //mySerial.begin(9600);
  Serial.begin(9600);
  servo1.attach(5); 
  servo2.attach(6);
  servo3.attach(9);
  servo4.attach(10); 
  u8g2.begin(); // start the u8g2 library
}

void walking_otto() 
{  //normal walking
  walking();
  for (pos =0; pos <=34; pos += 1) { 
    servo1.write(sv1-2*pos);
    servo3.write(sv3-pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(13);
  } 
  for (pos =sv3-34; pos >=sv3-45; pos -= 1) {
    servo3.write(pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(13);
  }
  for (pos = 0; pos <= 90; pos += 7) { 
    servo4.write(sv4-10);              
    delay(10); 
  }
  for (pos =sv3-45; pos <=sv3-34; pos += 1) { 
    servo3.write(pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(13);
  }
  for (pos =34; pos >=0; pos -= 1) {
    servo1.write(sv1-2*pos);
    servo3.write(sv3-pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(13);
  }
  walking();
  for (pos =0; pos <=34; pos += 1) { 
    servo1.write(sv1+pos);
    servo3.write(sv3+2*pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(13);
  }
  for (pos =sv1+34; pos <=sv1+45; pos += 1) { 
    servo1.write(pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(13);
  }
  for (pos = 180; pos >= 90; pos -= 7) { 
    servo2.write(sv2+10);              
    delay(13);                       
  }
   for (pos =sv1+45; pos >=sv1+34; pos -= 1) { 
    servo1.write(pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(13);
  }
  for (pos =34; pos >=0; pos -= 1) { 
    servo1.write(sv1+pos);
    servo3.write(sv3+2*pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(13);
  }
  
           
}
void happy_otto() 
{  //normal walking
 happy();
  for (pos =0; pos <=35; pos += 1) { 
    servo1.write(sv1-2*pos);
    servo3.write(sv3-pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(10);
  } 
  
  for (pos =35; pos >=0; pos -= 1) { 
    servo1.write(sv1-2*pos);
    servo3.write(sv3-pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(10);
  }
  happy();
  for (pos =0; pos <=35; pos += 1) { 
    servo1.write(sv1+pos);
    servo3.write(sv3+2*pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(10);
  }
  for (pos =35; pos >=0; pos -= 1) { 
    servo1.write(sv1+pos);
    servo3.write(sv3+2*pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(10);
  }
  
           
}
void round_otto() 
{  //normal walking
  
  for (pos =0; pos <=34; pos += 1) { 
    servo1.write(sv1-2*pos);
    servo3.write(sv3-pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(12);
  } 
  for (pos =sv3-34; pos >=sv3-60; pos -= 1) { 
    servo3.write(pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(12);
  }
  for (pos = 0; pos <= 83; pos += 1) { 
    servo4.write(sv4-10);              
    delay(17); 
  }
  for (pos =sv3-60; pos <=sv3-34; pos += 1) { 
    servo3.write(pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(10);
  }
  for (pos =34; pos >=0; pos -= 1) { 
    servo1.write(sv1-2*pos);
    servo3.write(sv3-pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(10);
  }
  turn();
  turn();
}
void sad_otto() 
{ 
  
  for (pos =0; pos <=80; pos += 1) { 
    servo1.write(sv1+pos);
    servo3.write(sv3-pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(8);
  }
  sad();
  delay(2000);
  
  for (pos =80; pos >=0; pos -= 1) { 
    servo3.write(sv3-pos);
    servo1.write(sv1+pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(8);
  }
  sad();
}
void angry_otto() 
{ 
  angry();
  for (pos =0; pos <=30; pos += 1) { 
    servo1.write(sv1-pos);
    servo3.write(sv3+pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(6);
  }
  angry();
  delay(2600);
  angry();
  for (pos =30; pos >=0; pos -= 1) { 
    servo3.write(sv3+pos);
    servo1.write(sv1-pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(7);
  }
  
}
void dance_otto() 
{  //normal walking
  for (pos =0; pos <=34; pos += 1) { 
    servo1.write(sv1-pos);
    servo3.write(sv3+pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(13);
  } 
  for (pos =34; pos >=0; pos -= 1) { 
    servo1.write(sv1-pos);
    servo3.write(sv3+pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(13);
  }
  dance();

  for (pos =0; pos <=36; pos += 1) { 
    servo1.write(sv1+pos);
    servo3.write(sv3-pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(13);
  }
  for (pos =36; pos >=0; pos -= 1) { 
    servo1.write(sv1+pos);
    servo3.write(sv3-pos);
    servo2.write(sv2);
    servo4.write(sv4);
    delay(13);
  } 
  dance();

}

void walking(){
    u8g2.clearBuffer();	
    u8g2.setBitmapMode(1);
    u8g2.setFontMode(1);
    u8g2.drawBox(25, 11, 24, 34);
    u8g2.drawBox(78, 11, 24, 34);
    u8g2.sendBuffer();
    delay(100);
    u8g2.clearBuffer();	
    u8g2.setBitmapMode(1);
    u8g2.setFontMode(1);
    u8g2.drawBox(25, 11, 24, 26);
    u8g2.drawBox(78, 11, 24, 26);
    u8g2.sendBuffer();
    delay(100);
    u8g2.clearBuffer();	
    u8g2.setBitmapMode(1);
    u8g2.setFontMode(1);
    u8g2.drawBox(25, 11, 24, 10);
    u8g2.drawBox(78, 11, 24, 10);
    u8g2.sendBuffer();
    delay(100);
    u8g2.clearBuffer();	
    u8g2.setBitmapMode(1);
    u8g2.setFontMode(1);
    u8g2.drawBox(25, 11, 24, 26);
    u8g2.drawBox(78, 11, 24, 26);
    u8g2.sendBuffer();
    delay(100);
    u8g2.clearBuffer();	
    u8g2.setBitmapMode(1);
    u8g2.setFontMode(1);
    u8g2.drawBox(25, 11, 24, 34);
    u8g2.drawBox(78, 11, 24, 34);
    u8g2.sendBuffer();
    delay(100);

}
void angry(){
  u8g2.clearBuffer();	

  u8g2.setBitmapMode(1);
  u8g2.setFontMode(1);
  u8g2.drawBox(30, 22, 22, 24);
  u8g2.drawBox(72, 22, 22, 24);
  u8g2.drawLine(20, 7, 52, 15);
  u8g2.drawLine(20, 7, 20, 10);
  u8g2.drawLine(20, 10, 52, 15);
  u8g2.drawLine(21, 9, 43, 13);
  u8g2.drawLine(21, 8, 32, 10);
  u8g2.drawLine(71, 15, 103, 7);
  u8g2.drawLine(103, 7, 103, 10);
  u8g2.drawLine(103, 10, 71, 15);
  u8g2.drawLine(103, 8, 85, 12);
  u8g2.drawLine(102, 9, 90, 12);
  u8g2.sendBuffer();
  delay(200);
  u8g2.clearBuffer();
  u8g2.setBitmapMode(1);
  u8g2.setFontMode(1);
  u8g2.drawBox(30, 22, 22, 8);
  u8g2.drawBox(72, 22, 22, 8);
  u8g2.drawLine(20, 7, 52, 15);
  u8g2.drawLine(20, 7, 20, 10);
  u8g2.drawLine(20, 10, 52, 15);
  u8g2.drawLine(21, 9, 43, 13);
  u8g2.drawLine(21, 8, 32, 10);
  u8g2.drawLine(71, 15, 103, 7);
  u8g2.drawLine(103, 7, 103, 10);
  u8g2.drawLine(103, 10, 71, 15);
  u8g2.drawLine(103, 8, 85, 12);
  u8g2.drawLine(102, 9, 90, 12);
  u8g2.sendBuffer();
  delay(200);
}
void turn(){
  u8g2.clearBuffer();
  u8g2.setBitmapMode(1);
  u8g2.setFontMode(1);
  u8g2.drawCircle(36, 28, 16);
  u8g2.drawCircle(88, 28, 16);
  u8g2.drawCircle(36, 28, 15);
  u8g2.drawCircle(88, 28, 15);
  u8g2.drawDisc(42, 28, 7);
  u8g2.drawDisc(94, 28, 7);
  u8g2.sendBuffer();
  delay(100);
  u8g2.clearBuffer();
  u8g2.setBitmapMode(1);
  u8g2.setFontMode(1);
  u8g2.drawCircle(36, 28, 16);
  u8g2.drawCircle(88, 28, 16);
  u8g2.drawCircle(36, 28, 15);
  u8g2.drawCircle(88, 28, 15);
  u8g2.drawDisc(36, 34, 7);
  u8g2.drawDisc(88, 34, 7);
  u8g2.sendBuffer();
  delay(100);
  u8g2.clearBuffer();
  u8g2.setBitmapMode(1);
  u8g2.setFontMode(1);
  u8g2.drawCircle(36, 28, 16);
  u8g2.drawCircle(88, 28, 16);
  u8g2.drawCircle(36, 28, 15);
  u8g2.drawCircle(88, 28, 15);
  u8g2.drawDisc(30, 28, 7);
  u8g2.drawDisc(82, 28, 7);
  u8g2.sendBuffer();
  delay(100);
  u8g2.clearBuffer();
  u8g2.setBitmapMode(1);
  u8g2.setFontMode(1);
  u8g2.drawCircle(36, 28, 16);
  u8g2.drawCircle(88, 28, 16);
  u8g2.drawCircle(36, 28, 15);
  u8g2.drawCircle(88, 28, 15);
  u8g2.drawDisc(36, 22, 7);
  u8g2.drawDisc(88, 22, 7);
  u8g2.sendBuffer();
  delay(100);
  u8g2.clearBuffer();
  u8g2.setBitmapMode(1);
  u8g2.setFontMode(1);
  u8g2.drawCircle(36, 28, 16);
  u8g2.drawCircle(88, 28, 16);
  u8g2.drawCircle(36, 28, 15);
  u8g2.drawCircle(88, 28, 15);
  u8g2.drawDisc(42, 28, 7);
  u8g2.drawDisc(94, 28, 7);
  delay(100);

  u8g2.sendBuffer();
}
void happy()
{
  u8g2.clearBuffer();
 u8g2.setBitmapMode(1);
  u8g2.setFontMode(1);
  u8g2.drawCircle(86, 26, 14);
  u8g2.drawCircle(86, 26, 15);
  u8g2.drawDisc(86, 30, 6);
  u8g2.drawDisc(41, 30, 6);
  u8g2.drawCircle(41, 26, 15);
  u8g2.drawCircle(41, 26, 14);
  u8g2.sendBuffer();
  delay(100);
  u8g2.clearBuffer(); 
  u8g2.setBitmapMode(1);
  u8g2.setFontMode(1);
  u8g2.drawCircle(86, 26, 14);
  u8g2.drawCircle(86, 26, 15);
  u8g2.drawDisc(86, 26, 6);
  u8g2.drawDisc(41, 26, 6);
  u8g2.drawCircle(41, 26, 15);
  u8g2.drawCircle(41, 26, 14);
  u8g2.sendBuffer();
  delay(100);
  u8g2.clearBuffer();
 u8g2.setBitmapMode(1);
  u8g2.setFontMode(1);
  u8g2.drawCircle(86, 26, 14);
  u8g2.drawCircle(86, 26, 15);
  u8g2.drawDisc(86, 30, 6);
  u8g2.drawDisc(41, 30, 6);
  u8g2.drawCircle(41, 26, 15);
  u8g2.drawCircle(41, 26, 14);
  u8g2.sendBuffer();
  delay(100);
}
void sad()
{
  u8g2.clearBuffer();	

  u8g2.setBitmapMode(1);
  u8g2.setFontMode(1);
  u8g2.drawCircle(37, 33, 14);
  u8g2.drawCircle(37, 33, 13);
  u8g2.drawDisc(34, 39, 6);
  u8g2.drawDisc(83, 39, 6);
  u8g2.drawCircle(86, 33, 13);
  u8g2.drawCircle(86, 33, 14);
  u8g2.drawLine(18, 18, 45, 6);
  u8g2.drawLine(18, 19, 45, 7);
  u8g2.drawLine(18, 20, 47, 7);
  u8g2.drawLine(105, 20, 76, 6);
  u8g2.drawLine(106, 20, 79, 6);
  u8g2.drawLine(106, 19, 79, 6);
  u8g2.sendBuffer();
  delay(200);
  u8g2.clearBuffer();
  u8g2.setBitmapMode(1);
  u8g2.setFontMode(1);
  u8g2.drawCircle(37, 33, 14);
  u8g2.drawCircle(37, 33, 13);
  u8g2.drawDisc(41, 39, 6);
  u8g2.drawDisc(90, 39, 6);
  u8g2.drawCircle(86, 33, 13);
  u8g2.drawCircle(86, 33, 14);
  u8g2.drawLine(18, 18, 45, 6);
  u8g2.drawLine(18, 19, 45, 7);
  u8g2.drawLine(18, 20, 47, 7);
  u8g2.drawLine(105, 20, 76, 6);
  u8g2.drawLine(106, 20, 79, 6);
  u8g2.drawLine(106, 19, 79, 6);
  u8g2.sendBuffer();
  delay(200);
}
void dance(){
  u8g2.clearBuffer();	

  u8g2.setBitmapMode(1);
  u8g2.setFontMode(1);
  u8g2.drawDisc(40, 31, 16);
  u8g2.drawDisc(92, 31, 10);
  u8g2.sendBuffer();
  delay(200);
  u8g2.clearBuffer();
  u8g2.setBitmapMode(1);
  u8g2.setFontMode(1);
  u8g2.drawDisc(40, 32, 10);
  u8g2.drawDisc(87, 32, 16);
  u8g2.sendBuffer();
  delay(200);
  u8g2.clearBuffer();
  u8g2.setBitmapMode(1);
  u8g2.setFontMode(1);
  u8g2.drawDisc(91, 32, 16);
  u8g2.drawDisc(37, 32, 16);
  u8g2.sendBuffer();
  delay(200);
}

void loop(void) {
   servo1.write(sv1);
   servo2.write(sv2);
   servo3.write(sv3);
   servo4.write(sv4);
   walking();
   delay(300);

 while (Serial.available() > 0) { 
		data = Serial.read();
    Serial.println(data);
		if (data == 'w')
		{
      for(i=0; i<2; i+=1)
      {
        walking_otto();
      }
    }

		if (data == 'h')
		{
      for(i=0; i<2; i+=1)
      {
        happy_otto();
      }
    }

		if (data == 'r')
		{
      for(i=0; i<1; i+=1)
      {
        round_otto();
      }
    }

		if (data == 's')
		{
      for(i=0; i<1; i+=1)
      {
        sad_otto();
      }
    }

    if (data == 'a')
   {
     for(i=0; i<2; i+=1)
      {
        angry_otto();
      }
    }
		if (data == 'd')
   {
      for(i=0; i<2; i+=1)
      {
        dance_otto();
      }
    }	
  }
}
