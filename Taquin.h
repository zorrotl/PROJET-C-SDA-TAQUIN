#ifndef _TAQUIN_
#define _TAQUIN_
#include "Liste.h"
struct Taquin
{
	Liste LEE;
	Liste LEAE;
	unsigned int nbC, nbL;
};

/**
* @brief initialiser, Créer le jeu de taquin avec l’état initial
* @param [in-out] t, Taquin à initialiser(Tableau2D)
*/
void initialiser(Taquin& t);



/**
* @brief deplacement, Déplace la case vide en fonction du mouv entré
* @param [in] mouv, mouvement
* @param [in] e, un Etat
*/
Etat deplacement(Mouvement mouv, const Etat& e);



/**
* @brief renvoie l'index du tableau le plus récemment entré avec g le plus petit de la liste du Taquin
* @param [in-out] t, Les listes du Taquin
* return index
*/
unsigned int gmin(Taquin& t);

unsigned int fmin(Taquin& t);

unsigned int hmin(Taquin& t);

/**
* @brief jouer, pour faire une itération de l'algorithme de recherche
* @param [in-out] Taquin t, le taquin à résoudre
* @return true si solution trouvée, false sinon
*/
bool jouer(Taquin& t);

/**
* @brief Afficher le contenue des adev et dev
* @param [in] t, tableau 2D à afficher
*/
void afficher(Taquin& t);


/**
* @brief detruire, désalloue un taquin
* @param [in-out] t, tableau à 2 dimensions à détruire (Tableau2D)
*/
void detruire(Taquin& t);

/* @brief renvoie vrai si l‘état existe déjà dans le taquin
* @param [in] ef
* @param [in] t
* @return bool
*/
bool appartient(const Etat& ef, Taquin& t);

/* @brief renvoie vrai s’il s’agir de l’état final, faux sinon
* @param [in] e
* @return bool
*/
bool but(const Etat& e);

/**
* @brief renvoie l'heuristique de l'etat
* @param [in-out] e, L'Etat de la liste
* @return h
*/
unsigned int heuristique(Etat& e);

void afficherSolution(Taquin& t);

#endif