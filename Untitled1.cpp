#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stdlib.h>
using namespace std;

int main() {
	int Chosen = 0;
	int Bank = 50;
	int Bet = 0;
	int Winner = 0;
	int Posizione1 = 0;
	int Posizione2 = 0;
	int Posizione3 = 0;
	int Posizione4 = 0;
	cout << "Scommetti su una delle chiocciole!\n" << "	1	2	3	4 \n" << "	@	@	@	@\n" << "Inserisci il numero della chiocciola";
	cin >> Chosen;
	cout << "Quanto vuoi scommettere? Hai: " << Bank << "$ \n";
	while (true) {
		cin >> Bet;
		if (Bet > Bank || Bet < 0) {
			cout << "La tua scommessa è troppo alta o negativa. Riprova \n";
		} else {
			break;
		}
	}
	srand(time(0));
	Posizione1 = rand() % 16;
	srand(time(0));
	Posizione2 = rand() % 16;
	srand(time(0));
	Posizione3 = rand() % 16;
	srand(time(0));
	Posizione4 = rand() % 16;
	if (Posizione1 > Posizione2 && Posizione1 >> Posizione3 && Posizione1 >> Posizione4 )  { //1
		Winner = 1;
	} else if (Posizione2 > Posizione1 && Posizione2 >> Posizione3 && Posizione2 >> Posizione4) { //2
		Winner = 2;
	} else if (Posizione3 > Posizione2 && Posizione3 >> Posizione1 && Posizione3 >> Posizione4) {// 3
		Winner = 3;
	}else if (Posizione4 > Posizione2 && Posizione4 >> Posizione1 && Posizione4 >> Posizione3) {// 4
		Winner = 4;
	}
	for (int i = 1; i <= 4; i++) {
		switch (i) {
			case 1 :
			cout << "1 ";
			for (int j = 0; i <= Posizione1; i++) 
				{
				cout << "-";
			}
			cout << "@ \n" << "\n";
			break;
			case 2 :
			cout << "2 ";
			for (int j = 0; i <= Posizione2; i++) {
				cout << "-";
			}
			cout << "@ \n" << "\n";			
			break;
			case 3 :
			cout << "3 ";
			for (int j = 0; i <= Posizione3; i++) {
				cout << "-";
			}
			cout << "@ \n" << "\n";
			break;
			case 4 :
			cout << "4 ";
			for (int j = 0; i <= Posizione4; i++) {
				cout << "-";
			}
			cout << "@ \n" << "\n";
			break;				
		}
	}	
	if (Chosen == Winner) {
		cout << "Hai vinto! La tua scommessa sara' raddopiata. \n";
		Bank = Bank + (Bet * 2);
		cout << "Ora hai: " << Bank << "$\n";
	} else {
		cout << "Hai perso :( La tua scommessa sara' sottratta al tuo conto. \n";
		Bank = Bank - Bet;
		cout << "Ora hai: " << Bank << "$\n";
	}
	
	
}