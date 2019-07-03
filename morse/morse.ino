#include <Morse.h>

Morse m(13);
char c;           // 串口输入的单个字符
String strMorse;  // Morse电码

void setup() {
  Serial.begin(9600);
}

void loop(){
  if(Serial.available()>0){
    // 串口读取数据
    c = Serial.read();
    Serial.print(c);

    // 如果输入的c是小写字母，输出字母对应信号
    if(isLowerCase(c)){
      // 转换为morse电码
      switch(c){
        case 'a' : strMorse = String("*-");    break;
        case 'b' : strMorse = String("-***");  break;
        case 'c' : strMorse = String("-*-*");  break;
        case 'd' : strMorse = String("-**");   break;
        case 'e' : strMorse = String("*");     break;
        case 'f' : strMorse = String("**-*");  break;
        case 'g' : strMorse = String("--*");   break;
        case 'h' : strMorse = String("****");  break;
        case 'i' : strMorse = String("**");    break;
        case 'j' : strMorse = String("*---");  break;
        case 'k' : strMorse = String("-*-");   break;
        case 'l' : strMorse = String("*-**");  break;
        case 'm' : strMorse = String("--");    break;
        case 'n' : strMorse = String("-*");    break;
        case 'o' : strMorse = String("---");   break;
        case 'p' : strMorse = String("*--*");  break;
        case 'q' : strMorse = String("--*-");  break;
        case 'r' : strMorse = String("*-*");   break;
        case 's' : strMorse = String("***");   break;
        case 't' : strMorse = String("-");     break;
        case 'u' : strMorse = String("**-");   break;
        case 'v' : strMorse = String("***-");  break;
        case 'w' : strMorse = String("*--");   break;
        case 'x' : strMorse = String("-**-");  break;
        case 'y' : strMorse = String("-*--");  break;
        case 'z' : strMorse = String("--**");  break;
      }

      // 将Morse电码输出
      int i=0;
      while(strMorse[i]){  // 如果当前Morse电码不为空
        if(strMorse[i] == '-'){
          m.dash();
        }
        if(strMorse[i] == '*'){
          m.dot();
        }
        i++;          
      }
      // 输出字母之间的间隔
      m.c_space();  
    }
    
    // 如果是空格，则是单词之间的间隔
    if(isWhitespace(c)){
      m.w_space();
    }
    // 如果是回车，本句话结束，则延迟3s
    if(c == '\n'){
      delay(3000);
    }
    
  }
}
