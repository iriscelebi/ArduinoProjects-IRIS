//
int green = 6;
int red = 5;
int yellow =10;
int blue = 9;



void close_all_leds()               //Function to turn off all Leds
{
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, LOW);
  delay(10);
}
void disable_driver()               //Function to close Led Driver
{
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(yellow, LOW);  
  delay(10);
}


void setup() {
  Serial.begin(57600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(A3, INPUT);
  disable_driver();
  while (!Serial) {}
  Serial.println("Serial Communication is established");
}

void loop() {
  float volt;
  if (Serial.available() > 0) {
    int val = Serial.read();
    Serial.println(val);
    if (val == 'r') {                  //4 On
      close_all_leds();
      Serial.println("Red is on");
      digitalWrite(red, HIGH);
    }
    else if (val == 'g') {             //5 On
      close_all_leds();
      Serial.println("Green is on");
      digitalWrite(green, HIGH);
    }
    else if (val == 'b') {             //6 On
      close_all_leds();
      Serial.println("Blue is on");
      digitalWrite(blue, HIGH);
    }
    else if (val == 'y') {              //7 On
      close_all_leds();
      Serial.println("Yellow is on");
      digitalWrite(yellow, HIGH);
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
  float x = analogRead(A3); //Reads the analog value on pin A3 into x
  //Serial.print("Analog Value: ");
  volt= (x/1023.0)*5.0;
  //Serial.println(x);
  Serial.println(volt);
  
  
  
  delay(100);
}












