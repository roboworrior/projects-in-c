#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


struct employee{
	
int code;

float salary;

char name[20];

};
	  

void show(struct employee e[]){
	
	

	
int b=0;
while(b<3){

printf("\nname %s \ncode %d\nsalary in $ = %.2f\n",e[b].name,e[b].code,e[b].salary);

b++;
}
	
}


int main(){

struct employee e[3];

int a=0;

while(a<3){

printf("enter the employee %d code ",a+1);
scanf("%d",&e[a].code); 

printf("enter the employee %d salary ",a+1);
scanf("%f",&e[a].salary); 

printf("enter the employee %d name ",a+1);
scanf("%s",e[a].name); 

a++;

printf("\n");
}

show(e);

	return 0;
}




























































