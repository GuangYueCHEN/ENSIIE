/**
 *	\file	includes/honshu.h
 *	\authors	Romain PEREIRA, Douha OURIMI, Afizullah RAHMANY, GuangYue CHEN
 *	\brief	Les structures principales du jeu
 *
 *	Ce fichier contient toutes les fonctions principales du jeu
 *	(import, export...), et importes tous les fichiers header
 */

# ifndef HS_H
#	define HS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h> 
# include <time.h>
# include <errno.h>
# include <unistd.h>
# include "types.h"
# include "flags.h"
# include "grille.h"
# include "tuile.h"
# include "list.h"
# include "affichage.h"
# include "entree.h"

/** game status */
/** flag indiquant que le jeu est initialisé */
# define HS_INITIALIZED	(1 << 0)
/** flag indiquant que le jeu boucle infini */
# define HS_RUNNING	(1 << 1)

/** \internal : on signale que la structure existe */
typedef struct s_afficheur t_afficheur;
typedef struct s_entreur t_entreur;
/**
 *	\struct s_honshu
 *
 *	It holds the whole game state
 */
typedef struct	s_honshu {
	/** la grille  */
	t_grille grille;

	/** les tuiles (dans la main ET sur la carte) (\see tuile.h) */
	t_tuile * tuiles;

	/** taille du tableau 'tuiles' */
	unsigned int nb_tuiles;

	/** l'afficheur */
	t_afficheur * afficheur;

	/** l'entreur */
	t_entreur * entreur;

	/** flags */
	BYTE flags;
}		t_hs;

/**
 *	\brief Initialise le jeu avec le fichier donnée
 *	\param tuiles fichier où les tuiles sont déclarées
 *	\param save fichier ou le jeu est sauvegardé
 *	\return Une nouvelle partie d'honshu allouée et initialisée, NULL si erreur .
 */
t_hs * hs_read(char * tuiles, char * save);

/**
 *	\brief Initialise le jeu de manière aléatoire
 *	\param mean : mean valeur de 'n'
 *	\param amplitude : amplitude pour 'n'
 *	\return Une nouvelle partie d'honshu allouée et initialisée,
 *		generée de façon aléatoire
 *	, NULL si erreur 
 */
t_hs * hs_rand(INDEX mean, INDEX amplitude);

/**
 *	\brief "De-Alloue" le jeu
 *	\param hs : instance hs (partie jeu) qui va etre free
 *	(qui avait été allouée par hs_read/hs_rand)
 *	\see hs_read
 *	\see hs_rand
 */
void hs_delete(t_hs * hs);

/**
 *	\brief sauvegarde les tuiles et la partie
 *	\param hs : une instance du jeu
 *	\param tuiles_chemin : le chemin de la sauvegarde du fichier tuile 
 *	\param partie_chemin : le chemin de la sauvegarde du fichier partie
 *	\return : 1 si succès, 0 sinon
 */
int hs_export(t_hs * hs, char * tuiles_chemin, char * partie_chemin);

# endif
