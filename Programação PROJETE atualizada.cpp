// C++ code
//
#include <Servo.h>
#include <LiquidCrystal.h> //incluir o lcd na biblioteca
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //definir os pinos do lcd
float celsius=0; //variável para a temperatura
int tmp=0; //variável que representa o sensor de temperatura
float umidade; //variável que mostra a umidade
int trimpot; //trimpot usado para simular o sensor de umidade
int chave=0; // chave usada para mudar a programação
Servo servo;

void setup()
{
  Serial.begin(9600); //inicia o serial monitor
  servo.attach(13); // define o pino do micro servo
  lcd.begin(16,2); //inicia o lcd 16x2
  pinMode(A1,INPUT); //define o pino A1 como entrada do sensor
  pinMode(6,OUTPUT); //define o led de baixa temperatura
  pinMode(7,OUTPUT); //define o led de baixa umidade
  pinMode(8,OUTPUT); //define o led de alta temperatura
  pinMode(9,OUTPUT); //define o led de umidade em excesso
}

void loop()
{
  chave=analogRead(A2);
  tmp=analogRead(A1); //realiza a leitura do sensor de temperatura no pina A1
  float celsius = analogRead(A1); //define que a variável celsius será dada pelo sensor A1
  Serial.print("Celsius: "); //coloca "celsius" no serial monitor
  Serial.println(celsius); //coloca o valor do sensor no serial monitor
  Serial.print("chave: "); // coloca o valor da chave no serial monitor
  Serial.println(chave); // colocar o valor da chave no Serial monitor
  //umidade logo a seguir
  trimpot=analogRead(A0); //define o trimpot no pino A0
  float umidade = analogRead(A0); //define que a variável umidade será dada pelo sensor A0
  Serial.print("Nivel de umidade: "); //coloca "umidade" no serial monitor
  Serial.println(umidade); //coloca o valor do trimpot no serial monitor
  delay(500); //delay de meio segundo para os resultados
  //Programação dos Leds
  
  
  //microservo / temperatura / umidade
  if (digitalRead(9)==HIGH || digitalRead(7)==HIGH){
    servo.write(180);
  }
  else{ servo.write(0);
      }
  //leitura MILHO
  if (chave<512){
    //sensor de umidade
  if (trimpot>500){
    digitalWrite(8,1);
  }
  else { digitalWrite(8,0);
  }
  if (trimpot<200){
    digitalWrite(7,1);
  }
  else { digitalWrite(7,0);
       }
  //sensor de temperatura
  celsius= -40 + 0.488155 * (analogRead(A1) - 20);
  if (celsius<20){
    digitalWrite(6,1);
  }
  else { digitalWrite(6,0);
       }
  if (celsius>30){
    digitalWrite(9,1);
  }
  else { digitalWrite(9,0);
       }
    if (digitalRead(9)==HIGH || digitalRead(7)==HIGH){
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.write("Irrigando");
    lcd.setCursor(1,1);
    lcd.write("milho...");
    delay(1000);
  }
  else{
  lcd.clear();
  lcd.setCursor(1,1);
  lcd.write("Lendo Solo...");
  delay(1000);
  lcd.clear();
  }
}
  // LEITURA ALFACE
  if (chave>512){
    //sensor de umidade
  if (trimpot>700){
    digitalWrite(8,1);
  }
  else { digitalWrite(8,0);
  }
  if (trimpot<600){
    digitalWrite(7,1);
  }
  else { digitalWrite(7,0);
       }
  //sensor de temperatura
  celsius= -40 + 0.488155 * (analogRead(A1) - 20); //congifuração inicial do sensor de temperatura
  if (celsius<15){
    digitalWrite(6,1);
  }
  else { digitalWrite(6,0);
       }
  if (celsius>25){
    digitalWrite(9,1);
  }
  else { digitalWrite(9,0);
       }
    if (digitalRead(9)==HIGH || digitalRead(7)==HIGH){ //apresenta no LCD as ações que estão sendo feitas no momento
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.write("Irrigando");
    lcd.setCursor(1,1);
    lcd.write("alface...");
    delay(1000);
  }
  else{
  lcd.clear();
  lcd.setCursor(1,1);
  lcd.write("Lendo Solo...");
  delay(1000);
  lcd.clear(); //finaliza asa ações do LCD
  }
  }
  //Programação LCD
  
  //umidade
  lcd.setCursor(1,0); //coloca o cursor na primeira coluna do lcd e na primeira linha
  lcd.print("UR: "); //define "UR" como sigla para a umidade
  lcd.print(umidade); //mostra o valor do trimpot no lcd
  //temperatura
  lcd.setCursor(1,1); //coloca o cursor na segunda coluna do lcd e na primeira linha
  lcd.print("C: "); //define "C" como sigla para a temperatura
  lcd.print(celsius); //mostra o valor do sensor de temperatura no lcd
  delay(5000); //delay de meio segundo 
  }
