#include <WiFi.h>

const char* ssid = "Entuple2";         // Your Wi-Fi SSID
const char* password = "En!uple@2023"; // Your Wi-Fi password

const int ledPin = 2; // Built-in LED pin on most ESP32 boards

WiFiServer server(80); // Create a server on port 80

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);  // Set the LED pin as output

  // Connect to Wi-Fi
  Serial.print("Connecting to Wi-Fi: ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Status: ");
    Serial.println(WiFi.status());  // Print status codes
  }

  Serial.println("\nConnected to Wi-Fi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());  // Print the IP address

  server.begin();  // Start the web server
}

void loop() {
  WiFiClient client = server.available(); // Listen for incoming clients

  if (client) {
    String request = "";
    while (client.available()) {
      request += (char)client.read(); // Read the incoming data
    }

    Serial.println(request); // Print the request for debugging

    // Check for "GET" requests to control the LED
    if (request.indexOf("/on") != -1) {
      digitalWrite(ledPin, HIGH);  // Turn LED ON
    }
    if (request.indexOf("/off") != -1) {
      digitalWrite(ledPin, LOW);   // Turn LED OFF
    }

    // Send the response to the client
    client.print("HTTP/1.1 200 OK\r\n");
    client.print("Content-Type: text/html\r\n");
    client.print("\r\n");
    client.print("<html><body>");
    client.print("<h1>LED Control</h1>");
    client.print("<a href=\"/on\"><button>Turn ON</button></a><br><br>");
    client.print("<a href=\"/off\"><button>Turn OFF</button></a><br><br>");
    client.print("</body></html>");

    delay(1);  // Wait for the client to receive the response
    client.stop();  // Close the connection
  }
}


