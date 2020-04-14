// 1er jeux.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <time.h>
void game(int nbsalle);
int main()
{
	srand(time(0));
	while (true)
	{
		game(5 + (rand() % 20));
	}
	return 0;
}



  



void game(int nbsalle)
{
	const int sortes_de_salles = 4;

	const int chances_de_coffres = 8;

	const int max_arm = 2;

	const int sortes_de_pus = 4;

	const int degats_squelette = 2;

	const int max_hauteur = 3;

	const int unite_hauteur = 5;

	const int max_pv = 5;

	const int heal_plante = 1;


	std::cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n Hello advanturer! Enter the dungeon and save the prinssece!\n/////////////////////////////////////////////////\n";
	int compteur = 0;
	int chance = 1;
	int arm = 0;
	int pv = max_pv;
	while (compteur < nbsalle)
	{
		//visite une salle
		int salle =(rand() % sortes_de_salles);
		if  (salle == 0) 
		{
			int chance1 = rand() % chances_de_coffres;
			printf("une Grande salle vide\n\n\n");
			if (chance1 <= chance)
			{
				printf("un coffre!!\nune armure en mailles,");
				if (arm < max_arm)
				{
					printf(" vous l'equipez\n");
					arm++;
				}
				else
				{
					printf("c'est bien trop lourd\n");
				}
			}
		}
		else if (salle == 1)
		{
			if (arm > degats_squelette)
			{
				printf("les monstres ont peur de vous!!\n");
			}
			else
			{
				printf("un squelette vous attaque, vous prenez %d degats\n", degats_squelette - arm);
				pv = pv - (degats_squelette - arm);
			}
		}
		else if (salle == 2) 
		{
			int hauteur = (rand() % max_hauteur);
			printf("vous tombez dans un trou\n");
			pv = pv - hauteur;
			if (hauteur >= 1)
			{
				printf("vous etes tomber de %d m, vous prenez %d de degats\n", hauteur * unite_hauteur, hauteur);
			}
			else
			{
				printf("haha, trop bon pour les trous\n");
			}
		}
		else if (salle == 3)
		{//heal
			printf ("ouf, des plantes magiques!\n");
			if (pv < max_pv)
			{
				printf("miam, des bons pv!\n");
				pv = pv + heal_plante;
				if (pv > max_pv)
				{
					pv = max_pv;
				}
			}
			else
			{
				printf("bof, pas faim\n");
			}
		}
		
		//mort ou pas 
		
		if (pv <= 0)
		{
			printf("tu es mort!\nx x\n _\n");
			break;
		}
		printf("pv: %d\n", pv);
		if (arm >= 1)
		{
			printf("armure: %d\n", arm);
		}
		compteur++;
		//pas une salle(pus)
		getchar();
		int pus = (rand() % sortes_de_pus);
		if (pus == 0)
		{
			printf("\n\nvous travercez un long couloir\n\n");
		}
		else if (pus == 1)
		{
			printf("\n\nvous montez avec des escaliers\n\n");
		}
		else if (pus == 2)
		{
			printf("\n\nvous passez sur un petit pont\n\n");
		}
		else if (pus == 3)
		{
			printf("\n\nun petit feux de camp vous attend\nprenez une pause\n\n");
		}
		


		
		getchar();
	}
	if (pv > 0)
	{
		printf ("Bravo!! tu as gagnier\n");
	}
	getchar();
}

