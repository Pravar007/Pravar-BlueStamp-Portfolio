#include <IRremote.h>
#include <Servo.h>

// IR module initialization
int RECV_PIN = 8;
IRrecv irrecv(RECV_PIN);
decode_results results;

Servo bottomServo;     //bottom servo Pin
Servo mainPivot;       //main pivot servo Pin
Servo secondaryPivot;  //secondary pivot servo Pin
Servo clawServo;       //claw servo Pin

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();  // Initialize the IR receiver

  //Servo pin definition
  bottomServo.attach(4);
  mainPivot.attach(5);
  secondaryPivot.attach(6);
  clawServo.attach(7);

  // setting all servos to 90 degrees
  bottomServo.write(90);
  mainPivot.write(90);
  secondaryPivot.write(90);
  clawServo.write(90);
  delay(1000);
}

void loop() {
  // mapping remote button presses to servo movement functions
  if (irrecv.decode()) {
    if (irrecv.decodedIRData.decodedRawData == 3810328320)  // bottom servo right
    {
      bottomServo_right();
    } else if (irrecv.decodedIRData.decodedRawData == 4144561920)  // bottom servo left
    {
      bottomServo_left();
    }

    else if (irrecv.decodedIRData.decodedRawData == 3910598400)  // main pivot forward
    {
      mainPivot_forward();
    }

    else if (irrecv.decodedIRData.decodedRawData == 4077715200)  // main pivot backward
    {
      mainPivot_back();
    }

    else if (irrecv.decodedIRData.decodedRawData == 3860463360)  // secondary pivot forward
    {
      secondaryPivot_forward();
    }

    else if (irrecv.decodedIRData.decodedRawData == 3877175040)  // secondary pivot backward
    {
      secondaryPivot_back();
    }

    else if (irrecv.decodedIRData.decodedRawData == 4061003520)  // claw open
    {
      claw_open();
    }

    else if (irrecv.decodedIRData.decodedRawData == 2707357440)  // claw close
    {
      claw_close();
    }

    irrecv.resume();  //receive the next value
  }
}

//******************SERVO MOVEMENT FUNCTIONS******************//
// runs an infinite for loop to slowly change the angle of each servo until "9" is pressed, which stops the for loop

// Function to twist the bottom servo to the right
void bottomServo_right() {
  int bR = bottomServo.read();                                  // Read the current position of the bottom servo
  for (bR <= 180; bR += 1;) {                                   // Loop to increment the position from current to 180 degrees
    if (irrecv.decode()) {                                      // Check if an infrared signal is received
      if (irrecv.decodedIRData.decodedRawData == 2774204160) {  // Check if the received signal matches a specific value
        break;                                                  // If the signal matches, exit the loop
      }
      irrecv.resume();  // Resume receiving infrared signals
    }
    bottomServo.write(bR);  // Set the bottom servo position to the current value
    delay(15);              // Delay for stability
  }
}

// Function to twist the bottom servo to the left
void bottomServo_left() {
  int bR = bottomServo.read();                                  // Read the current position of the bottom servo
  for (bR <= 180; bR -= 1;) {                                   // Loop to decrement the position from current to 0 degrees
    if (irrecv.decode()) {                                      // Check if an infrared signal is received
      if (irrecv.decodedIRData.decodedRawData == 2774204160) {  // Check if the received signal matches a specific value
        break;                                                  // If the signal matches, exit the loop
      }
      irrecv.resume();  // Resume receiving infrared signals
    }
    bottomServo.write(bR);  // Set the bottom servo position to the current value
    delay(15);              // Delay for stability
  }
}

// Function to move the main pivot forward
void mainPivot_forward() {
  int mP = mainPivot.read();                                    // Read the current position of the main pivot
  for (mP <= 180; mP -= 1;) {                                   // Loop to decrement the position from current to 0 degrees
    if (irrecv.decode()) {                                      // Check if an infrared signal is received
      if (irrecv.decodedIRData.decodedRawData == 2774204160) {  // Check if the received signal matches a specific value
        break;                                                  // If the signal matches, exit the loop
      }
      irrecv.resume();  // Resume receiving infrared signals
    }
    mainPivot.write(mP);  // Set the main pivot position to the current value
    delay(15);            // Delay for stability
  }
}

// Function to move the main pivot backward
void mainPivot_back() {
  int mP = mainPivot.read();                                    // Read the current position of the main pivot
  for (mP <= 180; mP += 1;) {                                   // Loop to increment the position from current to 180 degrees
    if (irrecv.decode()) {                                      // Check if an infrared signal is received
      if (irrecv.decodedIRData.decodedRawData == 2774204160) {  // Check if the received signal matches a specific value
        break;                                                  // If the signal matches, exit the loop
      }
      irrecv.resume();  // Resume receiving infrared signals
    }
    mainPivot.write(mP);  // Set the main pivot position to the current value
    delay(15);            // Delay for stability
  }
}

// Function to move the secondary pivot forward
void secondaryPivot_forward() {
  int sP = secondaryPivot.read();                               // Read the current position of the secondary pivot
  for (sP <= 180; sP += 1;) {                                   // Loop to increment the position from current to 180 degrees
    if (irrecv.decode()) {                                      // Check if an infrared signal is received
      if (irrecv.decodedIRData.decodedRawData == 2774204160) {  // Check if the received signal matches a specific value
        break;                                                  // If the signal matches, exit the loop
      }
      irrecv.resume();  // Resume receiving infrared signals
    }
    secondaryPivot.write(sP);  // Set the secondary pivot position to the current value
    delay(15);                 // Delay for stability
  }
}

// Function to move the secondary pivot backward
void secondaryPivot_back() {
  int sP = secondaryPivot.read();                               // Read the current position of the secondary pivot
  for (sP <= 180; sP -= 1;) {                                   // Loop to decrement the position from current to 0 degrees
    if (irrecv.decode()) {                                      // Check if an infrared signal is received
      if (irrecv.decodedIRData.decodedRawData == 2774204160) {  // Check if the received signal matches a specific value
        break;                                                  // If the signal matches, exit the loop
      }
      irrecv.resume();  // Resume receiving infrared signals
    }
    secondaryPivot.write(sP);  // Set the secondary pivot position to the current value
    delay(15);                 // Delay for stability
  }
}

// Function to open the claw
void claw_open() {
  int c = clawServo.read();                                     // Read the current position of the claw servo
  for (c >= 0; c -= 1;) {                                       // Loop to decrement the position from current to 0 degrees
    if (irrecv.decode()) {                                      // Check if an infrared signal is received
      if (irrecv.decodedIRData.decodedRawData == 2774204160) {  // Check if the received signal matches a specific value
        break;                                                  // If the signal matches, exit the loop
      }
      irrecv.resume();  // Resume receiving infrared signals
    }
    clawServo.write(c);  // Set the claw servo position to the current value
    delay(15);           // Delay for stability
  }
}

// Function to close the claw
void claw_close() {
  int c = clawServo.read();                                     // Read the current position of the claw servo
  for (c >= 0; c += 1;) {                                       // Loop to increment the position from current to 180 degrees
    if (irrecv.decode()) {                                      // Check if an infrared signal is received
      if (irrecv.decodedIRData.decodedRawData == 2774204160) {  // Check if the received signal matches a specific value
        break;                                                  // If the signal matches, exit the loop
      }
      irrecv.resume();  // Resume receiving infrared signals
    }
    clawServo.write(c);  // Set the claw servo position to the current value
    delay(15);           // Delay for stability
  }
}
