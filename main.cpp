#include "Taquin.h"
using namespace std;

int main(int argc, char* argv[]) {
	Taquin t;
	initialiser(t);
	do
	{
	} while (!jouer(t));
	afficherSolution(t);
	detruire(t);
	//system("pause");
}