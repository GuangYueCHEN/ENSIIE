function B=tridiaganal(n)
    B=zeros(n,n);
    
    for i=1:n,
        B(i,i)=3
    end
    
        
    for i=2:n,
        B(i,i-1)=1
    end
        
    for i=1:n-1,
        B(i,i+1)=1
    end
    
    
    
endfunction
