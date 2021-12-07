#include <stdio.h>

int main (void)
{
    String s1, s2;
    s1 = create();
    s2 = create();

    add (s1, ‘H’);
    add (s1, ‘e’);
    add (s1, ‘l’);
    add (s1, ‘l’);
    add (s1, ‘o’);

    add (s2, ‘H’);
    add (s2, ‘e’);
    add (s2, ‘l’);
    add (s2, ‘l’);
    add (s2, ‘o’);
    add (s2, ‘ ’);
    add (s2, ‘W’);
    add (s2, ‘o’);
    add (s2, ‘r’);
    add (s2, ‘l’);
    add (s2, ‘d’);

    print (s1);   // this statement will display (Hello)
    add (s2, !);
    print (s2); // this statement will display (Hello World!)
    print (insert(s2, 11,s)); // this statement will return (Hello Worlds!)
    print (delete(s2, 11)); // this statement will return (Hello World)
    print (substitute(s2, ‘World’, ‘CCPROG’)); // this statement will return (Hello CCPROG!)
    print (compare(s1, s2)); // this statement will return (0)
    print (getLength(s1))// this statement will return (5)

    return 0;
}
