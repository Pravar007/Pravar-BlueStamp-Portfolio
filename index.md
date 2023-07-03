| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Pravar K | Thomas Jefferson High School for Science and Technology | Mehcanical Engineering | Rising Junior 

# **Mini Tank**

## **Milestone Three**
<iframe width="520" height="293" src="https://www.youtube.com/embed/d-ae45pgoyI" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

  This third milestone represents full completion of the stock project. This means full movement and full functionality of all the sensors on board. The robot is now able to be controlled by both bluetooth and a remote, avoid obstacles, follow obstacles, follow light, and display messages on the LED screen mounted to the front. The obstacle detection for the avoidance and follow features uses an ultrasonic sensor mounted onto a servo motor. This servo allows the sensor to turn and look in different directions for a clear path, or to find any obstacles in the way. When the robot encounters an obstacle in avoidance mode, it turns its "eyes" (the ultrasonic sensor) around to find a clear path, when it does, it simply turns to that direction and goes forward until it encounters another obstacle, where it repeats this process. The opposite happens for follow mode, where it looks for the obstacle, and goes in its direction. Depending on how far the obstacle is from the robot, it could either travel backward away from it or forwards towards it. The IR reciever is used to connect the robot to a remote, through which it can be controlled. The light following feature uses the two photoresistors mounted to either front corner. The amount of light they recieve determines the direction that the robot travels. If both recieve bright light, the robot goes forward. If one recieves more light than the other (difference should be significant), the robot turns toward the photoresistor getting more light until the two recieve the same amount of light, continuing forward when they do. 

  
  Some of the biggest challenges when building this robot were getting the bespoke IR remote libraries to work with the arduino program, and finding a battery with the right power output to allow the motors to function as intended. Next, I plan to modify this robot to possibly include a remote controlled robotic arm attached to it so that it could pick up objects nad be more useful in my daily life. I am also looking at adding a projectile to make it more like a tank. A possible cosmetic modification could be to 3D-print a shell that covers the tank tracks to make it look more rugged. Some key topics that I learned about while bulding this robot were arduino programming, component wiring, troubleshooting, and debugging.

## **Milestone Two**
<iframe width="520" height="293" src="https://www.youtube.com/embed/A6prT1Q4WG4" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

  My second milestone with the mini tank robot is achieving full movement. This means both my motors operate as intended; in both directions and at different speeds. My goal for movement was for the robot to be able to move fully by itself, and be controlled remotely. I had a choice between using a physical remote to control my robot and using an app on my phone, and I chose my phone as the remote, which meant using the bluetooth module (TI HM-10). The code maps the button presses on my phone to the correct functions that make the robot move, as well as displaying an animation on the 8x16 LED panel bolted to the front of the robot. When the "forward" button is presssed, both motors engage at full speed in the same direction, when the "back" button is pressed, the same happens, but in the opposite direction. In order to turn - since the tracks themselves don't steer - the left and right tracks are spun in opposite directions; right going forward turns left, and vice versa. 

## **Milestone One**

<iframe width="520" height="293" src="https://www.youtube.com/embed/kTaH7wy5VD0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

  My first milestone with this project is finishing its assembly. The tank is built around a metal chassis to which the motors and the battery holder are connected. Four standoffs bolt into the center of the chassis, on top of which rests an acrylic plate that is home to the rest of the electronics. Standoffs rise from this acrylic plate to a servo motor attached to the ultrasonic sensor. Also attached to this acrylic plate is the arduino, one IR reciever, and two photocell sensors. Dropping down the front of the robot attached to the acrylic plate is an 8x16 LED panel. Bolted to the chassis are two free-spinning wheels, which are connected to the driving wheels by plastic tank tracks. The wires from the motors and battery holder are wired into the motoshield, while the rest of the components connect into the topmost sensor shield. Overall, the cable management on this robot is fairly neat and does not obstruct the function of any of the components. 

## **CODE**

