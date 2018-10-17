#include "tests.h"

t_grille grille;
INDEX n = 32;

/** \internal test la fonction 'grille_init' */
 void test_grille_init(void) {
	grille_init(&grille, n);
	CU_ASSERT(grille.n == n);
	CU_ASSERT(grille.cases != NULL);
	grille_deinit(&grille);
}
/** \internal : teste la fonction "grille_deinit" */
void test_grille_deinit(void) {
	grille_init(&grille, n);
	grille_deinit(&grille);
	CU_ASSERT(grille.cases==NULL);
}

/** \internal : teste la fonction " grille_get" */
void test_grille_get(void) {
	grille_init(&grille, 16);

	t_tuile tuile;
	tuile_init(&tuile);
	tuile_set_case(&tuile, TYPE_USINE, 0);
	tuile_set_case(&tuile, TYPE_FORET, 1);
	tuile_set_case(&tuile, TYPE_LAC, 2);
	tuile_set_case(&tuile, TYPE_VILLE, 3);
	tuile_set_case(&tuile, TYPE_RESSOURCE, 4);
	tuile_set_case(&tuile, TYPE_USINE, 5);

	grille_insert(&grille, &tuile, 0, 0);


	t_case * case1 = grille_get(&grille,0,2);
	CU_ASSERT(case1->type==TYPE_RESSOURCE);
	case1=grille_get(&grille,0,0);
	CU_ASSERT(case1->type==TYPE_USINE);
	case1=grille_get(&grille,0,1);
	CU_ASSERT(case1->type==TYPE_LAC);
	case1=grille_get(&grille,1,0);
	CU_ASSERT(case1->type==TYPE_FORET);
	case1=grille_get(&grille,1,1);
	CU_ASSERT(case1->type==TYPE_VILLE);
	case1=grille_get(&grille,1,2);
	CU_ASSERT(case1->type==TYPE_USINE);
	grille_deinit(&grille);
}

/** \internal test la fonction grille_can_insert */
void test_grille_can_insert(void) {

	grille_init(&grille, n);

	t_tuile tuiles[3];
	BYTE i, j;
	for (i = 0 ; i < 3 ; i++) {
		tuile_init(tuiles + i);
		for (j = 0 ; j < 6 ; j++) {
			tuile_set_case(tuiles + i, TYPE_VILLE, j);
		}
	}

	t_tuile * first = tuiles + 0;
	CU_ASSERT(grille_can_insert(&grille, first, n + 1, 0) == 0);
	CU_ASSERT(grille_can_insert(&grille, first, 0, n + 1) == 0);
	CU_ASSERT(grille_can_insert(&grille, first, n + 1, n + 1) == 0);
	CU_ASSERT(grille_can_insert(&grille, first, 0, 0) == 0);

	grille_insert(&grille, first, 0, 0);

	t_tuile * second = tuiles + 1;
	CU_ASSERT(grille_can_insert(&grille, second, 0, 0) == 0);
	CU_ASSERT(grille_can_insert(&grille, second, 0, 1) == 1);
	CU_ASSERT(grille_can_insert(&grille, second, 0, 2) == 1);
	CU_ASSERT(grille_can_insert(&grille, second, 1, 0) == 1);
	CU_ASSERT(grille_can_insert(&grille, second, 1, 1) == 1);
	CU_ASSERT(grille_can_insert(&grille, second, 1, 2) == 1);

	/** bottom left corner == lac */
	tuile_set_case(second, TYPE_LAC, 4);
	grille_insert(&grille, second, 0, 2);

	t_tuile * third = tuiles + 2;
	CU_ASSERT(grille_can_insert(&grille, third, 0, 4) == 0); /** insertion sur case 'L' */
	CU_ASSERT(grille_can_insert(&grille, third, 1, 4) == 1);
	grille_deinit(&grille);
}

/** \internal : teste la fonction "grille_insert" */
 void test_grille_insert(void) {
	grille_init(&grille, n);
	 
	 t_tuile tuile;
	tuile_init(&tuile);
	tuile_set_case(&tuile, TYPE_USINE, 0);

	int status;
	status=grille_insert(&grille, &tuile, 0, 0);
	t_case * case1=grille_get(&grille,0,0);
	CU_ASSERT(status==1&&case1->type==TYPE_USINE);

	grille_deinit(&grille);

	/** reinitialise la grille */
	grille_init(&grille, n);
	
	/** 3 tuiles pleines de villes */
	t_tuile tuiles[4];
	unsigned int nb_tuiles = sizeof(tuiles) / sizeof(t_tuile);
	BYTE i, j;
	for (i = 0 ; i < nb_tuiles ; i++) {
		tuile_init(tuiles + i);
		for (j = 0 ; j < 6 ; j++) {
			tuile_set_case(tuiles + i, TYPE_VILLE, j);
		}
	}

	tuiles[0].rotation = NORD;
	tuiles[1].rotation = SUD;
	tuiles[2].rotation = EST;
	tuiles[3].rotation = OUEST;

	INDEX m = n / 2;
	grille_insert(&grille, tuiles + 0, m, m);
	grille_insert(&grille, tuiles + 1, m + 1, m);
	grille_insert(&grille, tuiles + 2, m + 2, m);
	grille_insert(&grille, tuiles + 3, m - 2, m + 1);
	
	/** La grille devrait ressembler à:
	 *
	 *       x=m	
	 *        
	 * y=m    V V V V V
	 *    V V V V V V V
	 *    V V V V V
	 */
	INDEX pos[17][2] = {
		/** 1ère ligne */
		{m, m}, {m + 1, m}, {m + 2, m}, {m + 3, m}, {m + 4, m},

		/** 2eme ligne */
		{m - 2, m + 1}, {m - 1, m + 1}, {m, m + 1}, {m + 1, m + 1},
		{m + 2, m + 1}, {m + 3, m + 1}, {m + 4, m + 1},

		/** 3eme ligne */
		{m - 2, m + 2}, {m - 1, m + 2}, {m, m + 2},
		{m + 1, m + 2}, {m + 2, m + 2}
	};

	for (i = 0 ; i < 17 ; i++) {
		t_case * c = grille_get(&grille, pos[i][0], pos[i][1]);
		CU_ASSERT(c != NULL);
		CU_ASSERT(c->type == TYPE_VILLE);
	}
	CU_ASSERT(grille_get(&grille, m - 3, m) == NULL);
	grille_deinit(&grille);
}

