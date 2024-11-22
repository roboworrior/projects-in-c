#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//const int k=6;


int main(){

FILE *ptr;

char arr[1000];

ptr=fopen("file.txt","r");


char c;
int a=0;

c=fgetc(ptr);

while(c!=EOF){

c=fgetc(ptr);

arr[a]=c;

a++;
}

fclose(ptr);

a=0;
while(arr[a]!=EOF){
printf("%c",arr[a]);
a++;
}
	
	
	return 0;
}






























































