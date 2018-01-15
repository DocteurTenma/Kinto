#include <SPI.h>
#include <Ethernet.h>
#include <LiquidCrystal.h>

const int MOTOR = 7;
int vitMoteur = 0;


// Network and API
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 177);
EthernetServer server(80);

// Algo
int lightState = 0;
String scoreStr = "";
int scoreIsDefined = 0;
float score = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(MOTOR, OUTPUT);
  Serial.begin(9600);
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());

}


void loop() {

  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // read the command
    String command = client.readStringUntil('/');
    Serial.println(command);
    command = client.readStringUntil('/');
    Serial.println(command);

    if (command == "start") {
        Serial.println("START");
        digitalWrite(MOTOR, HIGH);
        delay(200);
    }

    if (command == "stop") {
        Serial.println("STOP");
        digitalWrite(MOTOR, LOW);
        delay(200);
    }    


    while (client.connected()) {
      if (client.available()) {
           // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          // Autorise le cross origin
          client.println("Access-Control-Allow-Origin: *");
          client.println("Content-Type: text/html");
          client.println("Ok");
          break;
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}
