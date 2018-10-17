-- ###################################################################
-- # Application : PL/pgSQL script
-- # Fichier     : stock.sql
-- # Auteur      : yourself (dec 201)
-- ###################################################################

-- ###################################################################
-- # Q1 : modification de la table vin
-- ###################################################################

  ALTER TABLE vin
  DROP COLUMN stock ;


 ALTER TABLE vin
  ADD COLUMN stock INTEGER CHECK (stock>0);





-- ###################################################################
-- # Q2 et Q3 : fonctions pour initialiser les stocks
-- ###################################################################

-- ***
-- *** f_initialise_stock_vin(num_vin, qte)
-- *** --> Donner une description de la fonction





-- ***2222222222222222222222222222222222222222222222222222222222222222
CREATE OR REPLACE FUNCTION 
f_initialise_stock_vin(num_vin INTEGER, qte INTEGER) 
RETURNS void AS $fisv$
   BEGIN
   
  UPDATE vin
  SET stock=qte
  WHERE n_vin=num_vin;

   END;








$fisv$ LANGUAGE plpgsql;

-- ***
-- *** tests de la fonction f_initialise_stock_vin()
-- ***
SELECT f_initialise_stock_vin(170, 12);
SELECT f_initialise_stock_vin(170, -666);













-- ***3333333333333333333333333333333333333333333333333333333333333333333333
-- *** f_initialise_stock()
-- *** --> Donner une description de la fonction
-- ***
CREATE OR REPLACE FUNCTION f_initialise_stock() 
RETURNS void AS $fis$
   DECLARE
   curseur CURSOR FOR SELECT * FROM vin;
   num vin.n_vin%type;
      -- un curseur pour parcourir la table vin
   BEGIN
   
      FOR ligne IN curseur LOOP
        num := ligne.n_vin;
          EXECUTE  f_initialise_stock_vin(num,24);

      END LOOP;


      -- Un appel à la fonction f initialise stock vin serait bienvenu 
      -- EXECUTE f initialise stock vin(...)
   END;
$fis$ LANGUAGE plpgsql;

-- ***

-- *** tests de la fonction f_initialise_stock_vin()
-- ***
SELECT f_initialise_stock();













-- ###################################################################
-- # Q4 et Q5 : triggers 
-- ###################################################################

-- ***
-- *** f_verifie_stock() 
-- *** --> Donner une description de la fonction
-- ***
CREATE OR REPLACE FUNCTION f_verifie_stock () RETURNS TRIGGER AS
$fvs$
   DECLARE
    rest vin.stock%type; -- une variable pour mettre le stock disponible
   BEGIN
      select stock INTO rest from vin where n_vin=NEW.n_vin;
      if (rest<NEW.c_qte) THEN 
      
	 RAISE NOTICE '% fdqsjkfhsdjkqhfjksdq!!!!!!!!',NEW.n_vin;
	 return NULL;
	END IF;
END;
$fvs$ LANGUAGE plpgsql;

-- ***
-- *** d_verifie_stock() 
-- *** --> Donner une description du trigger
-- ***
DROP TRIGGER d_verifie_stock  ON commande;
CREATE TRIGGER d_verifie_stock BEFORE INSERT ON commande FOR EACH ROW
EXECUTE PROCEDURE f_verifie_stock();

-- ***
-- tests du trigger d_verifie_stock
-- ***
-- INSERT INTO commande

-- ***
-- *** f_diminue_stock()
-- *** --> Donner une description de la fonction
-- ***
CREATE OR REPLACE FUNCTION f_diminue_stock () RETURNS TRIGGER AS
$fds$
  DECLARE
    rest vin.stock%type; -- une variable pour mettre le stock disponible
   BEGIN
      select stock INTO rest from vin where n_vin=NEW.n_vin;
      if (rest>NEW.c_qte) THEN 
        UPDATE vin  SET stock=rest-NEW.c_qte  WHERE n_vin=NEW.n_vin;
	
	RETURN NEW;
	ELSE
	 RAISE NOTICE '% fdqsjkfhsdjkqhfjksdq!!!!!!!!',NEW.n_vin;
	END IF;

   END;
$fds$ LANGUAGE plpgsql;

-- ***
-- *** d_verifie_stock()
-- *** --> Donner une description du déclencheur
-- ***
DROP TRIGGER d_diminue_stock ON commande ;
DROP TRIGGER d_verifie_stock ON commande ;
CREATE TRIGGER d_diminue_stock before insert on commande
for each row
execUTE PROCEDURE f_diminue_stock();


