const int ProxSensor1=A7;
const int ProxSensor2=A8;
const int ProxSensor3=A9;

int inputVal = 0;
int inputVal1 = 0;
int inputVal2 = 0;
void setup() {
    pinMode(ProxSensor1,INPUT);
        pinMode(ProxSensor2,INPUT);
    pinMode(ProxSensor3,INPUT);

    Serial.begin(9600);
}

const uint8_t zAxis = A2;
const uint8_t yAxis = A1;
const uint8_t xAxis = A0;

//Min and Max values after calibration:
int16_t zLow = 276, zHigh = 409, xHigh = 399, xLow = 264, yHigh = 396, yLow = 260;



void loop() {

   inputVal = digitalRead(ProxSensor1);
   inputVal1 = digitalRead(ProxSensor2);
   inputVal2 = digitalRead(ProxSensor3);

  short angleX = map(constrain(analogRead(xAxis), xLow, xHigh),xLow,xHigh,-90,90);
  short angleY = map(constrain(analogRead(yAxis), yLow, yHigh),yLow,yHigh,-90,90);
 short angleZ = map(constrain(analogRead(zAxis), zLow, zHigh),zLow,zHigh,0,180);
//  short angleZ = analogRead(zAxis);

  String dataString = String(angleX);
  
 
  dataString = String(angleZ);
   dataString=dataString+","+inputVal+","+inputVal1+","+inputVal2;
  Serial.println(dataString);
  delay(1);
}
