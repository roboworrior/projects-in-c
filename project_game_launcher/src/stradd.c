#include <stdio.h>

void stradd(char arr[100],char arr2[100],int a){


int i=0;
while(arr2[i]!='\0'){
	
  arr[i+a]=arr2[i];
	
	i++;
}
arr[i+a]='\0';
	
}

