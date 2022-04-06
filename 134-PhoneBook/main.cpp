# include <iostream>//directive to preprocessor indicating to add input library and ouput
// iostream used to use cin and cout
//#includes<coinage.h>
# include <fstream>
#include <cstdlib> // contains string functions
#include <string> // the string library can sometimes also not be used but it is better if you put it
#define size 10 // the address book size (number of contacts)
// & serves when I have a variable and want to get its address, * serves when I have the address and want to get the pointed value

using namespace std; // line that tells the compiler that we use standard language, is mandatory
// n = first name / c = last name / tc=home phone / ce=mobile / ic=home address / ie=email address

struct person {
  string name;
  string surname;
  string phone_house; 
  string cell;
  string home_address;
  string email_address;
};

void bubblesort(person address_book [], int);
void phone_house(person address_book [], int *);
void display(person address_book [], int);
void initdb(person address_book [], int *);
void InsertQueue2 (person address_book [], int *, person);
void load(person address_book [], int *, string);
void save(person address_book [], int, string);
void edit(person address_book[], int);
void search(person address_book[], int);

string NomeRub = "address_book.txt";

int main() {
	char choice;
	person address_book [size];
	int entered = 0;
	// initdb(address book, & entered);

	do {
    // system("cls");
    cout << "the address book at the moment contains:" << entered << "elements\n \n\n\n";
    cout << "\t1 - phone_home\n"
            "\t2 - list\n"
            "\t3 - search\n"
            "\t4 - delete\n"
            "\t5 - edit\n"
            "\t6 - load address book\n"
            "\t7 - save Address Book\n"
            "\t0 - finish\n\n";
		cout << " make your choice:";
		cin >> choice;
		// system ("cls");
		switch (choice) {
//			case '1': phone_house(address_book, & entered); break;
			case '2': display (address_book, entered); break;
			case '3': search(address_book, entered); break; // search
			case '4': break; // delete
			case '5': edit(address_book, entered); break; // edit
			case '6': load(address_book, & entered, NomeRub); break;
//			case '7': save(address_book, entered, NomeRub); break;
			case '0': cout<< "\n \nGoodBye\n\n";
		}
	} while (choice != '0');

	return 0;
}

void load(person address_book [], int * dim, string filename) {
	ifstream fsIn;
	fsIn.open (filename.c_str()); // open the output file
	if (!fsIn) {
	  cout<< "Error opening" << filename;
	}
	else {
	  cout << filename << "open";
	}
	   
	cout << endl;
	*dim = 0;
	while (!fsIn.eof ()) {
	   getline(fsIn, address_book[*dim].name);
	   if (fsIn.eof ()) {
	   	  break;
	   }
	   getline (fsIn, address_book [*dim].surname);
	   getline (fsIn, address_book [*dim].phone_house);
	   getline (fsIn, address_book [*dim].cell);
	   getline (fsIn, address_book [*dim].home_address);
	   getline (fsIn, address_book [*dim].email_address);
	   cout << "Loaded:" << address_book [*dim].name << " " << address_book[*dim].surname << endl;
	   *dim = *dim + 1;
	}
	
	fsIn.close();
	cout << " \n \nPress Any Key to continue...";
	//getch();	
}

void save(person address_book [], int dim, string filename) {
	ofstream fsOut;
	fsOut.open(filename.c_str ()); // open the output file
	if (!fsOut) {
    cout<< "Error opening" << filename;
	}
	else {
    cout << filename<< "Opened";
	}
	   
	cout << endl;
	
	for (int i = 0; i < dim; i++) {
	   cout << "Saving:" << address_book[i].name << " " << address_book[i].surname << endl;
	   fsOut << address_book[i].name << endl;
     fsOut << address_book[i].surname << endl;
     fsOut << address_book[i].phone_house << endl; 
     fsOut << address_book[i].cell<< endl;
     fsOut << address_book[i].home_address << endl;
     fsOut << address_book[i].email_address << endl;		
	}
	
	fsOut.close();
	cout << " \n \nPress Any Key to continue...";
//	getch();
}

	
void phone_home(person address_book[], int * x) {
	char confirm;
	cout << "currently there are" << *x << "records in address book" << endl;
	if (*x == size) {
    cout << " attention, full address book.Delete some elment in order to make a new insert\n";
	}
	else {
		cout << " enter surname:";
		cin >> address_book [*x].surname;
		cout << " enter the name:";
		cin >> address_book [*x].name;
		cout << " enter the house number:";
		cin >> address_book [*x].phone_house;
		cout << " enter the mobile number:";
		cin >> address_book [*x].cell;
		cout << "enter home_address:";
		cin >> address_book [*x].home_address;
		cout << " enter email_address:";
		cin >> address_book [*x].email_address;
 
  	cout <<" \nyou entered:\n";
   
		cout<< "surname:" << address_book [*x].surname << endl;
		cout<< "name:" << address_book [*x].name << endl;
		cout<< "house number:" << address_book [*x].phone_house << endl;
		cout<< "mobile number:" << address_book [*x].cell << endl;
		cout<< "home_address:" << address_book [*x].home_address << endl;
		cout<< "email_address:" << address_book [*x].email_address << endl;
		cout<< " \n \nconfirm the insertion in the address book? (S / N):"; 
		cin >> confirm;
	
		if ((confirm == 's') || (confirm == 'S')) {
      *x = *x + 1;
      bubblesort(address_book, *x);
      cout << "reorder" << endl;
    }

		cout << "currently there are" << *x << "records in address book" << endl;
	}
	
	cout<<"\n\npress one key to continue..."; 
//	getch();
}

