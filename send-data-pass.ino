
/*

   VARIABLES

   count: variable to hold count of rr peaks detected in 10 seconds

   flag: variable that prevents multiple rr peak detections in a single heatbeat

   hr: HeartRate (initialised to 72)

   hrv: Heart Rate variability (takes 10-15 seconds to stabilise)

   instance1: instance when heart beat first time

   interval: interval between second beat and first beat

   timer: variable to hold the time after which hr is calculated

   value: raw sensor value of output pin

*/
// Pour l'envoi de données
#include <TheThingsNetwork.h>
#include <TheThingsMessage.h>


// Set your AppEUI and AppKey
// Set your AppEUI and AppKey
const char *appEui = "0706050403020100";
const char *appKey = "F8326BB396FFCBCE137E796D2704CBFF";

#define loraSerial Serial1
#define debugSerial Serial

// Replace REPLACE_ME with TTN_FP_EU868 or TTN_FP_US915
#define freqPlan TTN_FP_EU868

TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

devicedata_t data = api_DeviceData_init_default;

// Pour le calcul cardiaque

long instance1 = 0, timer;

double hrv = 0,  interval = 0;
byte  hr = 72;
int value = 0, count = 0, toSend = 0;

bool flag = 0;

#define shutdown_pin 10

#define threshold 100 // to identify R peak

#define timer_value 10000 // 10 seconds timer to calculate hr

byte payload[1] ;

void setup()
{
  // setup pour l'envoi
  loraSerial.begin(57600);
  debugSerial.begin(9600);

  // Wait a maximum of 10s for Serial Monitor
  while (!debugSerial && millis() < 10000)
    ;

  debugSerial.println("-- STATUS");
  ttn.showStatus();

  debugSerial.println("-- JOIN");
  ttn.join(appEui, appKey);

  // setup pour le calcul cardiaque

  Serial.begin(9600);

  pinMode(8, INPUT); // Setup for leads off detection LO +

  pinMode(9, INPUT); // Setup for leads off detection LO -

}

void loop()
{
  //debugSerial.println("-- LOOP");


  if ((digitalRead(8) == 1) || (digitalRead(9) == 1)) {

    Serial.println("leads off!");

    digitalWrite(shutdown_pin, LOW); //standby mode

    instance1 = micros();

    timer = millis();

  }

  else {

    digitalWrite(shutdown_pin, HIGH); //normal mode

    value = analogRead(A0);

    value = map(value, 250, 400, 0, 100); //to flatten the ecg values a bit

    if ((value > threshold) && (!flag)) {

      count++;

      flag = 1;

      interval = micros() - instance1; //RR interval

      instance1 = micros();

    }

    else if ((value < threshold)) {

      flag = 0;

    }


    if ((millis() - timer) > 10000) {

      hr = count * 6;

      timer = millis();

      count = 0;

      payload[0] = hr ;

      toSend++;



    }

    if (toSend > 2)
    {
      ttn.sendBytes(payload, sizeof(payload));
      toSend=0;
    }
    Serial.print(hr);
    Serial.print(",");
    Serial.println(value);
    delay(10);
  }

}
