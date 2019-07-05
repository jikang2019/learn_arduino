void setup()
  {
    pinMode(2, OUTPUT); // 1
    pinMode(3, OUTPUT); // 2
    pinMode(4, OUTPUT); // 3
    pinMode(5, OUTPUT); // 4
    pinMode(6, OUTPUT); // 消隐控制端
    pinMode(7, OUTPUT); // 锁定控制端
    Serial.begin(9600);
    digitalWrite(6, LOW);
   }

byte income = 0;

void loop()
{
  if(Serial.available()>0){
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(10);
    
    income = Serial.read();
    income  = income - '0';

    if(income & 0x1){
      digitalWrite(2, HIGH);
    }
    else {
      digitalWrite(2, LOW);
    }
    if((income>>1) & 0x1){
      digitalWrite(3, HIGH);
    }
    else{
      digitalWrite(3, LOW);
    }
    if((income>>2) & 0x1){
      digitalWrite(4, HIGH);
    }
    else {
      digitalWrite(4, LOW);
    }
    if((income>>3) & 0x1){
      digitalWrite(5, HIGH);
    }
    else {
      digitalWrite(5, LOW);
    }
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
    delay(10);
  }

}
