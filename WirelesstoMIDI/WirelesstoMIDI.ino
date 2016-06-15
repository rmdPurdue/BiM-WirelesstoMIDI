#include <SoftwareSerial.h>
#include "WirelesstoMIDI.h"

SoftwareSerial xbee(2,3);
SoftwareSerial MIDI(4,5);

MESSAGE Dancer1[15];
MESSAGE Dancer2[15];
byte LeftArmX, LeftArmY, LeftArmZ, RightArmX, RightArmY, RightArmZ,
     LeftLegX, LeftLegY, LeftLegZ, RightLegX, RightLegY, RightLegZ,
     GyroX, GyroY, GyroZ, Dancer1Chan, Dancer2Chan;
     
char startChar, endChar, delimChar;
int dataBufferSize = 60;
int serialBuffer[60];

void setup() {
  Serial.begin(9600);
  startChar = '#';    // Indicates start of Serial message
  endChar = '!';      // Indicates end of Serial message
  delimChar = ',';    // Serial message data delimeter
  LeftArmX = 0;
  LeftArmY = 1;
  LeftArmZ = 2;
  RightArmX = 3;
  RightArmY = 4;
  RightArmZ = 5;
  LeftLegX = 6;
  LeftLegY = 7;
  LeftLegZ = 8;
  RightLegX = 9;
  RightLegY = 10;
  RightLegZ = 11;
  GyroX = 12;
  GyroY = 13;
  GyroZ = 14;
  
  Dancer1Chan = 14;
  Dancer2Chan = 15;
  
  Dancer1[LeftArmX].control1 = 0;
  Dancer1[LeftArmX].control2 = 1;
  Dancer1[LeftArmY].control1 = 2;
  Dancer1[LeftArmY].control2 = 3;
  Dancer1[LeftArmZ].control1 = 4;
  Dancer1[LeftArmZ].control2 = 5;
  Dancer1[RightArmX].control1 = 6;
  Dancer1[RightArmX].control2 = 7;
  Dancer1[RightArmY].control1 = 8;
  Dancer1[RightArmY].control2 = 9;
  Dancer1[RightArmZ].control1 = 10;
  Dancer1[RightArmZ].control2 = 11;
  Dancer1[LeftLegX].control1 = 12;
  Dancer1[LeftLegX].control2 = 13;
  Dancer1[LeftLegY].control1 = 14;
  Dancer1[LeftLegY].control2 = 15;
  Dancer1[LeftLegZ].control1 = 16;
  Dancer1[LeftLegZ].control2 = 17;
  Dancer1[RightLegX].control1 = 18;
  Dancer1[RightLegX].control2 = 19;
  Dancer1[RightLegY].control1 = 20;
  Dancer1[RightLegY].control2 = 21;
  Dancer1[RightLegZ].control1 = 22;
  Dancer1[RightLegZ].control2 = 23;
  Dancer1[GyroX].control1 = 24;
  Dancer1[GyroX].control2 = 25;
  Dancer1[GyroY].control1 = 26;
  Dancer1[GyroY].control2 = 27;
  Dancer1[GyroZ].control1 = 28;
  Dancer1[GyroZ].control2 = 29;
  
  Dancer2[LeftArmX].control1 = 0;
  Dancer2[LeftArmX].control2 = 1;
  Dancer2[LeftArmY].control1 = 2;
  Dancer2[LeftArmY].control2 = 3;
  Dancer2[LeftArmZ].control1 = 4;
  Dancer2[LeftArmZ].control2 = 5;
  Dancer2[RightArmX].control1 = 6;
  Dancer2[RightArmX].control2 = 7;
  Dancer2[RightArmY].control1 = 8;
  Dancer2[RightArmY].control2 = 9;
  Dancer2[RightArmZ].control1 = 10;
  Dancer2[RightArmZ].control2 = 11;
  Dancer2[LeftLegX].control1 = 12;
  Dancer2[LeftLegX].control2 = 13;
  Dancer2[LeftLegY].control1 = 14;
  Dancer2[LeftLegY].control2 = 15;
  Dancer2[LeftLegZ].control1 = 16;
  Dancer2[LeftLegZ].control2 = 17;
  Dancer2[RightLegX].control1 = 18;
  Dancer2[RightLegX].control2 = 19;
  Dancer2[RightLegY].control1 = 20;
  Dancer2[RightLegY].control2 = 21;
  Dancer2[RightLegZ].control1 = 22;
  Dancer2[RightLegZ].control2 = 23;
  Dancer2[GyroX].control1 = 24;
  Dancer2[GyroX].control2 = 25;
  Dancer2[GyroY].control1 = 26;
  Dancer2[GyroY].control2 = 27;
  Dancer2[GyroZ].control1 = 28;
  Dancer2[GyroZ].control2 = 29;
  
  serialBuffer[0] = B10000111;
  serialBuffer[1] = B11111111;
  serialBuffer[2] = B10000111;
  serialBuffer[3] = B11111111;
  serialBuffer[4] = B10000111;
  serialBuffer[5] = B11111111;
  serialBuffer[6] = B10000111;
  serialBuffer[7] = B11111111;
  serialBuffer[8] = B10000111;
  serialBuffer[9] = B11111111;
  serialBuffer[10] = B10000111;
  serialBuffer[11] = B11111111;
  serialBuffer[12] = B10000111;
  serialBuffer[13] = B11111111;
  serialBuffer[14] = B10000111;
  serialBuffer[15] = B11111111;
  serialBuffer[16] = B10000111;
  serialBuffer[17] = B11111111;
  serialBuffer[18] = B10000111;
  serialBuffer[19] = B11111111;
  serialBuffer[20] = B10000111;
  serialBuffer[21] = B11111111;
  serialBuffer[22] = B10000111;
  serialBuffer[23] = B11111111;
  serialBuffer[24] = B10000111;
  serialBuffer[25] = B11111111;
  serialBuffer[26] = B10000111;
  serialBuffer[27] = B11111111;
  serialBuffer[28] = B10000111;
  serialBuffer[29] = B11111111;
  serialBuffer[30] = B10000111;
  serialBuffer[31] = B11111111;
  serialBuffer[32] = B10000111;
  serialBuffer[33] = B11111111;
  serialBuffer[34] = B10000111;
  serialBuffer[35] = B11111111;
  serialBuffer[36] = B10000111;
  serialBuffer[37] = B11111111;
  serialBuffer[38] = B10000111;
  serialBuffer[39] = B11111111;
  serialBuffer[40] = B10000111;
  serialBuffer[41] = B11111111;
  serialBuffer[42] = B10000111;
  serialBuffer[43] = B11111111;
  serialBuffer[44] = B10000111;
  serialBuffer[45] = B11111111;
  serialBuffer[46] = B10000111;
  serialBuffer[47] = B11111111;
  serialBuffer[48] = B10000111;
  serialBuffer[49] = B11111111;
  serialBuffer[50] = B10000111;
  serialBuffer[51] = B11111111;
  serialBuffer[52] = B10000111;
  serialBuffer[53] = B11111111;
  serialBuffer[54] = B10000111;
  serialBuffer[55] = B11111111;
  serialBuffer[56] = B10000111;
  serialBuffer[57] = B11111111;
  serialBuffer[58] = B10000111;
  serialBuffer[59] = B11111111;
}

