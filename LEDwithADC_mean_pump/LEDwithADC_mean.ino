
#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads(0x48); //create ads object with adress 0x48

float Voltage = 0.0;
float mean = 0.0;
float sum = 0.0;
float total = 0.0;

int green = 5;
int red = 6;
int yellow =10;
int blue = 7;

int16_t adc0; 

void close_all_leds()               
{
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, LOW);
  delay(10);
}
void disable_driver()               
{
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, LOW);  
  delay(10);
}


void setup() {
  Serial.begin(57600);
  ads.begin();
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(A3, INPUT);
  disable_driver();
  //while (!Serial) {}
  
  
}

void loop() {
     
  
  if (Serial.available() > 0) {
    int val = Serial.read();
    //Serial.println(val);
    if (val == 's') {                  //save

      mean=sum/total;
      //Voltage = (adc0 * 0.1875)/1000;
      Serial.println(mean);
      Serial.println(total);
      sum=0.0;
      total=0.0;
      
    }
    if (val == 'r') {                  //4 On
      close_all_leds();
      Serial.println("Red is on");
      digitalWrite(red, HIGH);
      ads.setGain(GAIN_TWOTHIRDS);
    }
    else if (val == 'g') {             //5 On
      close_all_leds();
      Serial.println("Green is on");
      digitalWrite(green, HIGH);
      ads.setGain(GAIN_TWO);
    }
    else if (val == 'b') {             //6 On
      close_all_leds();
      Serial.println("Blue is on");
      digitalWrite(blue, HIGH);
      ads.setGain(GAIN_ONE);
    }
    else if (val == 'y') {              //7 On
      close_all_leds();
      Serial.println("Yellow is on");
      digitalWrite(yellow, HIGH);
      ads.setGain(GAIN_TWO);
    }
    else if (val == 'c') {            //All OFF
      Serial.println("All leds are off");
      close_all_leds();      
    }
    else if (val == 'd') {            //All ON
      Serial.println("Driver is off");
      disable_driver();
    }
  }
  
  adc0 = ads.readADC_SingleEnded(0); //read single ended 0

  if(adc0 > 0){
  
  sum = sum + adc0; //read single ended 0
  total++;
  
  }
  
   
  //delay(2);
  
}












