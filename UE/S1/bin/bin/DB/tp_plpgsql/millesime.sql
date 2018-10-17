-- ###################################################################
-- # Application : PL/pgSQL script
-- # Fichier     : millesime.sql
-- # Auteur      : yourself (dec 201)
-- ###################################################################

-- ###################################################################
-- # Q1 : table miroir
-- ###################################################################

-- ***
-- *** creation de vin_m, une table miroir de vin
-- ***  
DROP TABLE vin_m;
CREATE TABLE vin_m( 
   n_vin TEXT PRIMARY KEY,
  cru  CHARACTER VARYING(20),
  millesime INTEGER,
  region  CHARACTER VARYING(20),
  n_viticulteur INTEGER,
  stock INTEGER CHECK(stock>0)
   );  


-- ###################################################################
-- # Q2 : fonction
-- ###################################################################

-- ***
-- *** f_initialise_vin_m() 
-- *** --> Donner une description de la fonction
-- ***
CREATE OR REPLACE FUNCTION f_initialise_vin_m () RETURNS void AS $fun$
   DECLARE
      curseur CURSOR FOR SELECT * FROM vin;  -- un curseur pour parcourir la table vin
      num vin_m.n_vin%type;
      cruu vin.cru%type;
      mil vin.millesime%type;
      reg vin.region%type;
      viti vin.n_viticulteur%type;
      sto vin.stock%type;
      -- autres variables
      
   BEGIN
      RAISE NOTICE '*** Insertion dans vin_m ***';
      
      -- boucle sur le curseur
      FOR i IN curseur LOOP
      num:=i.n_vin;
      cruu:=i.cru;
      mil:=i.millesime;
      reg:=i.region;
      viti:=i.n_viticulteur;
      sto:=i.stock;
      	 -- affectation des valeurs courantes (si besoin)

          num:=mil||num;
	 -- création de la clé de vin_m
	 
      	  RAISE NOTICE '***INSERT % % % % % % ***',num,cruu,mil,reg,viti,sto;
	 -- affichage du tuple inséré (ça ne peut pas faire de mal)
	 INSERT INTO vin_m VALUES(num,cruu,mil,reg,viti,sto);   
      	 -- insertion du tuple dans vin_m
      
       END LOOP;
 EXCEPTION
    WHEN  DUP_VAL_ON_INDEX THEN
    RAISE DUP_VAL_ON_INDEX
    USING MESSAGE = 'qsssssssss % qssssssssss:'||$1;
    WHEN OTHERS THEN
    RAISE  OTHERS
    USING MESSAGE = 'qsssssssss % qssssssssss:'||$1;


   END;
$fun$ LANGUAGE plpgsql;

-- ***
-- *** tests de la fonction f_initialise_vin_m()
-- ***
DELETE  FROM vin_m;
SELECT f_initialise_vin_m();
SELECT f_initialise_vin_m(); -- pour tester l'exception


-- ###################################################################
-- # Q3 : déclencheur
-- ###################################################################

-- ***
-- *** f_calcule_millesime() 
-- *** --> Donner une description de la fonction
-- ***
--CREATE OR REPLACE FUNCTION f_calcule_millesime () RETURNS TRIGGER AS
--$fun$
  -- DECLARE
      -- ...
  -- BEGIN
      -- ...
 --  END;
--$fun$ LANGUAGE plpgsql;

-- ***
-- *** d_calcule_millesime() 
-- *** --> Donner une description du trigger
-- ***
--DROP TRIGGER d_calcule_millesime ON /* ... */;
--CREATE TRIGGER d_calcule_millesime /* ... */
--EXECUTE PROCEDURE f_calcule_millesime();

-- ***
-- tests du trigger d_calcule_millesime
-- ***
--INSERT INTO vin_m
--VALUES ('1988278', 'POMMARD', 1986, 'BOURGOGNE', 10);

--INSERT INTO vin_m
--VALUES ('1988278', 'POMMARD', NULL, 'BOURGOGNE', 10);

--DELETE FROM vin_m;
--SELECT f_initialise_vin_m();
