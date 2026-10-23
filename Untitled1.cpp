#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
	int Bank = 50;
	bool playing = true;
	while (playing)
	{
		int Chosen = 0;
		int Bet = 0;
		int Winner = 0;
		int Posizione1 = 0;
		int Posizione2 = 0;
		int Posizione3 = 0;
		int Posizione4 = 0;
		cout << "Scommetti su una delle chiocciole!\n"
			 << "	1	2	3	4 \n"
			 << "	Jeremy	Gimley	Sancho	Aubrey \n"
			 << "	@	@	@	@\n"
			 << "Inserisci il numero della chiocciola: ";
		while (true) {
			cin >> Chosen;
			if (Chosen <= 4 && Chosen > 0) {
				break;
			} else {
				cout << "Numero non valido, prova di nuovo.";
			}
		}
		
		cout << "Quanto vuoi scommettere? Hai: " << Bank << "$ \n";
		while (true)
		{
			cin >> Bet;
			if (Bet > Bank || Bet < 0)
			{
				cout << "La tua scommessa è troppo alta o negativa. Riprova \n";
			}
			else
			{
				break;
			}
		}
		std::default_random_engine generator;
		generator.seed(time(0));
		Posizione1 = generator() % 16;
		Posizione2 = generator() % 16;
		Posizione3 = generator() % 16;
		Posizione4 = generator() % 16;
		if (Posizione1 > Posizione2 && Posizione1 > Posizione3 && Posizione1 > Posizione4)
		{ // 1
			Winner = 1;
		}
		else if (Posizione2 > Posizione1 && Posizione2 > Posizione3 && Posizione2 > Posizione4)
		{ // 2
			Winner = 2;
		}
		else if (Posizione3 > Posizione2 && Posizione3 > Posizione1 && Posizione3 > Posizione4)
		{ // 3
			Winner = 3;
		}
		else if (Posizione4 > Posizione2 && Posizione4 > Posizione1 && Posizione4 > Posizione3)
		{ // 4
			Winner = 4;
		}
		for (int i = 1; i <= 4; i++)
		{
			if (i == 1)
			{
				cout << "1 ";
				for (int j = 0; j <= Posizione1; j++)
				{
					cout << "-" << flush;
					std::this_thread::sleep_for(std::chrono::milliseconds(150));
				}
				cout << "@ \n"
					 << "\n";
				std::this_thread::sleep_for(std::chrono::milliseconds(150));
			}
			if (i == 2)
			{
				cout << "2 ";
				for (int j = 0; j <= Posizione2; j++)
				{
					cout << "-" << flush;
					std::this_thread::sleep_for(std::chrono::milliseconds(150));
				}
				cout << "@ \n"
					 << "\n";
				std::this_thread::sleep_for(std::chrono::milliseconds(150));
			}
			if (i == 3)
			{
				cout << "3 ";
				for (int j = 0; j <= Posizione3; j++)
				{
					std::this_thread::sleep_for(std::chrono::milliseconds(150));
					cout << "-" << flush;					
				}
				cout << "@ \n"
					 << "\n";
				std::this_thread::sleep_for(std::chrono::milliseconds(150));
			}
			if (i == 4)
			{
				cout << "4 ";
				for (int j = 0; j <= Posizione4; j++)
				{
					cout << "-" << flush;
					std::this_thread::sleep_for(std::chrono::milliseconds(150));
				}
				cout << "@ \n"
					 << "\n";
				std::this_thread::sleep_for(std::chrono::milliseconds(150));
			}
		}
		if (Chosen == Winner)
		{
			cout << "Hai vinto! La tua scommessa sara' raddopiata. \n";
			Bank = Bank + (Bet * 2);
			cout << "Ora hai: " << Bank << "$\n";
		}
		else
		{
			cout << "Hai perso :( La tua scommessa sara' sottratta al tuo conto. \n";
			if ((Bank - Bet) <= 0) {
				cout << "Non hai piu' soldi :(. Prova di nuovo un altra volta.";
				break;
			} else {
				Bank = Bank - Bet;
				cout << "Ora hai: " << Bank << "$\n";
			}
			
		}
		while (true) {
			cout << "Vuoi giocare di nuovo? (s/n): ";
			char scelta;
			cin >> scelta;
			if (scelta == 's' || scelta == 'S') {
				break;
			} else if (scelta == 'n' || 'N') {
				playing = false;
				break;
			} else {
				cout << "Carattere non valido, prova di nuovo.";
			}
		}
	}
	return 0;
} 