void swap(person address_book[], int a, int b) {
	string tmp;
	// cout<<"in Swap between element" < < a<< " and element "<<b<<"\n";
	tmp = address_book[a].surname;
	address_book[a].surname = address_book[b].surname;
	address_book[b].surname = tmp;
	
	tmp = address_book[a].name;
	address_book[a].name = address_book [b].name;
	address_book[b].name = tmp;
	
	tmp = address_book[a].phone_house;
	address_book[a].phone_house = address_book [b].phone_house;
	address_book[b].phone_house = tmp;

	tmp = address_book[a].cell;
	address_book[a].phone_house = address_book[b].cell;
	address_book[b].cell = tmp;

	tmp = address_book[a].home_address;
	address_book[a].home_address = address_book[b].home_address;
	address_book[b].home_address = tmp;

	tmp = address_book[a].email_address;
	address_book[a].email_address = address_book [b].email_address;
	address_book[b].email_address = tmp;
}

int compare(person address_book [], int a, int b) {
	if ((address_book[a].surname > address_book[b].surname) ||
	   ((address_book [a].surname == address_book[b].surname) && (address_book[a].name > address_book[b].name)) ) {
    return 1;
  }
	else {
	   return 0;
	}
}

void bubblesort(person address_book[], int dim) {
	int i, j;
	for (j = 0; j < dim; j++) {
		for (i = 0; i < dim - 1; i++) {
			if (compare (address_book, i, i + 1)) {
        swap (address_book,i, i + 1);
			}
		}
	}
}

void display(person address_book[], int dim) {
// 	system ("`cls");
	for (int i=0; i < dim; i++) {
		cout << "record number:" << i + 1 << endl;
		cout << "surname:" << address_book[i].surname << endl;
		cout << "name:" << address_book[i].name << endl;
		cout << "house number:" << address_book[i].phone_house << endl;
		cout << "mobile number:" << address_book[i].cell << endl;
		cout << "home_address:" << address_book[i].home_address << endl;
		cout << "email_address:" << address_book[i].email_address << endl << endl;	
	}
	cout << " \n \nPress Any Key to continue..."; 
//	getch();
}

void search(person address_book[], int dim){
	string name;
	cout << "Enter Surname to Search: " << name;
	for (int i=0; i < dim; i++) {
		if ( address_book[i].surname == name ) {
			cout << " Found: \n";
			cout << "name:" << address_book[i].name << endl;
			cout << "house number:" << address_book[i].phone_house << endl;
			cout << "mobile number:" << address_book[i].cell << endl;
			cout << "home_address:" << address_book[i].home_address << endl;
			cout << "email_address:" << address_book[i].email_address << endl << endl;
			break;
		}
	}
}

void edit(person address_book[], int dim) {
	ofstream fsOut;
	fsOut.open(NomeRub.c_str()); // open the output file
	if (!fsOut) {
    cout << "Error opening" << NomeRub;
	}
	else {
    cout << NomeRub << "Opened";
	}
	   
	cout << endl;
	
	string name;
	cout<<"Enter Surname to Edit: "<<name;
	for (int i=0; i < dim; i++) {
		if (address_book[i].surname == name) {
			string fname, pHouse, cell, homeAdd, email;
			cout << " Found: \n";
			cout << "Enter Name: ";
			cin >> fname;
			cout << "Enter House Number: ";
			cin >> pHouse;
			cout << "Enter Cell Number: ";
			cin >> cell;
			address_book[i].cell = cell;
			cout << "Enter Home Address: ";
			cin >> homeAdd;
			address_book[i].home_address = homeAdd;
			cout << "Enter Email Address: ";
			address_book[i].email_address = email;
			break;
		}
	}
	fsOut.close();
}


void InsertQueue2(person address_book[], int *x, person new1) {
	address_book [*x].surname = new1.surname;
	address_book [*x].name = new1.name;
	address_book [*x].phone_house=new1.phone_house;
	address_book [*x].cell = new1.cell;
	address_book [*x].home_address = new1.home_address;
	address_book [*x].email_address = new1.email_address;
	*x = *x + 1;
}

void InsertQueue(person address_book[], int * x,
                 string firstname, string lastname, string home_phone,
                 string mobile, string home_address, string email_address) {
	address_book [*x].surname = lastname;
	address_book [*x].name = firstname;
	address_book [*x].phone_house = home_phone;
	address_book [*x].cell = mobile;
	address_book [*x].home_address = home_address;
	address_book [*x].email_address = email_address;
	*x = *x + 1;
}

void initdb(person address_book[], int * x) {
	InsertQueue(address_book, x, "Fabiani", "leave", "089", "666", "my house", " gersca@");
	InsertQueue(address_book, x, "Lotito", "leave", "098", "333", "your home", " MarStar@");
	InsertQueue(address_book, x, "Biagio", "baggiano", "000", "123", "flat land", "BigPharma @ nonmiavra");
	
	person ne;
	
	ne.name = "Paola";
	ne.surname = "brosio";
	ne.email_address = "tg4 @ fabianivattene";
	ne.cel l ="bathroom writing";
	ne.phone_house = "noncello";
	ne.home_address = "DaChiMiMantiene";
	
	InsertQueue2(address_book,x,ne);
	
	/* InsertQueue (address_book, x,"","","","","","");
	InsertQueue (address_book, x,"","","","","","");
	InsertQueue (address_book, x,"","","","","","");
	InsertQueue (address_book, x,"","","","","","");*/
	bubblesort(address_book, * x);
}

