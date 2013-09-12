#include <gtk/gtk.h>
#include<string.h>
#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>

   static GtkWidget *button_signin;
   static GtkWidget *entry1;
   static GtkWidget *entry2;
   static GtkWidget *entry3;
   static GtkWidget *entry4;
   static GtkWidget *entry5;
   static GtkWidget *entry6;
   static GtkWidget *entry7;
   static GtkWidget *entry8;

static void button_press(GtkWidget *button_signin,gpointer data)
{
 //getting data from the entry
 char *get_name  = gtk_entry_get_text(GTK_ENTRY(entry1));
 char *get_fname = gtk_entry_get_text(GTK_ENTRY(entry2));
 char *get_dob   = gtk_entry_get_text(GTK_ENTRY(entry3));
 char *get_10    = gtk_entry_get_text(GTK_ENTRY(entry4));
 char *get_12    = gtk_entry_get_text(GTK_ENTRY(entry5));
 char *get_grad  = gtk_entry_get_text(GTK_ENTRY(entry6));
 char *get_emailid = gtk_entry_get_text(GTK_ENTRY(entry7));
 char *get_mobile  = gtk_entry_get_text(GTK_ENTRY(entry8));
 
 // validation
 bool valid = TRUE;
 for (int i = 0; i < strlen(get_name);++i)
  { 
    if (isdigit(get_name[i]))
    {
        valid = FALSE;
        break;
    }
  }
 if(valid==FALSE)
  {
  printf("Name Not valid \n");
  valid=TRUE;
  }
 for (int i = 0; i < strlen(get_fname);++i)
  { 
    if (isdigit(get_fname[i]))
    {
        valid = FALSE;
        break;
    }
  }
 if(valid==FALSE)
  {
  printf("Father's Name Not valid \n");
  valid=TRUE;
  }
   
 for (int i = 0; i < strlen(get_10);++i)
  { 
    if (!isdigit(get_10[i]))
    {
        valid = FALSE;
        break;
    }
  }
 if(valid==FALSE)
  {
  printf("10th percentage Not valid \n");
  valid=TRUE;
  }
  
  for (int i = 0; i < strlen(get_12);++i)
      { 
        if (!isdigit(get_12[i]))
        {
        valid = FALSE;
        break;
        }
     }
 if(valid==FALSE)
  {
  printf("12th percentage Not valid\n");
  valid=TRUE;
  }

  for (int i = 0; i < strlen(get_grad);++i)
      { 
        if (!isdigit(get_grad[i]))
        {
        valid = FALSE;
        break;
        }
     }
 if(valid==FALSE)
  {
  printf("Graduation percentage Not valid\n");
  valid=TRUE;
  }
  
  for (int i = 0; i < strlen(get_mobile);++i)
      { 
        if (isdigit(get_mobile[i]))
        {
        valid = FALSE;
        break;
        }
     }
 if(valid==FALSE)
  {
  printf("Mobile Number Not valid\n");
  valid=TRUE;
  }
 
 //for checking that data entered is stored in string
 /*printf("%s\n",get_name);printf("%s\n",get_fname);//printf("%s\n",get_dob);//printf("%s\n",get_10);printf("%s\n",get_12);
 printf("%s\n",get_grad);printf("%s\n",get_emailid);printf("%s\n",get_mobile);
*/
}

