#include<stdio.h>
#include<stdlib.h>

int main()
{
    char name[64]; 
    char ch;
	printf("Enter the name of the file to be created: "); 
	fgets(name, 64, stdin); 
	FILE* fptr;
    fptr = fopen(name, "w"); 

    printf("Enter data...\n");
    while( (ch = getchar()) != EOF) { 
        putc(ch, fptr); 
    } 

	fclose(fptr); 
    return 0;
}