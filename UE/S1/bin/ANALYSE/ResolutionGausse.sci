
function x=ResolutionGausse(A,b)
    [At,bt]=trisss(A,b)
    x=sorsup(At,bt)
endfunction
