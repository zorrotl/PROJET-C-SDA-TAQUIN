#include "Tableau2D.h"

using namespace std;

/**
* @brief initialiser, alloue un damier de nbL lignes et nbC colonnes
* @param [in-out] m, tableau à 2 dimensions à initialiser(Tableau2D)
* @param [in] nbL, nombre de lignes
* @param [in] nbC, nombre de colonnes
*/
void initialiser(Tab2D& m, unsigned int nbL, unsigned int nbC) {
	m.nbL = nbL;
	m.nbC = nbC;
	m.tab = new Item*[nbL];
	for (unsigned int i = 0; i < nbL; i++)
	{
		m.tab[i] = new Item[nbC];
	}
}


/**
* @brief detruire, désalloue un Tableau2D
* @param [in-out] t, tableau à 2 dimensions à détruire (Tableau2D)
*/
void detruire(Tab2D& m) {
	for (unsigned int i = 0; i < m.nbL; i++)
	{
		delete[] m.tab[i];
	}
	delete[] m.tab;
	m.tab = NULL;
}




/**
* @brief Lire un Tableau2D
* @param [in-out] m, tableau à 2 dimensions à détruire (Tab2D)
*/
void lire(Tab2D& m) {
	char val[10];
	for (unsigned int i = 0; i < m.nbL; i++)
	{
		for (unsigned int j = 0; j < m.nbC; j++) {
			cin >> val;
			if (*val == '#')
			{
				m.tab[i][j] = 0;
			}
			else
			{
				m.tab[i][j] = atoi(val);
			}

		}
	}
}


/**
* @brief Afficher un Tableau2D
* @param [in] t, tableau 2D à afficher
*/
void afficher(const Tab2D& m) {
	for (unsigned i = 0; i < m.nbL; i++)
	{
		for (unsigned int j = 0; j < m.nbC; j++)
		{

			if (m.tab[i][j] == 0)
			{
				cout << setw(3) << "#";
			}
			else
			{
				cout << setw(3) << m.tab[i][j];
			}

		}
		cout << endl;
	}
}