/** \internal : teste la fonction "grille_remove" */
 void test_grille_remove(void) {
	/** reinitialise la grille */
	grille_init(&grille, n);
	
	/** 3 tuiles pleines de villes */
	t_tuile tuiles[4];
	unsigned int nb_tuiles = sizeof(tuiles) / sizeof(t_tuile);
	BYTE i, j;
	for (i = 0 ; i < nb_tuiles ; i++) {
		tuile_init(tuiles + i);
		for (j = 0 ; j < 6 ; j++) {
			tuile_set_case(tuiles + i, TYPE_VILLE, j);
		}
	}

	tuiles[0].rotation = NORD;
	tuiles[1].rotation = SUD;
	tuiles[2].rotation = EST;
	tuiles[3].rotation = OUEST;

	INDEX m = n / 2;
	grille_insert(&grille, tuiles + 0, m, m);
	grille_insert(&grille, tuiles + 1, m + 1, m);
	grille_insert(&grille, tuiles + 2, m + 2, m);
	grille_insert(&grille, tuiles + 3, m - 2, m + 1);
	
	/** La grille devrait ressembler à:
	 *
	 *       x=m	
	 *        
	 * y=m    V V V V V
	 *    V V V V V V V
	 *    V V V V V
	 */
	CU_ASSERT(grille_remove(&grille, tuiles + 0) == 4);

	grille_deinit(&grille);
}

/** \internal : test la fonction 'grille_get_village' */
 void test_grille_get_village(void) {
	/** reinitialise la grille */
	grille_init(&grille, 32);
	
	/** 3 tuiles pleines de villes */
	t_tuile tuiles[4];
	unsigned int nb_tuiles = sizeof(tuiles) / sizeof(t_tuile);
	BYTE i, j;
	for (i = 0 ; i < nb_tuiles ; i++) {
		tuile_init(tuiles + i);
		for (j = 0 ; j < 6 ; j++) {
			tuile_set_case(tuiles + i, TYPE_VILLE, j);
		}
	}

	tuiles[0].rotation = NORD;
	tuiles[1].rotation = SUD;
	tuiles[2].rotation = EST;
	tuiles[3].rotation = OUEST;

	INDEX m = n / 2;
	grille_insert(&grille, tuiles + 0, m, m);
	grille_insert(&grille, tuiles + 1, m + 1, m);
	grille_insert(&grille, tuiles + 2, m + 2, m);
	grille_insert(&grille, tuiles + 3, m - 2, m + 1);
	
	/** La grille devrait ressembler à:
	 *
	 *       x=m	
	 *        
	 * y=m    V V V V V
	 *    V V V V V V V
	 *    V V V V V
	 */
	CU_ASSERT(grille_get_village(&grille, m, m) == 17);
	CU_ASSERT(grille_get_village(&grille, m, m) == 0);

	for (i = 0 ; i < nb_tuiles ; i++) {
		for (j = 0 ; j < 6 ; j++) {
			FLAG_RESET(tuiles[i].cases[j].flags);
		}
	}
	
	CU_ASSERT(grille_get_village(&grille, m, m) == 17);
	grille_deinit(&grille);
}

/** \internal : ajoute les tests à la suite */
void test_grille(CU_pSuite suite) {
	CU_add_test(suite, "grille_init", test_grille_init);
	CU_add_test(suite, "grille_deinit", test_grille_deinit);
	CU_add_test(suite, "grille_can_insert", test_grille_can_insert);
	CU_add_test(suite, "grille_get", test_grille_get);
	CU_add_test(suite, "grille_insert", test_grille_insert);
	CU_add_test(suite, "grille_remove", test_grille_remove);
	CU_add_test(suite, "grille_get_village", test_grille_get_village);
}

/** \internal : initialise la suite */
int test_init_grille(void) {
	return (0);
}

/** \internal : deinitialise la suite */
int test_deinit_grille(void) {
	return (0);
}


