// Luxmetro WiFi   by Stefano Maiocchi - Vigevano (PV)
// Usa WeMos D1 mini basata su ESP-8266
// Usa WeMos OLED Shield 64x48 pixel 0,66 pollici  interfaccia I2C
// Usa il sensore di luce MAX44009 range:0-188000 lux  interfaccia: I2C
// Crea un Access Point WiFi e lo usa come Web Server
// Vai a http://192.168.4.1 in un browser su un dispositivo connesso a
// questo Accesso Point per vederlo
 
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

#include <Wire.h>           // Display e sensore luce usano I2C
#include <SFE_MicroOLED.h>  // Libreria usata dal display
#include <MAX44009.h>       // Libreria usata dal sensore di luce

const char *ssid = "LUXMETRO";   // nome dell'Access Point
//const char *password = "lux";  // eventuale password

#define PIN_RESET 255       // usato dal display
#define DC_JUMPER 0         // indirizzo I2C display : 0 = 0x3C, 1 = 0x3D

ESP8266WebServer server(80);              // Dichiarazione AP WebServer
MicroOLED oled(PIN_RESET, DC_JUMPER);     // Dichiarazione display
MAX44009 light;                           // Dichiarazione sensore luce


// Crea la stringa HTML per il browser
void invialux() {
  String valorelux = "<h1>LUX : <b>";
  valorelux += String(int(light.get_lux()));
  valorelux += "</b></h1>";
  server.send(200, "text/html", "<h1>LUXMETRO</h1>" + valorelux );
}

int middleX = oled.getLCDWidth() / 2;     // Centro orizzontale display

void setup()
{
  oled.begin();      // Inizializza display
  oled.clear(ALL);   // Pulisce memoria display
  light.begin();     // Inizializza sensore luce

  WiFi.softAP(ssid);             // Crea Access Point senza password
//  WiFi.softAP(ssid, password); // se usi la password aggiungi il parametro password
  server.begin();                // Avvia il server
}
 
void loop()
{
  server.handleClient();
  server.on("/", invialux); // invia la stringa HTML per il browser
  oled.clear(PAGE);         // Pulisce pagina display
  oled.line(0,0,63,0);      // Disegna bordo superiore
  oled.line(63,0,63,47);    // Disegna bordo destro
  oled.line(63,47,0,47);    // Disegna bordo inferiore
  oled.line(0,47,0,0);      // Disegna bordo sinistro
  oled.setFontType(1);      // Uso font tipo 1 8x16
  oled.setCursor(20,5);     // Posiziona cursore in alto e semicentrato
  oled.print("LUX");        // Scrive il testo LUX
                            // Posiziona cursore in terza linea e centrato
  oled.setCursor((middleX - (oled.getFontWidth() * (String(int(light.get_lux())).length()/2)) - 2), 26);
  oled.print(int(light.get_lux()));    // Scrive il valore intero di luce espresso in lux
  oled.display();           // Aggiorna il display 
  delay(1000);              // Pausa 1 secondo
}
