/*
  De manera burda se envia un mensaje del MPU-6050
  via Osc a Processing
*/
#include "Wire.h"

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>

#define LED_BUILTIN 2

//_______________________________start Wireless parameters
/* Nombre de la red y Contraseña */
char ssid[] = "RED_55f";          // your network SSID (name)
char pass[] = "ps1c0s0m4t1c0o";         // your network password


WiFiUDP Udp;                                // A UDP instance to let us send and receive packets over UDP

/* YOU WILL NEED TO CHANGE THIS TO YOUR COMPUTER'S IP! */
const IPAddress outIp(192, 168, 1, 118);     // remote IP of your computer
//const IPAddress outIp(192, 168, 1, 117);     // remote IP of your computer

//this should match the port to listen on in the python sketch
const unsigned int outPort = 8000;          // remote port to receive OSC
const unsigned int localPort = 11500;        // local port to listen for OSC packets (actually not used for sending)

//_______________________________end of Wireless



int buttonA = D1;
int buttonB = D2;
int buttonC = D5;

int valorA = 0;
int valorB = 0;
int valorC = 0;

int estado = 0;
int estadoPrevio = 5;

bool finaliza = false;

void setup() {

  Serial.begin (57600);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  //wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Starting UDP");
  Udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(Udp.localPort());



  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
  pinMode(buttonC, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  valorA = digitalRead(buttonA);
  delay (100);
  valorB = digitalRead(buttonB);
  delay (100);
  valorC = digitalRead(buttonC);
  delay (100);

  imprimeValores();
  condicionales();
  enviaDatosOSC ();

  delay (1000);
}

void imprimeValores()
{
  Serial.print("valorA es:_");
  Serial.println(valorA);
  Serial.print("valorB es:_");
  Serial.println(valorB);

  Serial.print("valorC es:_");
  Serial.println(valorC);

  Serial.print("valor de estado es:___");
  Serial.println(estado);
  Serial.print("valor de estadoPrevio is__");
  Serial.println(estadoPrevio);

}

void condicionales ()
{

  if (valorA == 0 && valorB == 0 && valorC == 0) //reposo
  {
    Serial.println("estado__0");
    estado = 1;
  }

  if (valorA == 1 && valorB == 0 && valorC == 0) // Hoja _1
  {
    Serial.println("estado__1");
    estado = 2;
  }

  if (valorB == 1  && valorA == 1 && valorC == 0) // Hoja _2
  {
    Serial.println("estado__2");
    estado = 3;

  }

  if (valorA == 1 && valorB == 1 && valorC == 1) // Hoja _3
  {
    Serial.println("estado__3");
    estado = 4;
  }
}


void enviaDatosOSC ( )
{
  if (estado != estadoPrevio) {
    lectorCasos();
    estadoPrevio = estado;

  }
}

void lectorCasos() {

  switch (estado) {
    case 1:
      OSCcaso_1();
      break;

    case 2:
      OSCcaso_2();
      break;

    case 3:
      OSCcaso_3();
      break;

    case 4:
      OSCcaso_4();
      break;

    default:
      Serial.println("_");
      break;

  }
}



void OSCcaso_1() {
  Serial.println("sending message estado 1...");

  OSCMessage msg0("/layer3/clip1/connect");
  msg0.add( 1);
  Udp.beginPacket(outIp, outPort);
  msg0.send(Udp);
  Udp.endPacket();
  msg0.empty();

  OSCMessage msg1("/layer2/clip1/connect");
  msg1.add( 1);
  Udp.beginPacket(outIp, outPort);
  msg1.send(Udp);
  Udp.endPacket();
  msg1.empty();

  OSCMessage msg2("/layer1/clip1/connect");
  msg2.add( 1);
  Udp.beginPacket(outIp, outPort);
  msg2.send(Udp);
  Udp.endPacket();
  msg2.empty();
}

void OSCcaso_2() {
  Serial.println("sending message estado 2...");

  OSCMessage msg3("/layer3/clip2/connect");
  msg3.add( valorA);
  Udp.beginPacket(outIp, outPort);
  msg3.send(Udp);
  Udp.endPacket();
  msg3.empty();

  OSCMessage msg4("/layer2/clip2/connect");
  msg4.add( valorA);
  Udp.beginPacket(outIp, outPort);
  msg4.send(Udp);
  Udp.endPacket();
  msg4.empty();

  OSCMessage msg5("/layer1/clip2/connect");
  msg5.add( valorA);
  Udp.beginPacket(outIp, outPort);
  msg5.send(Udp);
  Udp.endPacket();
  msg5.empty();
}

void OSCcaso_3() {
  Serial.println("sending message estado 3...");


  OSCMessage msg6("/layer3/clip3/connect");
  msg6.add( valorB);
  Udp.beginPacket(outIp, outPort);
  msg6.send(Udp);
  Udp.endPacket();
  msg6.empty();

  OSCMessage msg7("/layer2/clip3/connect");
  msg7.add( valorB);
  Udp.beginPacket(outIp, outPort);
  msg7.send(Udp);
  Udp.endPacket();
  msg7.empty();


  OSCMessage msg8("/layer1/clip3/connect");
  msg8.add( valorB);
  Udp.beginPacket(outIp, outPort);
  msg8.send(Udp);
  Udp.endPacket();
  msg8.empty();



}

void OSCcaso_4() {
  Serial.println("sending message estado 4...");


  OSCMessage msg9("/layer3/clip4/connect");
  msg9.add( valorC);
  Udp.beginPacket(outIp, outPort);
  msg9.send(Udp);
  Udp.endPacket();
  msg9.empty();

  OSCMessage msg10("/layer2/clip4/connect");
  msg10.add( valorC);
  Udp.beginPacket(outIp, outPort);
  msg10.send(Udp);
  Udp.endPacket();
  msg10.empty();


  OSCMessage msg11("/layer1/clip4/connect");
  msg11.add( valorC);
  Udp.beginPacket(outIp, outPort);
  msg11.send(Udp);
  Udp.endPacket();
  msg11.empty();

}



