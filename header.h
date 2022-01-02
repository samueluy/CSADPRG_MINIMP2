#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE 1 

//String data type that is implemented using a linked list
struct linkedList
{
    char cChar; //data of type char stored in a node
    struct String* strNext; //pointer to the next node of the linked list
};

typedef struct linkedList* String;

String create(); //creates a String 
String add (String s, char c);
String insert (String s, char c, int pos);
//String delete (String s, int pos);
//String substitute (String s, String find, String replace);
//int compare (String s1, String s2);
int getLength(String s);
void print (String s);  
