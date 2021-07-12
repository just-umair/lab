// Task 1

// #include <iostream>
// #include <unistd.h>
// using namespace std;

// int main()
// {


// int x = 0;
// cout << "Enter Number of Childs you want to make: ";
// cin >> x;
// while (x <= 2)
// {
// 	cout << "You must enter a number greater than 2" << endl;
// 	cout << "Enter again: ";
// 	cin >> x;  	
// }
// cout << "Parent ID is: " << getppid() << endl;
// for (int i = 0; i < x; i++)
// {
// 	if (fork()==0)
// 	{
// 		cout << "Child ID is: " << getpid() << endl;
// 	}
// }

// return 0;
// }
// }


// Task 2
// #include <iostream>
// #include <unistd.h>
// using namespace std;
// int sum(int);
// int product(int);
// int main()
// {

// int n, result;
// cout << "Enter a Number: ";
// cin >> n;
// int x = fork();
// cout << "Fork Returned: " << x << endl;
// if (x == 0)
// {
// 	result = sum(n);
// 	cout << "Sum is " << result << endl;
// }
// else
// {
// 	result = product(n);
// 	cout << "Product is " << result << endl;
// }

// return 0;
// }

// int sum(int n)
// {
// int result = 0;
// for (int i = 1; i <= n; i++)
// {
// result = result+i;
// }
// return result;
// }

// int product(int n)
// {
// int result = 1;
// for (int i = 1; i <= n; i++)
// {
// result = result*i;
// }
// return result;
// }


// Task 3

// #include <iostream>
// #include <unistd.h>
// using namespace std;

// int main()
// {

// int count = 0;
// int n;
// cout << "Enter Number of Fork Calls: ";
// cin >> n;
// for (int i = 0; i < n; i++)
// {
// int p = fork();

// if (p == 0)
// {
// cout << "Child Process Count: " << ++count << endl;
// }
// else if (p > 0)
// {
// cout << "Parent Process Count: " << ++count << endl;
// }

// }

// return 0;
// }



