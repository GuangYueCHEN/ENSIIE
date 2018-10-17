/**
 * \file	includes/grille.h
 * \authors	Romain PEREIRA, Douha OURIMI, Afizullah RAHMANY, GuangYue CHEN
 * \brief	Data structures and core functions
 */

# ifndef GRILLE_H
#	define GRILLE_H

# include "honshu.h"

/** \internal : on precise au compilateur que les structures existent */
typedef struct s_case t_case;
/** \internal : on precise au compilateur que les structures existent */
typedef struct s_tuile t_tuile;

/**
 *	\struct s_grille
 *
 *	La grille n*n de jeu sur laquelle on pose les tuiles
 */
typedef struct	s_grille {
	/** taille de la grille */
	INDEX n;

	/**
	 * tableau à 1 dimension de 't_case *', contenant:
	 * les cases de la grille
	 *
	 * l'indicage est:
	 *
	 *  0   1   ... n
	 * n+1 n+2  ... 2n
	 *          ...
	 *          ... n*n
	 */
	t_case ** cases;
}		t_grille;

/**
 *	\brief Initialises (et alloue) la grille
 *	\param grille : la grille
 *	\param n : la taille de la grille
 *	\return 1 si succès, 0 sinon
 */
int grille_init(t_grille * grille, INDEX n);

/**
 *	\brief Dé-alloue la grille
 *	\param grille : la grille
 */
void grille_deinit(t_grille * grille);

/**
 *	\brief Renvoie la case aux coordonnées \a x et \a y de la grille
 *	\param grille : la grille
 *	\param x : coordonnée x
 *	\param y : coordonnée y
 *	\return la case aux coordonnées (x, y) sur la grille (peut être NULL)
 *	\see includes/case.h
*/
t_case * grille_get(t_grille * grille, INDEX x, INDEX y);

 /**
  *	\brief Teste si la tuile peut être inséré aux coordonnées données.
  *	\param grille : la grille
  *	\param tuile : la tuile a inséré
  *	\param x : la coordonnée x
  *	\param y : la coordonnée y
  *	\return 1 si la tuile peut être inséré, 0 sinon
  */
int grille_can_insert(t_grille * grille, t_tuile * tuile, INDEX x, INDEX y);

/**
 *	\brief Insère la tuile dans la grille aux coordonnées (x, y)
 *	\param grille : la grille
 *	\param tuile : la tuile a inséré
 *	\param x : coordonnée x
 *	\param y : coordonnée y
 *	\return 1 si la tuile a été inséré, 0 sinon
 *	\attention : Aucuns tests d'insertion n'est effectué ici!
 *	\see grille_can_insert
 *	\see includes/tuile.h
 */
int grille_insert(t_grille * grille, t_tuile * tuile, INDEX x, INDEX y);

/**
 *	\brief Supprimes la tuile de la grille
 *	\param grille : la grille
 *	\param tuile : la tuile
 *	\return le nombre de tuile retiré (car les tuiles 'au dessus'
 *		peuvent être retiré si elles ne passent plus les tests
 *		de superposition)
 *	\see includes/tuile.h
 */
int grille_remove(t_grille * grille, t_tuile * tuile);

/**
 *	\brief : Comptes la taille d'un village
 *	\param grille : la grille
 *	\param x : coordonnée x d'une case
 *	\param y : coordonnée y d'une case
 *	\return La taille du village associé à la case. Si la case n'est
 *		pas une case 'VILLE', ou si la case a déjà été visité,
 *		alors renvoie 0
 *	\attention Les cases du meme village sont marqués par le flag 'T_VISITED'
 */
unsigned int grille_get_village(t_grille * grille, INDEX x, INDEX y);

# endif
