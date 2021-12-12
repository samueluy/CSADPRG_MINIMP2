#include "header.h"

int main (void)
{
    String s1, s2;
    s1 = create();
    s2 = create();

    //add (s1, 'e');
    //add (s1, 'l');
    //add (s1, 'l');
    //add (s1, 'o');
    //
    //add (s2, 'H');
    //add (s2, 'e');
    //add (s2, 'l');
    //add (s2, 'l');
    //add (s2, 'o');
    //add (s2, ' ');
    //add (s2, 'W');
    //add (s2, 'o');
    //add (s2, 'r');
    //add (s2, 'l');
    //add (s2, 'd');

    //print (s1);   // this statement will display (Hello)
    //add (s2, '!');
    //print (s2); // this statement will display (Hello World!)
    //print (insert(s2, 11, 's')); // this statement will return (Hello Worlds!)
    //print (delete(s2, 11)); // this statement will return (Hello World)
    //print (substitute(s2, "World", "CCPROG")); // this statement will return (Hello CCPROG!)
    //print (compare(s1, s2)); // this statement will return (0)
    //print (getLength(s1));// this statement will return (5)

    return 0;
}

String create ()
{
    String* strHead = NULL;
    String* strTrail = NULL;
    String* strTemp = NULL;

    //create individual nodes in the linked list (String)
    //these nodes are not yet attached to the linked list
    for(int i = 0; i < MIN_SIZE; i++)
    {
        strTemp = (String*)malloc(sizeof(String));
        //to make sure every character is null after creation
        strTemp->cChar = '\0';
        strTemp->strNext = NULL;

        //if linked list is still empty; make strTemp as the first node
        if(strHead == NULL)
        {
            strHead = strTemp;
        }
        else
        {
            strTrail = strHead;
            while(strTrail->strNext != NULL)
            {
                strTrail = strTrail->strNext;
            }
            strTrail->strNext = strTemp; //attach next nodes to linked list
        }
    }

    return *strHead;
}