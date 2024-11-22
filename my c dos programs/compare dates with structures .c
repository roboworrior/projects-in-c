#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct time1 {
	
	int date ;
	int month;
	int year;
	
	int hour;
	int minutes;
	int seconds;
	
}time1;


int datcmp( time1 d1, time1 d2)
{
	
	if(d1.year < d2.year){
	 return 1;
	}
	
	if(d1.year > d2.year){
	 return -1;
	}
	
	if(d1.month < d2.month){
	 return 1;
	}
		
	if(d1.month > d2.month){
	 return -1;
	}
	
	if(d1.date < d2.date){
	 return 1;
	}
	
	if(d1.date > d2.date){
	 return -1;
	}
		
	if(d1.hour < d2.hour){
	 return 1;
	}
	if(d1.hour > d2.hour){
	 return -1;
	}
	
	if(d1.minutes < d2.minutes){
	 return 1;
	}
	if(d1.minutes > d2.minutes){
	 return -1;
	}
	
	if(d1.seconds < d2.seconds){
	 return 1;
	}

	if(d1.seconds > d2.seconds){
	 return -1;
	}
	
	
	return 0;
	}



int main(){

time1 d1 = {21,8,2017   ,22,34,45}; // target 

time1 d2 = {21,8,2027    ,22,34,45}; // source
	
	
printf("source   date -- %d/%d/%d  time -- %d:%d:%d",d1.date, d1.month, d1.year, d1.hour, d1.minutes,d1.seconds);

printf("\n\ntarget  date -- %d/%d/%d  time -- %d:%d:%d",d2.date, d2.month, d2.year, d2.hour, d2.minutes,d2.seconds);


int a = datcmp(d1,d2); // first is  source then target  ex.. datcmp(source , target );


if(a<0){
printf("\n\n\n\n            target date  is smaller then source");
}

if(a>0){
printf("\n\n\n\n              target date  is bigger  then source");
}

if(a==0){
printf("\n\n\n\n              target date  and  source date are same");
}
	
	
	printf("         value = %d",a);
		return 0;
}






























































