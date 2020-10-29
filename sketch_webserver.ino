#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Scheda di Angelo";  // Enter SSID here
const char* password = "angelovoicu";  //Enter Password here

ESP8266WebServer server(80);

boolean res;

void setup() {
  Serial.begin(115200);
  res = WiFi.softAP("Scheda di Angelo", "angelovoicu");

  server.on("/", onReq);
  server.begin();

}

void loop() {
  server.handleClient();
}


void onReq() {
  const char *text = R"(
  <!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Document</title>

    <style>
      body { 
        margin: 0;
      }

      h1 {
        font-family: Helvetica, Arial, sans-serif;
        text-align: center;
        font-size: 3.5rem;
      }

      h2 {
        font-family: Helvetica, Arial, sans-serif;
        font-size: 3rem;
        margin-top: 100px;
        text-align: center;
      }
    </style>
  </head>
  <body>
    <h1>Ciao da Angelo &#x1F44B</h1>

    <h2 id="hour"></h2>

    <script>
      var el = document.querySelector("#hour");
      setInterval(() => {
        let d = new Date();
        el.innerText =
          d.getHours() + ":" + d.getMinutes() + ":" + d.getSeconds();
      }, 1000);
    </script>
  </body>
</html>)";
  
  server.send(200, "text/html", text);
}
