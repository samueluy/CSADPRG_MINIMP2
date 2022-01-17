#include "header.h"

int main (void)
{
    String s1, s2, s3, s4;
    s1 = create();
    s2 = create();
    s3 = create(); // Find
    s4 = create(); // Replace

	add (s1, 'H');
    add (s1, 'e');
    add (s1, 'l');
    add (s1, 'l');
    add (s1, 'o');
    
    add (s2, 'H');
    add (s2, 'e');
    add (s2, 'l');
    add (s2, 'l');
    add (s2, 'o');
    add (s2, ' ');
    add (s2, 'W');	
    add (s2, 'o');
    add (s2, 'r');
    add (s2, 'l');
    add (s2, 'd');

	add (s3, 'W');
    add (s3, 'o');
    add (s3, 'r');
    add (s3, 'l');
    add (s3, 'd');
    
    add (s4, 'C');
    add (s4, 'C');
    add (s4, 'P');
    add (s4, 'R');
    add (s4, 'O');
    add (s4, 'G');

    print (s1);   // this statement will display (Hello)
	printf("\n");
    add (s2, '!');
    print (s2); // this statement will display (Hello World!)
	printf("\n");
    print (insert(s2, 's', 11)); // this statement will return (Hello Worlds!)
	printf("\n");
    print (delete(s2, 11)); // this statement will return (Hello World)
	printf("\n");
    print (substitute(s2, s3, s4)); // this statement will return (Hello CCPROG!)
	printf("\n");
    printf("%d", compare(s1, s2)); // this statement will return (0)
	printf("\n");
    printf ("%d", getLength(s1));// this statement will return (5)

    return 0;
}

/**
 * @brief Returns an empty String
 * 
 * @return String   empty String 
 */
String create ()
{
    String strTemp = NULL;

    //dynamic memory allocation
    strTemp = (String) malloc(sizeof(struct linkedList));
    //to make sure returned character is null after creation
    strTemp->cChar = '\0';
    strTemp->strNext = NULL;

    return strTemp;
}

/**
 * @brief Adds a character c to the end of the String s
 * 
 * @param String s : string to be manipulated
   		  char c : character to be added
   		  
 * @return String s : the pointer of the first element in String s
 */
String add (String s, char c){
	while (s->strNext != NULL) s = s->strNext;

    s->strNext = (String) malloc(sizeof(struct linkedList));
    s->cChar = c;
    s->strNext->cChar = '\0';
    s->strNext->strNext = NULL;

    return s;
}

/**
 * @brief Inserts a new character into a given position in the given String
 * 
 * @param String s : string to be manipulated
 *        char c  : character to be inserted
 * 	      int pos : index of the position where a given character is to be inserted
 *
 * @return String : the pointer to the first element in String s
 */
String insert (String s, char c, int pos){
	int nTemp = -1;
	String strTemp;
	strTemp = create(); //creates a temporary String
	while(s->strNext != NULL){
		nTemp++;
		if(nTemp == pos){ 
			//inserts the character into strTemp
			add(strTemp, c);
		}
		add(strTemp, s->cChar);
		s = s->strNext;
	}
	//deallocates the memory used by s to reduce wastage of memory
	free(s);
	//make the pointer to the first element in String s equal to the 
	//pointer to the first element in strTemp
	s = strTemp;
	return s;
}

/**
 * @brief Deletes a character from String s at index int pos/
 * 
 * @param String s : string to be manipulated
   		  int pos : index of the position of the character to be deleted
   		  
 * @return String : the pointer of the first element in String s
 */
 
 String delete (String s, int pos)
 {	
    // Stores the head of the linked list
    struct linkedList* strTemp = s;
 
    // If position 0 needs to be removed
    if (pos == 0) {
        s = strTemp->strNext; // change head of the linked list
        free(strTemp); // free memory of deleted node
    }
 
 	else 
 	{
 		 // Loop until node before the node to be deleted is found
	    for (int i = 0; strTemp != NULL && i < pos - 1; i++)
	        strTemp = strTemp->strNext;
	        
	    // stores the node after the node to be deleted
	    struct linkedList* next = strTemp->strNext->strNext;
	    
	    // free memory of node to be deleted
	    free(strTemp->strNext); 
	 
	    strTemp->strNext = next; // ulink the deleted node from the linked list
	 
	}
   
	return s; 	
  	
}

