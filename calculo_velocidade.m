 wa = -((contador_encoder*0.08373)); %// velocidade angular por segundos do encoder %0.08373 se timeout 0.03 se timeout 0.1 0.02512
 w_vetor(cont) = wa; 
 v(cont) = (wa*fator*Raio)/100;
 velocidade = v;
 velocidade_maxima = max(velocidade);