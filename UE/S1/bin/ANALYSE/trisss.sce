function [At,bt] =trisss(A,b)
    
    n=size(b)
    for k=1:n-1,
        if abs(A(k,k))==0  then, 
            disp("xxxxxxxxxxxxxx\n")
            
            ,else,
            
            for i=k+1:n,
                c=A(i,k)/A(k,k)
                b(i)=b(i)-c*b(k)
                A(i,k)=0
                   for j=k+1:n,
                       A(i,j)=A(i,j)-c*A(k,j),
                   end
                
              end
         end
    end
      
      At=A
      bt=b  
        
      
    
endfunction
