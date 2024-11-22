#include <stdio.h>
#include <string.h>
void FLR(char *arr,int i){
	
	if(i==1){
	
	FILE *file;
	file=fopen("path.txt","r");
	char c=fgetc(file);
	int a=0;
	while(c!=EOF){
	arr[a]=c;
	c=fgetc(file);
	a++;
    }
	arr[a-1]='\0';
	fclose(file);
}
	
	if(i==2){
		

	
   }

}
