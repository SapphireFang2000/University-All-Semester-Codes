int object_distance = 0;

int door_status = 0;

long readUltrasonicDistance(int pin)
{
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);

  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  
  return pulseIn(pin, HIGH);
}

void setup()
{
  pinMode(3, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  object_distance = 0;

  object_distance = 0.01723 * readUltrasonicDistance(3);
  if (object_distance < 100) 
  {
    if (door_status < 1) 
    {  
      digitalWrite(5, HIGH);   
      digitalWrite(6, LOW);
      digitalWrite(13, HIGH); 
      delay(5000);            
      digitalWrite(5, LOW);    
      door_status = 1;    
    }
  }
  else {
    if (door_status > 0) 
    {     
      digitalWrite(13, LOW);   
      delay(1000);             
      digitalWrite(5, LOW);    
      digitalWrite(6, HIGH);
      delay(5000);           
      digitalWrite(6, LOW);
      door_status = 0;      
    }
  }
}

