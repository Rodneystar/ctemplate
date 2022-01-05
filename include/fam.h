


struct MyStruct{
    // char * name;--
    int age;
    int nums[];
};
typedef struct MyStruct MyStruct;

struct MyDeets{
    const char * name;
    int age;
};
typedef struct MyDeets MyDeets;

MyStruct* getMyStruct(int argc, char const *argv[]);

void takesStruct(struct MyDeets mystruct);

void takesPt(struct MyDeets *pt);