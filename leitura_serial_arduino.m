a = 1 ;
s1=serial('COM12');
fopen(s1);
set(s1, 'Timeout',0.0400);
while a == 1 
velocidade = fgets(s1)
end