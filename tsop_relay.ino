
int flag1=1,flag2=1,flag3=1;


void setup()  
{  
  pinMode(15,INPUT); // TSOP is connected on the 15ht pin
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);  
}  


void loop()  
{  
  int remote_val = remote();  
  if(remote_val>0)  
  {  
    Serial.println(remote_val);  
    //delay(1500); // A remote press will normally generate 3 signal trains. This is to avoid reading duplicates  

    if(remote_val==128)*// to check which of the button is pressed
    {
      if(flag1==1)
      {
        digitalWrite(5,1);
        delay(500);
      }
      if(flag1==-1)
      {
        digitalWrite(5,0);
        delay(500);
      }
     flag1=flag1*-1;// to have data of on/off
    }
    if(remote_val==129)
    {
      if(flag2==1)
      {
        digitalWrite(6,1);
        delay(500);
      }
      if(flag2==-1)
      {
        digitalWrite(6,0);
        delay(500);
      }
     flag2=flag2*-1;
    }
    if(remote_val==130)
    {
      if(flag3==1)
      {
        digitalWrite(7,1);
        delay(500);
      }
      if(flag3==-1)
      {
        digitalWrite(7,0);
        delay(500);
      }
      flag3=flag3*-1;
    }
  }
  delay(1000);
} 



int remote()  
{  
  int value = 0;  
  int time = pulseIn(15,LOW);  
  if(time>2000) // Checking if the Start Bit has been received. Start Bit Duration is 2.4ms  
  {  
    for(int counter1=0;counter1<12;counter1++) // A loop to receive the next 12 bits  
    {  
      if(pulseIn(15,LOW)>1000) // checking the duration of each pulse, if it is a '1' then we use it in our binary to decimal conversion, '0's can be ignored.  
      {  
        value = value + (1<< counter1);// binary to decimail conversion. 1<< i is nothing but 2 raised to the power of i  
      }  
    }  
  }  
  return value;  
}  


