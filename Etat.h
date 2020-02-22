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
	Tab2D tab2D; //damier r�sultant
	Mouvement mouv; //mouvement
	unsigned int LEE; //index du damier pr�c�dent
	unsigned int g; //nombre de coups g de l��tat initial � e
	unsigned int h; //heuristique h de e � l��tat but
	Position vide; //position de la case vide dans le damier r�sultant
};

/**
* @brief Afficher un Etat
* @param [in] t, tableau 2D � afficher
*/
void afficher(const Etat& e);

/**
* @brief Renvoie true si les deux �tats sont semblables, false sinon
* @param [in] e1
* @param [in] e2
* @return tmp
*/
bool Same(const Etat& e1, const Etat& e2);

/**
* @brief Donne f d'un �tat
* @param [in] �tat
* @return f de l'�tat (g+h)
*/
unsigned int f(const Etat& e);

#endif