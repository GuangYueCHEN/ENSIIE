<?php

include("tpModele.php");
include("tpVue.php");

verif_authent();

$numCli=$_POST['numCli'];
$montant=$_POST['montant'];


enTete("Enregistrement d'un achat");
if($montant==null)	affiche_erreur("Impossible d'enregistrer l'achat vide");
else if(insert_achat($numCli,$montant)) {
	affiche_info("Achat enregistré");
} else {
	affiche_erreur("Impossible d'enregistrer l'achat");
}

retour_menu();
pied();
?>


