int Pin0 = 11; //in4
int Pin1 = 10; //in3
int Pin2 = 9; //in2
int Pin3 = 8; //in1
int _step = 0; 
//boolean dir = false;// chieu motor : true(thuan kim dong ho)


int st; 
boolean dir;

//int numStep = 4096;
void setup() 
{ 
 pinMode(Pin0, OUTPUT);  
 pinMode(Pin1, OUTPUT);  
 pinMode(Pin2, OUTPUT);  
 pinMode(Pin3, OUTPUT);  
 Serial.begin(9600);
} 

//
void N(int now, int next){
    
  
  
  
  if((now==1 && next==2)||(now==3 && next==1)) { st=1; dir=false;}
  if((now==1 && next==3)||(now==2 && next==1)) { st=1; dir=true; }
  if(now==2 && next==3)                        { st=2; dir=true; }
  if(now==3 && next==2)                        { st=2; dir=false;}
  st*=1365;
while(st){
  switch(_step){ 
     case 0: 
             digitalWrite(Pin0, LOW);  
             digitalWrite(Pin1, LOW); 
             digitalWrite(Pin2, LOW); 
             digitalWrite(Pin3, HIGH); 
             break;  
     case 1: 
             digitalWrite(Pin0, LOW);  
             digitalWrite(Pin1, LOW); 
             digitalWrite(Pin2, HIGH); 
             digitalWrite(Pin3, HIGH); 
             break;  
     case 2: 
             digitalWrite(Pin0, LOW);  
             digitalWrite(Pin1, LOW); 
             digitalWrite(Pin2, HIGH); 
             digitalWrite(Pin3, LOW); 
             break;  
     case 3: 
             digitalWrite(Pin0, LOW);  
             digitalWrite(Pin1, HIGH); 
             digitalWrite(Pin2, HIGH); 
             digitalWrite(Pin3, LOW); 
             break;  
      case 4: 
             digitalWrite(Pin0, LOW);  
             digitalWrite(Pin1, HIGH); 
             digitalWrite(Pin2, LOW); 
             digitalWrite(Pin3, LOW); 
             break;  
      case 5: 
             digitalWrite(Pin0, HIGH);  
             digitalWrite(Pin1, HIGH); 
             digitalWrite(Pin2, LOW); 
             digitalWrite(Pin3, LOW); 
             break;  
     case 6: 
             digitalWrite(Pin0, HIGH);  
             digitalWrite(Pin1, LOW); 
             digitalWrite(Pin2, LOW); 
             digitalWrite(Pin3, LOW); 
             break;  
     case 7: 
             digitalWrite(Pin0, HIGH);  
             digitalWrite(Pin1, LOW); 
             digitalWrite(Pin2, LOW); 
             digitalWrite(Pin3, HIGH); 
             break;  
     default: 
             digitalWrite(Pin0, LOW);  
             digitalWrite(Pin1, LOW); 
             digitalWrite(Pin2, LOW); 
             digitalWrite(Pin3, LOW); 
             break;  
     } 
     
   if(dir)  _step++; 
   else     _step--; 

 

   if(_step>7)   _step=0; 
   if(_step<0)   _step=7; 
   st--;
   Serial.println(st);
   delay(1); 
  } 
}

 void loop() 
{ 
 N(2,3);
 while(1);
}
