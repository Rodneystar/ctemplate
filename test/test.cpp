#include <stdio.h>

#include "CppUTest/TestHarness.h"

extern "C" {
    // #include <stdlib.h>
    #include "fam.h"
    #include "leadymem.h"
}

#pragma GCC diagnostic ignored "-Woverflow"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"

TEST_GROUP(LearningTests)
{
};

TEST(LearningTests, bigLongArray)
{
    int size = 10000;
    long * randoms = lotsRandoms(size);

    for(int i = 0; i < size; i++) { 
        CHECK_EQUAL(i, *(randoms+i));
    }

}

TEST(LearningTests, FirstTest)
{
   printf("we think it's printing shit \n");
   CHECK_EQUAL(1,1);
}


// typedef struct MyStruct{
//     // char * name;--
//     int age;
//     int nums[];
// } MyStruct;

TEST(LearningTests, UnderStandingFAM)
{
    int tmp[] = {1,2,3,4,5};
    int nums[5];
    MyStruct *m;
    m = (MyStruct *) malloc(sizeof(*m) + sizeof(tmp));

    m->age = 5;
    memcpy(nums, tmp,sizeof(tmp));
    memcpy(m->nums, tmp,sizeof(tmp));
    CHECK_EQUAL(1, m->nums[0]  );
    CHECK_EQUAL(2, m->nums[1] );
    CHECK_EQUAL(3, m->nums[2] );
    CHECK_EQUAL(4, m->nums[3] );
    CHECK_EQUAL(5, m->nums[4] );
}

TEST(LearningTests, overflowInteger) {
    int mi = __INT_MAX__ + __INT_MAX__;
    printf("\nmi: %d\n\n", mi);
    CHECK_EQUAL(-2, mi );
}


TEST(LearningTests, passingStructs) {
  
    struct MyDeets mystruct;
    mystruct.age = 3;
    mystruct.name = "lark";

    struct MyDeets * mystructpointer = &mystruct;
    takesStruct(mystruct);
    takesPt(mystructpointer);
}

TEST(LearningTests, runStructs) {
    struct MyDeets mystruct;
    mystruct.age = 3;
    mystruct.name = "lark";

    struct MyDeets myDeets = {
        .name = "things",
        .age = 5
    };
    struct MyDeets *mypstruct = &myDeets;

    // printf("it's printing at least ");
    printf("s name: %s, s age: %d, p name: %s, p age: %d\n", mystruct.name, mystruct.age, mypstruct->name, mypstruct->age);

    CHECK_EQUAL("lark", mystruct.name);
    CHECK_EQUAL(3, mystruct.age );
    CHECK_EQUAL("things", mypstruct->name );
    CHECK_EQUAL(5, mypstruct->age );
}

TEST(LearningTests, tokens) {
    int toknum = 0;
    char src[] = "Hello,, world!";
    const char delimiters[] = ", !";
    char *token = strtok(src, delimiters);
    printf("tokens\n");
    STRCMP_EQUAL("Hello", token);
    STRCMP_EQUAL("world", strtok(NULL, delimiters) );
}


TEST(LearningTests, stringCopy) {
    const char * a = "first";
    char * b = (char*) alloca(strlen(a));

    sprintf(b, "%s", a);

    printf("\ncopy strings\nprinting b: %s\n\n", b);
    STRCMP_EQUAL("first", b);
}

