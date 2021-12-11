#include <stdlib.h>
#include <gtk/gtk.h>
#include <stddef.h>
#include <locale.h>
#include "calculator.h"


static GtkBuilder *gtkBuilder;
static GtkEntry  *displayNumbersEntry;
static GtkWidget *calculatorWindow;
static GtkWidget *messageDialog,
    *resetButton,
    *divisionButton,
    *multiplicationButton,
    *subtractionButton,
    *sumButton,
    *decimalSeparatorButton,
    *equalsButton,
    *oneButton,
    *twoButton,
    *threeButton,
    *fourButton,
    *fiveButton,
    *sixButton,
    *sevenButton,
    *eightButton,
    *nineButton,
    *zeroButton;


static void resetButton_onClick(GtkWidget *widget, gpointer data) {
    inputs_reset();
    gtk_entry_set_text(displayNumbersEntry, ftoa(shows_a_result()));
}

static void divisionButton_onClick(GtkWidget *widget, gpointer data) {
    inputs('/');
    gtk_entry_set_text(displayNumbersEntry, get_tokens());
}

static void multiplicationButton_onClick(GtkWidget *widget, gpointer data) {
    inputs('*');
    gtk_entry_set_text(displayNumbersEntry, get_tokens());
}

static void subtractionButton_onClick(GtkWidget *widget, gpointer data) {
    inputs('-');
    gtk_entry_set_text(displayNumbersEntry, get_tokens());
}

static void sumButton_onClick(GtkWidget *widget, gpointer data) {
    inputs('+');
    gtk_entry_set_text(displayNumbersEntry, get_tokens());
}

static void decimalSeparatorButton_onClick(GtkWidget *widget, gpointer data) {
    inputs('.');
    gtk_entry_set_text(displayNumbersEntry, get_tokens());
}

static void equalsButton_onClick(GtkWidget *widget, gpointer data) {
    inputs_equals();
    gtk_entry_set_text(displayNumbersEntry, ftoa(shows_a_result()));
    if (strcmp(g_error_message, MSG_DIVISION_BY_ZERO) == 0) {
        messageDialog = gtk_message_dialog_new (NULL,
                                 GTK_DIALOG_DESTROY_WITH_PARENT,
                                 GTK_MESSAGE_ERROR,
                                 GTK_BUTTONS_CLOSE,
                                 "Error: %s",
                                 shows_a_error_message());
        gtk_dialog_run (GTK_DIALOG (messageDialog));
        gtk_widget_destroy (messageDialog);
        strcpy(g_error_message, "");
    }
}

static void oneButton_onClick(GtkWidget *widget, gpointer data) {
    inputs('1');
    gtk_entry_set_text(displayNumbersEntry, get_tokens());
}

static void twoButton_onClick(GtkWidget *widget, gpointer data) {
    inputs('2');
    gtk_entry_set_text(displayNumbersEntry, get_tokens());
}

static void threeButton_onClick(GtkWidget *widget, gpointer data) {
    inputs('3');
    gtk_entry_set_text(displayNumbersEntry, get_tokens());
}

static void fourButton_onClick(GtkWidget *widget, gpointer data) {
    inputs('4');
    gtk_entry_set_text(displayNumbersEntry, get_tokens());
}

static void fiveButton_onClick(GtkWidget *widget, gpointer data) {
    inputs('5');
    gtk_entry_set_text(displayNumbersEntry, get_tokens());
}

static void sixButton_onClick(GtkWidget *widget, gpointer data) {
    inputs('6');
    gtk_entry_set_text(displayNumbersEntry, get_tokens());
}

static void sevenButton_onClick(GtkWidget *widget, gpointer data) {
    inputs('7');
    gtk_entry_set_text(displayNumbersEntry, get_tokens());
}

static void eightButton_onClick(GtkWidget *widget, gpointer data) {
    inputs('8');
    gtk_entry_set_text(displayNumbersEntry, get_tokens());
}

static void nineButton_onClick(GtkWidget *widget, gpointer data) {
    inputs('9');
    gtk_entry_set_text(displayNumbersEntry, get_tokens());
}

static void zeroButton_onClick(GtkWidget *widget, gpointer data) {
    inputs('0');
    gtk_entry_set_text(displayNumbersEntry, get_tokens());
}

int main(int argc, char *argv[]) {

    gtk_disable_setlocale();

    gtk_init(&argc, &argv);

    gtkBuilder = gtk_builder_new();
    gtk_builder_add_from_file(gtkBuilder, "calculator_ui.glade", NULL);

    calculatorWindow = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "calculatorWindow"));
    g_signal_connect (calculatorWindow, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    displayNumbersEntry = GTK_ENTRY(gtk_builder_get_object(gtkBuilder, "displayNumbersEntry"));

    resetButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "resetButton"));
    g_signal_connect (resetButton, "clicked", G_CALLBACK (resetButton_onClick), NULL);

    divisionButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "divisionButton"));
    g_signal_connect (divisionButton, "clicked", G_CALLBACK (divisionButton_onClick), NULL);

    multiplicationButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "multiplicationButton"));
    g_signal_connect (multiplicationButton, "clicked", G_CALLBACK (multiplicationButton_onClick), NULL);

    subtractionButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "subtractionButton"));
    g_signal_connect (subtractionButton, "clicked", G_CALLBACK (subtractionButton_onClick), NULL);

    sumButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "sumButton"));
    g_signal_connect (sumButton, "clicked", G_CALLBACK (sumButton_onClick), NULL);

    decimalSeparatorButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "decimalSeparatorButton"));
    g_signal_connect (decimalSeparatorButton, "clicked", G_CALLBACK (decimalSeparatorButton_onClick), NULL);

    equalsButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "equalsButton"));
    g_signal_connect (equalsButton, "clicked", G_CALLBACK (equalsButton_onClick), NULL);

    oneButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "oneButton"));
    g_signal_connect (oneButton, "clicked", G_CALLBACK (oneButton_onClick), NULL);

    twoButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "twoButton"));
    g_signal_connect (twoButton, "clicked", G_CALLBACK (twoButton_onClick), NULL);

    threeButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "threeButton"));
    g_signal_connect (threeButton, "clicked", G_CALLBACK (threeButton_onClick), NULL);

    fourButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "fourButton"));
    g_signal_connect (fourButton, "clicked", G_CALLBACK (fourButton_onClick), NULL);

    fiveButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "fiveButton"));
    g_signal_connect (fiveButton, "clicked", G_CALLBACK (fiveButton_onClick), NULL);

    sixButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "sixButton"));
    g_signal_connect (sixButton, "clicked", G_CALLBACK (sixButton_onClick), NULL);

    sevenButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "sevenButton"));
    g_signal_connect (sevenButton, "clicked", G_CALLBACK (sevenButton_onClick), NULL);

    eightButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "eightButton"));
    g_signal_connect (eightButton, "clicked", G_CALLBACK (eightButton_onClick), NULL);

    nineButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "nineButton"));
    g_signal_connect (nineButton, "clicked", G_CALLBACK (nineButton_onClick), NULL);

    zeroButton = GTK_WIDGET(gtk_builder_get_object(gtkBuilder, "zeroButton"));
    g_signal_connect (zeroButton, "clicked", G_CALLBACK (zeroButton_onClick), NULL);

    resetButton_onClick(resetButton, NULL);
    gtk_widget_grab_focus (resetButton);

    g_object_unref(G_OBJECT(gtkBuilder));
    gtk_widget_show(calculatorWindow);
    gtk_main();

    return 0;
}

