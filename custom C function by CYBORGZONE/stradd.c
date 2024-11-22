#include <stdio.h>

/*

HELLO ITS ME CYBORGZONE 
*  
* ADD THIS TO YOUR CODE =====>  #include"stradd"
* 
*  CALL THIS FUNCTION LIKE ===>  stradd(CHAR_destination,"char you wana add",strlen of destination -1); 
	
	main sytex	         stradd(CHAR_destination,char_Source,strlen of destination);		

*/

void stradd(char arr[100],char arr2[100],int a){


int i=0;
while(arr2[i]!='\0'){
	
  arr[i+a]=arr2[i];
	
	i++;
}
arr[i+a]='\0';
	
}

