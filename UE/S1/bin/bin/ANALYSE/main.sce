//exec("~/bin/ANALYSE/trisss.sci")
//A=[1 0 0 ;2 3 0;1 4 -1]
//b=[1 8 10]
//x=triangulaire(A,b)
//disp(x)
//disp("calcul triangulaire")





//disp("GAUSSE")

//A=[3 1 2;3 2 6;6 1 -1]
//b=[6,16,15]

//[At,bt]=trisss(A,b)
//disp(At)
//disp(bt)


//exec("~/bin/ANALYSE/sorsup.sci")
//A=[1 2 3;0 4 8;0 0 5]
//b=[6 16 15]

//x=sorsup(A,b)
//disp(x)

//disp("calcul triangulaire sup")


//disp("RESOLUTIONGAUSSE")
//exec("~/bin/ANALYSE/ResolutionGausse.sci")
//A=[1 2 3;5 2 1;3 -1 1]
//b=[5,5,6]
//x=ResolutionGausse(A,b)
//disp(x)


//exec("~/bin/ANALYSE/FactLU.sci")
//A=[3 1 2 ;3 2 6;6 1 -1]
//[L,U]=FactLU(A);
//disp(L)
//disp(U)

//exec("~/bin/ANALYSE/ResolutionLU.sci")
//A=[1 2 3;5 2 1 ;3 -1 1]
//b=[5 5 6];
//x=ResolutionLU( A , b );
//disp(x);

//A=[15 10 18 12;10 15 7 13;18 7 27 7;12 13 7 22];

//B=FactCholesky(A);
//disp(B);
//b=[83 72 26 97];
//b=b'

//x=ResolutionCholesky(A,b)
//disp(x)


//A=[10 7 8 7;7 5 6 5;8 6 10 9;7 5 9 10];
//b=[32 23 33 31]
//dA=[0 0 0.1 0.2;0.08 0.04 0 0;0 -0.02 -0.02 0;-0.01 -0.01 0 -0.02]
//db=[0.1 -0.1 0.1 -0.1]
//z=ResolutionGausse(A,b)
//x=ResolutionGausse(A,b+db)
//y=ResolutionGausse(A+dA,b)
//disp(x)
//disp(y)
//disp(z)


A=[1 2 2 1;-1 2 1 0 ; 0 1 -2 2;1 2 1 2]
b=[1 1 1 1 ]
B=Jacobi(A,b)
disp(B)









