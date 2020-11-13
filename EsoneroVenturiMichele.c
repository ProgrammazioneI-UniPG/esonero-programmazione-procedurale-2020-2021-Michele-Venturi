#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
  int i = 0;
  char testo[129];
  char key[129];
  printf("Inserire il Testo (non più lungo di 128 caratteri) da Cifrare:\n");
  fgets(testo, 129, stdin);

  // --- Controllo la lunghezza del testo
  int l = strlen(testo);
  l--;

  int scelta = 0;
  printf("Premere 1 se si desidera inserire una chiave con cui cifrare il testo;\nPremere 2 se si desidera generare randomicamente una chiave con cui cifrare il testo.\n");
  scanf("%d", &scelta);

  while(scelta!=1 && scelta!=2) { // controllo che il valore inserito non sia diverso da 1 o 2
    printf("Il Valore inserito non è valido\nPremere 1 se si desidera inserire una chiave con cui cifrare il testo;\nPremere 2 se si desidera generare randomicamente una chiave con cui cifrare il testo\n");
    scanf("%d", &scelta);
  }

  if(scelta == 1) {
    //la chiave viene inserita
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
    printf("Inserire la chiave (di lunghezza pari o superiore al testo ma inferiore a 128 caratteri) con cui cifrare il testo:\n");
    fgets(key, 128, stdin);

  } else {
    //la chiave viene generata
    int j;
    time_t t;

    srand((unsigned) time(&t));

    for(j = 0 ; j < l ; j++) {
      key[j]= rand() % 128;
    }
    printf("la chiave generata casualmente è: %s\n", key);
  }

  char cifrato[128];

  for(i=0; i<l; i++) { //cifro il testo
    cifrato[i] = testo[i] ^ key[i];
  }

  printf("il testo cifrato è: %s\n", cifrato);

  char decifrato[128];
  for(i=0; i<l; i++) { //decifro il testo
    decifrato[i] = cifrato[i] ^ key[i];
  }

  printf("il testo decifrato è: %s\n", decifrato);

  return 0;
}
