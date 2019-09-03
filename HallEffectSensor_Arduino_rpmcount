#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int hallPin = 2; // pin 2 = int 0
volatile unsigned long cntTime = 0;
volatile unsigned long cnt = 0;
volatile unsigned long rpm = 0, maxrpm = 0;
int dispRotTime = 0, rotTime = 0;
unsigned long measureTime = 0, curTime, startTime = 0;
int dispCnt = 0, measureCnt = 0;
const int resetTime = 2000;
const int minRotNum = 1;  // 1 - calc after every rotation

void doCount() // interrupt callback should be as short as possible!
{
  if (digitalRead(hallPin) == LOW)
  {
    cnt++;
    cntTime = millis();
  }
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(hallPin, INPUT_PULLUP);
  digitalWrite(hallPin, HIGH);
  attachInterrupt(digitalPinToInterrupt(hallPin), doCount, FALLING);  // hall pin on interrupt 0 = pin 2
  digitalWrite(hallPin, HIGH);
  pinMode(hallPin, INPUT_PULLUP);
  cntTime = millis();
  lcd.print("0  rpm");

}
void loop() {
  curTime = millis();
  if (curTime - cntTime > resetTime) { // reset when less than 30RPM (dt>2s)
    cnt = measureCnt = 0;
    rpm = 0;
  }
  if (cnt == 1) startTime = cntTime;
  if (cnt - measureCnt >= minRotNum) {
    rpm = 60000L * (cnt - measureCnt) / (cntTime - measureTime);
    measureCnt = cnt;
    measureTime = cntTime;
  }
  rotTime = (cntTime - startTime) / 1000; // time in seconds
  if (cnt > 1 || !dispRotTime) { // keep previous time on the OLED until new rotation starts
    dispRotTime = rotTime;
    dispCnt = cnt;
  }
  if (rpm > maxrpm) maxrpm = rpm;
  Serial.print(maxrpm);
  Serial.println("maxrpm");
  lcd.setCursor(0, 1);
  lcd.print(maxrpm);
  lcd.print(" rpm");
  delay(1000);

}
