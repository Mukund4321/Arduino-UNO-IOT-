
#include <DHT.h>

#define DHTPIN 2

#define DHTTYPE    DHT11    


DHT dht(DHTPIN, DHTTYPE);




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature = dht.readTemperature();
  float Humidity = dht.readHumidity();
  Serial.print("temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(Humidity);

  delay(2000); 
}
