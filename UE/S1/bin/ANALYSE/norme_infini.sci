function x=norme_infini(y)
    n=size(y,1);

    i=-8888;
    for j = 1 : n 
        if i<y(j) then
            i=y(j)
            end
    end
     x=i;
 
endfunction
