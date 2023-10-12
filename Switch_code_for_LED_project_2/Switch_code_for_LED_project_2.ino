
const int red_led_pin =  9;
const int green_led_pin =  10;
const int blue_led_pin =  11;

void setup() {
  Serial.begin(9600);
  pinMode(red_led_pin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char terminationChar = '\n'; // Define the termination character
    String receivedString = Serial.readStringUntil(terminationChar);
    // Serial.println("Received: " + receivedString);
    // Process the receivedString as needed

    if((receivedString+terminationChar) == "1\n"){
      digitalWrite(red_led_pin, HIGH);
    }
    else
    {
      digitalWrite(red_led_pin, LOW);
    }
  }
}
