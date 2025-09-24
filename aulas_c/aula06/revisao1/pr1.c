#include <math.h>

float loglcdf(float x, float a, float b){
    
    float result;
    
    if (x >= 0){
        
        result = 1 / (1 + (pow((x / a), b)));
        
    } else {
        
        result = 0;
        
    }
    
    return result;
}