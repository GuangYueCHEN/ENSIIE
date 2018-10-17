-- ###################################################################
-- # Application : SQL script
-- # File        : create_show.sql
-- # Author      : novembre 2015 (Marie Szafranski)
-- # Function    : Create the database "show"
-- ###################################################################

DROP TABLE IF EXISTS Billet;
DROP TABLE IF EXISTS Representation;
DROP TABLE IF EXISTS Salle;
DROP TABLE IF EXISTS Spectacle; 

CREATE TABLE Spectacle(
   n_spectacle INTEGER, 
   nom VARCHAR(100) NOT NULL,
   duree INTEGER,
   s_type VARCHAR(10),
   CONSTRAINT pk_spectacle PRIMARY KEY (n_spectacle),
   CONSTRAINT dom_duree_spectacle CHECK (duree > 60 AND duree < 240),  
   CONSTRAINT dom_type_spectacle CHECK (s_type IN ('theatre', 'danse',
   'concert'))
   );

CREATE TABLE Salle(
   n_salle INTEGER,
   nb_places INTEGER, 
   CONSTRAINT pk_salle PRIMARY KEY (n_salle),
   CONSTRAINT dom_places_salle CHECK (nb_places >= 100 and nb_places
   <= 500)
   ); 

CREATE TABLE Representation(
   r_date DATE, 
   n_salle INTEGER, 
   prix INTEGER, 
   n_spectacle INTEGER, 
   CONSTRAINT pk_representation PRIMARY KEY (n_salle, r_date), 
   CONSTRAINT fk_representation_spectacle 
      FOREIGN KEY (n_spectacle) REFERENCES Spectacle ON DELETE CASCADE,
      -- si un spectacle est supprimé, ses représentations le sont
      -- également
   CONSTRAINT fk_representation_salle 
      FOREIGN KEY (n_salle) REFERENCES Salle ON DELETE RESTRICT, 
      -- si une salle est indisponible, on peut reprogrammer la
      -- représentation ailleurs mais pas automatiquement
   CONSTRAINT dom_prix_representation CHECK (prix > 50 and prix < 300) 
   ); 
   
CREATE TABLE Billet(
   n_billet SERIAL,
   n_salle INTEGER,
   b_date DATE,
   nom_client VARCHAR(50) NOT NULL,
   n_spectacle INTEGER,
   CONSTRAINT pk_billet PRIMARY KEY (n_billet),
   CONSTRAINT fk_billet_spectacle 
      FOREIGN KEY (n_spectacle) REFERENCES Spectacle ON DELETE CASCADE,
      -- si un spectacle est supprimé, ses billets le sont également
   CONSTRAINT fk_billet_representation 
      FOREIGN KEY (n_salle, b_date) 
      REFERENCES Representation (n_salle, r_date) ON UPDATE CASCADE 
      -- si une représentation est reprogrammée, on met à jour les billets
      );
