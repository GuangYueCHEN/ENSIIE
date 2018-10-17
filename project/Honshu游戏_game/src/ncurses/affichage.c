# include "honshu.h"
# include "ncurses/entree.h"
# include <ncurses.h>

# define WELCOME_MESSAGE ("< Appuyer sur une touche pour jouer >")
# define TUILES_TITLE ("< Les tuiles restantes >")
# define TUILES_X (6)
# define TUILES_Y (4)
# define GRILLE_TITLE ("< Grille >")
# define GRILLE_X (32)
# define GRILLE_Y (TUILES_Y)
# define GRILLE_EMPTY ('.')

struct s_afficheur{
};

/**
 *	\brief initialise l'afficheur
 *	\param hs : l'instance du jeu
 *	\return un nouvel afficheur (ou NULL)
 */
t_afficheur * afficheur_new(t_hs * hs){
	(void)hs;
	/* initialize afficheur */
	t_afficheur * afficheur=(t_afficheur *)malloc(sizeof (t_afficheur));
	if(afficheur==NULL)  return(NULL);

	/** initialisation de ncurses */
	initscr();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	timeout(-1);
	if (has_colors()) {
		start_color();
		init_pair(1, COLOR_GREEN, COLOR_BLACK);
		init_pair(2, COLOR_RED, COLOR_BLACK);
		init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	}
	int width, height;
	getmaxyx(stdscr, height, width);
	mvprintw(height / 2, (width - strlen(WELCOME_MESSAGE))/ 2, WELCOME_MESSAGE);
	return (afficheur);
}


/**
 *	\brief de-initialise l'afficheur
 *	\param afficheur : l'instance de l'afficheur
 */
void afficheur_delete(t_afficheur * afficheur){
	(void)afficheur;
	free(afficheur);
	endwin();
}

/**
 *	\internal : affiche une tuile
 */
static void afficher_une_tuile(t_tuile * tuile, INDEX x, INDEX y){
	BYTE i ;
	INDEX nx,ny;
	for(i=0;i<6;i++) {
		INDEX dx = DECALAGE[tuile->rotation][i][0];
		INDEX dy = DECALAGE[tuile->rotation][i][1];
		nx = x + dx * 2;
		ny = y + dy;
		mvprintw(ny, nx, "%c", case_char(tuile->cases[i].type));
	}
}

/**
 *	\internal : affiche toutes les tuiles dans la main
 */
static void afficher_tuiles(t_hs * hs){

	attron(A_BOLD);
	mvprintw(TUILES_Y - 2, TUILES_X - 5, TUILES_TITLE);
	attroff(A_BOLD);

	INDEX i;
	for(i=0;i<hs->nb_tuiles;i++){
		t_tuile * tuile = &(hs->tuiles[i]);
		INDEX x = TUILES_X + i%2*7 ;
		INDEX y = TUILES_Y + i/2*4;
		if (i == hs->entreur->tuile) {
			attron(A_BOLD);
		}
		if (FLAG_ISSET(tuile->flags, TUILE_SUR_CARTE)) {
			attron(COLOR_PAIR(2));
		}
		afficher_une_tuile(tuile,x,y);
		if (i == hs->entreur->tuile) {
			attroff(A_BOLD);
		}

		if (FLAG_ISSET(tuile->flags, TUILE_SUR_CARTE)) {
			attroff(COLOR_PAIR(2));
		}
	}
}

/**
 *	\internal : affiche les titres
 */
static void afficher_title(t_hs * hs){
	attron(A_BOLD);
	mvprintw(GRILLE_Y - 4, 1, "Total tiles: %d", hs->nb_tuiles);
	mvprintw(GRILLE_Y - 3, 1, "Current score: %d", 42);
	attroff(A_BOLD);
}

/**
 *	\internal : affiche la grille
 */
static void  afficher_grille(t_hs * hs){
	t_grille * grille = &(hs->grille);
	t_case * cases;
	attron(A_BOLD);
	mvprintw(GRILLE_Y - 2,
		GRILLE_X + (hs->grille.n * 2 - strlen(GRILLE_TITLE)) / 2 - 1,
		GRILLE_TITLE);
	attroff(A_BOLD);
	INDEX i,j;
	for(i=0;i<grille->n;i++){
		for(j=0;j<grille->n;j++){
			cases=grille_get(grille,i,j);
			char c = GRILLE_EMPTY;
			if (cases != NULL) {
				c = case_char(cases->type);
				if (cases->tuile == hs->tuiles + hs->entreur->tuile) {
					attron(COLOR_PAIR(2));
				}
			}
			mvprintw(GRILLE_Y + j, GRILLE_X + i * 2, "%c ", c);
			attroff(COLOR_PAIR(2));

		}
	}
}

/**
 *	\internal : affiche la tuile selectionné
 */
static void afficher_selection(t_hs * hs) {
	t_tuile * tuile = hs->tuiles + hs->entreur->tuile;
	if (FLAG_ISSET(tuile->flags, TUILE_SUR_CARTE)) {
		return ;
	}
	INDEX ix = hs->entreur->cursorX;
	INDEX iy = hs->entreur->cursorY;
	INDEX x = GRILLE_X + ix * 2;
	INDEX y = GRILLE_Y + iy;
	attron(COLOR_PAIR(grille_can_insert(&(hs->grille), tuile, ix, iy) ? 1 : 2));
	afficher_une_tuile(tuile, x, y);
	attroff(COLOR_PAIR(1) | COLOR_PAIR(2));
}

/**
 *	\brief affiche l'état actuel du jeu
 *	\param honshu : l'instance du jeu
 */
void afficher(t_hs * hs){

	clear();

	mvprintw(LINES -1, 0 ,   "< Honshu >");

	afficher_title(hs);

	afficher_tuiles(hs);

	afficher_grille(hs);
	
	afficher_selection(hs);

	refresh();

}
