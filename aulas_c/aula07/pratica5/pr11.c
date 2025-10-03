float raiz(float x){
    double y = 1;
    double quadrado = y * y;
  

    
   while (quadrado < x) {
       
     
       y++;
       
       quadrado = y * y;
      
    if (((quadrado >= x - 0.01) && (quadrado <= x + 0.01))){
        return y;
    }
       
   }
   y -= 1;
   
   
   for (float i = 0.1; i <= 0.9; i += 0.1){
    
        float temp1 = y + i;
        // printf("temp1 %f\n", temp1);
        
        
        for (float j = 0.00; j < 0.09; j += 0.01){

            
            double temp2 = temp1 + j;
            
           // printf("temp2 %lf\n", temp2);
            
            for (float k = 0.001; k <= 0.009; k += 0.001){
                
               double temp3 = temp2 + k;
              //  printf("temp3 %llf\n", temp3);
                
                 quadrado = temp3 * temp3;
            
              //  printf("quadrado %f\n", quadrado);
            
                if ((( quadrado >= x - 0.01) && (quadrado <= x + 0.01))){
                    return temp2;
                    
                }
            
            
            }
            
        }
        
    }
    
    
    return y;
    
}