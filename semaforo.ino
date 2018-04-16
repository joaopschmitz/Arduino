  //PROGRAMA SEMAFORO CONTROLADO POR INTERRUPÇÃO EXTERNA
  //DECLARAÇÃO DE VARIAVÉIS GLOBAIS
  int movimento1; //contagem de carros na via 1
  int movimento2; // contagem de carro na via 2
  int interrupcao1 = 2; // pino da interrupção 1
  int interrupcao2 = 3; // pino da interrupção 2
  int ledverde1 = 1; // pino do led verde semaforo1
  int ledverde2 = 4; // pino do led verde semaforo2
  int ledamarelo1 = 5; // pino do led amarelo semaforo1
  int ledamarelo2 = 6; // pino do led amarelo semaforo2
  int ledvermelho1 = 7; // pino do led vermelho semaforo1
  int ledvermelho2 = 8; // pino do led vermelho semaforo2
  float relacao;
  
  int tempomin = 60000; // tempo de delay 1 min 60000 milisegundos
  int temporelacao;
  
  void setup() {
  
  
  pinMode(interrupcao1, INPUT); // declarando os pinos de interrupção como entradas
  pinMode(interrupcao2, INPUT); // declarando os pinos de interrupção como entradas
  pinMode(ledverde1, OUTPUT); // declarando as portas de saída dos leds
  pinMode(ledverde2, OUTPUT); // declarando as portas de saída dos leds
  pinMode(ledamarelo1, OUTPUT); // declarando as portas de saída dos leds
  pinMode(ledamarelo2, OUTPUT); // declarando as portas de saída dos leds
  pinMode(ledvermelho1, OUTPUT); // declarando as portas de saída dos leds
  pinMode(ledvermelho2, OUTPUT); // declarando as portas de saída dos leds

  attachInterrupt(digitalPinToInterrupt(interrupcao1), contagem1, RISING);
  attachInterrupt(digitalPinToInterrupt(interrupcao2), contagem2, RISING);


}

