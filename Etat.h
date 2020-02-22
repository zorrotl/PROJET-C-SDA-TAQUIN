#ifndef _ETAT_
#define _ETAT_
#include "Tableau2D.h"
enum Mouvement { OUEST, EST, NORD, SUD, FIXE };

struct Position
{
	unsigned int abs;
	unsigned int ord;
};

struct Etat
{
	Tab2D tab2D; //damier résultant
	Mouvement mouv; //mouvement
	unsigned int LEE; //index du damier précédent
	unsigned int g; //nombre de coups g de l’état initial à e
	unsigned int h; //heuristique h de e à l’état but
	Position vide; //position de la case vide dans le damier résultant
};

/**
* @brief Afficher un Etat
* @param [in] t, tableau 2D à afficher
*/
void afficher(const Etat& e);

/**
* @brief Renvoie true si les deux états sont semblables, false sinon
* @param [in] e1
* @param [in] e2
* @return tmp
*/
bool Same(const Etat& e1, const Etat& e2);

/**
* @brief Donne f d'un état
* @param [in] état
* @return f de l'état (g+h)
*/
unsigned int f(const Etat& e);

#endif