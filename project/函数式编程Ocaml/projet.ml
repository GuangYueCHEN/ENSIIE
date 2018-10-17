(*Question 1*)
(*Ecrire une fonction sum: int list -> int qui, sur la donne ́e d’une liste d’entiers l, calcule la somme des elements de l.*)


(** sum : int list -> int
@param l Une liste des entiers
@return la somme des elements de l
*)

let sum l=List.fold_right ( function x-> function acc -> x+acc) l 0 
;;
(* tester list =[1; 2; 3; 4; 5; 6; 7; 8]
- : int = 36*)





(*Question 2
Ecrire une fonction powerset: ’a list -> (’a list) list qui, sur la donnee d’une liste l, retourne la liste de toutes les sous-listes que l’on peut extraire de l*)

(** merge : 'a -> 'a list list -> 'a list list 
@param x un entier , l Une liste 
@return une liste de 'a liste qui contient x dans chaque 'a liste
*)

let rec merge x l = match l with 
  |[]->[]
  |a::r->(x::a)::(merge x r);;

(** powerset1 : 'a list -> 'a list list 
@param l Une liste 
@return une liste de 'a liste qui contient tous les sou-ensembles du liste l ,sauf '[]'
*)
let rec powerset1 l = match l with 
  |[]->[]
  |a::r->([a]::(powerset1 r))@(merge a (powerset1 r))
;;

(** powerset : 'a list -> 'a list list 
@param l Une liste 
@return une liste de 'a liste qui contient tous les sou-ensembles du liste l , contient '[]'
*)
let powerset l= let ml =powerset1 l in ([])::ml
;;

(* tester list =[1; 3; 4; 7]
int list list =[[]; [1]; [3]; [4]; [7]; [4; 7]; [3; 4]; [3; 7]; [3; 4; 7]; [1; 3]; [1; 4];
 [1; 7]; [1; 4; 7]; [1; 3; 4]; [1; 3; 7]; [1; 3; 4; 7]]*)








(*Question 3*)
(*Utiliser les deux questions precedentes pour definir une fonction subset_sum_0: int list -> int -> int repondant au probleme SUBSET-SUM-OPT*)

(** subset_sum_0 : int list -> int -> int = <fun>
@param l Une liste des entiers ,s un entier
@return un entier qui est le plus grand somme des sous-ensembles de l mais inderieur à s 
*)
let subset_sum_0 l s = List.fold_right 
(function l-> function max->let sum = sum l in 
if sum>max&&sum<=s then sum else max)
 (powerset l) 0
;;
(* tester a la fin ensemble*)






(*Question 4*)
(* Ecrire une fonction get all sums: int list -> int list reposant sur l’algorithme precedent. 
L’utilisation de fonctions auxiliaires est recommande ́.*)

(** get_all_sums : int list -> int list
@param l Une liste des entiers 
@return une liste des entiers qui cotient tous les sommes des sous-ensembles de l 
*)
let rec get_all_sums l = 
   match l with
   |[]->[0]
   |a::r ->(get_all_sums r)@(  List.map(function x->x+a) (get_all_sums r)  )
;;

(* tester list =[1; 3; 4; 7]
int list = [0; 7; 4; 11; 3; 10; 7; 14; 1; 8; 5; 12; 4; 11; 8; 15]*)






(*Question 5*)
(* E crire une fonction subset sum 1: int list -> int -> int repondant au proble`me 
SUBSET-SUM- OPT a` l’aide de la fonction precedente. *)

(** subset_sum_1 : int list -> int -> int 
@param l Une liste des entiers ,s un entier 
@return un entier qui est le plus grand somme des sous-ensembles de l mais inderieur à s 
*)
let rec  subset_sum_1 l s=List.fold_right 
(function x -> function y -> if x>y&&x<=s then x else y) 
(get_all_sums l) 0;;
(* tester a la fin ensemble*)








(*Question 6*)
(* Ecrireunefonctioncleanup:intlist->int->float->intlistreposantsurl’algorithme3. 
Testez la fonction avec s = 90, δ = 0.1 et la liste des entiers de 1 a` 100, 
et essayez d’expliquer ce qu’elle fait dans votre rapport. *)


(** insert : 'a -> 'a list -> 'a list
@param x un element,l Une liste croissante
@return une liste croissante qui contient  le element x
*)
let rec insert x l =
 match l with
 |[] -> [x]
 |h::t ->if x <= h then x :: h :: t else h :: insert x t
;;

(** sort : 'a list -> 'a list 
@param l Une liste 
@return une liste croissante avoir les meme elements
*)
let rec sort l = match l with 
 |[] -> []
 |h::t -> insert h (sort t)
;;


(* testerlist =[1; 7; 4; 3]
int list = [1; 3; 4; 7]*)




(** clean_up : int list -> int -> float -> int list
@param l Une liste des entiers , s un entier ,delta un float 
@return une liste apres lèalgorithme nettoyage
*)
let clean_up l s delta = let ml = sort l in match ml with 
| [] ->[]
|a::r -> List.fold_left 
    (function liste_t -> function value -> let m = match (List.rev liste_t) with []-> s |last::r->last in 
    	if (float_of_int value)>(1.0+.delta)*.(float_of_int m)&&value<=s then  liste_t@[value] else liste_t)
    [a] r 
;;

(** cree : int -> int list
@param i un entier 
@return une liste contient les entiers de i à 100
*)
let rec cree i= if i<=100 then i::(cree (i+1)) else [];;

(* tester s = 90, δ = 0.1 et la liste des entiers de 1 a` 100 
- : int list =
[1; 2; 3; 4; 5; 6; 7; 8; 9; 10; 12; 14; 16; 18; 20; 23; 26; 29; 32; 36; 40;
 45; 50; 56; 62; 69; 76; 84]*)
