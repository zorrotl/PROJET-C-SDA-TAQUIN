#include "Taquin.h"
using namespace std;


/**
* @brief initialiser, Créer le jeu de taquin avec l’état initial
* @param [in-out] t, Taquin à initialiser(Tableau2D)
*/
void initialiser(Taquin& t) {
	initialiser(t.LEE);
	initialiser(t.LEAE);
	unsigned int nbL, nbC;
	cin >> nbL >> nbC;

	t.nbC = nbC;
	t.nbL = nbL;

	Etat e;
	e.tab2D.nbC = nbC;
	e.tab2D.nbL = nbL;
	initialiser(e.tab2D, nbL, nbC);

	lire(e.tab2D);
	e.mouv = FIXE;
	e.g = 0;
	e.h = heuristique(e);

	for (unsigned int i = 0; i < nbL; i++)
	{
		for (unsigned int j = 0; j < nbC; j++)
		{
			if (e.tab2D.tab[i][j] == 0)
			{
				e.vide.abs = j;
				e.vide.ord = i;
			}
		}
	}

	inserer(t.LEAE, longueur(t.LEAE), e);
	cout << "Damier : " << nbL << " lignes, " << nbC << " colonnes" << endl;
}

/**
* @brief deplacement, Déplace la case vide en fonction du mouv entré
* @param [in] mouv, mouvement
* @param [in] e, un Etat
*/
Etat deplacement(Mouvement mouv, const Etat& e)
{
	Etat e_r;
	initialiser(e_r.tab2D, e.tab2D.nbL, e.tab2D.nbC);
	for (unsigned int i = 0; i < e_r.tab2D.nbL; i++)
	{
		for (unsigned int j = 0; j < e_r.tab2D.nbC; j++)
		{
			e_r.tab2D.tab[i][j] = e.tab2D.tab[i][j];
		}
	}
	e_r.vide.abs = e.vide.abs;
	e_r.vide.ord = e.vide.ord;
	e_r.mouv = mouv;
	e_r.g = e.g + 1;

	switch (mouv)
	{
	case NORD:
		e_r.tab2D.tab[e_r.vide.ord][e_r.vide.abs] = e.tab2D.tab[e_r.vide.ord - 1][e_r.vide.abs];
		e_r.tab2D.tab[e_r.vide.ord - 1][e_r.vide.abs] = 0;
		e_r.vide.ord--;
		break;
	case OUEST:
		if (e_r.vide.abs == 0)
		{
			e_r.tab2D.tab[e_r.vide.ord][e_r.vide.abs] = e.tab2D.tab[e_r.vide.ord][e.tab2D.nbC - 1];
			e_r.tab2D.tab[e_r.vide.ord][e.tab2D.nbC - 1] = 0;
			e_r.vide.abs = e.tab2D.nbC - 1;
		}
		else
		{
			e_r.tab2D.tab[e_r.vide.ord][e_r.vide.abs] = e.tab2D.tab[e_r.vide.ord][e_r.vide.abs - 1];
			e_r.tab2D.tab[e_r.vide.ord][e_r.vide.abs - 1] = 0;
			e_r.vide.abs--;
		}
		break;
	case SUD:
		e_r.tab2D.tab[e_r.vide.ord][e_r.vide.abs] = e.tab2D.tab[e_r.vide.ord + 1][e_r.vide.abs];
		e_r.tab2D.tab[e_r.vide.ord + 1][e_r.vide.abs] = 0;
		e_r.vide.ord++;
		break;
	case EST:
		if (e_r.vide.abs == e.tab2D.nbC - 1)
		{
			e_r.tab2D.tab[e_r.vide.ord][e_r.vide.abs] = e.tab2D.tab[e_r.vide.ord][0];
			e_r.tab2D.tab[e_r.vide.ord][0] = 0;
			e_r.vide.abs = 0;
		}
		else
		{
			e_r.tab2D.tab[e_r.vide.ord][e_r.vide.abs] = e.tab2D.tab[e_r.vide.ord][e_r.vide.abs + 1];
			e_r.tab2D.tab[e_r.vide.ord][e_r.vide.abs + 1] = 0;
			e_r.vide.abs++;
		}
		break;
	case FIXE:
		return e_r;
	}
	e_r.h = heuristique(e_r);

	return e_r;
}


