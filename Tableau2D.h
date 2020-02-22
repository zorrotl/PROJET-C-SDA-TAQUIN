#ifndef _TABLEAU_
#define _TABLEAU_
#include "Item.h"
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;
struct Tab2D {
	Item** tab; // adresse du tableau bidimensionnel
				// en mémoire dynamique
	int nbL; // nombre de lignes de la matrice
	int nbC; // nombre de colonnes de la matrice
};


/**
* @brief initialiser, alloue un damier de nbL lignes et nbC colonnes
* @param [in-out] m, tableau à 2 dimensions à initialiser(Tableau2D)
* @param [in] nbL, nombre de lignes
* @param [in] nbC, nombre de colonnes
*/
void initialiser(Tab2D& m, unsigned int nbL, unsigned int nbC);

/**
* @brief detruire, désalloue un Tableau2D
* @param [in-out] t, tableau à 2 dimensions à détruire (Tableau2D)
*/
void detruire(Tab2D& m);

/**
* @brief Lire un Tableau2D
* @param [in-out] m, tableau à 2 dimensions à détruire (Tab2D)
*/
void lire(Tab2D& m);

/**
* @brief Afficher un Tableau2D
* @param [in] t, tableau 2D à afficher
*/
void afficher(const Tab2D& m);
#endif