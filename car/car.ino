// f前进 b后退  R右转  L左转  s停止

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}

int income = 0;
void loop()
{
  if(Serial.available()>0){
    income = Serial.read();
  }
  switch(income){
    case 'f' : forward();  break;
    case 'b' : backward(); break;
    case 'l' : left();     break;
    case 'r' : right();    break;
    case 's' : stop();     break;
    default : break;
  }
  
}

// 马达正转
void forward(){
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
}

void backward(){
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
}

void left(){
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
}

void right(){
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
}

void stop(){
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}
