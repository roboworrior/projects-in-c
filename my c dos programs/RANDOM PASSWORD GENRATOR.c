#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//                                                   RANDOM PASSWORD CREATOR                                   byy CYBORG

	//const int o=1;  // for how many symbols
	//const int p=1;  // for how many numbers
	//const int k=2;  // for how many letters	
	
	  
int main()
{

int h;
	  int len;  // lenth of password	


char let[]={"qwertyuiopasdfghjklzxcvbnm"};

char sam[]={"!@#$%^&*()_+|=/"};

int num[]={1,2,3,4,5,6,7,8,9,0};

int nom;
	
int l=0;	
srand(time(0));
	
	
	printf("ENTER HOW MANY PASSWORDS :");
	scanf("%d",&h);
	
	
	printf("\nENTER HOW long a password  :");
	scanf("%d",&len);
	
	printf("\n");
for(int i=0; i<h; i++){	
	printf("%d) password is :  ",i+1);
l=0;


while(l<len){
	
	
nom=rand()%3;	
	
	if(nom==0){
	//for(int a=0;a<=k;a++){
	nom=rand()%26;

	printf("%c",let[nom]);
//}
}


if(nom==1){
	//for(int b=0;b<=o;b++){
	nom=rand()%16;

	printf("%c",sam[nom]);
//}
}



if(nom==2){
	//for(int c=0;c<=p;c++){
		
		nom=rand()%10;
	
	printf("%d",num[nom]);
		
	//}	
	
}


l++;	
	
}
	printf("\n");
	
}

	printf("\n\n\n                 DEVLOP BY CYBORG");
	return 0;
}




























































