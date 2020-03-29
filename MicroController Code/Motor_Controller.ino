/*  Simple Stepper Motor Control with serial input
 *      
 *  by Ryan A Decker - LINK
 *  
 */
 
// Setup configurable parameters
const int STEP_PIN = 3; 
const int DIR_PIN = 4;
const int WINE_POUR_TIME = 4000;  // 1 second

// Motor dependent parameters
const int STEPS_PER_REV = 400;
const int STEP_DELAY = 1500;

// Define stepper directions
const bool CW = HIGH;
const bool CCW = LOW;


void setup() {
  // Sets the two pins as Outputs
  pinMode(STEP_PIN, OUTPUT); 
  pinMode(DIR_PIN, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  if(Serial.available()){
    char message[2];
    Serial.readBytes(message, 2);
    Serial.println(message);
    delay(3000);
    if(message[0] == 76){         // Left == Counter Clock Wise
      double revolutions = 0.5;
      step_clockwise(revolutions*STEPS_PER_REV); 
      delay(WINE_POUR_TIME);
      step_counter_clockwise(revolutions*STEPS_PER_REV);
    }
  }
}


void step_clockwise(int steps){
  // Set direction
  digitalWrite(DIR_PIN, CW);

  // Rotate number of steps
  for(int i = 0; i < steps; i++){
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(STEP_DELAY);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(STEP_DELAY);  
  }
}


void step_counter_clockwise(int steps){
  // Set direction
  digitalWrite(DIR_PIN, CCW);

  // Rotate number of steps
  for(int i = 0; i < steps; i++){
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(STEP_DELAY);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(STEP_DELAY);  
  }
}
