#include <stdio.h>
#include <stdlib.h>

//default size of String is 100 (+1 for null character to end String)
//may be changed to 100 later 
#define MIN_SIZE 101 

//String data type that is implemented using a linked list
typedef struct String
{
    char cChar; //data of type char stored in a node
    struct String* strNext; //pointer to the next node of the linked list
}String;

String create(); //creates a String 
//Set add (String s, char c);
//String insert (String s, char c, int pos);
//String delete (String s, int pos);
//String substitute (String s, String find, String replace);
//int compare (String s1, String s2);
//int getLength(String s);
//void print (String s);  
