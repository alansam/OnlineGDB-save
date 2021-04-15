/* With the help of Google Translate: */
/* Con l'aiuto di Google Translate: */
#include <iostream>
//serve ad indicare  la libreria di input e ouput. Iostream serve per usare cin e cout . Libreria di IO
// serves to indicate the input library and output. Iostream is for using cin and cout. Library of IO
#include <ctime>
#include<cstdlib>
#define size 20   //Definire costanti letterali /* Define literal constants */

//using namespace std;
                    //Ã¨ obbligatoria usarla in quanto indica al compilatore il linguaggio che si utilizza. 
                    // Qui si utilizza il linguaggio standard
                    // it is mandatory to use it as it tells the compiler which language is being used.
                    // The standard language is used here
// NOTE: This is absoulutely NOT true! In actualiity it's frowned upon.
// NOTA: questo NON è assolutamente vero! In realtà è disapprovato.


enum Language { IT, EN, };
//Language constexpr LANG(IT); // choose language Italian - scegli la lingua italiana
Language constexpr LANG(EN); // choose language English - scegli la lingua inglese

int main() {
  //int pretende che il programma ritorni un codice di uscita intero metterlo nella relazione di word
  // int expects the program to return an integer exit code to put it in the word relation

  // main Ã¨ la funzione principale del nostro programma
  // parentesi graffa aparte sta ad indicare apputno l'inizio (START) del nostro programma. 
  // main is the main function of our program
  // The brace apart indicates the start (START) of our program.

#ifdef IS_DOS_
  system("color 4F");
  //il primo numero (4) Ã¨ per lo sfondo, mentre il secondo (6) Ã¨ per il colore dei caratteri. I colori sono 16 in quanto esdecimale.
	//Per vedere un numero a cosa corrisponde biosgna andare su cmd e scrivere "Color" con una lettera affianco ad apparirÃ  la leggenda dei colori.
  // the first number (4) is for the background, while the second (6) is for the font color. The colors are 16 as it is hexdecimal.
	// To see a number what biosgna corresponds to go to cmd and write "Color" with a letter next to it, the legend of the colors will appear.
#endif /* IS_DOS_ */

	const int MAX = 20 ; // dimensione massima del vettore /* maximum vector size */
	int vett[MAX]; // dichiarazione del vettore /* declaration of the carrier */
	//int sta significa che la variabile Ã¨ di tipo intero che a sua volta puÃ² essere sia positivo e sia negativo
	// int sta means that the variable is of type integer which in turn can be both positive and negative

	int i; //indice dei cicli /* cycle index */
	int n; // dichiaro il numero e lo chiamo n /* I declare the number and call it n */
	int j, tmp, scelta; //tmp sta per temporaneo /* tmp stands for temporary */

	std::cout << "Alessio Capacchione" << std::endl;

  i = 0; /*<<<<<< Initialize i before the loop */ /* Inizializza i prima del ciclo */
  do {
    //utilizzo il ciclo do while per non accettare il primo numero qualora fosse inferiore ad 1
    // I use the do while loop to not accept the first number if it is less than 1
    switch (LANG) {
    default:
    case IT:
      {
  	    std::cout << "Inserisci il " << i << "esimo valore:  ";
      }
  	  break;
  	case EN:
  	  {
    	  std::cout << "Insert value " << i << ": ";
  	  }
  	  break;
    }
	  std::cin >> n;
	  //E'la funziona di input che serve a prelevare il valore dalla tastiera
	  // It is the input function used to fetch the value from the keyboard
  } while (n <= 0);
  //fino a quando il primo n numero inserito Ã¨ minore di 1, non accettarlo. 
	//ho utilizzato il do while poichÃ¨ non so si sa quando l'utente inserirÃ  un numero maggiore di 1. Sulla relazione ho messo un approfondimeno 
  // as long as the first n number entered is less than 1, don't accept it.
	// I used the do while as I don't know when the user will enter a number greater than 1. On the relation I have put a little more depth

	vett[0] = n; /* <<<<<<<<<< IMPORTANT! Save the value in the array! */ /* IMPORTANTE! Salva il valore nell'array! */

	for (i = 1; i < size; i++) {  //ciclo di riempimento del vettore /* vector fill loop */
	//i++ Ã¨ l'incremento, size Ã¨il numero degli elementi (definiti dal compilatore, in questo caso massimo 20) presenti in vettore. 
	// i++ is the increment, size is the number of elements (defined by the compiler, in this case maximum 20) present in the vector.
    switch (LANG) {
    default:
    case IT:
  	  std::cout << "Inserisci il " << i << "esimo valore: "; //visualizza in output "Inserisci il 0..1....esimo valore.
  	  break;
  	 case EN:
  	  std::cout << "Insert value " << i << ": "; // output "Enter the 0..1 .... th value.
  	  break;
    }
	  std::cin >> vett[i];
	} // viene letto vett /* viene letto vett */

  switch (LANG) {
  default:
  case IT:
    {
      std::cout << "Vettore prima di ordinare:" << std::endl;
    }
    break;
  case EN:
    {
      std::cout << "Vector befor sort:" << std::endl;
    }
    break;
  }
  auto ix(0);
  for (auto iv : vett) {
    std::cout << "[" << ix++ << "] " << iv << std::endl;
  }

	// Ordinamento del vettore  in ordine crescente
	// Sorting the vector in ascending order
  for (i = 0; i < size; i++) {
    for (j = i + 1; j < size; j++) {
      // Se Ã¨ presente un elemento piÃ¹ piccolo trovato a destra dell'array, scambiarlo.
      // If there is a smaller element found to the right of the array, swap it.
      if (vett[j] < vett[i]) {
        tmp = vett[i]; //tmp sta x temporaneo /* sta x temporary */
        vett[i] = vett[j];
        vett[j] = tmp;
      }
    }
  }
    // Leggi  la matrice ordinata in ordine crescente
    // the matrix sorted in ascending order
  switch (LANG) {
  default:
  case IT:
    {
      std::cout << "Gli elementi del vettore in ordine crescente sono:" << std::endl;
    }
    break;
  case EN:
    {
      std::cout << "vector elements in ascending order are:" << std::endl;
    }
    break;
  }
  for (i = 0; i < size; i++) {
    std::cout << "{" << i << "} " << vett[i] << std::endl;
  }

#ifdef IS_DOS_
	system("PAUSE");  // dato che la finestra al momento della fine del progranmma si chiude,si mette questo per non chiedere la finestra DOS
	// since the window closes at the end of the program, this is used to not ask for the DOS window
#endif /* IS_DOS_ */

	return 0; // valore di ritorno della funzione main /* return value of the main function */
}
// l'ultima parentesi graffa sta ad indicare la fine (END) del programma 
// the last brace indicates the end (END) of the program    