void loop() {
  parseSerial(serialBuffer);
  for(int i = 0; i < 14; i++) {
    int command = (B1011 << 4) | Dancer1Chan;
    Serial.print(command);
    Serial.print(" ");
    Serial.print(Dancer1[i].control1);
    Serial.print(" ");
    Serial.print(Dancer1[i].data1);
    Serial.print(" ");
    Serial.print(command);
    Serial.print(" ");
    Serial.print(Dancer1[i].control2);
    Serial.print(" ");
    Serial.println(Dancer1[i].data2);
    command = (B1011 << 4) | Dancer2Chan;
    Serial.print(command);
    Serial.print(" ");
    Serial.print(Dancer2[i].control1);
    Serial.print(" ");
    Serial.print(Dancer2[i].data1);
    Serial.print(" ");
    Serial.print(command);
    Serial.print(" ");
    Serial.print(Dancer2[i].control2);
    Serial.print(" ");
    Serial.println(Dancer2[i].data2);
  }

}

void parseSerial(int serialBuffer[60]) {
  Dancer1[LeftArmX].data1 = serialBuffer[0] & B00000111;
  Dancer1[LeftArmX].data2 = serialBuffer[1] & B01111111;
  Dancer1[LeftArmY].data1 = serialBuffer[2] & B00000111;
  Dancer1[LeftArmY].data2 = serialBuffer[3] & B01111111;
  Dancer1[LeftArmZ].data1 = serialBuffer[4] & B00000111;
  Dancer1[LeftArmZ].data2 = serialBuffer[5] & B01111111;
  Dancer1[RightArmX].data1 = serialBuffer[6] & B00000111;
  Dancer1[RightArmX].data2 = serialBuffer[7] & B01111111;
  Dancer1[RightArmY].data1 = serialBuffer[8] & B00000111;
  Dancer1[RightArmY].data2 = serialBuffer[9] & B01111111;
  Dancer1[RightArmZ].data1 = serialBuffer[10] & B00000111;
  Dancer1[RightArmZ].data2 = serialBuffer[11] & B01111111;
  Dancer1[LeftLegX].data1 = serialBuffer[12] & B00000111;
  Dancer1[LeftLegX].data2 = serialBuffer[13] & B01111111;
  Dancer1[LeftLegY].data1 = serialBuffer[14] & B00000111;
  Dancer1[LeftLegY].data2 = serialBuffer[15] & B01111111;
  Dancer1[LeftLegZ].data1 = serialBuffer[16] & B00000111;
  Dancer1[LeftLegZ].data2 = serialBuffer[17] & B01111111;
  Dancer1[RightLegX].data1 = serialBuffer[18] & B00000111;
  Dancer1[RightLegX].data2 = serialBuffer[19] & B01111111;
  Dancer1[RightLegY].data1 = serialBuffer[20] & B00000111;
  Dancer1[RightLegY].data2 = serialBuffer[21] & B01111111;
  Dancer1[RightLegZ].data1 = serialBuffer[22] & B00000111;
  Dancer1[RightLegZ].data2 = serialBuffer[23] & B01111111;
  Dancer1[GyroX].data1 = serialBuffer[24] & B00000111;
  Dancer1[GyroX].data2 = serialBuffer[25] & B01111111;
  Dancer1[GyroY].data1 = serialBuffer[26] & B00000111;
  Dancer1[GyroY].data2 = serialBuffer[27] & B01111111;
  Dancer1[GyroZ].data1 = serialBuffer[28] & B00000111;
  Dancer1[GyroZ].data2 = serialBuffer[29] & B01111111;
  Dancer2[LeftArmX].data1 = serialBuffer[30] & B00000111;
  Dancer2[LeftArmX].data2 = serialBuffer[31] & B01111111;
  Dancer2[LeftArmY].data1 = serialBuffer[32] & B00000111;
  Dancer2[LeftArmY].data2 = serialBuffer[33] & B01111111;
  Dancer2[LeftArmZ].data1 = serialBuffer[34] & B00000111;
  Dancer2[LeftArmZ].data2 = serialBuffer[35] & B01111111;
  Dancer2[RightArmX].data1 = serialBuffer[36] & B00000111;
  Dancer2[RightArmX].data2 = serialBuffer[37] & B01111111;
  Dancer2[RightArmY].data1 = serialBuffer[38] & B00000111;
  Dancer2[RightArmY].data2 = serialBuffer[39] & B01111111;
  Dancer2[RightArmZ].data1 = serialBuffer[40] & B00000111;
  Dancer2[RightArmZ].data2 = serialBuffer[41] & B01111111;
  Dancer2[LeftLegX].data1 = serialBuffer[42] & B00000111;
  Dancer2[LeftLegX].data2 = serialBuffer[43] & B01111111;
  Dancer2[LeftLegY].data1 = serialBuffer[44] & B00000111;
  Dancer2[LeftLegY].data2 = serialBuffer[45] & B01111111;
  Dancer2[LeftLegZ].data1 = serialBuffer[46] & B00000111;
  Dancer2[LeftLegZ].data2 = serialBuffer[47] & B01111111;
  Dancer2[RightLegX].data1 = serialBuffer[48] & B00000111;
  Dancer2[RightLegX].data2 = serialBuffer[49] & B01111111;
  Dancer2[RightLegY].data1 = serialBuffer[50] & B00000111;
  Dancer2[RightLegY].data2 = serialBuffer[51] & B01111111;
  Dancer2[RightLegZ].data1 = serialBuffer[52] & B00000111;
  Dancer2[RightLegZ].data2 = serialBuffer[53] & B01111111;
  Dancer2[GyroX].data1 = serialBuffer[54] & B00000111;
  Dancer2[GyroX].data2 = serialBuffer[55] & B01111111;
  Dancer2[GyroY].data1 = serialBuffer[56] & B00000111;
  Dancer2[GyroY].data2 = serialBuffer[57] & B01111111;
  Dancer2[GyroZ].data1 = serialBuffer[58] & B00000111;
  Dancer2[GyroZ].data2 = serialBuffer[59] & B01111111;
}



/*****************************************
**  Get Serial Data Function            **
*****************************************/
/*
boolean getSerialData() {
  int serialBufferIndex = 0;
  boolean storeData = false;
  while(xbee.available() > 0) {
    int incomingByte = xbee.read();
    if(incomingByte == startChar) {
      serialBufferIndex = 0;
      storeData = true;
    }
    if(storeData) {
      if(serialBufferIndex == DATABUFFERSIZE - 1) {
        serialBufferIndex = 0;
        break;
      }
      if(incomingByte == 255) {
        serialBuffer[serialBufferIndex] = 0;
        return true;
      } else {
        if(incomingByte != '!' && incomingByte != delimiterChar) {
          serialBuffer[serialBufferIndex++] = incomingByte;
          serialBuffer[serialBufferIndex] = 0;
        }
      }
    }
  }
  return false;
}
*/
