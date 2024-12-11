int led = 2;
int IR = 3;
int IR_Value ;

void setup(){
				Serial.begin(9600);
				pinMode(led, OUTPUT);
				pinMode(IR, INPUT);
}

void loop(){
				IR_Value = digitalRead(IR);
				if(IR_Value == HIGH){
								digitalWrite(led, HIGH);
								Serial.println("LED is on");
								delay(50);
								
				}else{
								digitalWrite(led, LOW);
								Serial.println("LED is Off");
								delay(50);
				}
}