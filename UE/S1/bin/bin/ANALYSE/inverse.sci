function B=inverse(A)
    n=size(A,1)
    B=eye(n,n)

    for k=1:n-1,
        for i=k+1:n,
            c=A(i,k)/A(k,k)
            A(i,k)=0
          
            for j=k+1:n,
                A(i,j)=A(i,j)-c*A(k,j)
            end
            for j=1:n,
                 B(i,j)=B(i,j)-c*B(k,j)
             end
         end
         
    end
        


       for k=n:-1:2,
        for i=k-1:-1:1,
            c=A(i,k)/A(k,k)
            A(i,k)=0
          
            for j=k-1:-1:1,
                A(i,j)=A(i,j)-c*A(k,j)
            end
            
            for j=n:-1:1,
                 B(i,j)=B(i,j)-c*B(k,j)
             end
         end
         
    end
    
     
    
    for k=1:n,
   
            c=A(k,k)
            for j=1:n,
                 B(k,j)=B(k,j)/c
             end
       
    end
        
    
    
    

    
    
endfunction
