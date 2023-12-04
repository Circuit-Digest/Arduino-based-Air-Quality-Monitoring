#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include  <Adafruit_SSD1306.h>
#include <dht.h> 
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define  SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     4  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH,  SCREEN_HEIGHT, &Wire, OLED_RESET);

#define sensor    A0 
#define DHT11PIN 2

int gasLevel  = 0;         //int variable for gas level
String quality =""; 
dht DHT;



void sendSensor()
{
  int readData = DHT.read11(DHT11PIN);
  float h = DHT.humidity;
  float t = DHT.temperature;

  if (isnan(h) || isnan(t)) {
  Serial.println("Failed  to read from DHT sensor!");
    return;
  }
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setFont();
  display.setCursor(0, 43);
  display.println("Temp  :");
  display.setCursor(80, 43);
  display.println(t);
  display.setCursor(114, 43);
  display.println("C");
  display.setCursor(0,  56);
  display.println("RH    :");
  display.setCursor(80, 56);
  display.println(h);
  display.setCursor(114, 56);
  display.println("%");
}

void air_sensor()
{
  gasLevel = analogRead(sensor);

  if(gasLevel<151){
    quality = "  GOOD!";
  }
  else if (gasLevel >151 && gasLevel<200){
    quality =  "  Poor!";
  }
  else if (gasLevel >200 && gasLevel<300){
    quality  = "Very bad!";
  }
    else if (gasLevel >300 && gasLevel<500){
    quality  = "Toxic!";
  }
    else{
    quality = " Toxic";   
}
  
  display.setTextColor(WHITE);
  display.setTextSize(1);  
  display.setCursor(1,5);
  display.setFont();
  display.println("Air Quality:");
  display.setTextSize(1);
  display.setCursor(5,23);
  display.println(gasLevel);
  
  display.setCursor(20,23);
  display.println(quality);  
}

void setup() {
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c)) { // Address  0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
}
  display.clearDisplay();
  display.setTextColor(WHITE);
  
  display.setTextSize(2);
  display.setCursor(50, 0);
  display.println("Air");
  display.setTextSize(1);
  display.setCursor(23, 20);
  display.println("Quality monitor");
  display.display();
  delay(1200);
  display.clearDisplay();
  
  display.setTextSize(1.5);
  display.setCursor(20, 20);
  display.println("BY Circuit");
  display.setCursor(20, 40);
  display.println("Digest");
  display.display();
  delay(1000);
  display.clearDisplay();    
}

void loop() {
display.clearDisplay();
air_sensor();
sendSensor();
display.display();  
}
