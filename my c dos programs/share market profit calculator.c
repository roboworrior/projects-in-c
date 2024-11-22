#include<stdio.h>


int main(){

int dp,b,o,q2;
float q,buy,sell;

printf("***WELCOME LETS CALCULATE PROFITS****\n");


printf("\nfor share market press 1 for other press 2--");
scanf("%d",&o);


if(o==1)
{
printf("\nenter the buy value of per share---");
scanf("%f",&buy);

printf("\nenter the quentyti of shares---");
scanf("%f",&q);

             printf("\nif its a holding press 1 or press 0---");
          scanf("%d",&dp);

           if(dp==1){

              dp=16;
          }
              else{
                  dp=0;
            
              }

b=50;

int fc=b+dp;

float qpc=fc/q;


printf("\nenter the sell value of share---");
scanf("%f",&sell);


printf("\nenter the quentity of share---");
scanf("%d",&q2);

float po,fbp,fsp;

fbp=buy+qpc;


po=sell-fbp;

printf("\nBROKERAGE ----%d",b);
printf("\nDP CHARGES ----%d",dp);
printf("\n\n\t\t\t\tTOTAL BUY VALE----%f",buy*q);
printf("\n\t\t\t\tTOTAL SELL VALUE ----%f",sell*q);



printf("\n\n\t\t\t\tFINAL PROFIT  ----%f",po*q2);



printf("\n\n\n\n\n\n\n\nDEVLOP BY CYBORG");




}

    return 0;
}