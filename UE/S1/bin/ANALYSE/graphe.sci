function graphe()
    
    for i=150:10:250 
    C=tridiaganal(i)
    tic()
   
    [L,U]=FactLU(C)
    
   x=toc()
   
     tic()
   
    B=FactCholesky(C)
    
     y=toc()
   
   
   tic()
   
   D=C*C
   [L2,U2]=FactLU(D)
   
   z=toc()
   
       tic()
   
    B2=FactCholesky(D)
    
     k=toc()
     
plot(i,x,'.')
plot(i,y,'o')
plot(i,z,'+')
plot(i,k,'*')

   
end


    
endfunction
