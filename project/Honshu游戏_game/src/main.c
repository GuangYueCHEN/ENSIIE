# include "honshu.h"

/**
 *	\internal affiche l'aide de lancement à l'utilisateur
 */
static void help(char * prog) {
	fprintf(stderr, ".-----------------------------------------------------------.\n");
	fprintf(stderr, "| usage: %s %-34s|\n", prog, "{-s [TUILE] [PARTIE]}");
	fprintf(stderr, "|                         {-r [MOYENNE] [AMPLITUDE]}        |\n");
	fprintf(stderr, "| avec: -s : charge une partie enregistré                   |\n");
	fprintf(stderr, "|            - TUILE  : fichier decrivant les tuiles        |\n");
	fprintf(stderr, "|            - PARTIE : le fichier de partie                |\n");
	fprintf(stderr, "|       -r : crée une nouvelle partie aléatoire             |\n");
	fprintf(stderr, "|            - MOYENNE   : taille moyenne de la carte n     |\n");
	fprintf(stderr, "|            - AMPLITUDE : amplitude de l'aléatoire sur n   |\n");
	fprintf(stderr, "|-----------------------------------------------------------|\n");
	fprintf(stderr, "| exemple:                                                  |\n");
	fprintf(stderr, "|    charger une partie                                     |\n");
	fprintf(stderr, "|    > %s %-36s|\n", prog, "-s ./bin/tuiles ./bin/saves/partie1");
	fprintf(stderr, "|                                                           |\n");
	fprintf(stderr, "|    generer une partie aléatoire                           |\n");
	fprintf(stderr, "|    > %s %-36s|\n", prog, "-r 16 8");
	fprintf(stderr, "|                                                           |\n");
	fprintf(stderr, "|    afficher l'aide                                        |\n");
	fprintf(stderr, "|    > %s %-36s|\n", prog, "--help");
	fprintf(stderr, "'-----------------------------------------------------------'\n");
}

/**
 *	\internal : une fonction interne pour convertir une chaine de caractères
 *              en entier non signé
 */
static unsigned int parse_uint(char * str) {
	unsigned int i;
	for (i = 0 ; str[i] ; i++) {
		if (*str < '0' || *str > '9') {
			return (0);
		}
	}
	int v = atoi(str);
	return (v < 0 ? 0 : (unsigned int)v);
}

/**
 *	\internal : main
 *  1) lis les arguments (voir --help)
 *  2) alloues/initialise la mémoire
 *  3) boucle infini de jeu
 *  4) libération de la mémoire, fin du programme
 */
int main(int argc, char ** argv) {
	t_hs * hs;
	if (argc == 1) {
		hs = hs_rand(32, 16);
	} else if (argc == 4 && strcmp(argv[1], "-s") == 0) {
		hs = hs_read(argv[2], argv[3]);
	} else if (argc == 4 && strcmp(argv[1], "-r") == 0) {
		unsigned int mean = parse_uint(argv[2]);
		unsigned int amplitude = parse_uint(argv[3]);
		if (mean <= 3) {
			help(argv[0]);
			return (EXIT_FAILURE);
		}
		hs = hs_rand(mean, amplitude);
	} else {
		help(argv[0]);
		return (EXIT_FAILURE);
	}

	if (hs == NULL) {
		fprintf(stderr, "%s erreur d'initialisation.\n", argv[0]);
		return (EXIT_FAILURE);
	}

	FLAG_SET(hs->flags, HS_INITIALIZED);
	fprintf(stderr, "Le jeu est initialisé\n");

	FLAG_SET(hs->flags, HS_RUNNING);
	fprintf(stderr, "Le jeu boucle\n");
	while (FLAG_ISSET(hs->flags, HS_RUNNING)) {
		entrer(hs);
		afficher(hs);
	/*	FLAG_UNSET(hs->flags, HS_RUNNING);*/
	}
	
	fprintf(stderr, "Le jeu est arrêté\n");

	/** libère la mémoire */
	hs_delete(hs);

	return (EXIT_SUCCESS);
}
