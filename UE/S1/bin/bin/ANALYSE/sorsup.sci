function x=sorsup(A,b)
    n=length(b)
    x(n)=b(n)/A(n,n)
  
    for i=n-1:-1:1,
       
        sum1=0
        for j=i+1:n, 
        sum1=sum1+A(i,j)*x(j)
       
        end
        x(i)=(1/A(i,i))*(b(i)-sum1)
        
    end
    
    
    
    
    
    
    
endfunction
