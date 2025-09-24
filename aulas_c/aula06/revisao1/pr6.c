float arredonda(float n) {
    float parteInt = (int)n;
    float parteFrac = (n - parteInt);
    
    if (n < 0){
        return -(arredonda(-n));
    } else{
        
        if (parteFrac < 0.25){
            
            return parteInt;
            
        } else if (parteFrac < 0.75){
            
            return parteInt + 0.5;
            
        } else {
            
            return parteInt + 1;
            
        }
        
    }
}

void arredondaNotas(float *endNota1, float *endNota2, float *endNota3) {
    *endNota1 = arredonda(*endNota1);
    *endNota2 = arredonda(*endNota2);
    *endNota3 = arredonda(*endNota3);
}
