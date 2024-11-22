#include <stdio.h>
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

int mbal=500,brate,srate,exp,tmp,h,dp=16;

char *name,*wname;

GtkWidget *ent[10];


void val(int *ptr,gpointer *data){

 gchar *arr = gtk_entry_get_text(GTK_ENTRY(*data)); 
 
 name=gtk_entry_get_text(GTK_ENTRY(ent[3]));
 wname=gtk_entry_get_text(GTK_ENTRY(ent[1]));
	
	
 FILE *ptr1;
  
 ptr1=fopen("/home/cyborg/Documents/c_programing/money_log/GUI/data.txt","w");  
 fprintf(ptr1,"%s\n",arr); 	
 fclose(ptr1);	
 
 
 ptr1=fopen("data.txt","r");
 fscanf(ptr1,"%d",ptr); 	
 fclose(ptr1);	
						
}
	

void print(GtkWidget *win, gpointer *data){	
//g_print("%s",gtk_entry_get_text(data[0]));

val(&exp, &ent[0]);
val(&srate,&ent[5]);
val(&brate,&ent[4]);
val(&h,    &ent[6]);
val(&tmp,    &ent[2]);

int pro=(srate-brate)*h-dp;

if(srate!=0 && brate!=0 && name!=NULL){
FILE *ptr;
ptr=fopen("/home/cyborg/Documents/c_programing/money_log/GUI/entry.txt","a");
mbal=mbal+pro;
fprintf(ptr,"\n\n%s x %d : BUY = %d  SALE = %d    net profit : %d\t\t\t\t\t\tmain balance :%d",name,h,brate,srate,pro,mbal);
fclose(ptr);

}

if(wname!=NULL&&tmp!=0){

FILE *ptr;
ptr=fopen("/home/cyborg/Documents/c_programing/money_log/GUI/entry.txt","a");
mbal=mbal+tmp;
fprintf(ptr,"\n\n\n%s  	%d\t\t\t\t\t\tmain balance :%d",wname,tmp,mbal);
fclose(ptr);
}

if(exp!=0){

FILE *ptr;
ptr=fopen("/home/cyborg/Documents/c_programing/money_log/GUI/entry.txt","a");
mbal=mbal-exp;
fprintf(ptr,"\n\n\nexpensis   %d\t\t\t\t\t\tmain balance :%d",exp,mbal);
fclose(ptr);

}

				
g_print("mabal :%d\n",mbal);
g_print("srate  :%d\n",srate);
g_print("brate:%d\n",brate);
g_print("h :%d\n",h);
g_print("%s\n",name);
g_print("profit :%d\n",pro);
}

