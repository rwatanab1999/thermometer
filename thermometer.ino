#include <Servo.h>    //サーボ制御用ライブラリ
Servo servodemo;

void setup() {
  servodemo.attach(7);   //D7を出力に設定
  Serial.begin(9600); //通信速度 9600bps
  pinMode(12,OUTPUT);//D12ピンを出力ポートに設定
}
void loop(){
  int value = analogRead(A0);   //A0からアナログ入力しvalueに代入
  
  int temp = 500*(float)value/1023-60;   //valueを温度に変換しtempに代入
  Serial.println(temp);    //シリアルモニタに温度を表示
  delay(100);//待ち時間１００ms

  if(temp >= 30){　　　　　//温度が30℃以上のときに
    digitalWrite(12,HIGH);　　//D12にHIGHをデジタル出力
  }
  else{
    digitalWrite(12,LOW);　　//D12にLOWをデジタル出力
  }
  
  int deg = (temp - 20)*4.5;   //温度tempを角度に変換しdegに代入
  servodemo.write(deg);   //サーボモータを動かす
  delay(100);
}