```
  #include <IRremoteTank.h>
  int RECV_PIN = A0;       
  IRrecv irrecv(RECV_PIN);   
  decode_results results;
  
  //Array, used to store the data of the pattern, can be calculated by yourself or obtained from the modulus tool
  unsigned char start01[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
  unsigned char front[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
  unsigned char back[] = {0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
  unsigned char left[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
  unsigned char right[] = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
  unsigned char STOP01[] = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
  unsigned char clear[] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
  #define SCL_Pin  A5  //Set clock pin to A5
  #define SDA_Pin  A4  //Set data pin to A4
  
  #define ML_Ctrl 13  //define direction control pin of left motor
  #define ML_PWM 11   //define PWM control pin of left motor
  #define MR_Ctrl 12  //define direction control pin of right motor
  #define MR_PWM 3   //define PWM control pin of right motor
  
  #define Trig 5  //ultrasonic trig Pin
  #define Echo 4  //ultrasonic echo Pin
  int distance; //save the distance value detected by ultrasonic, follow function
  int random2; //save the variable of random numberssave the variable of random numbers
  //save the distance value detected by ultrasonic, obstacle avoidance function
  int a;  
  int a1;
  int a2;
  
  #define servoPin 9  //servo Pin
  int pulsewidth;
  
  #define light_L_Pin A1   //define the pin of left photo resistor sensor
  #define light_R_Pin A2   //define the pin of right photo resistor sensor
  int left_light;
  int right_light;
  
  // char bluetooth_val; //save the value of Bluetooth reception
  int flag;  //flag variable, it is used to entry and exist function
  void setup(){
    Serial.begin(9600);
    irrecv.enableIRIn(); // Initialize the IR receiver 
  
    pinMode(Trig, OUTPUT);
    pinMode(Echo, INPUT);
    pinMode(ML_Ctrl, OUTPUT);
    pinMode(ML_PWM, OUTPUT);
    pinMode(MR_Ctrl, OUTPUT);
    pinMode(MR_PWM, OUTPUT);
    
    pinMode(servoPin, OUTPUT);
    procedure(70); //set servo to 90°
    pinMode(SCL_Pin,OUTPUT);
    pinMode(SDA_Pin,OUTPUT);
    matrix_display(clear);    //Clear the display
    matrix_display(start01);  //display start pattern
    pinMode(light_L_Pin, INPUT);
    pinMode(light_R_Pin, INPUT);
  }
  
  void loop(){
    if (irrecv.decode(&results)) {
      if(results.value==0xFF629D) //FRONT
      {
          Car_front();
          matrix_display(front);  //display forward pattern
      }
      else if(results.value==0xFFA857) //BACK
      {
        Car_back();
        matrix_display(back);  // display back pattern
      }
  
      else if(results.value==0xFF22DD) //LEFT
      {
        Car_left();
        matrix_display(left);  //show left-turning pattern
      }
  
      else if(results.value==0xFFC23D) //RIGHT
      {
        Car_right();
        matrix_display(right);  //show right-turning pattern
      }
  
      else if(results.value==0xFF02FD) //STOP
      {
        Car_Stop();
        matrix_display(STOP01);  //display stop pattern
      }
      else if(results.value==0xFF42BD) //FOLLOW OBJ
      {
        matrix_display(start01);  
        follow();
      }
  
      else if(results.value==0xFF4AB5) //AVOID OBJ
      {
        matrix_display(start01);  
        avoid();
      }
  
      else if(results.value==0xFF52AD) //LIGHT FOLLOW
      {
        matrix_display(start01);  
        light_track();
      }
          irrecv.resume(); //receive the next value
        }
  }
  /*****************Obstacle Avoidance Function**************/
  void avoid() 
  {
    flag = 0;  //the design that enter obstacle avoidance function
    while (flag == 0) 
    {
      random2 = random(1, 100);
      a = checkdistance();  //assign the front distance detected by ultrasonic sensor to variable a
      
      if (a < 20) //when the front distance detected is less than 20cm
      {
        Car_Stop();  //robot stops
        delay(200); //delay in 200ms
        
        procedure(160);  //Ultrasonic platform turns left
        for (int j = 1; j <= 10; j = j + (1)) { ///for statement, the data will be more accurate if ultrasonic sensor detect a few times.
          a1 = checkdistance();  //assign the left distance detected by ultrasonic sensor to variable a1
        }
        delay(200);
        procedure(20); //Ultrasonic platform turns right
        for (int k = 1; k <= 10; k = k + (1)) {
          a2 = checkdistance(); //assign the right distance detected by ultrasonic sensor to variable a2
        }
        if (a1 < 50 || a2 < 50)  //robot will turn to the longer distance side when left or right distance is less than 50cm.if the left or right distance is less than 50cm, the robot will turn to the greater distance
        {
          if (a1 > a2) //left distance is greater than right
          {
            procedure(90);  //Ultrasonic platform turns back to right ahead ultrasonic platform turns front
            Car_left();  //robot turns left
            delay(500);  //turn left 500ms
            Car_front(); //go forward
          } 
          else 
          {
            procedure(90);
            Car_right(); //robot turns right
            delay(500);
            Car_front();  //go forward
          }
        } 
        else  //both distance on two side is greater than or equal to 50cm, turn randomly
        {
          if ((long) (random2) % (long) (2) == 0)  //when the random number is even
          {
            procedure(90);
            Car_left(); //robot turns left
            delay(500);
            Car_front(); //go forward
          } 
          else 
          {
            procedure(90);
            Car_right(); //robot turns right
            delay(500);
            Car_front(); ///go forward
         } } } 
    else  //If the front distance is greater than or equal to 20cm, robot car will go front
    {
        Car_front(); //go forward
    }
    // receive the input to end the obstacle avoidance function
    if (irrecv.decode(&results)) {
      if(results.value==0xFF02FD)
      {
        flag = 1;  //when assign 1 to flag, end loop
        }
        irrecv.resume(); //receive the next value
    }}}
  /*******************Follow****************/
  void follow() {
    flag = 0;
    while (flag == 0) {
      distance = checkdistance();  //assign the distance detected by ultrasonic sensor to distance
      if (distance >= 20 && distance <= 60) //the range to go front
      {
        Car_front();
      }
      else if (distance > 10 && distance < 20)  //the range to stop
      {
        Car_Stop();
      }
      else if (distance <= 10)  // the range to go back
      {
        Car_back();
      }
      else  //other situations, stop
      {
        Car_Stop();
      }
      // if (Serial.available())
      // {
      //   bluetooth_val = Serial.read();
      //   if (bluetooth_val == 'S') 
      //   {
      //     flag = 1;  //end loop
      //   }}
      if (irrecv.decode(&results)) {
      if(results.value==0xFF02FD)
      {
        flag = 1;  //when assign 1 to flag, end loop
        }
        irrecv.resume(); //receive the next value
    }}}
  //The function to control ultrasonic sensor 
  float checkdistance() {
    digitalWrite(Trig, LOW);
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);
    float distance = pulseIn(Echo, HIGH) / 58.00;  //58.20 means 2*29.1=58.2
    delay(10);
    return distance;
  }
  //The function to control servo the function controlling servo
  void procedure(int myangle) {
    for (int i = 0; i <= 50; i = i + (1)) {
      pulsewidth = myangle * 11 + 500;
      digitalWrite(servoPin,HIGH);
      delayMicroseconds(pulsewidth);
      digitalWrite(servoPin,LOW);
      delay((20 - pulsewidth / 1000));
    }}
  
  /****************Light Follow******************/
  void light_track() {
    flag = 0;
    while (flag == 0) {
      left_light = analogRead(light_L_Pin);
      right_light = analogRead(light_R_Pin);
      if (left_light > 650 && right_light > 650) //the value detected by photo resistor, go forward
      {  
        Car_front();
      } 
      else if (left_light > 650 && right_light <= 650)  //the value detected by photo resistor, turn left
      {
        Car_left();
      } 
      else if (left_light <= 650 && right_light > 650) //the value detected by photo resistor, turn right
      {
        Car_right();
      } 
      else  //other situations, stop
      {
        Car_Stop();
      }
      if (irrecv.decode(&results)) {
      if(results.value==0xFF02FD)
      {
        flag = 1;  //when assign 1 to flag, end loop
        }
        irrecv.resume(); //receive the next value
    }}}
  /***************Dot Matrix *****************/
  // this function is used for dot matrix display 
  void matrix_display(unsigned char matrix_value[])
  {
    IIC_start();
    IIC_send(0xc0);  //Choose address
    
    for(int i = 0;i < 16;i++) //pattern data has 16 bits
    {
       IIC_send(matrix_value[i]); //convey the pattern data
    }
    IIC_end();   //end the transmission of pattern data
    IIC_start();
    IIC_send(0x8A);  //display control, set pulse width to 4/16
    IIC_end();
  }
  //The condition starting to transmit data
  void IIC_start()
  {
    digitalWrite(SCL_Pin,HIGH);
    delayMicroseconds(3);
    digitalWrite(SDA_Pin,HIGH);
    delayMicroseconds(3);
    digitalWrite(SDA_Pin,LOW);
    delayMicroseconds(3);
  }
  //convey data
  void IIC_send(unsigned char send_data)
  {
    for(char i = 0;i < 8;i++)  //each byte has 8 bits
    {
        digitalWrite(SCL_Pin,LOW);  //pull down clock pin SCL Pin to change the signals of SDA
        delayMicroseconds(3);
        if(send_data & 0x01)  //set high and low level of SDA_Pin according to 1 or 0 of every bit
        {
          digitalWrite(SDA_Pin,HIGH);
        }
        else
        {
          digitalWrite(SDA_Pin,LOW);
        }
        delayMicroseconds(3);
        digitalWrite(SCL_Pin,HIGH); //pull up clock pin SCL_Pin to stop transmitting data
        delayMicroseconds(3);
        send_data = send_data >> 1;  // detect bit by bit, so move the data right by one
    }}
  //The sign that data transmission ends
  void IIC_end()
  {
    digitalWrite(SCL_Pin,LOW);
    delayMicroseconds(3);
    digitalWrite(SDA_Pin,LOW);
    delayMicroseconds(3);
    digitalWrite(SCL_Pin,HIGH);
    delayMicroseconds(3);
    digitalWrite(SDA_Pin,HIGH);
    delayMicroseconds(3);
  }
  /*************the function to run motor*************/
  void Car_front()
  {
    digitalWrite(MR_Ctrl,LOW);
    analogWrite(MR_PWM,200);
    digitalWrite(ML_Ctrl,LOW);
    analogWrite(ML_PWM,200);
  }
  void Car_back()
  {
    digitalWrite(MR_Ctrl,HIGH);
    analogWrite(MR_PWM,200);
    digitalWrite(ML_Ctrl,HIGH);
    analogWrite(ML_PWM,200);
  }
  void Car_left()
  {
    digitalWrite(MR_Ctrl,LOW);
    analogWrite(MR_PWM,255);
    digitalWrite(ML_Ctrl,HIGH);
    analogWrite(ML_PWM,255);
  }
  void Car_right()
  {
    digitalWrite(MR_Ctrl,HIGH);
    analogWrite(MR_PWM,255);
    digitalWrite(ML_Ctrl,LOW);
    analogWrite(ML_PWM,255);
  }
  void Car_Stop()
  {
    digitalWrite(MR_Ctrl,LOW);
    analogWrite(MR_PWM,0);
    digitalWrite(ML_Ctrl,LOW);
    analogWrite(ML_PWM,0);
  }
  void Car_T_left()
  {
    digitalWrite(MR_Ctrl,LOW);
    analogWrite(MR_PWM,255);
    digitalWrite(ML_Ctrl,LOW);
    analogWrite(ML_PWM,180);
  }
  void Car_T_right()
  {
    digitalWrite(MR_Ctrl,LOW);
    analogWrite(MR_PWM,180);
    digitalWrite(ML_Ctrl,LOW);
    analogWrite(ML_PWM,255);
  }


# **TV-B-Gone!**
![Headstone Image](TV-B-Gone.PNG)

<iframe width="520" height="293" src="https://www.youtube.com/embed/QaLAbvSM52E" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>  

  The TV-B-Gone is a small remote device that, with the press of a button, turns off any TV within a 150 foot radius. This remote consists of one  microcontroller, with five transistors, two 1.0Kohm resistors, three capacitors, and a battery holder for two AA batteries. The main parts are the four IR LEDs which broadcast the signal to turn off the TVs, the button, used to turn on the IR LEDs, an indicator LED that signals whether or not the device is turned on. Putting together this project involved placing and soldering all the components onto the circuit board, periodically testing that everything is working as intended. Once finished, a press of the button starts a broadcast of the most common IR codes for TVs in order to turn them off. 

| **Components list** | **Quantity** |
| -----------------| ----------------|
| IC1' 8-pin socket | 1 |    
| IC1 Microcontroller | 1 |
| XTL1 8.00 MHz ceramic oscillator | 1 |                                  
| C2 220uF capacitor | 1 |                                               
| C1	Ceramic 0.1uF capacitor (104) | 1 |
| R1, R5 1.0Kohm 1/4W 5% resistor | 2 |                                
| Narrow beam IR LED  | 2 |                                               
| Wide beam IR LED  | 2 |                                                 
| 3mm Green LED        | 1 |                                              
| SW1	6mm tact switch button    | 1 |                                    
| Q5	PNP transistor, EBC pinout        | 1 |                              
| Q1,2,3,4	NPN Transistor(TO-92) → 2N3904 EBC pinout | 4 |
| BATT	2x AA battery holder        | 1 |                                  
| AA Battery 1.5 V | 2 |                                                  
| PCB  | 1 |                                                              

<!---Replace this text with a brief description (2-3 sentences) of your project. This description should draw the reader in and make them interested in what you've built. You can include what the biggest challenges, takeaways, and triumphs from completing the project were. As you complete your portfolio, remember your audience is less familiar than you are with all that your project entails!

**Replace the BlueStamp logo below with an image of yourself and your completed project. Follow the guide [here](https://tomcam.github.io/least-github-pages/adding-images-github-pages-site.html) if you need help.**

![Headstone Image](logo.svg)
  
# Final Milestone
For your final milestone, explain the outcome of your project. Key details to include are:
- What you've accomplished since your previous milestone
- What your biggest challenges and triumphs were at BSE
- A summary of key topics you learned about
- What you hope to learn in the future after everything you've learned at BSE

**Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**

<iframe width="560" height="338" src="https://www.youtube.com/embed/F7M7imOVGug" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

# Second Milestone
For your second milestone, explain what you've worked on since your previous milestone. You can highlight:
- Technical details of what you've accomplished and how they contribute to the final goal
- What has been surprising about the project so far
- Previous challenges you faced that you overcame
- What needs to be completed before your final milestone 

**Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**

<iframe width="560" height="315" src="https://www.youtube.com/embed/y3VAmNlER5Y" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

# First Milestone
For your first milestone, describe what your project is and how you plan to build it. You can include:
- An explanation about the different components of your project and how they will all integrate together
- Technical progress you've made so far
- Challenges you're facing and solving in your future milestones
- What your plan is to complete your project

**Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**

<iframe width="560" height="315" src="https://www.youtube.com/embed/CaCazFBhYKs" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

# Schematics 
Here's where you'll put images of your schematics. [Tinkercad](https://www.tinkercad.com/blog/official-guide-to-tinkercad-circuits) and [Fritzing](https://fritzing.org/learning/) are both great resoruces to create professional schematic diagrams, though BSE recommends Tinkercad becuase it can be done easily and for free in the browser. 

# Code
Here's where you'll put your code. The syntax below places it into a block of code. Follow the guide [here]([url](https://www.markdownguide.org/extended-syntax/)) to learn how to customize it to your project needs. 

c++
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello World!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
```

