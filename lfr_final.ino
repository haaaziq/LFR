 //Pin declaration
int RightDir = 6;
int RightOpDir = 9;
int LeftDir = 10;
int LeftOpDir = 11;

//5-IR array sensor
int LeftSen = 2;
int LeftMSen = 3;
int MidSen = 4;
int RightMSen = 5;
int RightSen = 7;

void setup()
{
  Serial.begin(9600);
  //Serial.begin(115200);
  //Motor Driver Pin Setup
  pinMode(RightDir,OUTPUT);
  pinMode(RightOpDir,OUTPUT);
  pinMode(LeftDir,OUTPUT);
  pinMode(LeftOpDir,OUTPUT);
  
  //Setting the initial condition of motors
  digitalWrite(RightOpDir,LOW);
  digitalWrite(LeftOpDir,LOW);
  
  digitalWrite(RightDir,HIGH);
  digitalWrite(LeftDir,HIGH);
  
  //LSS05 Pin Setup
  pinMode(LeftSen,INPUT);
  pinMode(LeftMSen,INPUT);
  pinMode(MidSen,INPUT);
  pinMode(RightMSen,INPUT);
  pinMode(RightSen,INPUT);
}

//Different cases based on sensor reading
void loop()
{
  if((digitalRead(LeftSen)==0) && (digitalRead(LeftMSen)==0) && (digitalRead(MidSen)==0) && (digitalRead(RightMSen)==0) && (digitalRead(RightSen)==0))
  {
    moveForward();
    Serial.println("Forward");
  }
  else if((digitalRead(LeftSen)==1) && (digitalRead(LeftMSen)==1) && (digitalRead(MidSen)==0) && (digitalRead(RightMSen)==1) && (digitalRead(RightSen)==1))
  {
    moveForward();
    Serial.println("Forward");
  }
  else if((digitalRead(LeftSen)==1) && (digitalRead(LeftMSen)==0) && (digitalRead(MidSen)==0) && (digitalRead(RightMSen)==0) && (digitalRead(RightSen)==1))
  {
    moveForward();
    Serial.println("Forward");
  }
  else if((digitalRead(LeftSen)==1) && (digitalRead(LeftMSen)==0) && (digitalRead(MidSen)==0) && (digitalRead(RightMSen)==1) && (digitalRead(RightSen)==1))
  {
    moveForward();
    Serial.println("Forward");
  }
  
  else if((digitalRead(LeftSen)==1) && (digitalRead(LeftMSen)==1) && (digitalRead(MidSen)==0) && (digitalRead(RightMSen)==0) && (digitalRead(RightSen)==1))
  {
    moveForward();
    Serial.println("Forward");
  }

  
  else if(((digitalRead(LeftSen)==0)&&(digitalRead(LeftMSen)==0)) && ((digitalRead(MidSen)==1) && (digitalRead(RightMSen)==1) && (digitalRead(RightSen)==1)))
  {
    moveSlightLeft();
    Serial.println("Left");
  }
  else if(((digitalRead(LeftSen)==0)&&(digitalRead(LeftMSen)==1)) && ((digitalRead(MidSen)==1) && (digitalRead(RightMSen)==1) && (digitalRead(RightSen)==1)))
  {
    moveLeft();
    Serial.println("Left");
  }

    else if(((digitalRead(LeftSen)==0)&& (digitalRead(LeftMSen)==0)) && ((digitalRead(MidSen)==0) && (digitalRead(RightMSen)==1) && (digitalRead(RightSen)==1)))
  {
    moveLeft();
    Serial.println("Left");
  }

    else if(((digitalRead(LeftSen)==0)&& (digitalRead(LeftMSen)==0)) && ((digitalRead(MidSen)==0) && (digitalRead(RightMSen)==0) && (digitalRead(RightSen)==1)))
  {
    moveLeft();
    Serial.println("Left");
  }
  
  else if(((digitalRead(LeftSen)==1) && (digitalRead(LeftMSen)==1) && (digitalRead(MidSen)==1)) && ((digitalRead(RightMSen)==0)&&(digitalRead(RightSen)==0)))
  {
    moveSlightRight();    
    Serial.println("Right");
  }
  else if(((digitalRead(LeftSen)==1) && (digitalRead(LeftMSen)==1) && (digitalRead(MidSen)==1)) && ((digitalRead(RightMSen)==1)&&(digitalRead(RightSen)==0)))
  {
    
    moveRight();    
    Serial.println("Right");
  }
  
  else if((digitalRead(LeftSen)==1) && (digitalRead(LeftMSen)==1) && (digitalRead(MidSen)==0) && (digitalRead(RightMSen)==0)&&(digitalRead(RightSen)==0))
  {
    moveRight();    
    Serial.println("Right");
  }
  
  else if((digitalRead(LeftSen)==1) && (digitalRead(LeftMSen)==0) && (digitalRead(MidSen)==0) && (digitalRead(RightMSen)==0)&&(digitalRead(RightSen)==0))
  {
    moveRight();    
    Serial.println("Right");
  }
  
  else if((digitalRead(LeftSen)==1) && (digitalRead(LeftMSen)==1) && (digitalRead(MidSen)==1) && (digitalRead(RightMSen)==1)&&(digitalRead(RightSen)==1))
 
  {
    wait();
    Serial.println("Wait");
  }

  else{
    moveForward();
    }

    //delay(70);
}

void moveLeft() {
  // For robot to move left, right motor has to be faster than left motor
  digitalWrite(RightOpDir,LOW);
  digitalWrite(LeftDir,LOW);
    
  analogWrite(RightDir,95);
  analogWrite(LeftOpDir,110);
}

void moveSlightLeft() {
  // For robot to move left, right motor has to be faster than left motor
  digitalWrite(RightDir,LOW);
  digitalWrite(LeftDir,LOW);
    
  analogWrite(RightDir,95);
  analogWrite(LeftDir,35);
}

void moveRight() {
  // For robot to move right, left motor has to be faster than right motor
  digitalWrite(RightDir,LOW);
  digitalWrite(LeftOpDir,LOW);
  
  analogWrite(RightOpDir,110);
  analogWrite(LeftDir,95);
}
void moveSlightRight() {
  // For robot to move right, left motor has to be faster than right motor
  digitalWrite(RightDir,LOW);
  digitalWrite(LeftDir,LOW);
  
  analogWrite(RightDir,35);
  analogWrite(LeftDir,95);
}

void moveForward() {
  // For robot to move forward, both motors have to be same speed
  digitalWrite(RightOpDir,LOW);
  digitalWrite(LeftOpDir,LOW);
  
  analogWrite(RightDir,95);
  analogWrite(LeftDir,95);
}

void wait() {
 // Function to makes the robot stay
  //delay(40);
  digitalWrite(RightDir,LOW);
  digitalWrite(LeftDir,LOW);

  analogWrite(RightOpDir,55);
  analogWrite(LeftOpDir,55);
}
