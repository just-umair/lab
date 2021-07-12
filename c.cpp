// Question 1

// #include <stdio.h>
// #include <iostream>
// #include <unistd.h>
// using namespace std;
// int main()
// {
    
// int a,b;
// a = fork(),b= fork();
// if (a > 0 && b > 0)
// {
// cout << "-> I am parent" << endl << "First Child: "<< a << " Second Child: "<< b <<endl;
// cout<< "My ID is "<< getpid() << endl << endl;
// }
// else if (a == 0 && b > 0)
// {
// cout << "-> I am first Child" << endl << "First Child: "<< a << " Second Child: " << b<< endl;
// cout << "My ID is" << getpid() << endl << endl;
// }
// else if (a > 0 && b == 0)
// {
// cout << "-> I am second Child " << endl << "First Child: "<< a << " Second Child: " << b << endl;
// cout << "My ID is " << getpid() << endl << endl;
// }
// else
// {
// cout << "-> I am third Child" << endl << "First Child: " << a << " Second Child: " << b << endl;
// cout << "My ID is " << getpid();
// }
// return 0;
// }





// Question 2

// (A) execl → This takes the executable file PATH as first two arguments and then the other arguments with “NULL” as the last terminating argument.

// File.cpp
// #include <stdio.h>
// #include <iostream>
// #include <unistd.h>
// using namespace std;
// int main()
// {
// cout << "This is file1, calling file2 now" << endl << endl;
// execl("./file2", "./file2", (char*)NULL);
// cout << "This will not be printed";
// return 0;
// }

// File2.cpp
// #include <iostream>
// #include <unistd.h>
// #include <stdio.h>
// using namespace std;
// int main()
// {

// cout << "This is ./file2" << endl << endl;
// return 0;
// }








// (B) execlp → This does NOT takes the executable file path as first two arguments but instead simply the name of the file is enough an dthe compiler will find the file itself. Rest of the arguments are then given with “NULL” as the last terminating argument.

// File.cpp
// #include <stdio.h>
// #include <iostream>
// #include <unistd.h>
// using namespace std;
// int main()
// {
// cout << "This is file1, calling file2 now" << endl << endl;
// execlp("./file2", "./file2", (char*)NULL);
// cout << "This will not be printed";
// return 0;
// }

// File2.cpp
// #include <iostream>
// #include <unistd.h>
// #include <stdio.h>
// using namespace std;
// int main()
// {

// cout << "This is ./file2" << endl << endl;
// return 0;
// }










// ( C) execv → This requires a complete PATH as first argument and also an array which contains the path and the other arguments with NULL as terminating argument

// #include <stdio.h>
// #include <iostream>
// #include <unistd.h>
// using namespace std;
// int main()
// {
// char *p="/bin/ls";
// char *arg[]={p,NULL};
// execv(p, arg);
// cout << "This will not be printed";
// return 0;
// }



// (D) execvp → This does NOT requires a complete path as first argument but instead simply the name. Also an array which contains the path and the other arguments with NULL as terminating argument is provided.

// #include <stdio.h>
// #include <iostream>
// #include <unistd.h>
// using namespace std;
// int main()
// {
// char *p="ls"; // Complete path is not given.
// char *arg[]={p,NULL};
// execvp(p, arg);
// cout << "This will not be printed";
// return 0;
// }
 



// Question 3

// Example.cpp

// #include <stdio.h>
// #include <iostream>
// #include <unistd.h>
// using namespace std;
// int main()
// {
// cout << "We are in Example" << endl << "PID of Example: " << getpid() << endl << endl;
// execl("./Hello", "./Hello", (char*)NULL);
// return 0;
// }

// Hello.cpp

// #include <iostream>
// #include <unistd.h>
// #include <stdio.h>
// using namespace std;
// int main()
// {
// cout << "We are in Hello" << endl << "PID of Hello: " << getpid() << endl;
// return 0;
// }


