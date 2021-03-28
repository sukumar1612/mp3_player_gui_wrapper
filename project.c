#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>

static void destroy( GtkWidget *widget,
                     gpointer   data )
{
    gtk_main_quit ();
    //printf("button was %d",*data);
}
struct id{
        int x;
};

void location (char x[][50])
{
        FILE *p;
        p=fopen("music.txt","r+");

        int i=0;
        char name[50];
        //char location[50];
        for (;;)
        {
                if (feof(p))
                {
                        break;
                }
                fscanf(p,"%s %s\n",name,x[i]);
                i++;
        }
        char y[i][50];
        for (int j=0;j<i;j++)
        {
                char ch[] = {"ffplay "};
                strcpy(y[j],ch);
                strcat(y[j],x[j]);
                strcpy(x[j],y[j]);
        }

}
static void check(GtkWidget *widget, gpointer data)
{
	struct id *xy=data;
        char x[100][50];
        location(x);
        system (x[xy->x]); 
        //system ();
        gtk_main_quit ();
}
int no_of()
{
        FILE *p;
        p=fopen("music.txt","r+");

        int i=0;
        char name[50];
        char location[50];
        for (;;)
        {
                if (feof(p))
                {
                        break;
                }
	}
                fscanf(p,"%s %s\n",name,location);
                i++;
        }
        return i;

}
void nameo (char name[][10])
{
        FILE *p;
        p=fopen("music.txt","r+");

        int i=0;
        //char name[50];
        char location[50];
        for (;;)
        {
                if (feof(p))
                {
                        break;
                }
                fscanf(p,"%s %s\n",name[i],location);
                i++;
	}
}

int main( int   argc,
          char *argv[] )
{
    struct id xy[30];
    static GtkWidget *window;
    GtkWidget *scrolled_window;
    GtkWidget *table;
    GtkWidget *button[30];
    char buffer[32];
    int i, j;
    j=no_of();
    gtk_init (&argc, &argv);

    /* Create a new dialog window for the scrolled window to be
     * packed into.  */
    window = gtk_dialog_new ();
    g_signal_connect (window, "destroy",
                      G_CALLBACK (destroy), NULL);
    gtk_window_set_title (GTK_WINDOW (window), "GtkScrolledWindow example");
    gtk_container_set_border_width (GTK_CONTAINER (window), 0);
    gtk_widget_set_size_request (window, 300, 300);
    /* create a new scrolled window. */
    scrolled_window = gtk_scrolled_window_new (NULL, NULL);

    gtk_container_set_border_width (GTK_CONTAINER (scrolled_window), 10);

    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window),
                                    GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);

    gtk_box_pack_start (GTK_BOX (GTK_DIALOG(window)->vbox), scrolled_window,
                        TRUE, TRUE, 0);
    gtk_widget_show (scrolled_window);
        //put value of no of rows here
    table = gtk_table_new (j, j, FALSE);

    /* set the spacing to 10 on x and 10 on y */
    //gtk_table_set_row_spacings (GTK_TABLE (table), 10);
    gtk_table_set_col_spacings (GTK_TABLE (table), j);

    /* pack the table into the scrolled window */
    gtk_scrolled_window_add_with_viewport (
                   GTK_SCROLLED_WINDOW (scrolled_window), table);
    gtk_widget_show (table);

    char name[j][10];
    nameo(name);
    for (i = 0; i < j; i++)
    {
          //sprintf (buffer, "button %d", i);
          button[i] = gtk_toggle_button_new_with_label (name[i]);
          //x[i]=i;
          xy[i].x=i;
          g_signal_connect (button[i] , "clicked" ,G_CALLBACK (check) , &xy[i] );
          gtk_table_attach_defaults (GTK_TABLE (table), button[i],
                                     0, 1, i, i+1);
          gtk_widget_show (button[i]);
    }
    GtkWidget *button1;
    button1 = gtk_button_new_with_label ("pause");
    g_signal_connect_swapped (button1, "clicked",
                              G_CALLBACK (gtk_widget_destroy),
                              window);

  //  GtkWidget *btn = gtk_button_new_with_label ("pause");

    gtk_widget_set_can_default (button1, TRUE);
//  gtk_widget_set_can_default (btn, FALSE);
    gtk_box_pack_start (GTK_BOX (GTK_DIALOG (window)->action_area), button1, TRUE,TRUE,0);
//  gtk_box_pack_start (GTK_BOX (GTK_DIALOG (window)->action_area), btn, TRUE, TRUE,0);

    gtk_widget_grab_default (button1);
    gtk_widget_show (button1);

    gtk_widget_show (window);

    gtk_main();

    return 0;
}




