function [L,U]=FactLU(A)
   
    n=size(A,1)
    L=eye(n,n)
    U=zeros(n,n)
    for i=1:n-1
        for j=i:n
            sum1=0
            for k=1:i-1
                sum1=sum1+L(i,k)*U(k,j)
                end
            
            
            U(i,j)=A(i,j)-sum1;
        end
        
        for j=i+1:n
            sum2=0
            for k=1:i-1
                sum2=sum2+L(j,k)*U(k,i)
                end
            
            L(j,i)=(1/U(i,i))*(A(j,i)-sum2)
        end
        
    end
    sum3=0
    for k=1:n-1
        sum3=sum3+L(n,k)*U(k,n)
    end
    
    U(n,n)=A(n,n)-sum3
    
    
endfunction
