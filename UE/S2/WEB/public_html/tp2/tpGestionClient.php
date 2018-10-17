<?php

include("tpModele.php");
include("tpVue.php");

verif_authent();

enTete("Gestion des clients");


/* recupération du numéro de client entré dans le formulaire de menu */
$numCli = $_POST['numCli'];

// si aucune case n'a été cochée
if(! isset($_POST['choix']) ){
    affiche_erreur("Merci de cocher une case");
}
// si le numéro de client n'a pas été renseigné
elseif ((! isset($numCli)) | $numCli == "" | ! is_numeric($numCli)) {
    affiche_erreur("Vous devez impérativement taper un numéro de client");
}
else{	
    switch ($_POST['choix'])
    {
        /* Affichage d'un client */
        case "v":
          $tab=get_client($numCli);
	    affiche_info("Consultation du numéro client : $numCli");
        if($tab[0]==0){
	  
        affiche_info("Nom : $tab[1]");  affiche_info("Débit:$tab[2]");
        } if($tab[0]==-1){
            affiche_erreur("aucun client n'a été trouvé avec le numéro donné");
        }if($tab[0]==-2){
            affiche_erreur("la requête n'a pas pu être exécutée ");
        }if($tab[0]==-3){
            affiche_erreur(" la connexion à la BD n'a pas réussi");
        }
		
	/*
	  Compléter pour afficher les informations demandées ou le cas d'erreur approprié
	*/
        break;

        /* Modification d'un client */
        case "m" :
	    affiche_info("Modification du client no : $numCli");
	    /* Compléter pour faire appel à la fonction affiche_form_modif() */
        $tab=get_client($numCli);
        if($tab[0]==0){
	  
      affiche_info("Nom : $tab[1]");  affiche_info("Débit:$tab[2]");
        affiche_form_modif($numCli, $tab[1],$tab[2]);
        } if($tab[0]==-1){
            affiche_erreur("aucun client n'a été trouvé avec le numéro donné");
        }if($tab[0]==-2){
            affiche_erreur("la requête n'a pas pu être exécutée ");
        }if($tab[0]==-3){
            affiche_erreur(" la connexion à la BD n'a pas réussi");
        }

        break;

        /* Enregistrement d'un achat */
        case "a" :
	    affiche_info("Achat du client no : $numCli");
	    /*Compléter : récupérer les infos sur le client et appeler la fonction affiche_form_achat() */
       $tab=get_client($numCli);
        if($tab[0]==0){
	  
      affiche_info("Nom : $tab[1]");  affiche_info("Débit:$tab[2]");
        affiche_form_achat($numCli,$tab[2]) ;          
        } if($tab[0]==-1){
            affiche_erreur("aucun client n'a été trouvé avec le numéro donné");
        }if($tab[0]==-2){
            affiche_erreur("la requête n'a pas pu être exécutée ");
        }if($tab[0]==-3){
            affiche_erreur(" la connexion à la BD n'a pas réussi");
        }
    
        break;

        /* Création d'un client */
        case "c" :
            affiche_info("Création du numéro client : $numCli");
	    /*Compléter : vérifier si le client existe, et appeler la fonction affiche_form_creation() si ce n'est pas le cas */
             $tab=get_client($numCli);
              if($tab[0]==0){
              affiche_erreur("le client existe");
	          } if($tab[0]==-1){
	           affiche_form_creation($numCli);
	          }if($tab[0]==-2){
	           affiche_erreur("la requête n'a pas pu être exécutée ");
	          }if($tab[0]==-3){
	           affiche_erreur(" la connexion à la BD n'a pas réussi");
	         }

break;

        /* ne devrait jamais se produire... */
        default : 
            affiche_erreur("Cocher une case");
        break;
    }//fin switch
	
}// fin else
	
retour_menu();
pied();

?>