/**
 * @brief Prints the whole String via recuression method
 * 
 * @param str String to be printed
 */
void print(String str)
{
    printf("%c",str->cChar); // Print the current char of the node

    // If next node is not NULL
    if (str->strNext != NULL)
    {
        print(str->strNext);  // Print the next node
    }
}

/**
 * @brief Finds a substring from a string and if found, replaces it with another string.
 * 
 * @param String s Base string
 * @param String find Substring to search for
 * @param String replace String to replace with
 * @return String modified string
 */
 String substitute(String s, String find, String replace)
 {
 	String tempWord; // String variable which holds one word at a time
 	String newString; // replaced String
 	newString = create();
	
	while(s != NULL)
	{
		tempWord = create();
		while(s->cChar != ' ' && s->cChar != '\0') // Split String word per word
		{
			add(tempWord, s->cChar);
			s = s->strNext;		
			if(s->cChar == ' '){
				add(tempWord, s->cChar);
			}
		}
		
		if(compare(tempWord, find)) // add each letter of replace to the new String
		{
			while(replace != NULL)
			{
				add(newString, replace->cChar);
				replace = replace->strNext;
			}
			
			while(tempWord != NULL){ // Check and add trailing symbol
				if((tempWord->cChar >= 33 && tempWord->cChar <= 47) || (tempWord->cChar >= 58 && tempWord->cChar <= 64) ||
			  	(tempWord->cChar >= 91 && tempWord->cChar <= 96) || (tempWord->cChar >= 123 && tempWord->cChar <= 126))
					add(newString, tempWord->cChar);

				tempWord = tempWord->strNext;
			}
		}
		else // add each letter of tempWord to the new String
		{
			while(tempWord != NULL)
			{
				add(newString, tempWord->cChar);
				tempWord = tempWord->strNext;
			}
		}
		
		free(tempWord); // empty tempWord
		
		s = s->strNext;
	}
    return newString;
 }

/**
 * @brief Checks if two strings are similar
 * 
 * @param String s1 Source string to be compared
 * @param String s2 Target string to compare
 * @return int 0 = Different; 1 = Similar
 */
 
 int compare(String s1, String s2)
 {
	String s1Current;
	String s2Current = s2;
	s1Current = create();

	while(s1 != NULL) // create a temporarry String which does not contain any special character
	{
		if((s1->cChar >= 65 && s1->cChar <= 90) || (s1->cChar >= 97 && s1->cChar <= 122))
			add(s1Current, s1->cChar);

		s1 = s1->strNext;
	}
	
	
 	// Check if the lenghts are the same
 	 if(getLength(s1Current) != getLength(s2))
 	 	return 0;
	  
 		
 	// Chech the equivalence of each character
 	while(s1Current != NULL)
	 {
	 	if(s1Current->cChar!=s2Current->cChar)
			return 0;
		 
	 	else // next character
		 { 
	 		s1Current = s1Current->strNext;
	 		s2Current = s2Current->strNext;
		 }
	 }
	 return 1;
 }

/**
 * @brief Gets the length of the  parameter String
 * 
 * @param str String to be length measured
 * @return int the length of the String(str)
 */
int getLength(String str)
{
    int nCtr = 0;
    String strCurrent = str;

    // Check if the end of the String
    while(strCurrent->strNext != NULL)
    {
        nCtr++; // Increment String length 
        strCurrent = strCurrent->strNext; // Change struct string to be checked later

    }
	
    return nCtr;
}
