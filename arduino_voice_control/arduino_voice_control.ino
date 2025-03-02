String readvoice="";
char flag;

void setup() {
Serial.begin(9600);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);

}
//-----------------------------------------------------------------------//
void loop()
{
while (Serial.available())
{
char c = Serial.read(); //Conduct a serial read
readvoice += c; //build the string-"*forward#","reverse","left'and"right"
if(c =='#')flag=1;
}

if(flag)
{
flag=0;
Serial.print(readvoice);
if(readvoice.indexOf("forward")>=0)
{
Serial.print("MY ROBO");
digitalWrite(9, HIGH);

digitalWrite (12, HIGH);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
delay(100);
}

else if(readvoice.indexOf("back")>=0)
{
digitalWrite(9, LOW);
digitalWrite(12, LOW);
digitalWrite(10, HIGH);
digitalWrite(11,HIGH);

delay(100);
}

else if (readvoice.indexOf("left")>=0)
{
digitalWrite (9,HIGH);
digitalWrite (12,LOW);
digitalWrite (11,LOW);
digitalWrite (10,LOW);
delay (800);
digitalWrite(9, HIGH);
digitalWrite (12, HIGH);
digitalWrite(11,LOW);
digitalWrite(10,LOW);

delay(100);
}

else if ( readvoice.indexOf("right")>=0)
{
digitalWrite (12,HIGH);
digitalWrite (9,LOW);
digitalWrite (11,LOW);
digitalWrite (10,LOW);
delay (800);
digitalWrite(9, HIGH);
digitalWrite (12, HIGH);
digitalWrite(11,LOW);
digitalWrite(10,LOW);
delay(100);
}

else if (readvoice.indexOf("stop")>=0)
{
digitalWrite (9, LOW);
digitalWrite (10, LOW);
digitalWrite (11, LOW);
digitalWrite (12, LOW);

delay (100);
}

else
{
Serial.println("Not Matched");
}

readvoice="";
}
} //Reset the variable
