/* pour yann:
 * * fais des commentaires
 * * et fais des putain de fonctions stp
*/

#include <Arduino.h>
#include "BasicStepperDriver.h"

const int capteur_inductif = 13;
const int avance = 17;
const int arriere = 16;
const int enable = 4;   //sortie PWM avec LedC pour faire varier la vitesse
const int valeur_verre = 1410;
const int valeur_plastique = 1393;
int courant = 0;
int position1 = 0;
int position2 = 0;

/* bool:
   0: false
   1: true
*/
bool bac_plastique = 0;
bool bac_verre = 0;
bool bac_metal = 0;
//position sur A4
//courant sur A5

#define MOTOR_STEPS 200
#define RPM 120

#define MICROSTEPS 1 // 1 = Full step, 2 = half step

#define DIR 15
#define STEP 2
#define ENABLE 0

BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);

// use first channel of 16 channels (started from zero)
#define LEDC_CHANNEL_0 0

#define LEDC_TIMER_13_BIT 13

#define LEDC_BASE_FREQ 10000


void setup() {
  Serial.begin(9600);

  pinMode(capteur_inductif, INPUT);
  pinMode(avance, OUTPUT);
  pinMode(arriere, OUTPUT);

  digitalWrite(avance, LOW);
  digitalWrite(arriere, LOW);

  stepper.begin(RPM, MICROSTEPS);

  ledcSetup(LEDC_CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
  ledcAttachPin(enable, LEDC_CHANNEL_0);

  Serial.println(analogRead(A4));
}
void loop() {

}

void tri() {
  //if (capteur_effort > 10 )
  position_initiale = analogRead(A4);
  while ((position_initiale < 4000) && (bac_metal != 0) && (compteur_boucle < 100)) {
    compteur++;
    position_initiale = analogRead(A4);
    if (position_initiale > 4000)
    }
  while ( analogRead(A4) < 4000 ) //*************sortie Palpeur ( capteur_inductif == 0)
  { digitalWrite(avance, HIGH);
    ledcWrite( LEDC_CHANNEL_0, 8191);   //rapport cyclique de 0 à 8191 (6000 est le minimum pour déplacer le curseur)
    courant = analogRead(A5);
    Serial.println(courant);
    delay(300);
  }
