int pot = A0;
int motor = 9;
int val;
int motor_val;

void setup(){
				Serial.begin(9600);
				pinMode(pot, INPUT);
				pinMode(motor, OUTPUT);
}

void loop(){
				val = analogRead(pot);
				Serial.println(val);
				delay(20);
				
				analogWrite(motor,val);
}