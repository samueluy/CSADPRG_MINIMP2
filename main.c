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
    
    add (s3, 'C');
    add (s3, 'C');
    add (s3, 'P');
    add (s3, 'R');
    add (s3, 'O');
    add (s3, 'G');
    
    print (s1);   // this statement will display (Hello)
    add (s2, '!');
    print (s2); // this statement will display (Hello World!)
    //print (insert(s2, 11, 's')); // this statement will return (Hello Worlds!)
    //print (delete(s2, 11)); // this statement will return (Hello World)

    
    
    
    //print (substitute(s2, s3, s4)); // this statement will return (Hello CCPROG!)
    //print (substitute(s2, "World", "CCPROG")); // this statement will return (Hello CCPROG!)
    compare(s1, s2); // this statement will return (0)
    //print (getLength(s1));// this statement will return (5)

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
 	int nCount, findLen, simCount=0, found=0;
 	findLen = getLength(find);
 	String s1Current = s;
 	String s2Current = find; // default value
 	String s3Current = replace;
 	int lengthOfFind = getLength(find);
 	String newString;
 	String newTemp = s;
 	newString = create();
 	
    while(s1Current != NULL){ // itterate each character of s
    printf("here");
    	if(s1Current == s2Current){ // if first letter is similar
    		while(s2Current != NULL){ // itterate through each character of find
    		
    			if(s1Current != s2Current) // exit loop because different
				{
					nCount++; // start from here
					simCount=0; // reset similarity counter
					break; // exit the loop
				}
    			else // proceed to next character
				{
					if(simCount==findLen) // check if text is already similar
					{ 
						nCount-=findLen; // character count till the start of the word
						found=1; 
						break; // exit loop
					}
    				s1Current = s1Current->strNext; 
	    			s2Current = s2Current->strNext;
		 			nCount++;
				}
			}
	 		
			break;
		 }
	 	else{ // next character
	 		s2Current = find; // reset
	 		s1Current = s1Current->strNext;
	 		nCount++;
		 }
		 
		 if(found)
		 {
		 	while(newTemp->strNext != NULL)
		 	{
		 		if(nCount==0) // in first character of find
				 {
				 	while(s3Current != NULL) // itterate for the length of replace
				 	{
		 			add(newString, s3Current->cChar);
		 			s3Current = s3Current->strNext; // next character
		 			}
		 			while(lengthOfFind != 0)
		 			{
		 				newTemp = newTemp->strNext; // move to the end of find
					}
					nCount=-1; // exit if condition
				 }
		 		add(newString, newTemp->cChar); // add current char to newString
		 		newTemp = newTemp->strNext; // next character of newTemp
		 		nCount--; //
			}
		 }
		 else // no similarities found
		 {
		 	printf("Error! Substitution couldn�t be performed\n");
		 }
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
 
 void compare(String s1, String s2)
 {
	String s1Current = s1;
	String s2Current = s2;
	
 	// Check if the lenghts are the same
 	 if(getLength(s1) != getLength(s2)){
 	 	printf("0");
 	 	return;
	  }
 		
 	// Chech the equivalence of each character
 	
 	while(s1Current != NULL)
	 {
	 	if(s1Current!=s2Current){
	 		printf("0");
			return;
		 }
	 	else{ // next character
	 		s1Current = s1Current->strNext;
	 		s2Current = s2Current->strNext;
		 }
	 }
	 
	 printf("1");
	 return;
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
    String strCurrent = str;

    // Check if the end of the String
    while(strCurrent != NULL )
    {
        nCtr++; // Increment String length 
        strCurrent = strCurrent->strNext; // Change struct string to be checked later

    }
	
    return nCtr;
}
