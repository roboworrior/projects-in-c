#include <gtk/gtk.h>
#include <stdio.h>
#include "stradd.c"

int main(int argc, char **argv)
{
	gtk_init(&argc,&argv);
	
	GtkWidget *win;
	GtkWidget *scrl;
	GtkWidget *lab;
	GtkWidget *fix;
	//char arr[10][100];
	
	win=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	 
    fix=gtk_fixed_new();
    
    scrl=gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scrl),GTK_POLICY_ALWAYS,GTK_POLICY_ALWAYS);
	
	lab=gtk_label_new("asasa");
	gtk_fixed_put(GTK_FIXED(fix),lab,500,10);

	gtk_container_add(GTK_CONTAINER(win),fix);

	//gtk_container_add(GTK_CONTAINER(scrl),fix);

char buffer[4000];
char result[4000]="";

FILE *ptr;

ptr=popen("ls /home/cyborg/Documents/c_programing/project_game_launcher/rom","r");

while(fgets(buffer,sizeof(buffer),ptr)){
	
	strcat(result,buffer);
	};

pclose(ptr);

FILE *file;

file=fopen("test1.txt","w");
g_print("%s",result);

fprintf(file,"%s",result);

	fclose(file);
	gtk_widget_show_all(win);
	
	gtk_main();
	return 0;
}

