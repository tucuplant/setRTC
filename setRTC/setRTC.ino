#include <DS3231.h>
DS3231  rtc(SDA, SCL);
void setup() {
  // put your setup code here, to run once:
 rtc.begin();
   Serial.println( "Compiled: " __DATE__ ", " __TIME__ ", " __VERSION__);
   Serial.print(rtc.getTimeStr());
   //BUCLE DE TIEMPO
   int count=0,v,h,m,s;
   char* command = strtok(__TIME__, ":");
   while (command != 0) {
      if(count==0){
        h=atoi(command); 
      }
      if(count==1){
        m=atoi(command); 
      }
      if(count==2){
        s=atoi(command); 
      }

      command = strtok(0, ":");
      count++;
   }
   //BUCLE DE TIEMPO
  rtc.setTime(h, m, s);
}

void loop() {
  // put your main code here, to run repeatedly:

}
