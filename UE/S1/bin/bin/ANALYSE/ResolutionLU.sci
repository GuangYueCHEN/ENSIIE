function x=ResolutionLU(A,b)
    
    [L,U]=FactLU(A)
    y=sorsup(U,b)
    x=triangulaire(L,y)
    
    
endfunction
