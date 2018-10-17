function B=FactCholesky(A)
    n=size(A,1)
  
        B=zeros(n,n)
B(1,1)=sqrt(A(1,1))
 for j=1:n,
      for i=j:n,
       
       if i==j & j>1 then 
           sum2=0;
           for k=1:j-1,
               sum2 = sum2 + B(i,k)*B(i,k)
           end

           B(i,j)=sqrt(A(i,j)-sum2)
        else if i<>j then
            sum1=0
            for k=1:j-1,
                sum1 = sum1 + B(i,k)*B(j,k)
            end
            
           B(i,j)=(A(i,j)-sum1)/B(j,j)
       end
   end
     
        end
    end
    
 
    
endfunction
