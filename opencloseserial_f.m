if get(gui.togglebutton1,'Value') == 0
    
    if (~exist('s1'))
    P1 =  get(gui.popupmenu3, 'string');
    P2 =  get(gui.popupmenu3, 'value');
    Porta = P1(P2);
    Porta = char(Porta);
   % Porta = Porta(1,1); 
        s1=serial(Porta);
    end
%     fclose(s1)
    fopen(s1);
    set(s1, 'Timeout',0.15);
    flagserial = 1;    
    leitura_f

elseif get(gui.togglebutton1,'Value') == 1
    
    fclose(s1)
    clear s1
end