#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void encr(char *ptr){
	
	int i=0;
	
	
	while(1){
	
	
	
	if(ptr[i]=='\0'){
		break;
		}
		
	ptr[i]=ptr[i]+1;
	
	
	i++;
		
	}
	
	
	}
	
	void dencr(char *ptr){
	
	int i=0;
	
	
	while(1){
	
	
	
	if(ptr[i]=='\0'){
		break;
		}
		
	ptr[i]=ptr[i]-1;
	
	
	i++;
		
	}
	
	
	}
	  
int main(){

char str[]="hello bancho i hate u";

printf(" before encrption source string =%s",str);



encr(str); 



printf("\n\nafter encription target string =%s",str);


dencr(str);  



printf("\n\nafter dencription target string =%s",str);


	return 0;
}




























































