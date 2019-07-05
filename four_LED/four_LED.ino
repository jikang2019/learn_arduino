void setup()
{
  pinMode(2, OUTPUT); // 输出 1
  pinMode(3, OUTPUT); // 输出 2
  pinMode(4, OUTPUT); // 输出 3
  pinMode(5, OUTPUT); // 输出 4
  
  pinMode(8, OUTPUT);  // 锁销 1
  pinMode(9, OUTPUT);  // 锁销 2
  pinMode(10, OUTPUT); // 锁销 3
  pinMode(11, OUTPUT); // 锁销 4
  
  Serial.begin(9600);
  // 全部锁定
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
}

long num;     // 输入多对应的二进制数
String strIn; // 输入的字符串

void loop()
{ 
  num = 0;
 
  if(Serial.available()>0){
    strIn = Serial.readString(); // 读取串口输入的字符串
    
    // 将字符串转化为二进制数
    for(int i=0;strIn[i];i++){
      if(isDigit(strIn[i])){  // 如果字符为数字，则转换为二进制
        num = num<<4;
        num = num + (strIn[i]-'0');
      }
    }
    
    // 输出，显示数字
    for(int i=0;i<4;i++){
      digitalWrite(i+8, LOW); //解锁
      delay(10);
      for(int j=0;j<4;j++){   //显示数字
        if(num & 0x1)
          digitalWrite(j+2, HIGH);
        else
          digitalWrite(j+2, LOW);
        num = num>>1;         //下一位二进制数
      }
      delay(10);
      digitalWrite(i+8, HIGH); //上锁
      delay(10);
    }
  }
}
      
      
