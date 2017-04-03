   energia_cinetica = (((0.15+(massa/2000)))*((v).^2)); % I/R^2 = 0.15
   [energia_cinetica_maxima,instante] = max(energia_cinetica);
   instante = tempo(instante);
  