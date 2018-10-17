/*
 
 ######  #     #   ###     #       #     ######
 #       ##    #  #   #                  #
 #       # #   #   #      ##      ##     #
 #####   #  #  #    #      #       #     #####
 #       #   # #     #     #       #     #
 #       #    ##  #   #    #       #     #
 ######  #     #   ###   #####   #####   ######    2017-2018
 
 */


#include <stdlib.h>

#include "filtrages.h"

/*!
 \file filtrages.c
 \author 
 \date 6 décembre 2017
 \brief module contenant les fonctions de corrections des défauts d'image, filtrages, convolutions etc.
 */



/*!
 \fn unsigned char * filtrerMedianImageNB(unsigned char *img,int xs,int ys,int tailleFiltre,int *nc,int *nl)
 \brief applique le filtrage médian à tous les pixels de l'image (suffisamment éloignés des bords)
 \param img : adresse du bitmap
 \param xs : largeur de l'image
 \param ys : hauteur de l'image
 \param tailleFiltre : taille de la fenêtre de filtrage (doit être impaire, valeur conseillée 5)
 \param nc : pointeur sur le nombre de colonnes (modifiable) de l'image résultat
 \param nl : pointeur sur le nombre de lignes (modifiable) de l'image résultat
 \return l'image obtenue
 */

unsigned char * filtrerMedianImageNB(unsigned char *img, int xs, int ys, int tailleFiltre,int *nc,int *nl)
{
    unsigned char *res=NULL;
    
    /* ajouter votre code ici */
    
    *nl=ys;
    *nc=xs;
    return res;
}

/*!
 \fn unsigned char * filtrerImageNB(unsigned char *img,int xs,int ys,int tailleFiltre,int *nc,int *nl)
 \brief applique le filtrage moyenne à tous les pixels de l'image (suffisamment éloignés des bords)
 \brief à améliorer en passant le filtre en paramètre
 \param img : adresse du bitmap
 \param xs : largeur de l'image
 \param ys : hauteur de l'image
 \param tailleFiltre : taille de la fenêtre de filtrage (doit être impaire, valeur conseillée 5)
 \param nc : pointeur sur le nombre de colonnes (modifiable) de l'image résultat
 \param nl : pointeur sur le nombre de lignes (modifiable) de l'image résultat
 \return l'image obtenue
 */

unsigned char * filtrerImageNB(unsigned char *img, int xs, int ys, int tailleFiltre,int *nc,int *nl)
{
    unsigned char *res=NULL;
    
    /* ajouter votre code ici */
    
    *nl=ys;
    *nc=xs;
    return res;
}


