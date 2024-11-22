#include <stdio.h>
#include <string.h>

void main_balance(),sales(),update();

int srate,brate,h,mbal,dp=16;
//const int k=6;

int main(){
char arr[2000];

int a;

printf("*****$$****** WELCOME TO MONEY LOG  **********$$******\n\n");


main_balance();

printf("\t\t\t\t\t\t\tcurrent balance %d",mbal);



printf("\n\nfor profits press 1 for expencess press 2 :");
	scanf("%d",&a);


if(a==1){
	printf("\nfor stocks press 1 or press 2 for others ");
	scanf("%d",&a);

if(a==1)
{
		printf("\nenter stock name :");
		getchar();
		gets(arr);

		printf("\nhow many shares you sale :");
		scanf("%d",&h);

		printf("\nsale rate per share :");
		scanf("%d",&srate);

		printf("\nenter buy rate  :");
		scanf("%d",&brate);

	sales(arr,0);

}
else
{
		printf("\nenter the work name :");
		getchar();
		gets(arr);

		printf("\nenter net profit :");
		scanf("%d",&srate);

		sales(arr,1);

	}

}
else{
		printf("\nenter the amount : ");
		scanf("%d",&h);

		 update(h,0);// yaha jake yeh mbal ki txt file ko  update kar de

	}

		printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\tDEVLOP BY CYBORG");

	//getch();
	return 0;
}




void main_balance(){

FILE *ptr;

ptr=fopen("current  welth.txt","a");
fclose(ptr);

ptr=fopen("sale.txt","a");
fclose(ptr);	
	
	
ptr=fopen("current  welth.txt","r");
fscanf(ptr,"%d",&mbal);
fclose(ptr);

	}

void sales(char arr[],int x){
	FILE *ptr;
	int pro;

	if(x==0){
	pro=(srate-brate)*h-dp;

	ptr=fopen("sale.txt","a");
	fprintf(ptr,"\n\n%s x %d : BUY = %d  SALE = %d    net profit : %d\t\t\t\t\t\tmain balance :%d",arr,h,brate,srate,pro,mbal+pro);
	fclose(ptr);
	update(0,pro); // update the main bal,,,, with profit
    }


	if(x!=0){
				
	pro=srate; // for other profits
	ptr=fopen("sale.txt","a");
	fprintf(ptr,"\n\n%s  : %d\t\t\t\t\t\tmain balance :%d",arr,srate,mbal+pro);
	fclose(ptr);
	update(0,pro); // update the main bal,,,, with profit

	}

	}

void update(int x,int pro)
{
	FILE *ptr;


	if(x!=0)
	{
    ptr=fopen("current  welth.txt","w"); // for update the main bal
	fprintf(ptr,"%d",mbal-x);           //
	fclose(ptr);                        //


	ptr=fopen("sale.txt","a");          // for entry in sales n ladger
	fprintf(ptr,"\n\nexpenses -%d\t\t\t\t\t\tmain balance :%d",x,mbal-x);  //
	fclose(ptr);                        //
    }



	if(pro!=0){

	
	ptr=fopen("current  welth.txt","w");
	fprintf(ptr,"%d",mbal+pro);
	fclose(ptr);
   }


}

/*
brokeradge(){
	
paytm money =1;

stt 0.1%

sebi =0.0001%

stamp duty =0.015%

etc=0.00345%


srate+brate 

}
*/







































