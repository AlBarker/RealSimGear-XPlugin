

void setup() {
  // initialize the button pin as a input:
  pinMode(32, INPUT_PULLUP);
  pinMode(33, INPUT_PULLUP);
  pinMode(34, INPUT_PULLUP);
  pinMode(35, INPUT_PULLUP);
  pinMode(36, INPUT_PULLUP);
  pinMode(37, INPUT_PULLUP);
  pinMode(38, INPUT_PULLUP);
  pinMode(39, INPUT_PULLUP);
  pinMode(40, INPUT_PULLUP);
  pinMode(41, INPUT_PULLUP);
  pinMode(42, INPUT_PULLUP);
  pinMode(43, INPUT_PULLUP);
  pinMode(44, INPUT_PULLUP);
  pinMode(45, INPUT_PULLUP);
  pinMode(48, INPUT_PULLUP);
  pinMode(49, INPUT_PULLUP);
  
  // initialize the LED as an output:
  pinMode(13, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {

    if ((digitalRead(32)) == LOW) {
      Serial.println("GPS1_PROC");
      Serial.print("\n");
      delay(250);
    } else {
        if ((digitalRead(33)) == LOW) {
          Serial.println("GPS1_CDI");
          Serial.print("\n");
          delay(250);
        } else {
          if ((digitalRead(34)) == LOW) {
            Serial.println("GPS1_FPL");
            Serial.print("\n");
            delay(250);
          } else {
            if ((digitalRead(35)) == LOW) {
              Serial.println("GPS1_VNAV");
              Serial.print("\n");
              delay(250);
            } else {
              if ((digitalRead(36)) == LOW) {
                Serial.println("GPS1_OBS");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(37)) == LOW) {
                Serial.println("GPS1_MSG");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(38)) == LOW) {
                Serial.println("GPS1_NAV_FLIP");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(39)) == LOW) {
                Serial.println("GPS1_COM_FLIP");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(40)) == LOW) {
                Serial.println("GPS1_ZOOM_IN");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(41)) == LOW) {
                Serial.println("GPS1_ZOOM_OUT");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(42)) == LOW) {
                Serial.println("GPS1_MENU");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(43)) == LOW) {
                Serial.println("GPS1_DIRECT");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(44)) == LOW) {
                Serial.println("GPS1_ENTER");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(45)) == LOW) {
                Serial.println("GPS1_CLR");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(48)) == LOW) {
                Serial.println("GPS1_PUSH_CSR");
                Serial.print("\n");
                delay(250);
            } else {
              if ((digitalRead(49)) == LOW) {
                Serial.println("GPS1_NAV/COM_TOGGLE_ACTIVE");
                Serial.print("\n");
                delay(250);
            }
            }
            }
    
          }
        }
    }
}
            }
            }
            }
            }
            }
            }
          }
        }
    }
}
 

//BUTTONS
//32 GPS1 PROC
//33 GPS1 CDI
//34 GPS1 FPL
//35 GPS1 VNAV
//36 GPS1 OBS
//37 GPS1 MSG
//38 GPS1 NAV Flip
//39 GPS1 COM Flip
//40 GPS1 Zoom In
//41 GPS1 Zoom Out
//42 GPS1 Menu
//43 GPS1 Direct
//44 GPS1 Enter
//45 GPS1 Clr
//48 GPS1 Push Cursor
//49 GPS1 NAV/COM toggle active

//Encoders
//30 GPS1 Chapter UP/DN encoder
//31 second pin
//46 GPS1 Page UP/DN encoder
//47 second pin
//50 G430 COM/NAV1 coarse encoder
//51 second pin
//52 G430 COM/NAV1 fine encoder  
//53 second pin
