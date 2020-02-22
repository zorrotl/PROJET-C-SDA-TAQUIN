#include "Taquin.h"

/**
* @brief Afficher un Etat
* @param [in] t, tableau 2D à afficher
*/
void afficher(const Etat& e)
{
	// On affiche le dernier mouvement seulement s'il y en a eu au moins 1
	if (e.g > 0)
	{
		switch (e.mouv)
		{
		case NORD:
			cout << "NORD" << endl;
			break;
		case OUEST:
			cout << "OUEST" << endl;
			break;
		case SUD:
			cout << "SUD" << endl;
			break;
		case EST:
			cout << "EST" << endl;
			break;
		case FIXE:
			break;
		}

	}

	// On affiche maintenant le damier résultant (fonction afficher(Tableau2D&))
	afficher(e.tab2D);
}


/**
* @brief Renvoie true si les deux états sont semblables, false sinon
* @param [in] e1
* @param [in] e2
* @return tmp
*/
bool Same(const Etat& e1, const Etat& e2)
{
	bool tmp = true;
	for (unsigned int i = 0; i < e1.tab2D.nbL; i++)
	{
		for (unsigned int j = 0; j < e1.tab2D.nbC; j++)
		{
			if (e1.tab2D.tab[i][j] != e2.tab2D.tab[i][j])
			{
				tmp = false;
			}
		}
	}
	return tmp;
}

/**
* @brief Donne f d'un état
* @param [in] état
* @return f de l'état (g+h)
*/
unsigned int f(const Etat& e)
{
	return e.g + e.h;
}