/**
* @brief renvoie l'index du tableau le plus récemment entré avec g le plus petit de la liste LEAE du Taquin
* @param [in-out] t, Les listes du Taquin
* return index
*/
unsigned int gmin(Taquin& t)
{
	unsigned int g = lire(t.LEAE, 0).g, index = 0;
	for (unsigned int i = 0; i < longueur(t.LEAE); i++)
	{
		if (lire(t.LEAE, i).g < g)
		{
			g = lire(t.LEAE, i).g;
			index = i;
		}
	}
	return index;
}
/**
* @brief renvoie l'index du tableau avec le f le plus petit de la liste LEAE du Taquin
* @param [in-out] t, Les listes du Taquin
* return index
*/
unsigned int fmin(Taquin& t)
{
	unsigned int indice = 0;
	unsigned int f1 = lire(t.LEAE, 0).g + lire(t.LEAE, 0).h;
	for (unsigned int i = 0; i < longueur(t.LEAE); i++)
	{
		if (f(lire(t.LEAE, i)) < f1)
		{
			f1 = f(lire(t.LEAE, i));
			indice = i;
		}
	}
	return indice;
}
/**
* @brief renvoie l'index du tableau avec le h le plus petit de la liste LEAE du Taquin
* @param [in-out] t, Les listes du Taquin
* return index
*/
unsigned int hmin(Taquin& t)
{
	unsigned int indice = 0;
	unsigned int hmin = lire(t.LEAE, 0).h;
	for (unsigned int j = 0; j < longueur(t.LEAE); j++)
	{
		if (lire(t.LEAE, j).h < hmin)
		{
			hmin = lire(t.LEAE, j).h;
			indice = j;
		}
	}
	return indice;
}

/**
* @brief jouer, pour faire une itération de l'algorithme de recherche
* @param [in-out] Taquin t, le taquin à résoudre
* @return true si solution trouvée, false sinon
*/
bool jouer(Taquin& t) {

	Etat courant;
	// Indice
	unsigned int iCourant = 0;
	// donne l'index du tableau dans la liste LEAE le plus récemment entré avec le plus petit f 
	//si même f alors plus petit h 
	//si même h alors le plus récemment entrée
	if (longueur(t.LEAE) == 1)
	{
		iCourant = 0;
	}
	else
	{
		for (unsigned int i = 0; i < longueur(t.LEAE); i++)
		{
			if (f(lire(t.LEAE, fmin(t))) <= f(lire(t.LEAE.ch)))
			{
				iCourant = fmin(t);
			}
			else if (lire(t.LEAE, hmin(t)).h < lire(t.LEAE.ch).h)
			{
				iCourant = hmin(t);
			}
			else
			{
				iCourant = gmin(t);
			}
		}
	}
	courant = lire(t.LEAE, iCourant);
	if (but(courant))
	{
		return true;
	}

	inserer(t.LEE, longueur(t.LEE), courant); //insertion du premier élément
	supprimer(t.LEAE, iCourant);//suppression du premier élément
	Etat e;
	if (courant.vide.ord != 0)
	{
		if (!appartient(deplacement(NORD, courant), t))
		{
			e = deplacement(NORD, courant);
			e.LEE = longueur(t.LEE) - 1; // insertion en dernière position de lsite LEE
			inserer(t.LEAE, 0, e); //insertion en dernière position de la liste LEAE
		}
	}

	//if (courant.vide.abs != 0)
	{
		if (!appartient(deplacement(OUEST, courant), t))
		{
			e = deplacement(OUEST, courant);
			e.LEE = longueur(t.LEE) - 1; // insertion en dernière position de lsite LEE
			inserer(t.LEAE, 0, e); //insertion en dernière position de la liste LEAE
		}
	}


	if (courant.vide.ord != t.nbL - 1)
	{
		if (!appartient(deplacement(SUD, courant), t))
		{
			e = deplacement(SUD, courant);
			e.LEE = longueur(t.LEE) - 1; // insertion en dernière position de lsite LEE
			inserer(t.LEAE, 0, e); //insertion en dernière position de la liste LEAE
		}
	}

	//if (courant.vide.abs != t.nbC - 1)
	{
		if (!appartient(deplacement(EST, courant), t))
		{
			e = deplacement(EST, courant);
			e.LEE = longueur(t.LEE) - 1; // insertion en dernière position de lsite LEE
			inserer(t.LEAE, 0, e); //insertion en dernière position de la liste LEAE
		}
	}


	return false;
}

/**
* @brief Afficher le contenue des adev et dev
* @param [in] t, tableau 2D à afficher
*/
void afficher(Taquin& t) {
	cout << "Iteration " << longueur(t.LEE);
	cout << endl << "*** LEAE - long : " << longueur(t.LEE) << endl;
	for (unsigned int i = 0; i < longueur(t.LEE); i++)
	{
		cout << "index :" << i << endl;
		afficher(lire(t.LEE, i));
		cout << "f=g+h=" << lire(t.LEE, i).g << "+" << lire(t.LEE, i).h << "=" << f(lire(t.LEE,i)) << endl;
	}

	cout << "Fin iteration " << longueur(t.LEE) << endl << endl;

	//cout << "Iteration " << longueur(t.LEE);
	//cout << endl << "*** LEAE - long : " << longueur(t.LEAE) << endl;
	//for (unsigned int i = 0; i < longueur(t.LEAE); i++)
	//{
	//	afficher(lire(t.LEAE, i));
	//	cout << "f=g+h=" << lire(t.LEAE, i).g << "+" << lire(t.LEAE, i).h << "=" << f(lire(t.LEAE,i)) << endl;
	//}

	//cout << "Fin iteration " << longueur(t.LEE) << endl << endl;
}