int
main (int argc,char *argv[])
{
   GtkWidget *window;
   //GtkWidget *button_signin;
   GtkWidget *button_exit;
   GtkWidget *fixed;
   
   GtkWidget *textlabel_name;
   GtkWidget *textlabel_fname;
   GtkWidget *textlabel_title;
   GtkWidget *textlabel_dob;
   GtkWidget *textlabel_10;
   GtkWidget *textlabel_12;
   GtkWidget *textlabel_grad;
   GtkWidget *textlabel_emailid;
   GtkWidget *textlabel_mobile;
   GtkWidget *image;
   GtkWidget *image2;
   GError *error = NULL;
   GdkPixbuf *pixbuf;
   GtkWidget *calender_date;
   GtkWidget *calender_date1;
   guint year, month, day;
   

   // intialiazation
   gtk_init (&argc, &argv);
    
    
   //window attributes position,size,title
   window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
   gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
   gtk_window_set_default_size(GTK_WINDOW(window), 640, 380);
   gtk_window_set_title(GTK_WINDOW(window), "User Detail");
   gtk_container_set_border_width(GTK_CONTAINER(window),12);
   //gtk_window_set_resizable(GTK_WINDOW(window),FALSE);
  
  
   //button with label
   button_signin = gtk_button_new_with_label("SIGN UP>>");
   button_exit = gtk_button_new_with_label("EXIT (X)");  
  
  
  //calender
  //calender_date1=gtk_calendar_get_date(GtkCalendar *calendar_date,guint *year,guint *month,guint *day);
    calender_date = gtk_calendar_new ();
  
                                                         
  //labels
  textlabel_title = gtk_label_new("->USER DETAILS<-");
  textlabel_name  = gtk_label_new("NAME  :-");
  textlabel_fname = gtk_label_new("FATHER'S NAME  :-");
  textlabel_dob = gtk_label_new("D.O.B  :-");
  textlabel_10 = gtk_label_new("10th %(Rounded off)  :-");
  textlabel_12 = gtk_label_new("12th / DIPLOMA %(Rounded off) :-");
  textlabel_grad = gtk_label_new("GRADUATION %(Rounded off)  :-");
  textlabel_emailid = gtk_label_new("EMAIL ID  :-");
  textlabel_mobile = gtk_label_new("MOBILE NO.  :-");
  
 
  
 
   // entry is field like textbox
   entry1 = gtk_entry_new();
   entry2 = gtk_entry_new();
   entry3 = gtk_entry_new();
   entry4 = gtk_entry_new();
   entry5 = gtk_entry_new();
   entry6 = gtk_entry_new();
   entry7 = gtk_entry_new();
   entry8 = gtk_entry_new();
   
   gtk_entry_set_max_length(GTK_ENTRY(entry8),10);
   gtk_entry_set_max_length(GTK_ENTRY(entry4),2);
   gtk_entry_set_max_length(GTK_ENTRY(entry5),2);
   gtk_entry_set_max_length(GTK_ENTRY(entry6),2);
   char* txtBuffer = "dd/mm/yyyy";
   gtk_entry_set_text(GTK_ENTRY(entry3),txtBuffer);
   gtk_widget_set_sensitive(entry3,FALSE);
   
   
   //Image setting
   pixbuf = gdk_pixbuf_new_from_file_at_size ("/home/trilok/trantorlogo.png", 100, 100, &error);
   if(!pixbuf)
   {
     g_print ("Error: %s\n", error->message);
     g_error_free (error);
     /* Handle error here */
   }
   image = gtk_image_new_from_pixbuf(pixbuf);
   image2 = gtk_image_new_from_pixbuf(pixbuf);
   g_object_unref (pixbuf);



  //events monitoring from output window
  g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);
  g_signal_connect (button_exit,"clicked",G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect (button_signin,"clicked",G_CALLBACK(button_press), NULL);
  
  
  
  // for fixing widgets in container
  fixed = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(window), fixed);
  gtk_widget_show(fixed);
  
  
  //fixing button and entry in container
  // packing of widgeets in the fixxed window
  gtk_fixed_put(GTK_FIXED(fixed), image, 0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), image2, 0, 550);    
  gtk_fixed_put(GTK_FIXED(fixed), textlabel_title, 225, 20);
  gtk_fixed_put(GTK_FIXED(fixed), entry1, 300, 80);
  gtk_fixed_put(GTK_FIXED(fixed), entry2, 300, 135);
  gtk_fixed_put(GTK_FIXED(fixed), entry3, 300, 185);
  gtk_fixed_put(GTK_FIXED(fixed), entry4, 300, 235);
  gtk_fixed_put(GTK_FIXED(fixed), entry5, 300, 285);
  gtk_fixed_put(GTK_FIXED(fixed), entry6, 300, 335);
  gtk_fixed_put(GTK_FIXED(fixed), entry7, 300, 385);
  gtk_fixed_put(GTK_FIXED(fixed), entry8, 300, 435);
  gtk_fixed_put(GTK_FIXED(fixed), textlabel_name, 65, 85);
  gtk_fixed_put(GTK_FIXED(fixed), textlabel_fname,65, 140);
  gtk_fixed_put(GTK_FIXED(fixed), textlabel_dob,65, 190);
  gtk_fixed_put(GTK_FIXED(fixed), textlabel_10,65, 240);
  gtk_fixed_put(GTK_FIXED(fixed), textlabel_12,65, 290);
  gtk_fixed_put(GTK_FIXED(fixed), textlabel_grad,65, 340);
  gtk_fixed_put(GTK_FIXED(fixed), textlabel_emailid,65, 390);
  gtk_fixed_put(GTK_FIXED(fixed), textlabel_mobile,65, 440); 
  gtk_fixed_put(GTK_FIXED(fixed), button_signin,355, 550); 
  gtk_fixed_put(GTK_FIXED(fixed), button_exit,490, 550); 
  //gtk_fixed_put(GTK_FIXED(fixed), calender_date,300, 155); 
  
  gtk_widget_show_all(window);
 
  gtk_main ();

  return 0;
}
