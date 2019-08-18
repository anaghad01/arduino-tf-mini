int dist;
int data[9];
int i;
int err;
int pre=0;

void setup() {
Serial.begin(9600);
}

void loop() {

while(1)//check for condition
   {
      while(!Serial.available())
      {}
      data[0]=Serial.read();
      if(data[0]==89)//ascii value of Y
      {
         while(!Serial.available())
         {}
         data[1]=Serial.read();
         if(data[1]==89)
          {
            for(i=2;i<9;i++) 
            {
                while(!Serial.available()){}
                data[i]=Serial.read();
            }
            dist=(data[3]<<8)|data[2];
            err=dist-pre;
            err=abs(err);
            if(err>100)//avoid garbage values 
            {}
            else if(dist<=0)//negative values and zero skipped
            {}
            else
            {
              Serial.println(dist);
            }
            break;
         }                  
      }
   }
}
