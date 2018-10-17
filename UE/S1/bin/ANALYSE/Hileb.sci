function B=Hileb(n)
     B=zeros(n,n);
    for i=1:n,
        for j=1:n,
            B(i,j)=1/(i+j-1)
         end
        
    end
endfunction
