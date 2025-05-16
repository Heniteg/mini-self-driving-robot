// Naming pins from the connection

// Right side motor
const int EnableR = 5;
const int HighR = 6;
const int LowR = 7;

// Left side motor
const int EnableL = 10;
const int HighL = 9;
const int LowL = 8;

void setup() 
{
  // Setting up pinMode, for this case all are output

  // pinMode for right side motor
  pinMode(EnableR, OUTPUT);
  pinMode(HighR, OUTPUT);
  pinMode(LowR, OUTPUT);

  // pinMOde for left side motor
  pinMode(EnableL, OUTPUT);
  pinMode(HighL, OUTPUT);
  pinMode(LowL, OUTPUT);

}

// Function for forward control
void ForwardMotion()
{
  // Right motor forward
  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  
  // Left motor forward
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);

  // Setting speed from 0 - 255
  analogWrite(EnableR, 150);
  analogWrite(EnableL, 150);

}

// Function for backward control
void BackwardMotion()
{
  // Right motor forward
  digitalWrite(HighR, HIGH);
  digitalWrite(LowR, LOW);
  
  // Left motor forward
  digitalWrite(HighL, HIGH);
  digitalWrite(LowL, LOW);

  // Setting speed from 0 - 255
  analogWrite(EnableR, 150);
  analogWrite(EnableL, 150);

}

// Function for Stopping motor

void StopMotion()
{
  // Right motor stop
  digitalWrite(HighR, LOW);
  digitalWrite(LowR, LOW);
  
  // Left motor stop
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, LOW);

  // Setting speed from 0 - 255
  analogWrite(EnableR, 0);
  analogWrite(EnableL, 0);

}

void TurnLeft()
{
  // Left motor stopped and right motor moves forward
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, LOW);
  analogWrite(EnableL, 100); // tuning this value adjusts the degree of turning to the left

  digitalWrite(HighR, HIGH);
  digitalWrite(LowR, LOW);
  analogWrite(EnableR, 255);  // this is also tunable
}

void TurnRight()
{
  // Right motor stopped and left motor moves forward

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, LOW);
  analogWrite(EnableR, 100);  // this is also tunable

  digitalWrite(HighL, HIGH);
  digitalWrite(LowL, LOW);
  analogWrite(EnableL, 255); // tuning this value adjusts the degree of turning to the left

}

void TurnLeftInPlace() {
  // Left motor backward, Right motor forward
  digitalWrite(HighL, HIGH);
  digitalWrite(LowL, LOW);
  analogWrite(EnableL, 200);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR, 200);
}

void TurnRightInPlace() {
  // Left motor forward, Right motor backward
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL, 200);

  digitalWrite(HighR, HIGH);
  digitalWrite(LowR, LOW);
  analogWrite(EnableR, 200);
}

void loop() 
{
    // Testing the functions
    moving forward
    ForwardMotion();
    delay(3000);

    // Turning left
    TurnLeft();
    delay(1000);

    // Moving forward
    ForwardMotion();
    delay(3000);

    // Turning right
    TurnRight();
    delay(1000);

    // Moving backward
    BackwardMotion();
    delay(3000);

    // Stop
    StopMotion();  // Stop after forward and backward
    delay(2000);

    // testing in place left and right turn
    // TurnLeftInPlace();
    // delay(2000);
    // TurnRightInPlace();
    // delay(2000);

}
