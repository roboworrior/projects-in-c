#include <gtk/gtk.h>
#include <stdio.h>
#include <time.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

char arr[5][11];


void rnd(){

char let[]={"qwertyuiopasdfghjklzxcvbnm1234567890!@#$%^&*()_+|=-/.,:;'[]"};

srand(time(0));

int num[5];

int i=0;
int j=0;

while( j<=5 ){

while( i<10 ){

num[j]=rand()%54;


arr[j][i]=let[num[j]];

	i++ ;
}
	arr[j][i] = '\0';

i=0;
j++;

}



}

 void print(GtkWidget *win, gpointer  *entry)
{


	rnd();



    gtk_entry_set_text(GTK_ENTRY(entry[0]),("%s",arr[0]));
    gtk_entry_set_text(GTK_ENTRY(entry[1]),("%s",arr[1]));
	gtk_entry_set_text(GTK_ENTRY(entry[2]),("%s",arr[2]));
    gtk_entry_set_text(GTK_ENTRY(entry[3]),("%s",arr[3]));
	gtk_entry_set_text(GTK_ENTRY(entry[4]),("%s",arr[4]));




}
void txt(GtkWidget *win, gpointer  *entry){



	FILE *ptr;

	ptr=fopen("pass.txt","w");

	fprintf(ptr,"1)password : %s\n",arr[0]);
	fprintf(ptr,"2)password : %s\n",arr[1]);
	fprintf(ptr,"3)password : %s\n",arr[2]);
	fprintf(ptr,"4)password : %s\n",arr[3]);
	fprintf(ptr,"5)password : %s\n",arr[4]);

	g_print("DONE au\n");

	fclose(ptr);
}



int main(int argc,char **argv){

	gtk_init(&argc,&argv);

	GtkWidget  *win,*lab[6];
	GtkWidget  *but1,*but2;
	GtkWidget  *fix;
	GtkWidget  *entry[6];
	GdkPixbuf *buf;
	GtkWidget  *img;


	win=gtk_window_new(GTK_WINDOW_TOPLEVEL);

	img=gtk_image_new_from_file("back.png");
	fix=gtk_fixed_new();

	but1=gtk_button_new_with_label("GENERATE");
	but2=gtk_button_new_with_label("TXT");

   buf=gdk_pixbuf_new_from_file("ico.png",NULL);

    	      gtk_window_set_icon(GTK_WINDOW(win),buf);

    gtk_window_set_default_size(GTK_WINDOW(win),322,280);	//width,hight
	gtk_window_set_resizable(GTK_WINDOW(win),FALSE);	//width,hight
	gtk_window_set_title(GTK_WINDOW(win),"PGEN");


	gtk_fixed_put(GTK_FIXED( fix) ,img,0,0);

	entry[0]=gtk_entry_new();
	entry[1]=gtk_entry_new();
	entry[2]=gtk_entry_new();
	entry[3]=gtk_entry_new();
	entry[4]=gtk_entry_new();


    gtk_entry_set_max_length(GTK_ENTRY(entry[0]),50);
	gtk_entry_set_max_length(GTK_ENTRY(entry[1]),50);
	gtk_entry_set_max_length(GTK_ENTRY(entry[2]),50);
	gtk_entry_set_max_length(GTK_ENTRY(entry[3]),50);
	gtk_entry_set_max_length(GTK_ENTRY(entry[4]),50);



	 gtk_fixed_put(GTK_FIXED( fix) ,entry[0],150,55);
	gtk_fixed_put(GTK_FIXED( fix) ,entry[1],150,95);
	gtk_fixed_put(GTK_FIXED( fix) ,entry[2],150,140);
	gtk_fixed_put(GTK_FIXED( fix) ,entry[3],150,180);
	gtk_fixed_put(GTK_FIXED( fix) ,entry[4],150,220);



	lab[0]=gtk_label_new("1) PASSOWORD IS  => ");
	lab[1]=gtk_label_new("2) PASSOWORD IS  => ");
	lab[2]=gtk_label_new("3) PASSOWORD IS  => ");
	lab[3]=gtk_label_new("4) PASSOWORD IS  => ");
	lab[4]=gtk_label_new("5) PASSOWORD IS  => ");
	lab[5]=gtk_label_new("DEVLOP BY CYBORG");



	gtk_fixed_put(GTK_FIXED( fix) ,lab[0],1,61);
	gtk_fixed_put(GTK_FIXED( fix) ,lab[1],1,101);
	gtk_fixed_put(GTK_FIXED( fix) ,lab[2],1,146);
	gtk_fixed_put(GTK_FIXED( fix) ,lab[3],1,186);
	gtk_fixed_put(GTK_FIXED( fix) ,lab[4],1,226);
	gtk_fixed_put(GTK_FIXED( fix) ,lab[5],190,260);




	gtk_container_add(GTK_CONTAINER(win),fix);

    gtk_fixed_put(GTK_FIXED( fix) ,but1,7,7);    //   LEFT    ,  UP
	gtk_fixed_put(GTK_FIXED( fix) ,but2,250,7);


	//gtk_container_set_border_width(GTK_CONTAINER(win),180);

	g_signal_connect(G_OBJECT(win),"destroy",(gtk_main_quit),NULL);

	g_signal_connect(G_OBJECT(but1),"clicked",G_CALLBACK(print),(entry));
	g_signal_connect(G_OBJECT(but2),"clicked",G_CALLBACK(txt),(entry));




	//g_signal_connect(G_OBJECT(win),"destroy",G_CALLBACK(gtk_main_quit),NULL);


	gtk_widget_show_all(win);

	gtk_main();

	return 0;
	}
