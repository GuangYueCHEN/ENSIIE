function x=Jacobi(A,b)
    n=size(A,1);
    D=zeros(n);
    E=zeros(n);
    F=zeros(n);
    
    for i = 1:n
        D(i,i)=A(i,i);
    end
    

    for i=1:n
        for j= 1:n
            if i<>j then
            R(i,j)=-A(i,j);
            end
        
        end
    end    
    
    S=inverse(D);

    J=S*R;
    disp(J);
    r=S*b;

    disp(r);
    x=zeros(n,1);
    

       
       m=norme_infini(A*x-b)
       n=norme_infini(b)
      m=abs(m)
      n=abs(n)
      
    for i=1:3
               y=x
            x=J*y+r
       m=norme_infini(A*x)
       n=norme_infini(b)
      m=abs(m)
      n=abs(n)
      
       // disp(B)
    end
    
    
    
    
    
    
    
    
    
endfunction
