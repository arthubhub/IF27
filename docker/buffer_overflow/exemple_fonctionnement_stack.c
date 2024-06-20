#include <stdio.h>

void foo(){
    int a=5;
    char name[10];
    gets(name);
    printf("%s\n",name);
    printf("%x",a);
}


int main()
{
    foo();
    int a=0;
a=a+1;
a=a<<5;
	int b=12;
if (a>b) printf("a>b");
else b=a;
b=a-0x12;
    return 0;
}
