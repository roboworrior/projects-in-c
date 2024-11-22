#include <stdio.h>
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include "stradd.c"
#include <windows.h>

char path_poster[100][500];
char path_rom[100][500];
char arr[100][50];

int how;

void key(GtkWidget *win,GdkEventKey *event,gpointer gdata){

if (event->keyval == GDK_KEY_Escape){
        gtk_main_quit();
}

if (event->keyval == GDK_KEY_F11){
       gtk_window_fullscreen(GTK_WINDOW(win));
}
if (event->keyval == GDK_KEY_F12){
       gtk_window_unfullscreen(GTK_WINDOW(win));
}




}


void datatxt();

void scan(GtkWidget *win,gpointer data){
datatxt();

int c;



	FILE *ptr;
	ptr=fopen("data.txt","r");

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


for(int a=0; a!=how; a++){

	strcpy(path_rom[a],"rom//");


   c=strlen(path_rom[a]);                        //
   stradd(path_rom[a],arr[a],c);                 //         //PATH_TO_ROMS
   c=strlen(path_rom[a]);                        //
   stradd(path_rom[a],"//",c-1);                  //
   c=strlen(path_rom[a]);                        //
//											  //
   stradd(path_rom[a],arr[a],c);                 //
//											  //
   c=strlen(path_rom[a]);                        //
   stradd(path_rom[a],".cue",c-1);               //

	}






////////////////////////////////////////////////


////////////////////////////////////////////////
											//
											  //
for(int i=0;i!=how;i++){                       //

   strcpy(path_poster[i],"rom/");            //
   c=strlen(path_poster[i]);
   stradd(path_poster[i],arr[i],c);         //
   c=strlen(path_poster[i]);											  //PATH_TO_POSTERS CREATOR
   stradd(path_poster[i],"/",c-1);         //

   c=strlen(path_poster[i]);											  //PATH_TO_POSTERS CREATOR
   stradd(path_poster[i],arr[i],c);         //

   c=strlen(path_poster[i]);                 //
   stradd(path_poster[i],".png",c-1);       //




}                                             //
											  //
											  //
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
	strcpy(tem,"core\\ePSXe190\\ePSXe.exe -nogui -loadbin ");
	g_print("\n%d ",*data);


	for(int a=0;a!=how;a++){

	if(*data==a){
	g_print("%s NOW PLAYING\n ",arr[a]); //NO SPACE IN PATH
	c=strlen(tem);
	stradd(tem,path_rom[a],c);

    popen(tem,"r");
    g_print("\n\njdjfkdf::%s  ",tem);
   }

}


	//gtk_main_quit();

	}
void credit(GtkWidget *win,gpointer data){
g_print("\n\n\n\n\n\t\t\tDEVLOP BY AKSHAY SHARMA AKA CYBORG ZONE");

GtkWidget *win1=gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_default_size(GTK_WINDOW(win1),500,500);

GtkWidget *img=gtk_image_new_from_file("EXTRA/dev.png");

gtk_container_add(GTK_CONTAINER(win1),img);

gtk_widget_show_all(win1);
}


void datatxt(){
char buffer[100];
char result[4000]="";

FILE *ptr;


ptr=popen("cd rom & dir /b ","r");

while(fgets(buffer,sizeof(buffer),ptr)){

	strcat(result,buffer);
	};

pclose(ptr);

FILE *file;



file=fopen("data.txt","w");
//g_print("%s",result);

fprintf(file,"%s",result);

	fclose(file);

	}

int main(int argc, char **argv)
{

 int hight = GetSystemMetrics(SM_CYSCREEN); // resalution of compuetr
 int width = GetSystemMetrics(SM_CXSCREEN);


	//FLR(PATH,1);
   gtk_init(&argc,&argv);
	GtkWidget *win;
	GtkWidget *fix;
    GtkWidget *scrl;
	GtkWidget *cred=gtk_button_new_with_label("CREDITS");;
    GtkWidget *bimg;
    GtkWidget *bvd;

	scan(NULL,NULL);

	GtkWidget *but[how];
    GtkWidget *img[how];
	GdkPixbuf *ico;

    scrl=gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrl),GTK_POLICY_ALWAYS,GTK_POLICY_ALWAYS);
    fix=gtk_fixed_new();

    win=gtk_window_new(GTK_WINDOW_TOPLEVEL);

	bimg=gtk_image_new_from_file("back.png");

	ico=gdk_pixbuf_new_from_file("ico.png",NULL);

    bvd=gtk_video_new_from_file("bfile.mp4");

	for(int a=0;a!=how;a++){
	img[a]=gtk_image_new_from_file("");
	gtk_image_set_from_file(GTK_IMAGE(img[a]),path_poster[a]);
     }

	for(int a=0;a!=how;a++){
	but[a]=gtk_button_new();
	gtk_button_set_image(GTK_BUTTON(but[a]),img[a]);
    }

	gtk_window_set_title(GTK_WINDOW(win),"GAME LAUNCHER");
    gtk_window_set_default_size(GTK_WINDOW(win),width,hight);
    gtk_window_fullscreen(GTK_WINDOW(win));
    gtk_widget_add_events(win, GDK_KEY_PRESS_MASK);
    gtk_window_set_icon(GTK_WINDOW(win),ico);
    gtk_window_set_position(GTK_WINDOW(win),GTK_WIN_POS_CENTER);

 gtk_container_add(GTK_CONTAINER(win),scrl);

gtk_container_add(GTK_CONTAINER(scrl),fix);



    gtk_fixed_put(GTK_FIXED(fix),bimg,0,0);

	gtk_fixed_put(GTK_FIXED(fix),cred,950,960);

g_print("%d",how);
	int d=0;
	int h=0;
	int temp=0;

g_print("\nhight %d and width %d",hight,width);

	for(int a=0;a!=how;a++){

	if(d>width-100){
	h=h+480;
	d=0;
	temp=0;
	}

    gtk_fixed_put(GTK_FIXED(fix),but[a],20+d,50+h); //width,hight

    d=380*(temp+1);
    temp++;
    }

	g_signal_connect(G_OBJECT(win),"destroy",G_CALLBACK(gtk_main_quit),NULL);

	int ptr[how];

	for(int a=0;a!=how;a++){
	ptr[a]=a;
	g_signal_connect(G_OBJECT(but[a]),"clicked",G_CALLBACK(run),&ptr[a]);

     }

	g_signal_connect(G_OBJECT(cred),"clicked",G_CALLBACK(credit),&fix);

	g_signal_connect (G_OBJECT (win), "key_press_event",G_CALLBACK (key), NULL);
	gtk_widget_show_all(win);

	gtk_main();
	return 0;
}

