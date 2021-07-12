// Question 1

// #include <iostream>
// #include <pthread.h>
// using namespace std;

// int var;
// int result;
// void *fun(void *arg)
// {
// pthread_detach(pthread_self());
// var++;
// result = result + var;
// pthread_exit(NULL);
// return NULL;
// }

// int main()
// {
// var = 0;
// result = 0;
// pthread_t p1;
// pthread_create (&p1, NULL, &fun, NULL);
// pthread_join(p1, NULL);
// pthread_create (&p1, NULL, &fun, NULL);
// pthread_join(p1, NULL);
// pthread_create (&p1, NULL, &fun, NULL);
// pthread_join(p1, NULL);

// cout << "Result: " << result << endl << "Var = " << var << endl;
// return 0;

// }



// Question 2

// #include <iostream>
// #include <pthread.h>
// using namespace std;

// int count = 1;
// void *fun(void *arg)
// {
// pthread_detach(pthread_self());
// int *id = (int *) arg;
// cout << "Hello, I am thread " << count++ << ". My ID is " << pthread_self() << endl;
// pthread_exit(NULL);
// return NULL;
// }

// int main()
// {
// int n, i;
// cout << "Enter Number of threads: ";
// cin >> n;
// pthread_t p1[n];
// for (i = 0; i < n; i++)
// {
// pthread_create (&p1[i], NULL, fun, &i);
// }

// for (i = 0; i < n; i++)
// {
// pthread_join(p1[i], NULL);
// }

// return 0;

// }

// Question 3

// #include <iostream>
// #include <pthread.h>
// using namespace std;

// int n1, n2; // Two Variables to be used for mathematical operations.
// void *fun(void *arg)
// {
// pthread_detach(pthread_self());
// cout << "Value of n1: " << n1 << endl;
// cout << "Value of n2: " << n2 << endl;
// pthread_exit(NULL);
// }
// void *add(void *arg)
// {
// pthread_detach(pthread_self());
// cout << "Sum of " << n1 << " and " << n2 << ": " << n1+n2 << endl;
// pthread_exit(NULL);
// }
// void *sub(void *arg)
// {
// pthread_detach(pthread_self());
// cout << "Difference of " << n1 << " and " << n2 << ": " << n1-n2 << endl;
// pthread_exit(NULL);
// }
// void *product(void *arg)
// {
// pthread_detach(pthread_self());
// cout << "Product of " << n1 << " and " << n2 << ": " << n1*n2 << endl;
// pthread_exit(NULL);
// }
// void *divide(void *arg)
// {
// pthread_detach(pthread_self());
// cout << "Division of " << n1 << " by " << n2 << ": " << n1/n2 << endl;
// pthread_exit(NULL);
// }
// int main()
// {

// cout << "Enter value of n1: ";
// cin >> n1;
// cout << "Enter value of n2: ";
// cin >> n2;
// pthread_t p1[4];
// pthread_create(&p1[0], NULL, add, NULL);
// pthread_join(p1[0], NULL);
// pthread_create(&p1[1], NULL, sub, NULL);
// pthread_join(p1[1], NULL);
// pthread_create(&p1[2], NULL, product, NULL);
// pthread_join(p1[2], NULL);
// pthread_create(&p1[3], NULL, divide, NULL);
// pthread_join(p1[3], NULL);


// return 0;

// }











// Question 4

// #include <iostream>
// #include <unistd.h>
// #include <pthread.h>
// using namespace std;

// void *fun(void *arg)
// {
// pthread_detach(pthread_self());
// cout << "Thread ID is " << pthread_self() << ". Process ID is " << getpid() << endl;
// pthread_exit(NULL);
// }

// int main()
// {
// pthread_t p1[4];
// for (int i = 0; i < 4; i++)
// pthread_create(&p1[i], NULL, fun, NULL);
// for (int i = 0; i < 4; i++)
// pthread_join(p1[i], NULL);


// cout << endl << "All thread ids are different, since they are created differently" << endl
// << "However, Process ID remains the same since it is only the one process.. All threads are part of this one process" << endl;

// return 0;

// }



