(*Question 13*)
(*  Jusqu’a` pre ́sent, les diffe ́rentes approches retournent uniquement un entier s′. Modifiez vos codes 
afin de retourner aussi un sous-ensemble dont la somme des e ́le ́ments vaut s′.
Le type de retour des fonctions passe donc de int a`int * int list *)


(*les fonctions qui n'ont pas change*)
let sum l=List.fold_right ( function x-> function acc -> x+acc) l 0 
;;
let rec merge x l = match l with 
  |[]->[]
  |a::r->(x::a)::(merge x r)
;;

let rec powerset1 l = match l with 
  |[]->[]
  |a::r->([a]::(powerset1 r))@(merge a (powerset1 r))
;;

let powerset l= let ml =powerset1 l in ([])::ml
;;
let rec cree i= if i<=100 then i::(cree (i+1)) else []
;;
let rec separer l = match l with
[]->([],[])
|a::b::r->let (l1,l2) =separer r in ((a::l1),(b::l2))
|a::r->let (l1,l2) =separer r in ((a::l1),l2)
;;

let rec gen_random n m = if n=0 then []
       else let ml = gen_random (n-1) m in 
            let x= Random.int(m-1) in 
            x::ml
          ;;


(** subset_sum_0 : int list -> int -> int * int list= <fun>
@param l Une liste des entiers ,s un entier
@return un couple entier * liste  qui est le plus grand somme des sous-ensembles * ce sou-ensemble de l mais inderieur à s 
*)

let subset_sum_0 l s = List.fold_right 
(function l-> function max_cou->
  let sum = sum l in 
  let (max,ml)=max_cou in
                        
if sum>max&&sum<=s then (sum,l) else (max,ml))
 (powerset l) (0,[])
;;



(** get_all_sums : int list -> (int * int list) list
@param l Une liste des entiers 
@return une liste des entiers * une liste des entiers qui cotient tous les sommes des sous-ensembles et ceux sous-ensemble de l 
*)

let rec get_all_sums l = 
   match l with
   |[]->[(0,[])]
   |a::r ->
   let ml=get_all_sums r in
   ml@(  List.map(function x->let(sl,xl)=x in let s =sl+a in let xxl=a::xl in (s,xxl)) ml  )
;;
(* tester list =[1; 3; 4; 7]
- : (int * int list) list =[(0, []); (7, [7]); (4, [4]); (11, [4; 7]); (3, [3]); (10, [3; 7]);
 (7, [3; 4]); (14, [3; 4; 7]); (1, [1]); (8, [1; 7]); (5, [1; 4]);
 (12, [1; 4; 7]); (4, [1; 3]); (11, [1; 3; 7]); (8, [1; 3; 4]);
 (15, [1; 3; 4; 7])]*)

(** subset_sum_1 : int list -> int -> int * int list
@param l Une liste des entiers ,s un entier 
@return un couple entier * liste  qui est le plus grand somme des sous-ensembles * ce sou-ensemble de l mais inderieur à s 
*)
let rec  subset_sum_1 l s=List.fold_right 
(function x -> function y -> let (xs,xl)=x in let (ys,yl)=y in if xs>ys&&xs<=s then x else y) 
(get_all_sums l) (0,[]);;








(**  insert : 'a * 'b -> ('a * 'b) list -> ('a * 'b) list
@param x un couple des deux element ,l Une liste croissante contenant des couples
@return une liste croissante qui contient  le couple x
*)

let rec insert x l =
 match l with
 |[] -> [x]
 |h::t -> let (xx,xl)=x in let (hx,hl)=h in if xx <= hx then x :: h :: t else h :: insert x t
;;
(** sort : ('a * 'b) list -> ('a * 'b) list 
@param l Une liste de couple
@return une liste croissante avoir les meme couples
*)


let rec sort l = match l with 
 |[] -> []
 |h::t -> insert h (sort t)
;;

(** clean_up : (int * 'a list) list -> int -> float -> (int * 'a list) list
@param l Une liste de couple  entiers*element , s un entier ,delta un float 
@return une liste de couple apres lèalgorithme nettoyage
*)

let clean_up l s delta = let ml = sort l in match ml with 
| [] ->[]
|a::r -> List.fold_left 
    (function liste_t -> function value -> 
      let (m,ml) = match (List.rev liste_t) with []-> (s,[])|last::r->last in 
      let (valuex,valuel)=value in
      if (float_of_int valuex)>(1.0+.delta)*.(float_of_int m)&&valuex<=s then  liste_t@[value] else liste_t)
    [a] r 
;;

(** subset_sum_2x : int list -> int -> float -> (int * int list) list
@param l Une liste des entiers , s un entier ,delta un float 
@return une liste de couple qui sont  entiers*listes qui sont les somme des sou-ensembles mais apres nettoyage
*)
let rec subset_sum_2x l s delta=  
match l with
   |[]->[(0,[])]
   |a::r ->  let xl = subset_sum_2x r s delta  in  
   clean_up (xl@(  List.map(function x->let (xx,xl)=x in let xl2= a::xl in let xx2=xx+a in  (xx2,xl2) ) xl ) )s delta
;;
(** subset_sum_2 : int list -> int -> float -> int * int list 
@param l Une liste des entiers , s un entier ,delta un float 
@return un couple entier * liste  qui est le plus grand somme des sous-ensembles * ce sou-ensemble de l mais inderieur à s 
*)
let subset_sum_2 l s delta = let ml = List.rev (subset_sum_2x l s delta )in 
   match ml with []->(0,[])
   |a::r-> a;;




(** best_feasible : int -> (int * 'a list) list -> (int * 'a list) list -> int * 'a list
@param somme un entier , liste1 Une liste de couple entier*liste  croissants, liste2 Une liste de couple entier*liste  decroissant
@return un couple entier*liste qui est la somme d’un element de liste1 et d’un element de liste2, mais interieur à somme
*)
let  rec best_feasible somme liste1 liste2 = match liste1 with 
|[]->(0,[])
|a::r->let (ax,al)=a in 
     let l =  List.map( function x-> let (xx,xl)=x in let xl2= al@xl in let xx2=xx+ax in  (xx2,xl2) ) liste2 in 
             match l with 
             |[] -> (0,[])
             |aa::r2-> let res  =best_feasible somme r liste2 in 
                        let (resx,resl)=res in 
                       let xx= List.fold_right (function x -> function y -> 
                        let (sx,xl)=x in 
                       if sx<=somme then x else y ) l aa in
                       let (xxs,xxl)=xx in 
                       if( resx<somme&&(somme-resx)<(somme-xxs) ) then res else xx ;;
                   ;;

(** subset_sum_3 : int list -> int -> int * int list 
@param l Une liste des entiers ,s un entier 
@return un couple entier * liste  qui est le plus grand somme des sous-ensembles * ce sou-ensemble de l mais inderieur à s 
*)

let rec subset_sum_3 l s = let (l1,l2) =separer l in
   let n1=sort (get_all_sums l1 )in
   let n2=List.rev (sort (get_all_sums l2 )) in
   best_feasible s n1 n2 ;;



(*tester avec l=test_liste1 ,s =20
 res0 : int * int list = (12, [1; 2; 5; 4])
 val res1 : int * int list = (12, [1; 2; 5; 4])
val res2 : int * int list = (12, [1; 2; 5; 4])
val res3 : int * int list = (12, [1; 5; 2; 4])*)

let res0 = subset_sum_0 test_liste1 20;;
let res1 = subset_sum_1 test_liste1 20;;
let res2 = subset_sum_2 test_liste1 20 0.01;;
let res3 = subset_sum_3 test_liste1 20;;


(*tester avec l=test_liste2 ,s =9 
val res0 : int * int list = (8, [5; 0; 3])
 val res1 : int * int list = (8, [5; 0; 3])
val res2 : int * int list = (8, [5; 3]) 
val res3 : int * int list = (8, [3; 5; 0])*)
let res0 = subset_sum_0 test_liste2 9;;
let res1 = subset_sum_1 test_liste2 9;;
let res2 = subset_sum_2 test_liste2 9 0.01;;
let res3 = subset_sum_3 test_liste2 9;;