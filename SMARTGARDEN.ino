// PROGRAM SMART GARDEN  
#define ldr A0 // input sinyal resistansi cahaya 
#define led D1 // output lampu taman 
#define water D7 // input kelembapan tanah 
#define relay D2 // output relay 


void setup() {
  pinMode(led,OUTPUT); // output lampu taman 
  pinMode(ldr,INPUT); // input sinyal ldr
  pinMode(relay,OUTPUT); //output pin for relay board, this will sent signal to the relay
  pinMode(water,INPUT); // output kelembapan tanah 
  // put your setup code here, to run once:

}

void loop() {
Serial.begin(9600);
int cahaya = analogRead(ldr); // mengdeklarasikan variabel cahaya sebagai analog read dari sensor ldr 
int soil = digitalRead(water); // mengdeklarasikan variabel cahaya sebagai analog read dari sensor soil moisture 

if(cahaya > 600) // jika resistansi lebih besar dari 600
   {
  digitalWrite(led,HIGH); // pin digital akan menulis perintah bahwa output led menyala 
  Serial.println("lampu taman menyala"); // serial monitor akan memunculkan 
  }
  else // jika resistansi di bawah 600
  {
 digitalWrite(led,LOW); //pin digital akan menulis perintah bahwa output led mati 
  Serial.println("lampu taman mati"); // serial monitor akan memunculkan 
  }
   if(soil == HIGH) // jika sensor soil moisture membaca tanah lembab
   {
  digitalWrite(relay,LOW); // pin digital akan memberi perintah menyalakan relay SPDT
  Serial.println("siram"); // serial monitor akan memunculkan
  }
  else // jika sensor soil moisture tidak membaca tanah kering 
  {
  digitalWrite(relay,HIGH); // pin digital akan memberikan perintah mematikan relay 
  Serial.println("tidak di siram"); // serial monitor akan memunculkan
  }
  delay(100); // delay program 
  }