# Bill of Materials
Here's where you'll list the parts in your project. To add more rows, just copy and paste the example rows below.
Don't forget to place the link of where to buy each component inside the quotation marks in the corresponding row after href =. Follow the guide [here]([url](https://www.markdownguide.org/extended-syntax/)) to learn how to customize this to your project needs. 

| **Part** | **Note** | **Price** | **Link** |
|:--:|:--:|:--:|:--:|
| Item Name | What the item is used for | $Price | <a href="https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/"> Link </a> |
|:--:|:--:|:--:|:--:|
| Item Name | What the item is used for | $Price | <a href="https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/"> Link </a> |
|:--:|:--:|:--:|:--:|
| Item Name | What the item is used for | $Price | <a href="https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/"> Link </a> |
|:--:|:--:|:--:|:--:|

# Other Resources/Examples
One of the best parts about Github is that you can view how other people set up their own work. Here are some past BSE portfolios that are awesome examples. You can view how they set up their portfolio, and you can view their index.md files to understand how they implemented different portfolio components.
- [Example 1](https://trashytuber.github.io/YimingJiaBlueStamp/)
- [Example 2](https://sviatil0.github.io/Sviatoslav_BSE/)
- [Example 3](https://arneshkumar.github.io/arneshbluestamp/)

To watch the BSE tutorial on how to create a portfolio, click here.-->
