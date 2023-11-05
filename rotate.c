#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define SHAPE_WIDTH 150
#define SHAPE_HEIGHT 40
#define MAX_DIGITS 1000

void wipeScreen(){ system("clear || cls"); }
double absolute(double x){ return x < 0 ? -x : x; }

double sin(double x){
    double result = 0;
    double term = x;
    int sign = 1;
    for(int i = 1; i < 100; i++){
        result += sign * term;
        term *= x*x / (2*i+1) / (2*i);
        sign *= -1;
    }
    return result;
}

int main(int argc, char ** argv){
    int j = 0;
    if(argc != 3){
        printf("Usage: %s <radius> <speed> \n", argv[0]);
        return 1;
    }
    int radius = atoi(argv[1]);
    int speed = atoi(argv[2]);
    double angle = 0;

    char * beautifulmessage = malloc(sizeof(char*) * sizeof(char) * sizeof("i chaneing world"));

    for(int i = 0; i < sizeof("i chaneing world"); i++){
        beautifulmessage[i] = "i chaneing world"[i];
    }

    while(1){
        wipeScreen();
        for(int y = 0; y < SHAPE_HEIGHT; y++){
           //  j = j + 1 *  (y > SHAPE_HEIGHT/2 + sizeof("i chaneing world") && y < SHAPE_HEIGHT/2 - sizeof("i chaneing world") );  
           j ++;
           j = j % sizeof("i chaneing world");
            for(int x = 0; x < SHAPE_WIDTH; x++){ 

                printf(( (x - SHAPE_WIDTH/2)*(x - SHAPE_WIDTH/2) + (y - SHAPE_HEIGHT/2)*(y - SHAPE_HEIGHT/2) <= radius*radius) ? (x == SHAPE_WIDTH/2 && y == SHAPE_HEIGHT/2) ? "%c" : "*" : " ", beautifulmessage[j]);
                
            }
            printf("\n");
        }
        angle += 0.1;
        radius = 20 + 10 * sin(angle);
        usleep(1000000/speed);
    }
    free(beautifulmessage);
    return 0;
}
