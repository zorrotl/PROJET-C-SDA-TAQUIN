#ifndef LISTE_H_
#define LISTE_H_

/**
* @file Liste.h
* Projet sem06-tp-Cpp3
* @author l'�quipe p�dagogique
* @version 1 - 25/01/06
* @brief Composant de liste d'items stock�s dans une cha�ne � simple cha�nage
* Structures de donn�es et algorithmes - DUT1 Paris 5
*/

#include "Chaine.h"

/**
* Liste g�r�e dans une cha�ne d'items
*/
struct Liste {
	Chaine ch;	            // structure de stockage
	unsigned int nb;        // nombre d'�l�ments dans la liste
	unsigned int index;	    // index correspondant � la position courante dans la chaine
};

/**
* @brief Initialiser une liste vide
* la liste est allou�e en m�moire dynamique
* @see detruire, elle est � d�sallouer en fin d�utilisation
* @param[out] l : la liste � initialiser (vide)
*/
void initialiser(Liste& l);

/**
* @brief D�sallouer une liste
* @see initialiser, la liste a d�j� �t� allou�e en m�moire dynamique
* @param[out] l : la liste
*/
void detruire(Liste& l);

/**
* @brief Longueur de liste
* @param[in] l : la liste
* @return la longueur
*/
unsigned int longueur(const Liste& l);

/**
* @brief Lire un �l�ment de liste
* @param[in] l : la liste
* @return l'item lu
* @pre 0<=i<=longueur(l)
*/
Etat lire(Liste& l, unsigned int i);

/**
* @brief Ecrire un item dans la liste
* @param[in,out] l : la liste
* @param[in] i : position de l'�l�ment � �crire
* @param[in] it : l'item
* @pre 0<=i<=longueur(l)
*/
void ecrire(Liste& l, unsigned int i, const Etat& it);

/**
* @brief Ins�rer un �l�ment dans une liste
* @param[in,out] l : la liste
* @param[in] i : la position avant laquelle l'�l�ment est ins�r�
* @param[in] it : l'�l�ment ins�r�
* @pre 0<=i<=longueur(l)+1
*/
void inserer(Liste& l, unsigned int i, const Etat& it);

/**
* @brief Supprimer un �l�ment dans une liste
* @param[in,out] l : la liste
* @param[in] i : la position de l'�l�ment � supprimer
* @pre 0<=i<=longueur(l)
*/
void supprimer(Liste& l, unsigned int i);

#endif /*LISTE_H_*/
