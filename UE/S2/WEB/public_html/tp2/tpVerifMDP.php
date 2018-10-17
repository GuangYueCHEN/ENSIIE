<?php

include("tpVue.php");
include("tpModele.php");


//recuperer la valeur saisie dans le champ "mdp" 
$mdp = $_POST['mdp']; 

enTete("Vérification du mot de passe");

/*
  Si le mot de passe entré est vide ou faux (cf. fonction verif_mdp), afficher une erreur et un lien vers tpConnexion.php
 
  S'il est bon, rediriger vers la page index.php
*/
if($mdp=null||!verif_mdp($mdp)){
 print " passwords are wrong ";
 affiche_info('<a href="tpConnexion.php">retour</a>');
}
else  { 
	config(); 
	header("Location:index.php");
}
    
pied();

?>

