
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string> //la libreria string a volte può anche non essere utilizzata ma è meglio se la si mette

#define size 2

using namespace std;

void menu();
void riempimento (string n[], string c[], string tc[], string ce[], string ic[], string ie[], int taglia);
void visualizza (string n[], string c[], string tc[], string ce[], string ic[], string ie[], int taglia);
void bsort (string n[], string c[], string tc[], string ce[], string ic[], string ie[], int taglia);
void ricerca(string ricercato_nome, string ricercato_cognome, string n[], string c[], string tc[], string ce[], string ic[], string ie[], int taglia);
void elimina(string n[], string c[], string tc[], string ce[], string ic[], string ie[], int taglia);
void modifica(string n[], string c[], string tc[], string ce[], string ic[], string ie[], int taglia);

int main() {
	//srand(time(NULL));
	int scelta, i;

  string nome[size], cognome[size], telefono_casa[size], cellulare[size], indirizzo_casa[size], indirizzo_mail[size];
  riempimento(nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail, size);

	cout << "\n\n Hai inserito:\n";
	visualizza(nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail, size);
	bsort(nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail, size);

	cout << "\n\nTe li ho ordinati cosi':\n";
  visualizza(nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail, size);

  do {
  	cout << endl;
    cout << "Inserisci l'azione che vuoi eseguire" << endl;
    cout << "1.Aggiungi il numero telefonico" << endl;
    cout << "2.Visualizza la rubrica telefonica" << endl;
    cout << "3.Ricerca un contatto" << endl;
    cout << "4.Modifica un contatto" << endl;
    cout << "5.Elimina un contatto" << endl;
    cout << "6.esci dal programma" << '\n' << endl;
    cin >> scelta;

    switch (scelta) {
      case 1:
        riempimento(nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail, size);
      	bsort(nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail, size); //  put the arrays back in order
        // system("pause");
        break;

      case 2:
        visualizza(nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail, size);
        // system("pause");
        break;

      case 3:
      {
        cout << "\nQuale contatti vorresti cercare?\n";
	      string ricercato_nome;
        string ricercato_cognome;
        cout << "nome? ";
       	cin >> ricercato_nome;
        cout << "cognome? ";
       	cin >> ricercato_cognome;
       	ricerca(ricercato_nome, ricercato_cognome, nome, cognome, telefono_casa, cellulare, indirizzo_casa, indirizzo_mail, size);
        break;
      }
	     // return 0;

      //   int occ;
      //   cout << "\nQuale contatti vorresti cercare?";
      //   int ricercato;
      //   cin >> ricercato;
      //   for (i = 0; i < size; i++) {
      //     if (nome[i] == ricercato) {
      //       occ++;
      //     }
      //   }
	     // cout<<ricercato<<" e' presente "<<occ<<" volte\n"<<endl;
      //   system("pause");
      //   break;

      case 4:
      case 5:
        cout << "not yet implemented" << endl;
        break;

      case 6:
        cout << "arrivederci" << endl;
        break;

      // case 0: /* not needed */
      default:
        cout << "Il comando inserito non esiste" << endl << endl;
        break;
    }
  } while (scelta != 6);	//  not '6', '6' == 54 

	return 0;
}

// int main1() {
// 	string nome[size],cognome[size],telefono_casa[size],cellulare[size],indirizzo_casa[size],indirizzo_mail[size];
	
// 	riempimento(nome,cognome,telefono_casa,cellulare,indirizzo_casa,indirizzo_mail,size);
// 	cout<<"\n\n Hai inserito:\n";
// 	visualizza(nome,cognome,telefono_casa,cellulare,indirizzo_casa,indirizzo_mail,size);
// 	bsort(nome,cognome,telefono_casa,cellulare,indirizzo_casa,indirizzo_mail,size);
// 	cout<<"\n\nTe li ho ordinati cosi':\n";
//     visualizza(nome,cognome,telefono_casa,cellulare,indirizzo_casa,indirizzo_mail,size);
// 	return 0;
// }
	//g=tc m=c a=ic