clean_up (cree 1) 90 0.1;;

(* tester s = 90, δ = 0.01 et la liste des entiers de 1 a` 100 
- : int list =
[1; 2; 3; 4; 5; 6; 7; 8; 9; 10; 11; 12; 13; 14; 15; 16; 17; 18; 19; 20; 21;
 22; 23; 24; 25; 26; 27; 28; 29; 30; 31; 32; 33; 34; 35; 36; 37; 38; 39; 40;
 41; 42; 43; 44; 45; 46; 47; 48; 49; 50; 51; 52; 53; 54; 55; 56; 57; 58; 59;
 60; 61; 62; 63; 64; 65; 66; 67; 68; 69; 70; 71; 72; 73; 74; 75; 76; 77; 78;
 79; 80; 81; 82; 83; 84; 85; 86; 87; 88; 89; 90]*)
clean_up (cree 1) 90 0.01;;









(*Question 7*)
(* E ́crireunefonctionsubset sum 2: float -> int list -> int -> int  
qui utilise la fonction precedente pour re ́pondre au proble`me SUBSET-SUM-OPT.
 L’argument de type float correspond a` la pre ́cision δ utilise ́e lors du nettoyage.
Dans un premier temps, on pourra faire des tests avec δ = 0.01. N’he ́sitez pas ensuite a`
 essayer des valeurs de plus en plus petites pour δ *)

(** subset_sum_2x : int list -> int -> float -> int list
@param l Une liste des entiers , s un entier ,delta un float 
@return une liste des entiers qui sont les somme des sou-ensembles mais apres nettoyage
*)
let rec subset_sum_2x l s delta=  
match l with
   |[]->[0]
   |a::r ->  let xl = subset_sum_2x r s delta  in  
   clean_up (xl@(  List.map(function x->x+a) xl ) ) s delta
;;


(** subset_sum_2 : int list -> int -> float -> int
@param l Une liste des entiers , s un entier ,delta un float 
@return un entier qui est le plus grand somme des sous-ensembles de l mais inderieur à s 
*)
let subset_sum_2 l s delta = let ml = List.rev (subset_sum_2x l s delta )in 
   match ml with []->0
   |a::r-> a;;

(* tester s = 90, δ = 0.1 et la liste des entiers de 1 a` 100 
- : int = 84*)
subset_sum_2(cree 1) 90 0.1;;
(* tester s = 90, δ = 0.01 et la liste des entiers de 1 a` 100 
- : int = 90*)
subset_sum_2(cree 1) 90 0.01 ;;  
 
(*le plus petit delta , le plus correct*)








(*Question 8*)
(*  Question 8
E ́crire une fonction is feasible: int -> int list -> int list -> bool qui, sur la donnee d’un entier cible s,
 d’une liste l1 d’entiers croissants et d’une liste l2 d’entiers de ́croissants, retourne true si s s’ecrit 
comme la somme d’un e ́le ́ment de l1 et d’un e ́le ́ment de l2, et false sinon*)



(** is_feasible : int -> int list -> int list -> bool 
@param somme un entier , liste1 Une liste des entiers  croissants, liste2 Une liste des entiers de ́croissant
@return true si somme s’ecrit comme la somme d’un element de liste1 et d’un element de liste2, et false sinon 
*)
let  rec is_feasible somme liste1 liste2 = match liste1 with 
|[]->false
|a::r-> let l = List.map (function x -> x+a ) liste2 in 
             match l with 
             |[] -> false
             |aa::r2-> let truth =is_feasible somme r liste2 in 
                 if ( aa<somme ) then  truth 
                else 
                       let res= List.fold_right (function x -> function y -> if x!=somme then (0+y) else (1+y) ) l 0 in
                       if res==0 then false else true
                   ;;

(* tester somme = 12 ,  liste1 = [1;2;4;7] , liste2 =[10;8;2] 
- : bool = true*)
is_feasible 12 [1;2;4;7] [10;8;2] ;;
(* tester somme = 16 ,  liste1 = [1;2;4;7] , liste2 =[10;8;2] 
- : bool = false*)
is_feasible 16 [1;2;4;7] [10;8;2] ;;

          






