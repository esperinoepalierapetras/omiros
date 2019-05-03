#include <SD.h>
#include <SoftwareSerial.h>
#define SD_ChipSelectPin 4
#include <TMRpcm.h>
#include <SPI.h>
char val;
TMRpcm ixos;
SoftwareSerial BT(6, 5);
String voice;
long randNumber;
void setup()
{
 BT.begin(9600);
 SD.begin(4);
 Serial.begin(9600);
 ixos.speakerPin = 9;
 ixos.quality(1);
 ixos.setVolume(6);
 ixos.play("intro.wav");
}
void loop() {
  while (BT.available() ){  
  delay(10); 
  char c = BT.read();
  if (c == '#') {break;}
  voice += c;
  }
if (voice.length() > 0) 
{
  if(voice == "Σεφέρης") { ixos.play("sef.wav"); voice="";} 
  else if(voice == "Ρίτσος") { ixos.play("rit.wav"); voice=""; }
  else if ((voice == "σταμάτα") || (voice == "Σταμάτα")){ ixos.disable(); voice="";}
  else if(voice == "Βάρναλης") { ixos.play("var.wav"); voice=""; }
  else if(voice == "Καβάφης") { ixos.play("kav.wav"); voice=""; }
  else if(voice == "Ελύτης") { ixos.play("el.wav"); voice=""; }
  else if(voice == "Κάλβος") { ixos.play("kal.wav"); voice=""; }
  else if(voice == "Καρυωτάκης") { ixos.play("kar.wav"); voice=""; }
  else if(voice == "εγγονόπουλος") { ixos.play("egg.wav"); voice=""; }
  else if(voice == "πολυδούρη") { ixos.play("pol.wav"); voice=""; }
  else if(voice == "Αναγνωστάκης") { ixos.play("ana.wav"); voice=""; }
  else if(voice == "Σολωμός") { ixos.play("sol.wav"); voice=""; }
  else if(voice == "βοήθεια") { ixos.play("vs.wav"); voice=""; }
  else if(voice == "Ιεράπετρα") { ixos.play("fr.wav"); voice=""; }
  else if((voice == "Ευχαριστούμε") ||(voice == "ευχαριστούμε")){ ixos.play("tel.wav"); voice=""; }
  else if((voice != "Σολωμός") ||(voice != "Αναγνωστάκης") ||(voice != "εγγονόπουλος") ||(voice != "Καρυωτάκης") ||(voice != "Σεφέρης") || (voice != "Ρίτσος") || (voice != "Βάρναλης") || (voice != "Ελύτης")|| (voice != "Καβάφης")|| (voice != "σταμάτα")|| (voice != "πολυδούρη")|| (voice != "Κάλβος")) {  lathos(); voice="";}
  voice="";}}
void lathos(){
  randNumber = random(10);
  if (randNumber == 0) {ixos.play("er01.wav");}
  else if (randNumber == 1) {ixos.play("sf.wav");}
  else if (randNumber == 2) {ixos.play("er02.wav");}
  else if (randNumber == 3) {ixos.play("sf.wav");}
  else if (randNumber == 4) {ixos.play("er03.wav");}
  else if (randNumber == 5) {ixos.play("sf.wav");}
  else if (randNumber == 6) {ixos.play("er04.wav");}
  else if (randNumber == 7) {ixos.play("sf.wav");}
  else if (randNumber == 8) {ixos.play("er02.wav");}
  else if (randNumber == 9) {ixos.play("sf.wav");}
  voice="";}