int main(int argc, char **argv)
{
	gtk_init(&argc,&argv);
	
	GtkWidget *win,*but1;
	GtkWidget *lab[15];
	GtkWidget *img;
	GtkWidget *fix;
		
	PangoFontDescription *pfd,*pfd1;

    GdkPixbuf *ico;
 
    //main window
    win=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(win),300,450); //width / hight
	gtk_window_set_title(GTK_WINDOW(win),"MONEY LOG");
    fix=gtk_fixed_new();
	gtk_container_add(GTK_CONTAINER(win),fix);
	gtk_window_set_resizable(GTK_WINDOW(win),FALSE);
	
	//ICON
	
	ico=gdk_pixbuf_new_from_file("/home/cyborg/Documents/c_programing/money_log/GUI/ico.png",NULL);
	gtk_window_set_icon(GTK_WINDOW(win),ico);
	
	//font
	pfd=pango_font_description_from_string("Monospace Bold");
	pango_font_description_set_size(pfd,16 *PANGO_SCALE);
	
    pfd1=pango_font_description_from_string("Monospace Bold");
	pango_font_description_set_size(pfd1,10 *PANGO_SCALE);

	
	//backgrond
	img=gtk_image_new_from_file("/home/cyborg/Documents/c_programing/money_log/GUI/bac.png");
	
	but1=gtk_button_new_with_label("SAVE");	
	
	//labels
	
	lab[0]=gtk_label_new("Stocks Entry");
	gtk_widget_modify_font(lab[0],pfd);
	
	lab[1]=gtk_label_new("Others Entry");
	gtk_widget_modify_font(lab[1],pfd);

	lab[2]=gtk_label_new("Expensis");
	gtk_widget_modify_font(lab[2],pfd);

	lab[3]=gtk_label_new("Main balance");
	gtk_widget_modify_font(lab[3],pfd1);
	
    lab[4]=gtk_label_new("Stock name");
	gtk_widget_modify_font(lab[4],pfd1);
	
	lab[5]=gtk_label_new("Buy rate");
	gtk_widget_modify_font(lab[5],pfd1);
	
	lab[6]=gtk_label_new("Sell rate");
	gtk_widget_modify_font(lab[6],pfd1);
	
	lab[7]=gtk_label_new("How many");
	gtk_widget_modify_font(lab[7],pfd1);
	
	lab[8]=gtk_label_new("Work name");
	gtk_widget_modify_font(lab[8],pfd1);
	
    lab[9]=gtk_label_new("Net profit");
	gtk_widget_modify_font(lab[9],pfd1);
	
	lab[10]=gtk_label_new("enter amount");
	gtk_widget_modify_font(lab[10],pfd1);
	
	lab[11]=gtk_label_new("DEVLOP BY CYBORG");
	
	//lab[12]=gtk_label_new("%d",mbal);
	//gtk_widget_modify_font(lab[12],pfd1);
	
	//entryss
		ent[0]=gtk_entry_new();
		ent[1]=gtk_entry_new();
		ent[2]=gtk_entry_new();
		ent[3]=gtk_entry_new();
		ent[4]=gtk_entry_new();
		ent[5]=gtk_entry_new();
		ent[6]=gtk_entry_new();

	//fixed
	gtk_fixed_put(GTK_FIXED(fix),img,0,0);
	
    gtk_fixed_put(GTK_FIXED(fix),lab[0],10,60);
	gtk_fixed_put(GTK_FIXED(fix),lab[1],10,230);
	gtk_fixed_put(GTK_FIXED(fix),lab[2],10,330);

	gtk_fixed_put(GTK_FIXED(fix),lab[3],140,20);       //Left , Hight
	//gtk_fixed_put(GTK_FIXED(fix),lab[12],170,20);
	
	//stocks
	gtk_fixed_put(GTK_FIXED(fix),lab[4],10,100); 
    gtk_fixed_put(GTK_FIXED(fix),ent[3],120,100-5);

	gtk_fixed_put(GTK_FIXED(fix),lab[5],10,130);
	gtk_fixed_put(GTK_FIXED(fix),ent[4],120,130-5);

	gtk_fixed_put(GTK_FIXED(fix),lab[6],10,160);
    gtk_fixed_put(GTK_FIXED(fix),ent[5],120,160-5);

	gtk_fixed_put(GTK_FIXED(fix),lab[7],10,190);
	gtk_fixed_put(GTK_FIXED(fix),ent[6],120,190-5);
	
	//others
	gtk_fixed_put(GTK_FIXED(fix),lab[8],10,270);
	gtk_fixed_put(GTK_FIXED(fix),lab[9],10,300);
	gtk_fixed_put(GTK_FIXED(fix),ent[1],120,270-5);
    gtk_fixed_put(GTK_FIXED(fix),ent[2],120,300-5);
	
	//expensis
	gtk_fixed_put(GTK_FIXED(fix),lab[10],10,360);
	gtk_fixed_put(GTK_FIXED(fix),ent[0],120,360-5);

		
	gtk_fixed_put(GTK_FIXED(fix),lab[11],170,435);

	gtk_fixed_put(GTK_FIXED(fix),but1,120,398);
	
	//signals
	g_signal_connect(G_OBJECT(win),"destroy",G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect(G_OBJECT(but1),"clicked",G_CALLBACK(print),ent);
	
	gtk_widget_show_all(win);
	gtk_main();
	
	return 0;
}

