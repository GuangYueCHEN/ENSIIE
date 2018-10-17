function x=ResolutionCholesky(A,b)
    B=FactCholesky(A)

    C=B'
 
     y=sorsup(C,b)
    x=triangulaire(B,y)
    
    endfunction
