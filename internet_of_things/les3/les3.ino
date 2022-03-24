/*  
 *   Mediacollege Duurzaam huis BO
 *   Les 3
 *   Connectie met internet  
 *   Webserver
 *   Leds On Off
*/
// web server



#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
ESP8266WebServer server(80); // maak een instantie van de webserver op poort 80

//LED pins
uint8_t Led1 = D3; //LED indicator 
uint8_t Led2 = D5; //LED indicator
uint8_t Led3 = D6; //LED indicator

bool led1Status = false; //toggle led on/off
bool led2Status = false; //toggle led on/off
bool led3Status = false; //toggle led on/off

// your data
String studentName = "Nabil 33580"; // jouw student nummer + naam

const char* ssid = "Medialab";
const char* password = "Mediacollege2";

void wifiConnect(){
  WiFi.begin(ssid, password); // connect to wifi ssid with password 
  while (WiFi.status() != WL_CONNECTED) {
      delay(1000); // wait 1 sec
      Serial.print("Connecting..");
      }
  //if connected
  Serial.print("\r\nConnected: SSID: "); 
  Serial.print(ssid);
  Serial.print("    IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
  Serial.println("HTTP server started");
 }

void handleRoot() {server.send(200, "text/html", "<h3>Groetjesvan DuurzaamHuis! mijnnaam is: " +  studentName+  "<h3> <form action=\"/led1\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led1\"></form> " + "<form action=\"/led2\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led2\"></form> " +"<form action=\"/led3\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led3\"></form> ");    }

void handleNotFound(){
  String message = "File Not Found\n\n";
  server.send(404, "text/plain", message);
}

void setup(){
  pinMode(Led1, OUTPUT);     // Initialize the pin as an output
  pinMode(Led2, OUTPUT);     // Initialize the pin as an output
  pinMode(Led3, OUTPUT);     // Initialize the pin as an output
 
  Serial.begin(115200);      //  Start de serial monitor

/*
 * Webserver functionaliteit
 *  server.on("/"
 *  server.on("/easter_egg"
 *  server.on("/led1"
 *  server.onNotFound
 *  server.on("/led1"
 */
  server.on("/", handleRoot);

  server.on("/easter_egg", [](){
        server.send(200, "text/plain", "Liban");
    });

  server.on("/led1", [](){
       if(!led1Status && !digitalRead(Led1)){
         {server.send(200, "text/html", "<h3>Groetjesvan DuurzaamHuis! mijnnaam is: " +  studentName+  "<h3> <form action=\"/led1\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led1\"></form> " + "<form action=\"/led2\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led2\"></form> " +"<form action=\"/led3\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led3\"></form> ");    }
          digitalWrite(Led1, HIGH); // led 1 on
          led1Status = true;
          
        }else{
        {server.send(200, "text/html", "<h3>Groetjesvan DuurzaamHuis! mijnnaam is: " +  studentName+  "<h3> <form action=\"/led1\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led1\"></form> " + "<form action=\"/led2\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led2\"></form> " +"<form action=\"/led3\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led3\"></form> ");    }
        digitalWrite(Led1, LOW); // led 1 on
        led1Status = false;
       }    
    });

    server.on("/led2", [](){
        if(!led1Status && !digitalRead(Led2)){
         {server.send(200, "text/html", "<h3>Groetjesvan DuurzaamHuis! mijnnaam is: " +  studentName+  "<h3> <form action=\"/led1\" method=\"
         GET\"><input type=\"submit\" value=\"Toggle Led1\"></form> " + "<form action=\"/led2\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led2\"></form> " +"<form action=\"/led3\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led3\"></form> ");    }
          digitalWrite(Led2, HIGH); // led 1 on
          led1Status = true;
          
        }else{
        {server.send(200, "text/html", "<h3>Groetjesvan DuurzaamHuis! mijnnaam is: " +  studentName+  "<h3> <form action=\"/led1\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led1\"></form> " + "<form action=\"/led2\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led2\"></form> " +"<form action=\"/led3\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led3\"></form> ");    }
        digitalWrite(Led2, LOW); // led 1 on
        led1Status = false;
       }  
    });

    server.on("/led3", [](){
        if(!led1Status && !digitalRead(Led3)){
         {server.send(200, "text/html", "<h3>Groetjesvan DuurzaamHuis! mijnnaam is: " +  studentName+  "<h3> <form action=\"/led1\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led1\"></form> " + "<form action=\"/led2\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led2\"></form> " +"<form action=\"/led3\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led3\"></form> ");    }
          digitalWrite(Led3, HIGH); // led 1 on
          led1Status = true;
          
        }else{
        {server.send(200, "text/html", "<h3>Groetjesvan DuurzaamHuis! mijnnaam is: " +  studentName+  "<h3> <form action=\"/led1\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led1\"></form> " + "<form action=\"/led2\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led2\"></form> " +"<form action=\"/led3\" method=\"GET\"><input type=\"submit\" value=\"Toggle Led3\"></form> ");    }
        digitalWrite(Led3, LOW); // led 1 on
        led1Status = false;
       }  
    });

    


  server.onNotFound(handleNotFound);
}

void loop(){
  if (WiFi.status() != WL_CONNECTED) wifiConnect();// reconnect Wifi if necessary 
  server.handleClient();
}
