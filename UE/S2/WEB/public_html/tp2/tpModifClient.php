<?php

include("tpModele.php");
include("tpVue.php");

verif_authent();

$numCli=$_POST['numCli'];
$nomMod=$_POST['nomCli'];
$debitMod=$_POST['debitCli'];

enTete("Modification d'un client");

/*
 Faire appel à la fonction set_client, et afficher un message indiquant que la mise à jour a été effectuée, ou un message d'erreur
*/
if(set_client($numCli,$nomMod,$debitMod)){
   print "OK déja changé.\n ";
}else {
  print "été effectuée.\n ";
}


retour_menu();
pied();
?>


