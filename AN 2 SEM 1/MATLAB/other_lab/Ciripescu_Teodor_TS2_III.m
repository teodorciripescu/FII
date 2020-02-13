n=7;
chrs=['r' 'b' 'w' 'y'];
A=[ 'rrwryry';
    'ywywwyr';
    'bbbbrbb';
    'wyrybww';
    'rrbryry';
    'ywywwyr';
    'bbrbrbb';];

B = randi([2, 10], 7);
%matrice de vizitati bordata cu 1
Viz = zeros(n+1);
for i=1:n+1
    Viz(i,1)=1;
end
for i=1:n+1
    Viz(1,i)=1;
end
for j=1:n+1
    Viz(n+1,j)=1;
end
for j=1:n+1
    Viz(j,n+1)=1;
end
%%%%%%%%
n=7;
m=7;
row = 1;
col = 1; 
  minimul=999;
    row_inc = 0; 
  
    mn = min(m, n); 
    for len=1:mn 
        for i=1:len 
            disp([row col]);
            if(B(i,len)<minimul)
                minimul = B(len,i);
            end
            
            if (i == len) 
                break; 
            end
            if (row_inc>0) 
                row=row+1;  col=col-1; 
            else
                row=row-1;  col=col+1; 
            end
        end
  
        if (len == mn) 
            break; 
        end
        
        if (row_inc>0) 
            row=row+1;  row_inc = 0; 
        else
            col=col+1;  row_inc = 1; 
        end
    end
  
    
    if (row == 1)
        if (col == m) 
            row=row+1;  
        else
            col=col+1; 
        end
        row_inc = 1; 
    end 
    if (row ~= 1) 
           
        if (row == n) 
            col=col+1;  
        else
            row=row+1;  
        end
        row_inc = 0; 
    end
  
    MAX = max(m, n) ; 
    len=MAX;
    for diag = MAX:-1:1
  
        if (diag > mn) 
            len = mn; 
        else
            len = diag; 
        end
        for i = 1:len

            if(B(i,len)<minimul)
                minimul = B(len,i);
            end
            if (i  == len) 
                break; 
            end

            if (row_inc>0) 
                row=row+1;  col=col-1;  
            else
                col=col+1;  row=row-1; 
            end
        end 
  
        if (row == 1 || col == m)
            if (col == m) 
                row=row+1; 
            else
                col=col+1; 
            end
            row_inc = 1; 
        
  
        elseif (col == 1 || row == n)  
            if (row == n) 
                col=col+1; 
            else
                row=row+1; 
            end
            row_inc = 0; 
        end 
    end 

minimul
