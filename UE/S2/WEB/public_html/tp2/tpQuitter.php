<?php
include("tpModele.php");
include("tpVue.php");
enTete("BYE");
detruire_session();
affiche_info("Et maintenant <br/>Au revoir");
retour_menu();
pied();
?>
