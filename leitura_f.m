%%Constantes iniciais
cont = 0; % Contador de interações
contador_encoder = 0;
distancia_ant = 0; %distância inicial
Raio = 6 ; % Raio da roda do CD 6cm
fator = 1.034;% Razao entre o numero de dentes 32/41 = 0,78
%%
while(~get(gui.togglebutton1,'Value'))
    %%
    %Gráfico a esquerda
    massa = char((get(gui.edit6,'String')));%massa do carrinho de ratoeira
    massa = str2num(massa);
    [contador_encoder,count] = fscanf(s1,'%f');% leitura da porta serial 
    ant_contador_encoder = contador_encoder;
    cont = cont+1;%indice para os vetores
    vetor_encoder(cont)= contador_encoder;
    calculo_tempo;
    calculo_velocidade;
    calculo_distancia;
    plot(gui.axes4,distancia,v);%plotar velocidade em função da distância
    drawnow
   %%
   %%Gráfico a direita
    calculo_energia_cinetica
    plot(gui.axes1,t,energia_cinetica);%plotar energia cinética em função do tempo
    drawnow
    set(gui.edit4,'String',sprintf('%f',distancia(cont)))

end
 
if (get(gui.togglebutton1,'Value'))
    %%
    %%Simulação finalizada
       set(gui.editVel,'String',sprintf('%f',velocidade_maxima))
         set(gui.edit7,'String',sprintf('%f',energia_cinetica_maxima))
           set(gui.edit8,'String',sprintf('%f',instante))
 clear distancia; 
 clear v;
 clear t;
 clear energia_cinetica;
 
header = { ' ','Tempo', 'Contador','Velocidade angular','Velocidade Linear','Distância'};
xlswrite('dados.xlsx',header,'DADOS')
xlswrite('dados.xlsx',tempo','DADOS','B2')
xlswrite('dados.xlsx',vetor_encoder','DADOS','C2')
xlswrite('dados.xlsx',w_vetor','DADOS','D2')
xlswrite('dados.xlsx',velocidade','DADOS','E2')
xlswrite('dados.xlsx', d','DADOS','F2')
 end 
 