// 1er jeux.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
void game(int nbsalle);
int main()
{
    
	while (true)
	{
		game(5 + (rand() % 5));
	}
	return 0;
}



  



void game(int nbsalle)
{
	std::cout << "Hello advanturer! Anter the dongeon and save the prinssece!\n\n";
	int compteur = 0;
	int pv = 10;
	while (compteur < nbsalle)
	{
		//visite une salle
		int salle = 1 + (rand() % 3);
		if  (salle == 1) 
		{
			printf("Grande salle vide\n");
			
		}
		else if (salle == 2)
		{
			std::cout << "un scelette vous attaque\n";
			pv = pv - 2;
		}
		else if (salle == 3) 
		{
			std::cout << "vous tombez dans un trou\n";
			pv = pv - (rand() % 2);
		}
		compteur++;

		//mort ou pas 
		std::cout << "pv:";
		std::cout << pv ;
		std::cout << std::endl;
		if (pv <= 0)
		{
			std::cout << "tu es mort!\n";
			break;
		}


		std::cout << std::endl;
		getchar();
	}
	if (pv > 0)
	{
		std::cout << "Bravo!! tu as gagnier\n";
	}
	getchar();
}