(*Question 9*)
(* En s’inspirant de la question pre ́ce ́dente, e ́crire une fonction best feasible: int -> int list -> int list 
-> int qui, sur la donne ́e d’un entier cible s, d’une liste l1 d’entiers croissants et une liste l2 d’entiers 
de ́croissants, retourne le plus grand entier s′ ≤ s tel que s′ = u + v avec u dans l1 et v dans l2 *)

(** best_feasible : int -> int list -> int list -> int
@param somme un entier , liste1 Une liste des entiers  croissants, liste2 Une liste des entiers de ́croissant
@return un entier qui est la somme d’un element de liste1 et d’un element de liste2, mais interieur à somme
*)
let  rec best_feasible somme liste1 liste2 = match liste1 with 
|[]->0
|a::r-> let l = List.map (function x -> x+a ) liste2 in 
             match l with 
             |[] -> 0
             |aa::r2-> let res  =best_feasible somme r liste2 in 
                 
                       let xx= List.fold_right (function x -> function y -> if x<=somme then x else y ) l aa in
                       if( res<=somme&&(somme-res)<(somme-xx) ) then res else xx ;;
                   ;;
(* tester somme = 16 ,  liste1 = [1;2;4;7] , liste2 =[10;8;2] 
- : int = 12*)
best_feasible 12 [1;2;4;7] [10;8;2] ;;
(* tester somme = 16 ,  liste1 = [1;2;4;7] , liste2 =[10;8;2] 
- : int = 15*)
best_feasible 16 [1;2;4;7] [10;8;2] ;;
(* tester somme = 1000 ,  liste1 = [10;20;40;70] , liste2 =[10;8;2] 
- : int = 80*)
best_feasible 1000 [10;20;40;70] [10;8;2] ;;







(*Question 10*)
(* Proposer une fonction subset sum 3: int list -> int -> int re ́pondant au proble`me SUBSET-SUM- OPT  *)

(** separer : 'a list -> 'a list * 'a list 
@param  l Une liste 
@return l1,l2 deux listes qui sont sous-ensembles de tailles égales
*)
let rec separer l = match l with
[]->([],[])
|a::b::r->let (l1,l2) =separer r in ((a::l1),(b::l2))
|a::r->let (l1,l2) =separer r in ((a::l1),l2);;
(* tester [10;20;40;70]
- : int list * int list = ([10; 40], [20; 70])*)


(** subset_sum_3 : int list -> int -> int
@param l Une liste des entiers ,s un entier 
@return un entier qui est le plus grand somme des sous-ensembles de l mais inderieur à s 
*)

let rec subset_sum_3 l s = let (l1,l2) =separer l in
   let n1=sort (get_all_sums l1 )in
   let n2=List.rev (sort (get_all_sums l2 )) in
   best_feasible s n1 n2 ;;







(*Question 11*)
(* E ́crire une fonction gen random: int -> int -> int list qui, sur la donne ́e de deux entiers naturels n et m,
 retourne un ensemble fini a` n e ́le ́ments contenant des entiers entre 0 et m − 1 inclus *)


(** gen_random : int -> int -> int list
@param n un entier  , m un entier  
@return une liste contient n nombres des entiers interieur à  m
*)
let rec gen_random n m = if n=0 then []
       else let ml = gen_random (n-1) m in 
            let x= Random.int(m-1) in 
            x::ml
          ;;
(*tester n = 4 , m = 10
test_liste1 : int list = [1; 2; 5; 4]*)
let test_liste1=gen_random 4 10 ;;




(*Question 12*)
(* Profitez de cette fonction gen random pour tester davantage vos diffe ́rentes approches.
Pre ́sentez dans votre rapport les avantages et les inconve ́nients de chacune des approches que 
vous avez implantees. *)


(*tester
res0 : int = 12 
res1 : int = 12
res2 : int = 12
res3 : int = 12*)

let res0 = subset_sum_0 test_liste1 20;;
let res1 = subset_sum_1 test_liste1 20;;
let res2 = subset_sum_2 test_liste1 20 0.01;;
let res3 = subset_sum_3 test_liste1 20;;
(*tester
res0 : int = 8
res1 : int = 8
res2 : int = 8
res3 : int = 8
*)
let test_liste2=gen_random 10 25 ;;
let res0 = subset_sum_0 test_liste2 9;;
let res1 = subset_sum_1 test_liste2 9;;
let res2 = subset_sum_2 test_liste2 9 0.01;;
let res3 = subset_sum_3 test_liste2 9;;



(*Question 13*)
(*  Jusqu’a` pre ́sent, les diffe ́rentes approches retournent uniquement un entier s′. Modifiez vos codes 
afin de retourner aussi un sous-ensemble dont la somme des e ́le ́ments vaut s′.
Le type de retour des fonctions passe donc de int a`int * int list *)

(*voir bonus.ml*)
