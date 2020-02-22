/**
* @file Liste.cpp
* Projet sem06-tp-Cpp3
* @author l'�quipe p�dagogique
* @version 1 - 26/01/06
* @brief Composant de liste d'items stock�s dans une cha�ne � simple cha�nage
* Structures de donn�es et algorithmes - DUT1 Paris 5
*/

using namespace std;

#include "Liste.h"

/**
* @brief Initialiser une liste vide
* la liste est allou�e en m�moire dynamique
* @see detruire, elle est � d�sallouer en fin d�utilisation
* @param[out] l : la liste � initialiser (vide)
*/
void initialiser(Liste& l) {
	initialiser(l.ch);
	l.nb = 0;
	l.index = 0;
}

/**
* @brief D�sallouer une liste
* @see initialiser, la liste a d�j� �t� allou�e en m�moire dynamique
* @param[out] l : la liste
*/
void detruire(Liste& l) {
	detruire(l.ch);
}

/**
* @brief Longueur de liste
* @param[in] l : la liste
* @return la longueur
*/
unsigned int longueur(const Liste& l) {
	return l.nb;
}

/**
* @brief D�placer la position courante � une position donn�e dans la liste
* @param[in,out] l : la liste
* @param[in] i : la position de d�placement
* @pre 0<=i<=longueur(l)
* La fonction ci-dessous n'est pas pr�sente dans le fichier d'ent�te.
* C'est une fonction utilitaire qui n'a pas vocation � �tre employ�e par les
* utilisateurs du type Liste. C'est pourquoi elle est d�clar�e 'static'.
*/
static void deplacer(Liste& l, unsigned int i) {
	assert(i <= longueur(l));
	if (l.index > i) {
		debut(l.ch);
		l.index = 0;
	}
	while (l.index != i) {
		suivant(l.ch);
		l.index++;
	}
}

/**
* @brief Lire un �l�ment de liste
* @param[in] l : la liste
* @return l'item lu
* @pre 0<=i<longueur(l)
*/
Etat lire(Liste& l, unsigned int i) {
	assert((i >= 0) && (i < longueur(l)));
	deplacer(l, i);
	return (lire(l.ch));
}

/**
* @brief Ecrire un item dans la liste
* @param[in,out] l : la liste
* @param[in] i : position de l'�l�ment � �crire
* @param[in] it : l'item
* @pre 0<=i<longueur(l)
*/
void ecrire(Liste& l, unsigned int i, const Etat& it) {
	assert((i >= 0) && (i < longueur(l)));
	deplacer(l, i);
	ecrire(l.ch, it);
}

/**
* @brief Ins�rer un �l�ment dans une liste
* @param[in,out] l : la liste
* @param[in] i : la position avant laquelle l'�l�ment est ins�r�
* @param[in] it : l'�l�ment ins�r�
* @pre 0<=i<=longueur(l)
*/
void inserer(Liste& l, unsigned int i, const Etat& it) {
	assert((i >= 0) && (i <= longueur(l)));
	deplacer(l, i);
	inserer(l.ch, it);
	l.nb++;
}

/**
* @brief Supprimer un �l�ment dans une liste
* @param[in,out] l : la liste
* @param[in] i : la position de l'�l�ment � supprimer
* @pre 0<=i<longueur(l)
*/
void supprimer(Liste& l, unsigned int i) {
	assert((i >= 0) && (i < longueur(l)));
	deplacer(l, i);
	supprimer(l.ch);
	l.nb--;
}



