var
 a, b, c, maior is int;
 nome is string;
 begin
 in(a);
 in(b);
 in(c);

 maior := 0;
 if ( a>b ) and ( a>c ) then
    maior := a;
 else
    if (b>c) then
        maior := b;
    else
        maior := c;
    end;
 end;

 out({Maior idade: });
 out(maior);

 end