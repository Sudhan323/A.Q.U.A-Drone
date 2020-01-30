/*
*
* Project Name:   A.Q.U.A Drone
* Author List:    Sudharsanan J, Harish N, Manikandan A, Prithivirajan K
* Filename:     A.Q.U.A.Drone.ino
* Functions:    setup(), loop(), Read_Joystick(), Increase_Height(), Decrease_Height(), Forward_Motion(), Backward_Motion(), Right_Motion(), 
*               Left_Motion(), Run_Drone()
* Global Variables: joy_threshold_min,joy_threshold_max
*                   height,forward,turn
*
*/


/*
*
* Function Name:   setup()
* Input:    None
* Output:   Assign the pins on arduino for input and output
* Logic:    Sets the pin as input or output
* Example Call:   setup()
*
*/

void setup() {

//Setting Analog pins as Input for reading values from joystick  
pinMode(A0,INPUT);//height x //Blue
pinMode(A2,INPUT);//Navigate x //Green
pinMode(A4,INPUT);//Navigate y //Green White
pinMode(A3,INPUT);

//Setting pin as input for kill switch
pinMode(7,INPUT);//Switch

//Setting pins as output for controlling motor drivers to operate vertical motors
pinMode(23,OUTPUT);//Height 1
pinMode(25,OUTPUT);//Height 2
pinMode(27,OUTPUT);//Height 3
pinMode(29,OUTPUT);//Height 4

//Setting pins as output for controlling motor drivers to operate horizontal motors
pinMode(47,OUTPUT);//Right 1
pinMode(49,OUTPUT);//Right 2
pinMode(51,OUTPUT);//Left 1
pinMode(53,OUTPUT);//Left 2

//To control LEDs
pinMode(41,OUTPUT);//LED Positive
pinMode(39,OUTPUT);//LED Negative
pinMode(37,OUTPUT);
pinMode(35,OUTPUT);

//Assigning LED to glow always
digitalWrite(41,HIGH);//LED
digitalWrite(39,LOW);//LED

//Establishing serial communication with PC
Serial.begin(9600);
}

int joy_threshold_min = 100,joy_threshold_max = 580;//Setting Minimum and Maximum threshold values for Joy Stick 
int height,forward,turn;// Declaring variables for reading from joy stick

/*
*
* Function Name:   Read_Joystick()
* Input:    None
* Output:   Assigns values to variables from joystick
* Logic:    Read various analog values from the joy stick and assigns to the variable
* Example Call:   Read_Joystick()
*
*/

void Read_Joystick()
{
  height = analogRead(A0);
  forward = analogRead(A2);
  turn = analogRead(A4);
}

/*
*
* Function Name:   Decrease_Height()
* Input:    None
* Output:   Controls vertical motor
* Logic:    Write high into motor pins to make the motor to rotate in a direction to push the drone into water.
* Example Call:   Decrease_Height()
*
*/

void Decrease_Height()
{
  digitalWrite(23,HIGH);
  digitalWrite(27,HIGH);
  digitalWrite(25,LOW);
  digitalWrite(29,LOW);
  Serial.println("Increase_Height");
}

/*
*
* Function Name:   Increase_Height()
* Input:    None
* Output:   Controls vertical motor
* Logic:    Write high into motor pins to make the motor to rotate in a direction to pull the drone from water.
* Example Call:   Increase_Height()
*
*/

void Increase_Height()
{
  digitalWrite(23,LOW);
  digitalWrite(27,LOW);
  digitalWrite(25,HIGH);
  digitalWrite(29,HIGH);
  Serial.println("Decrease_Height");
}

/*
*
* Function Name:   Forward_Motion()
* Input:    None
* Output:   Controls horizontal motor
* Logic:    Write high into motor pins to make the motor to rotate in a direction to push the drone in forward direction.
* Example Call:   Forward_Motion()
*
*/

void Forward_Motion()
{
  digitalWrite(47,HIGH);
  digitalWrite(49,LOW);
  digitalWrite(51,HIGH);
  digitalWrite(53,LOW);
  Serial.println("Forward_Motion");
}

/*
*
* Function Name:   Backward_Motion()
* Input:    None
* Output:   Controls horizontal motor
* Logic:    Write high into motor pins to make the motor to rotate in a direction to push the drone in backward direction.
* Example Call:   Backward_Motion()
*
*/

void Backward_Motion()
{
  digitalWrite(47,LOW);
  digitalWrite(49,HIGH);
  digitalWrite(51,LOW);
  digitalWrite(53,HIGH);
  Serial.println("Backward_Motion");
}

/*
*
* Function Name:   Left_Motion()
* Input:    None
* Output:   Controls horizontal motor
* Logic:    Write high into motor pins to make the motor to rotate in a direction to push the drone towards right.
* Example Call:   Left_Motion()
*
*/


void Right_Motion()
{
  digitalWrite(47,LOW);
  digitalWrite(49,HIGH);
  digitalWrite(51,HIGH);
  digitalWrite(53,LOW);
  Serial.println("Right_Motion");
}

/*
*
* Function Name:   Left_Motion()
* Input:    None
* Output:   Controls horizontal motor
* Logic:    Write high into motor pins to make the motor to rotate in a direction to push the drone towards left.
* Example Call:   Left_Motion()
*
*/


void Left_Motion()
{
  digitalWrite(47,HIGH);
  digitalWrite(49,LOW);
  digitalWrite(51,LOW);
  digitalWrite(53,HIGH);
  Serial.println("Left_Motion");
}

/*
*
* Function Name:   Ideal_Motion()
* Input:    None
* Output:   Controls horizontal and vertical motor
* Logic:    Makes the motor to be in rest position to stop the drone in one direction.
* Example Call:   Ideal_Motion()
*
*/

void Ideal_Motion()
{
  digitalWrite(47,LOW);
  digitalWrite(49,LOW);
  digitalWrite(51,LOW);
  digitalWrite(53,LOW);
  digitalWrite(23,LOW);
  digitalWrite(27,LOW);
  digitalWrite(25,LOW);
  digitalWrite(29,LOW);
  Serial.println("Ideal Motion");
}

/*
*
* Function Name:   Run_Drone()
* Input:    None
* Output:   Controls horizontal and vertical motor according to the joystick reading.
* Logic:    Reads from the joystick and controls the drone as per the requirement.
* Example Call:   Run_Drone()
*
*/

void Run_Drone()
{
  while(1)
  {
    Read_Joystick();//Reading from joystick and operating as per requirement
    if(height > joy_threshold_max)
    {
      Increase_Height();
    }
    else
    if(height < joy_threshold_min)
    {
      Decrease_Height();
    }
    else
    if(forward > joy_threshold_max)
    {
      Forward_Motion();
    }
    else
    if(forward < joy_threshold_min)
    {
      Backward_Motion();
    }
    else
    if(turn > joy_threshold_max)
    {
      Right_Motion();
    }
    else
    if(turn < joy_threshold_min)
    {
      Left_Motion();
    }
    else
    {
      Ideal_Motion();
    }
  }
}

/*
*
* Function Name:   loop()
* Input:    None
* Output:   Continiously runs the program in a loop
* Logic:    Runs program in a loop
* Example Call:   loop()
*
*/

void loop() {
  Run_Drone();
}
