#include <stdio.h>
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include "stradd.c"
#include "FLR.c"

char path_poster[100][500]; 
char path_rom[100][500];
char arr[100][50];
char path_back[500];
char path_ico[500];
char path_data[500];
char  PATH[500];   
int how;

void datatxt();

void scan(GtkWidget *win,gpointer data){
datatxt();

int c;
	
	
	
	FILE *ptr;
	ptr=fopen(path_data,"r");
	
	int a=0;
	while(1){
		if(feof(ptr)){
			break;
		}
	
	fgets(arr[a],400,ptr);	
	a++;
	}
a=a-1;

how=a;


////////////////////////////////////////////////
											//	
											  //
for(int i=0;i!=how;i++){                       //

strcpy(path_poster[i],PATH);            //
c=strlen(path_poster[i]);
stradd(path_poster[i],"posters/",c);         //
c=strlen(path_poster[i]);											  //PATH_TO_POSTERS CREATOR
stradd(path_poster[i],arr[i],c);         //
c=strlen(path_poster[i]);                 //
stradd(path_poster[i],".png",c-1);       //
}                                             //
											  //
											  //
////////////////////////////////////////////////

////////////////////////////////////////////////
for(int i=0;i!=how;i++){                      //
strcpy(path_rom[i],PATH);                     //
c=strlen(path_rom[i]);                        //
stradd(path_rom[i],"rom/",c);                 //
c=strlen(path_rom[i]);                        //
stradd(path_rom[i],arr[i],c);                 //         //PATH_TO_ROMS
c=strlen(path_rom[i]);                        //
stradd(path_rom[i],"/",c-1);                  //
c=strlen(path_rom[i]);                        //
											  //
stradd(path_rom[i],arr[i],c);                 //
											  //
c=strlen(path_rom[i]);                        //
stradd(path_rom[i],".bin",c-1);               //
											  //
}                                             //
////////////////////////////////////////////////	
	
	
	//g_print("%s",PATH);
for(int i=0;i<a;i++){
g_print("\n %d   : %s    ",i+1,path_poster[i]);
}

g_print("\n\n");

for(int i=0;i<a;i++){
g_print("\n %d   : %s    ",i+1,path_rom[i]);
}

//g_print("\n\n%s",path_ico);

}


void run(GtkWidget *win,int *data){
	int c;
	char tem[500];
	strcpy(tem,"pcsxr -nogui -cdfile ");
	g_print("\n%d ",*data);
	
	
	for(int a=0;a!=how;a++){
	
	if(*data==a){
	g_print("%s NOW PLAYING\n ",arr[a]); //NO SPACE IN PATH 
	c=strlen(tem);
	stradd(tem,path_rom[a],c);
	
	system(tem);
	
   }
	
}
	
	
	//gtk_main_quit();
			
	}
void credit(GtkWidget *win,gpointer data){

g_print("\n\n\n\n\n\t\t\tDEVLOP BY AKSHAY SHARMA AKA CYBORG ZONE");


}

void datatxt(){
int c;		
char buffer[100];
char result[4000]="";

FILE *ptr;

char rom[200];

strcpy(rom,"ls ");
	c=strlen(rom);
	
	stradd(rom,PATH,c);
	c=strlen(rom);
	stradd(rom,"rom",c);
	


ptr=popen(rom,"r");

while(fgets(buffer,sizeof(buffer),ptr)){
	
	strcat(result,buffer);
	};

pclose(ptr);

FILE *file;


strcpy(path_data,PATH);
	c=strlen(path_data);
	stradd(path_data,"/data.txt",c);
	

file=fopen(path_data,"w");
//g_print("%s",result);

fprintf(file,"%s",result);

	fclose(file);
	}
	
int main(int argc, char **argv)
{
	
	FLR(PATH,1);
   gtk_init(&argc,&argv);
	GtkWidget *win;
	GtkWidget *fix;
    GtkWidget *scrl;
	GtkWidget *cred=gtk_button_new_with_label("CREDIT");;
    GtkWidget *bimg;
	
	scan(NULL,NULL);
	
	GtkWidget *but[how];
    GtkWidget *img[how];
	GdkPixbuf *ico;
    
    scrl=gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrl),GTK_POLICY_ALWAYS,GTK_POLICY_ALWAYS);
    fix=gtk_fixed_new();

    win=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	
	int c;
	
	strcpy(path_back,PATH);
	c=strlen(path_back);
	stradd(path_back,"back.png",c);

	bimg=gtk_image_new_from_file(path_back);
	
	strcpy(path_ico,PATH);
	c=strlen(path_ico);
	stradd(path_ico,"ico.png",c);
	ico=gdk_pixbuf_new_from_file(path_ico,NULL);
	
		
	
	for(int a=0;a!=how;a++){
	img[a]=gtk_image_new_from_file("");
	gtk_image_set_from_file(GTK_IMAGE(img[a]),path_poster[a]);
     }
	
	for(int a=0;a!=how;a++){
	but[a]=gtk_button_new();
	gtk_button_set_image(GTK_BUTTON(but[a]),img[a]);
    }
	
	gtk_window_set_title(GTK_WINDOW(win),"GAME LAUNCHER");
    gtk_window_set_default_size(GTK_WINDOW(win),1366,768);
	gtk_window_set_icon(GTK_WINDOW(win),ico);
 gtk_window_set_position(GTK_WINDOW(win),GTK_WIN_POS_CENTER);
 gtk_container_add(GTK_CONTAINER(win),scrl);

gtk_container_add(GTK_CONTAINER(scrl),fix);

    gtk_fixed_put(GTK_FIXED(fix),bimg,0,0);
	
	gtk_fixed_put(GTK_FIXED(fix),cred,1250,10);

//g_print("%d",how);
	int d=0;
	int h=0;
	int temp=0;
	
	for(int a=0;a!=how;a++){

	if(d==1350){
	h=h+450;
	d=0;
	temp=0;
	} 
       
    gtk_fixed_put(GTK_FIXED(fix),but[a],50+d,50+h); //width,hight
	 
    d=450*(temp+1);
    temp++;
    }
	
	g_signal_connect(G_OBJECT(win),"destroy",G_CALLBACK(gtk_main_quit),NULL);
	
	int ptr[how];
	
	for(int a=0;a!=how;a++){
	ptr[a]=a;
	g_signal_connect(G_OBJECT(but[a]),"clicked",G_CALLBACK(run),&ptr[a]);
	
     }
	
	g_signal_connect(G_OBJECT(cred),"clicked",G_CALLBACK(credit),NULL);
	
	gtk_widget_show_all(win);
	
	gtk_main();
	return 0;
}
