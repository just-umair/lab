// Question 1

// #include <iostream>
// #include <unistd.h>
// #include <stdio.h>
// #define WRITE 1
// #define READ 0
// using namespace std;
// int main()
// {
// int pid1;
// int fd1[2], fd2[2], fd3[2], fd4[2];
// int arr1[2], arr2[2], arr3[2], arr4[2];   
// int num;  
// pipe(fd1);
// pipe(fd2);
// pipe(fd3);
// pipe(fd4);
// pid1 = fork();

// if (pid1 > 0) // Parent Process
// {
// int pid2 = fork();
// if (pid2 > 0) // Parent Process (2)
// {
// close(fd1[READ]);  
// cout << "Enter Numbers for Addition and Subtraction: ";
// cin >> arr1[0];
// cin >> arr1[1];
// write (fd1[WRITE], &arr1, sizeof(arr1));
// close(fd1[WRITE]);
// }
// else // 2nd Child
// {
// close (fd1[WRITE]);
// read (fd1[READ], &arr1, sizeof(arr1));
// arr3[0] = arr1[0] + arr1[1];
// arr3[1] = arr1[0] - arr1[1];
// close (fd1[READ]);
// close (fd3[READ]);
// write (fd3[WRITE], &arr3, sizeof(arr3));
// close (fd3[WRITE]);
// exit(1);
// }
// close (fd2[READ]);
// cout << "Enter Numbers for Multiplication and Division: ";
// cin >> arr2[0];
// cin >> arr2[1];
// write (fd2[WRITE], &arr2, sizeof(arr2));
// close(fd2[WRITE]);
// }
// else // 1st Child
// {
// int pid3 = fork();
// if (pid3 > 0) // 1st Child (2)
// {
// close (fd2[WRITE]);
// read(fd2[READ], &arr2, sizeof(arr2));
// arr4[0] = arr2[0] * arr2[1];
// arr4[1] = arr2[0] / arr2[1];
// close (fd2[READ]);
// close (fd4[READ]);
// write (fd4[WRITE], &arr4, sizeof(arr4));
// exit(1);
// }
// else  // 3rd Child
// {
// close (fd3[WRITE]);
// close (fd4[WRITE]);
// read (fd3[READ], &arr3, sizeof(arr3));
// read (fd4[READ], &arr4, sizeof(arr4));
// close (fd3[READ]);
// close (fd4[READ]);

// cout << endl << endl;
// cout << "Sum = " << arr3[0] << endl << "Difference = " << arr3[1] << endl;
// cout << "Product = " << arr4[0] << endl << "Division = " << arr4[1] << endl;
// exit(1);
// }
// }
// return 0;

// }











// Question 2

//  #include <iostream>
// #include <unistd.h>
// #include <stdio.h>
// #define WRITE 1
// #define READ 0
// using namespace std;
// int main()
// {
// int pid;
// int fd[2];
// char buffer[15];
// pipe(fd);
// pid = fork();

// if (pid > 0) // Parent Process
// {
// cout << "I am Parent. I have sent message to the child." << endl;
// close(fd[READ]);  
// write (fd[WRITE], "Hello World", 16);
// close(fd[WRITE]);

// }
// else
// {
// cout << "I am Child. I have received message from Parent: ";
// close (fd[WRITE]);
// read(fd[READ], buffer, 15);
// cout << buffer << endl;
// close (fd[READ]);
// }
// return 0;
// }



// Question 3

// Program_1.cpp

// #include <iostream>
// #include <sys/stat.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <fcntl.h>
// using namespace std;
// int main()
// {
// int fd;
// int ret;
// char arr[100];
// char buffer[100];
// int i = 0;
// mkfifo("/tmp/myfifo", 0666);
// while(i<5) // loop will run for 5 times, then program will terminate
// {

// cout << "Write a Message: ";
// cin.getline(arr, 100);
// fd = open("/tmp/myfifo", O_WRONLY); // To write
// write(fd, arr, sizeof(arr));
// close(fd);
// ret = open("/tmp/myfifo", O_RDONLY); // To Read
// read(fd, buffer, 100);
// cout << "Program 2 says: ";
// cout << arr;
// cout << endl;
// close(ret);
// i++;
// }

// return 0;
// }

// Program_2.cpp

// #include <iostream>
// #include <sys/stat.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <fcntl.h>
// using namespace std;
// int main()
// {
// int fd;
// int ret;
// char arr[100];
// char buffer[100];
// int i = 0;
// mkfifo("/tmp/myfifo", 0666);
// while(i<5) // loop will run for 5 times, then program will terminate
// {

// ret = open("/tmp/myfifo", O_RDONLY); // To Read
// read(fd, buffer, 100);
// cout << arr;
// cout << endl;
// close(ret);
// cout << "Write a Message: ";
// cin.getline(arr, 100);
// fd = open("/tmp/myfifo", O_WRONLY); // To write

// write(fd, arr, sizeof(arr));
// close(fd);
// i++;
// }

// return 0;
// }

// Question 3

// File 2

// #include <stdio.h> 
// #include <string>
// #include <iostream> 
// #include <fcntl.h> 
// #include <sys/stat.h> 
// #include <sys/types.h> 
// #include <unistd.h> 
// using namespace std; 
// int main() 
// { 
//     int fd; 
  
//     // FIFO file path 
//     char myfifo[] = "/tmp/myfifo"; 
  
//     // Creating the named file(FIFO) 
//     // mkfifo(<pathname>, <permission>) 
//     mkfifo(myfifo, 0666); 
  
//     char arr1[80], arr2[80]; 
//     while (1) 
//     { 
//         // Open FIFO for write only 
//         fd = open(myfifo, O_WRONLY); 
  
//         // Take an input arr2ing from user. 
//         // 80 is maximum length 
// fflush(stdin); 
//         cin.getline(arr2, 80); 
  
//         // Write the input arr2ing on FIFO 
//         // and close it 
//         write(fd, arr2, 81); 
//         close(fd); 
  
//         // Open FIFO for Read only 
//         fd = open(myfifo, O_RDONLY); 
  
//         // Read from FIFO 
//         read(fd, arr1, sizeof(arr1)); 
  
//         // Print the read message 
//         cout << arr1 << endl; 
//         close(fd); 
//     } 
//     return 0; 
// }


// FILE1 

// #include <stdio.h> 
// #include <string> 
// #include <fcntl.h>
// #include <iostream> 
// #include <sys/stat.h> 
// #include <sys/types.h> 
// #include <unistd.h> 
// using namespace std; 
// int main() 
// { 
//     int fd1; 
  
//     // FIFO file path 
//     char myfifo[] = "/tmp/myfifo"; 
  
//     // Creating the named file(FIFO) 
//     // mkfifo(<pathname>,<permission>) 
//     mkfifo(myfifo, 0666); 
  
//     char str1[80], str2[80]; 
//     while (1) 
//     { 
//         // First open in read only and read 
//         fd1 = open(myfifo,O_RDONLY); 
//         read(fd1, str1, 80); 
  
//         // Print the read string and close 
//         cout << str1 << endl; 
//         close(fd1); 
  
//         // Now open in write mode and write 
//         // string taken from user. 
// fflush(stdin); 
//         fd1 = open(myfifo,O_WRONLY); 
//         cin.getline(str2, 80); 
//         write(fd1, str2, 81); 
//         close(fd1); 
//     } 
//     return 0; 
// }

