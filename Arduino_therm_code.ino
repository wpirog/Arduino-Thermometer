// piny

// czujnik temperatury
#define tempRec A5
#define tempLedRed 4
#define tempLedBlue 3
#define tempLedGreen 2

// segmenty wyświetlacza
#define G 12
#define F 11
#define A 10
#define B 9
#define E 8
#define D 7
#define C 6

// wyświetlacze przez tranzystory

#define wysw_1 13
#define wysw_2 5

// diody wyświetlacza

#define wyswLedRed A1
#define wyswLedBlue A0

// setup

void setup() {
  	
  Serial.begin(9600);
  
  pinMode(tempLedRed, OUTPUT);
  pinMode(tempLedBlue, OUTPUT);
  pinMode(tempLedGreen, OUTPUT);
  pinMode(tempRec, INPUT);
  
  pinMode(G, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(C, OUTPUT);
  
  
  pinMode(wysw_1, OUTPUT);
  pinMode(wysw_2, OUTPUT);
  
 
}

void loop() {
 
  // odczyt z termometra, zamiana na celsjusze
  float tempOdczyt = analogRead(tempRec);
  float temp = ((tempOdczyt * 5) / 1024)*100 - 50;
  
  temp = round(temp);
  int temp1 = int(temp);
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print('\n');
  
  // podświetlenie diody led rgb w zależności od temperatury
  
  if (temp >= 30  && temp <= 60) {
    // zielony
    digitalWrite(tempLedRed, LOW);
    digitalWrite(tempLedGreen, HIGH);
    digitalWrite(tempLedBlue, LOW);
  }else if(temp >= 0 && temp < 30 || temp > 60 && temp <= 90) {
    // żółty
    digitalWrite(tempLedRed, HIGH);
    digitalWrite(tempLedGreen, HIGH);
    digitalWrite(tempLedBlue, LOW);
  }else if(temp < 0 || temp > 90) {
    // czerowny
    digitalWrite(tempLedRed, HIGH);
    digitalWrite(tempLedGreen, LOW);
    digitalWrite(tempLedBlue, LOW);
  }
  
  // jeśli temperatura niższa od zera, 
  // podświetla się niebieska dioda
  // (imituje minus przed wyświetlaną liczbą)
  // jeśli 100 lub powyżej, podświetla się czerwona dioda
  // (imituje liczbę setek przed wyświetlaną liczbą)
  
  if (temp >= 0 && temp < 100) {
    digitalWrite(wyswLedBlue, LOW);
    digitalWrite(wyswLedRed, LOW);
  }else if (temp < 0) {
    digitalWrite(wyswLedBlue, HIGH);
    digitalWrite(wyswLedRed, LOW);
  }else if (temp >= 100) {
    digitalWrite(wyswLedBlue, LOW);
    digitalWrite(wyswLedRed, HIGH);
  }
  
  // wyświetlenie temperatury na wyświetlaczach 7 segmentowych
  // metodą multipleksingu
  int i = 0;
  for (i = 0; i < 10; i++) {
  	wyswietlLiczbe(temp1);
    delay(100);
  }
  
 
 
}

               
//

void jeden(){
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void dwa() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void trzy() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void cztery() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void piec() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void szesc() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void siedem() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void osiem() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void dziewiec() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void zero() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void wyswietlCyfre(int cyfra) {
  switch (cyfra) {
    case 1:
    	jeden();
    	break;
    case 2:
    	dwa();
    	break;
    case 3:
    	trzy();
    	break;
    case 4:
    	cztery();
    	break;
    case 5:
    	piec();
    	break;
    case 6:
    	szesc();
    	break;
    case 7:
    	siedem();
    	break;
    case 8:
    	osiem();
    	break;
    case 9:
    	dziewiec();
    	break;
    case 0:
    	zero();
    	break;
  }
}

void odliczanie() {
 int i = 9;
 for (i = 9; i >= 0; i--) {
    wyswietlCyfre(i); 
    delay(1000);
 }

}

void odliczanieDluzsze() {
 int i = 99;
  for (i = 99; i >= 0; i--) {
    wyswietlLiczbe(i); 
    delay(100);
  }

}

void wyswietlLiczbe(int liczba) {
  
  if (liczba >= 0 && liczba < 100) {
    
  	int DZIE = liczba / 10;
  	int JEDN = liczba - DZIE*10;
  
  	wyswietlCyfre(DZIE);
  	digitalWrite(wysw_1, LOW);
  	digitalWrite(wysw_2, HIGH);
  	delay(50);
  	wyswietlCyfre(JEDN);
  	digitalWrite(wysw_1, HIGH);
  	digitalWrite(wysw_2, LOW);
  	delay(50);
  }else if (liczba < 0) {
    
    int DZIE = liczba / -10;
    int JEDN = ((-1*liczba) - DZIE*10);
    
    wyswietlCyfre(DZIE);
  	digitalWrite(wysw_1, LOW);
  	digitalWrite(wysw_2, HIGH);
  	delay(50);
  	wyswietlCyfre(JEDN);
  	digitalWrite(wysw_1, HIGH);
  	digitalWrite(wysw_2, LOW);
  	delay(50);
  }else if (liczba >= 100) {
    
    int SETK = liczba / 100;
  	int DZIE = (liczba - SETK*100) / 10;
  	int JEDN = (liczba - (SETK*100 + DZIE*10));
    
    wyswietlCyfre(DZIE);
  	digitalWrite(wysw_1, LOW);
  	digitalWrite(wysw_2, HIGH);
  	delay(50);
  	wyswietlCyfre(JEDN);
  	digitalWrite(wysw_1, HIGH);
  	digitalWrite(wysw_2, LOW);
  	delay(50);
  }
}



 
  