void loop() {
  //CÓDIGO PARA FICAR NO LOOP SEMAFOROS LIGADOS DEPENDENDO DA PASSAGEM DOS VEÍCULOS

  if(movimento1>movimento2){
    relacao = movimento1/movimento2;
    movimento1 = 0;
    movimento2 = 0;
    temporelacao = relacao*tempomin;
    
  // SEMAFORO 1 VERDE 2 VERMELHO
    // Semaforo 1
  digitalWrite(ledverde1, HIGH);
  digitalWrite(ledamarelo1, LOW); 
  digitalWrite(ledvermelho1, LOW);

  // Semaforo 2
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledamarelo2, LOW); 
  digitalWrite(ledvermelho2, HIGH);
  
  // delay igual para ambos os semaforos
  delay(temporelacao);

  // SEMAFORO 1 AMARELO 2 VERMELHO
    // Semaforo 1
  digitalWrite(ledverde1, LOW);
  digitalWrite(ledamarelo1, HIGH); 
  digitalWrite(ledvermelho1, LOW);

  // Semaforo 2
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledamarelo2, LOW); 
  digitalWrite(ledvermelho2, HIGH);
  
  // delay igual para ambos os semaforos
  delay(3000); //coloquei 3 segundos no amarelo

  // SEMAFORO 1 VERMELHO 2 VERDE
    // Semaforo 1
  digitalWrite(ledverde1, LOW);
  digitalWrite(ledamarelo1, LOW); 
  digitalWrite(ledvermelho1, HIGH);

  // Semaforo 2
  digitalWrite(ledverde2, HIGH);
  digitalWrite(ledamarelo2, LOW); 
  digitalWrite(ledvermelho2, LOW);
  
  // delay igual para ambos os semaforos
  delay(tempomin); //semaforo 2 tem menos movimento logo fica menos tempo no verde

  // SEMAFORO 1 VERMELHO 2 AMARELO
    // Semaforo 1
  digitalWrite(ledverde1, LOW);
  digitalWrite(ledamarelo1, LOW); 
  digitalWrite(ledvermelho1, HIGH);

  // Semaforo 2
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledamarelo2, HIGH); 
  digitalWrite(ledvermelho2, LOW);
  
  // delay igual para ambos os semaforos
  delay(3000);
    
    }
   else if (movimento2>movimento1){
    relacao = movimento2/movimento1;
    movimento1 = 0;
    movimento2 = 0;
    temporelacao = relacao*tempomin;
    
  // SEMAFORO 1 VERDE 2 VERMELHO
    // Semaforo 1
  digitalWrite(ledverde1, HIGH);
  digitalWrite(ledamarelo1, LOW); 
  digitalWrite(ledvermelho1, LOW);

  // Semaforo 2
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledamarelo2, LOW); 
  digitalWrite(ledvermelho2, HIGH);
  
  // delay igual para ambos os semaforos
  delay(tempomin);

  // SEMAFORO 1 AMARELO 2 VERMELHO
    // Semaforo 1
  digitalWrite(ledverde1, LOW);
  digitalWrite(ledamarelo1, HIGH); 
  digitalWrite(ledvermelho1, LOW);

  // Semaforo 2
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledamarelo2, LOW); 
  digitalWrite(ledvermelho2, HIGH);
  
  // delay igual para ambos os semaforos
  delay(3000); //coloquei 3 segundos no amarelo

  // SEMAFORO 1 VERMELHO 2 VERDE
    // Semaforo 1
  digitalWrite(ledverde1, LOW);
  digitalWrite(ledamarelo1, LOW); 
  digitalWrite(ledvermelho1, HIGH);

  // Semaforo 2
  digitalWrite(ledverde2, HIGH);
  digitalWrite(ledamarelo2, LOW); 
  digitalWrite(ledvermelho2, LOW);
  
  // delay igual para ambos os semaforos
  delay(temporelacao); //semaforo 2 tem menos movimento logo fica menos tempo no verde

  // SEMAFORO 1 VERMELHO 2 AMARELO
    // Semaforo 1
  digitalWrite(ledverde1, LOW);
  digitalWrite(ledamarelo1, LOW); 
  digitalWrite(ledvermelho1, HIGH);

  // Semaforo 2
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledamarelo2, HIGH); 
  digitalWrite(ledvermelho2, LOW);
  
  // delay igual para ambos os semaforos
  delay(3000);
    }
   else{ //caso quando movimento1=movimento2
    // o tempo usado nos dois semaforos será o tempo minimo
    movimento1 = 0;
    movimento2 = 0;
    
    
  // SEMAFORO 1 VERDE 2 VERMELHO
    // Semaforo 1
  digitalWrite(ledverde1, HIGH);
  digitalWrite(ledamarelo1, LOW); 
  digitalWrite(ledvermelho1, LOW);

  // Semaforo 2
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledamarelo2, LOW); 
  digitalWrite(ledvermelho2, HIGH);
  
  // delay igual para ambos os semaforos
  delay(tempomin);

  // SEMAFORO 1 AMARELO 2 VERMELHO
    // Semaforo 1
  digitalWrite(ledverde1, LOW);
  digitalWrite(ledamarelo1, HIGH); 
  digitalWrite(ledvermelho1, LOW);

  // Semaforo 2
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledamarelo2, LOW); 
  digitalWrite(ledvermelho2, HIGH);
  
  // delay igual para ambos os semaforos
  delay(3000); //coloquei 3 segundos no amarelo

  // SEMAFORO 1 VERMELHO 2 VERDE
    // Semaforo 1
  digitalWrite(ledverde1, LOW);
  digitalWrite(ledamarelo1, LOW); 
  digitalWrite(ledvermelho1, HIGH);

  // Semaforo 2
  digitalWrite(ledverde2, HIGH);
  digitalWrite(ledamarelo2, LOW); 
  digitalWrite(ledvermelho2, LOW);
  
  // delay igual para ambos os semaforos
  delay(tempomin); //semaforo 2 tem menos movimento logo fica menos tempo no verde

  // SEMAFORO 1 VERMELHO 2 AMARELO
    // Semaforo 1
  digitalWrite(ledverde1, LOW);
  digitalWrite(ledamarelo1, LOW); 
  digitalWrite(ledvermelho1, HIGH);

  // Semaforo 2
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledamarelo2, HIGH); 
  digitalWrite(ledvermelho2, LOW);
  
  // delay igual para ambos os semaforos
  delay(3000);
    }

}

void contagem1() {
 movimento1 = ++movimento1;
  }

void contagem2() {
 movimento2 = ++movimento2;
  }
