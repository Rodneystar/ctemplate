// #include <stdlib.h>

long* lotsRandoms(int size){
    long* randArray = malloc(sizeof(long) * size);
    for(int i = 0; i< size; i++) {
        *(randArray + i) = (long) i; 
        // *(randArray + i) = random();
    }

    return randArray;
};