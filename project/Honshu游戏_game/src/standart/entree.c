# include "honshu.h"

/**
 *	\struct s_entreur
 *
 *	structure principal de l'afficheur
 */
struct s_entreur {

};

/**
 *	\brief initialise l'entreur
 *	\param hs : l'instance du jeu
 *	\return un nouvel entreur (ou NULL)
 */
t_entreur * entreur_new(t_hs * hs) {
	(void)hs;
	t_entreur * entreur = (t_entreur *) malloc(sizeof(t_entreur));
	return (entreur);
}

/**
 *	\brief de-initialise entreur
 *	\param entreur : l'instance de l'entreur
 */
void entreur_delete(t_entreur * entreur) {
	(void)entreur;
}

/**
 *	\brief met à jour les entrés utilisateurs
 *	\param honshu : l'instance du jeu
 */
void entrer(t_hs * hs) {
	(void)hs;
}

