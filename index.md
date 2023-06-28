| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Pravar K | Thomas Jefferson High School for Science and Technology | Mehcanical Engineering | Rising Junior 

# **Mini Tank**

## **Milestone Three**

## **Milestone Two**
<iframe width="520" height="293" src="https://www.youtube.com/embed/A6prT1Q4WG4" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

My second milestone with the mini tank robot is achieving full movement. This means both my motors operate as intended; in both directions and at different speeds. My goal for movement was for the robot to be able to move fully by itself, and be controlled remotely. I had a choice between using a physical remote to control my robot and using an app on my phone, and I chose my phone as the remote, which meant using the bluetooth module (TI HM-10). The code maps the button presses on my phone to the correct functions that make the robot move, as well as displaying an animation on the 8x16 LED panel bolted to the front of the robot. When the "forward" button is presssed, both motors engage at full speed in the same direction, when the "back" button is pressed, the same happens, but in the opposite direction. In order to turn - since the tracks themselves don't steer - the left and right tracks are spun in opposite directions; right going forward turns left, and vice versa. 

## **Milestone One**

<iframe width="520" height="293" src="https://www.youtube.com/embed/kTaH7wy5VD0" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

My first milestone with this project is finishing its assembly. The tank is built around a metal chassis to which the motors and the battery holder are connected. Four standoffs bolt into the center of the chassis, on top of which rests an acrylic plate that is home to the rest of the electronics. Standoffs rise from this acrylic plate to a servo motor attached to the ultrasonic sensor. Also attached to this acrylic plate is the arduino, one IR reciever, and two photocell sensors. Dropping down the front of the robot attached to the acrylic plate is an 8x16 LED panel. Bolted to the chassis are two free-spinning wheels, which are connected to the driving wheels by plastic tank tracks. The wires from the motors and battery holder are wired into the motoshield, while the rest of the components connect into the topmost sensor shield. Overall, the cable management on this robot is fairly neat and does not obstruct the function of any of the components. 

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

```c++
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