void riempimento (string n[], string c[], string tc[], string ce[], string ic[], string ie[], int taglia) {
	for (int i = 0; i < taglia; i++) { //scorrimento per tutta la lunghezza del vettore
		cout << "Inserisci il " << i + 1 << "^ nome: ";
		cin >> n[i];
		cout << "Inserisci il " << i + 1 << "^ cognome: ";
		cin >> c[i];
    cout << "Inserisci il " << i + 1 << "^ telefono di casa: "; 
		cin >> tc[i];
		cout << "Inserisci il " << i + 1 << "^ numero di cellulare: ";    
		cin >> ce[i];
		cout << "Inserisci il " << i + 1 << "^ indirizzo di casa: ";    
    cin >> ic[i];
    cout << "Inserisci il " << i + 1 << "^ indirizzo mail: ";    
    cin >> ie[i];
	}
}

void visualizza (string n[],string c[],string tc[],string ce[],string ic[],string ie[],int taglia) {
  for (int i = 0; i < taglia; i++) {
    cout << "Inserisci il " << i + 1 << "^ cognome: " << c[i] << endl;
    cout << "Inserisci il " << i + 1 << "^ nome: " << n[i] << endl;
    cout << "Inserisci il " << i + 1 << "^ telefono di casa: " << tc[i] << endl;
		cout << "Inserisci il " << i + 1 << "^ numero di cellulare: " << ce[i] << endl;
		cout << "Inserisci il " << i + 1 << "^ indirizzo di casa: " << ic[i] << endl;
    cout << "Inserisci il " << i + 1 << "^ indirizzo email: " << ie[i] << '\n' << endl;
  }
}

void bsort (string n[], string c[], string tc[], string ce[], string ic[], string ie[], int taglia) {
	for(int i = 0; i < taglia - 1; i++) { //ciclo esterno che serve a vedere i giorni,mese e anno sono stati ordinati fino a quel momento
    for (int j = 0; j < taglia - 1 - i; j++) { //ciclo interno che serve a confrontare ogni numero con il successivo e fa andare avanti i più grandi verso la fine e i più piccoli all'inizio
			if ((c[i] < c[j]) || ((c[i] == c[j] && (n[i] < n[j])))) { 
			  // you need to swap all the data or you'll end up leaving numbers, addresses etc. in the wrong places.  This is why you shouldn't be using separate arrays
    		swap(n[j + 1], n[j]); //scambio
    		swap(c[j + 1], c[j]); //scambio
    		swap(tc[j + 1], tc[j]); //scambio
    		swap(ce[j + 1], ce[j]); //scambio
    		swap(ic[j + 1], ic[j]); //scambio
    		swap(ie[j + 1], ie[j]); //scambio
			}
    }
  }
}

void ricerca(string ricercato_nome, string ricercato_cognome, string n[], string c[], string tc[], string ce[], string ic[], string ie[], int taglia) {
  // bool ricerca(int wanted) { //wanted contiene l'elemento da ricercare

	bool trovato = false; //conserva una variabile booleana che memeorizza l'esito della ricerca
	for (int i = 0; i < taglia; i++) {
    if (n[i] == ricercato_nome && c[i] == ricercato_cognome) { //confronto ogni elemento del vettore con l'elemento ricercato
      cout << "l'elemento ricercato e' presente all'interno del vettore" << endl;

      cout << "cognome: " << c[i] << endl;
      cout << "nome: " << n[i] << endl;
      cout << "telefono di casa: " << tc[i] << endl;
  		cout << "numero di cellulare: " << ce[i] << endl;
  		cout << "indirizzo di casa: " << ic[i] << endl;
      cout << "indirizzo email: " << ie[i] << '\n' << endl;

      trovato = true; //se viene trova la variabile ricorderà l'esito
      break;
	  }
	}

	if (!trovato) {
    cout << "l'elemento ricercato non e' presente all'interno del vettore" << endl;
	}

// 	return trovato; //al termine restituisce l'esito
  return;
}