/**
* @brief detruire, désalloue un taquin
* @param [in-out] t, tableau à 2 dimensions à détruire (Tableau2D)
*/
void detruire(Taquin& t)
{	
	Etat e;
	for (unsigned int i = 0; i < longueur(t.LEAE); i++)
	{
		e = lire(t.LEAE, i);
		detruire(e.tab2D);
	}
	for (unsigned int i = 0; i < longueur(t.LEE); i++)
	{
		e = lire(t.LEE, i);
		detruire(e.tab2D);
	}
	detruire(t.LEAE);
	detruire(t.LEE);
}

/* @brief renvoie vrai si l‘état existe déjà dans le taquin
* @param [in] ef
* @param [in] t
* @return bool
*/
bool appartient(const Etat& ef, Taquin& t)
{
	for (unsigned int i = 0; i < longueur(t.LEE); i++)
	{
		if (Same(lire(t.LEE, i), ef))
		{
			return true;
		}
	}
	for (unsigned int i = 0; i < longueur(t.LEAE); i++)
	{
		if (Same(lire(t.LEAE, i), ef))
		{
			return true;
		}
	}
	return false;
}

/* @brief renvoie vrai s’il s’agir de l’état final, faux sinon
* @param [in] e
* @return bool
*/
bool but(const Etat& e)
{
	// On crée l'état final
	Etat eFinal2;
	initialiser(eFinal2.tab2D, e.tab2D.nbL, e.tab2D.nbC);
	unsigned int cpt;
	// créer les différents états finaux possibles et les introduit dans eFinaux
	for (unsigned int k = 0; k < e.tab2D.nbC; k++)
	{
		cpt = 1;
		for (unsigned int i = 0; i < eFinal2.tab2D.nbL; i++)
		{
			for (unsigned int j = 0; j < eFinal2.tab2D.nbC; j++)
			{
				eFinal2.tab2D.tab[i][j] = ((cpt + (k - 1)) % eFinal2.tab2D.nbC) + 1 + eFinal2.tab2D.nbC * i;
				cpt++;
				if (eFinal2.tab2D.tab[i][j] == eFinal2.tab2D.nbL *eFinal2.tab2D.nbC)
				{
					eFinal2.tab2D.tab[i][j] = 0;
				}

			}
		}
		if (Same(eFinal2, e))
		{
			detruire(eFinal2.tab2D);
			return true;
		}
	}
	return false;
}

/**
* @brief renvoie l'heuristique de l'etat
* @param [in-out] e, L'Etat de la liste
* @return h
*/
unsigned int heuristique(Etat& e)
{
	unsigned int NBeFin = 0;
	unsigned int h = e.tab2D.nbL * e.tab2D.nbC;
	unsigned int h1[5];
	unsigned int cpt;
	// On crée l'état final
	Etat eFinal2;
	initialiser(eFinal2.tab2D, e.tab2D.nbL, e.tab2D.nbC);

	// créer les différents états finaux possibles et les introduit dans eFinaux
	for (unsigned int k = 0; k < e.tab2D.nbC; k++)
	{
		cpt = 1;
		for (unsigned int i = 0; i < eFinal2.tab2D.nbL; i++)
		{
			for (unsigned int j = 0; j < eFinal2.tab2D.nbC; j++)
			{
				eFinal2.tab2D.tab[i][j] = ((cpt + (k - 1)) % eFinal2.tab2D.nbC) + 1 + eFinal2.tab2D.nbC * i;
				cpt++;
				if (eFinal2.tab2D.tab[i][j] == eFinal2.tab2D.nbL *eFinal2.tab2D.nbC)
				{
					eFinal2.tab2D.tab[i][j] = 0;
				}

			}
		}
		h1[k] = 0;
		for (unsigned int i = 0; i < eFinal2.tab2D.nbL; i++)
		{
			for (unsigned int j = 0; j < eFinal2.tab2D.nbC; j++)
			{
				if ((e.tab2D.tab[i][j] != eFinal2.tab2D.tab[i][j]) && (e.tab2D.tab[i][j] != 0))
				{
					h1[k]++;
				}
			}
		}
		NBeFin++;
	}

	h = h1[0];
	for (unsigned int i = 0; i < NBeFin; i++)
	{
		if (h1[i] < h)
		{
			h = h1[i];
		}
	}
	return h;
}

void afficherSolution(Taquin& t)
{
	unsigned int j = lire(t.LEAE, t.LEAE.index).g, g;
	cout << "Solution en " << lire(t.LEAE, t.LEAE.index).g << " mouvements" << endl;
	inserer(t.LEE, longueur(t.LEE), lire(t.LEAE, t.LEAE.index)); //insertion du premier élément
	supprimer(t.LEAE, t.LEAE.index);//suppression du premier élément
	for (unsigned int i = 0; i < j + 1; i++)
	{
		g = t.LEE.nb - 1;
		for (unsigned int k = 0; k < j - i; k++)
		{
			g = lire(t.LEE, g).LEE;
		}
		afficher(lire(t.LEE, g));
	}
}
