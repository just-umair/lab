// Question 1

// #include <iostream>
// #include <pthread.h>
// #include <string>
// #include <unistd.h>
// using namespace std;

// string message;
// pthread_cond_t c = PTHREAD_COND_INITIALIZER;
// pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
// int done = 0;

// void *send_message(void *arg) {
//   pthread_mutex_lock(&m);
//   message = "Hello There!";
//   cout << "Message Sent to Receiver: " << message << endl;
//   done = 1;
//   pthread_cond_signal(&c);
//   pthread_mutex_unlock(&m);
//   pthread_exit(NULL);
// }
// void *receive_message(void *arg) {
//   pthread_mutex_lock(&m);
//   while (done == 0)
//     pthread_cond_wait(&c, &m);
//   cout << "Message Recieved from Sender: " << message << endl;
//   pthread_mutex_unlock(&m);
//   pthread_exit(NULL);
// }

// int main() {
//   pthread_t sender, receiver;

//   pthread_create(&sender, NULL, send_message, NULL);
//   pthread_create(&receiver, NULL, receive_message, NULL);

//   pthread_join(sender, NULL);
//   pthread_join(receiver, NULL);

//   return 0;
// }



// Question 2

// #include <iostream>
// #include <pthread.h>
// #include <string>
// #include <unistd.h>
// using namespace std;

// pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
// int bank_balance = 100;

// void *deposit_amount(void *arg) {

//   int deposited_amount = *(int *)arg;
//   pthread_mutex_lock(&m);
//   int old_balance = bank_balance;
//   int new_balance = old_balance + deposited_amount;
//   bank_balance = new_balance;
//   pthread_mutex_unlock(&m);
//   pthread_exit(NULL);
// }

// int main() {
//   pthread_t brother, dad, cousin;
//   int bro, d, co;
//   cout << "Enter amount deposited by Dad: ";
//   cin >> d;
//   cout << "Enter amount deposited by Brother: ";
//   cin >> bro;
//   cout << "Enter amount deposited by Cousin: ";
//   cin >> co;
//   pthread_create(&dad, NULL, deposit_amount, &d);
//   pthread_create(&brother, NULL, deposit_amount, &bro);
//   pthread_create(&cousin, NULL, deposit_amount, &co);

//   pthread_join(dad, NULL);
//   pthread_join(brother, NULL);
//   pthread_join(cousin, NULL);
//   cout << endl << "Final Balance: " << bank_balance << endl;
//   return 0;
// }








// Question 3

// #include <iostream>
// #include <pthread.h>
// #include <semaphore.h>
// #include <string>
// #include <unistd.h>
// using namespace std;

// sem_t s;
// void *fun(void *arg) {
//   sem_wait(&s); // Late arriving thread will wait here.
//   cout << "\nThread has Entered" << endl;
//   sleep(4); // Putting on sleep for 4 seconds.
//   cout << "Thread is exiting" << endl;
//   sem_post(&s);
// }
// int main() {

//   sem_init(&s, 0, 1);
//   pthread_t t1, t2;
//   pthread_create(&t1, NULL, fun, NULL);
//   pthread_create(&t2, NULL, fun, NULL);
//   pthread_join(t1, NULL);
//   pthread_join(t2, NULL);
//   sem_destroy(&s);
//   return 0;
// }


