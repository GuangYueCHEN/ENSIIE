function x=triangulaire(A,b)
     //xia san jiao cheng fa
    x(1)=b(1)/A(1,1)
    i=2
    while  i<length(b)+1,
        j=1
        sum1=0
        while j<=i-1, 
        sum1=sum1+A(i,j)*x(j)
        j=j+1,
        end
        x(i)=(1/A(i,i))*(b(i)-sum1)
        i=i+1;
    end
    
    
    
    
    
    
    
endfunction
