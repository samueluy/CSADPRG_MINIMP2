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

//To check how typedef String works when you want to add another node in the linked list
//(another character in a String), see the create() of the StringtTypedef-Create branch
String create ()
{
    String* strTemp = NULL;

    //dynamic memory allocation
    strTemp = (String*)malloc(sizeof(String));
    //to make sure returned character is null after creation
    strTemp->cChar = '\0';
    strTemp->strNext = NULL;

    return *strTemp;
}

/**
 * @brief Prints the whole String via recuression method
 * 
 * @param str String to be printed
 */
void print(String str)
{
    printf("%c",str.cChar); // Print the current char of the node

    // If next node is not NULL
    if (str.strNext != NULL)
    {
        print(*str.strNext);  // Print the next node
    }
}

/**
 * @brief Gets the length of the  parameter String
 * 
 * @param str String to be length measured
 * @return int the length of the Strign(str)
 */
int getLength(String str)
{
    int nCtr = 0;
    String* strCurrent = &str;

    // Check if the end of the String
    while(strCurrent != NULL )
    {
        nCtr++; // Increment String length 
        strCurrent = strCurrent->strNext; // Change struct string to be checked later

    }

    return nCtr;
}
