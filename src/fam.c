
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdalign.h>
#include <string.h>

#include "fam.h"

MyStruct* getMyStruct(int argc, char const *argv[])
{ 
    int tmp[] = {1,2,3,4,5,6};
    int nums[5];
    MyStruct *m;
    m = malloc(sizeof(*m) + sizeof(tmp));
    m->age = 5;
    memcpy(nums, tmp,sizeof(tmp));
    memcpy(m->nums, tmp,sizeof(tmp));
    m->nums[0] = 5;
    return m;
}

void takesStruct(struct MyDeets mystruct) {
    printf("takesStruct addr: %p\n", &mystruct);
}

void takesPt(struct MyDeets *pt) {
    printf("takesPt addr: %p\n", pt);
}