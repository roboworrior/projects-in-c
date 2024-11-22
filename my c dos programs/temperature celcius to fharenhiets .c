#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){

int far=32;  // 32 farn = 0 degari celecois +1 degree =1.8 faren
int cel=0;	
float ans,a=1.8;	
	
	printf("enter the temperature in celcios = ");
	scanf("%d",&cel);
	
	ans= a*cel; 
	
	printf("\nthe temperature in fahrenheit is  = %.2f",far+ans);
	
		return 0;
}




























































