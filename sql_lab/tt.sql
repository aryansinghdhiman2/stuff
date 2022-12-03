create or replace package circle as
function area(radius number) return number;
function circumference(radius number) return number;
end circle;
/
create or replace package body circle as
function area(radius number) return number
as
begin
return radius*radius*3.14;
end area;

function circumference(radius number) return number
as
begin
return  2*3.14*radius;

end circumference;
end circle;

declare
radius number:=:radius;
begin
dbms_output.put_line('area is '||circle.area(radius));
dbms_output.put_line('circumference is '|| circle.circumference(radius));
end;