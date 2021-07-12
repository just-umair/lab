// Question 1 - Monitors
// #include <ctime>
// #include <iostream>
// #include <pthread.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <unistd.h>

// using namespace std;

// // Declaring Functions..
// void *coffee_person_function(void *);
// void *milk_person_function(void *);
// void *water_person_function(void *);
// void *agent_function(void *);
// class Coffee
// {
// public:
// 	pthread_mutex_t mut;       // Mutex variable declaration
// 	pthread_cond_t cond[3];    // Condition variables declaration
// 	pthread_cond_t agent_cond; // Agent Function condition variable
// 	bool check; // Bool variable to avoid spurious wake up call of functions..
// 	Coffee();
// 	void coffee_person()
// 	{
// 		while (check == 0) // To avoid spurious wake up call. 
// 			pthread_cond_wait(&cond[0], &mut); // will wait until signal received. 
// 		cout << "Agent has selected Milk and Water." << endl;
// 		cout << "Person with infinite Coffee is drinking coffee." << endl;
// 		check = 0;
// 		pthread_cond_signal(&agent_cond); // will send signal to the agent function. 
// 	}

// 	void milk_person()
// 	{
// 		while (check == 0)
// 			pthread_cond_wait(&cond[1], &mut); // will wait until signal received
// 		cout << "Agent has selected Coffee and Water." << endl;
// 		cout << "Person with infinite Milk is drinking coffee." << endl;
// 		check = 0;
// 		pthread_cond_signal(&agent_cond); // will send signal to the agent function. 
// 	}

// 	void water_person()
// 	{
// 		while (check == 0)
// 			pthread_cond_wait(&cond[2], &mut); // will wait until signal received
// 		cout << "Agent has selected Milk and Coffee." << endl;
// 		cout << "Person with infinite Water is drinking coffee." << endl;
// 		check = 0;
// 		pthread_cond_signal(&agent_cond); // will send signal to the agent function
// 	}
// };
// Coffee obj; // A global variable of class obj. 
// int main() {

// 	pthread_t thread[4];

// 	void *(*pf[4])(void *); // Declaring Function pointers and assigning them functions. 

// 	pf[0] = &agent_function;
// 	pf[1] = &coffee_person_function;
// 	pf[2] = &milk_person_function;
// 	pf[3] = &water_person_function;

// 	for (int i = 0; i < 4; i++)
// 		pthread_create(&thread[i], NULL, pf[i], NULL);

// 	for (int i = 0; i < 4; i++)
// 		pthread_join(thread[i], NULL);

// 	return 0;
// }
// Coffee::Coffee() // Constructor of Class
// {
// 	check = 0;
// 	pthread_mutex_init(&mut, NULL);
// 	pthread_cond_init(&cond[0], NULL);
// 	pthread_cond_init(&cond[1], NULL);
// 	pthread_cond_init(&cond[2], NULL);
// 	pthread_cond_init(&agent_cond, NULL);
// }
// void *coffee_person_function(void *arg) {
// 	while (1) {
// 		obj.coffee_person();
// 	}
// }

// void *milk_person_function(void *arg) {
// 	while (1) {
// 		obj.milk_person();
// 	}
// }

// void *water_person_function(void *arg) {
// 	while (1) {
// 		obj.water_person();
// 	}
// }

// void *agent_function(void *arg) { // Agent Function

// 	while (1) {
// 		obj.check = 1;
// 		int t = rand() % 3; // random value from 0-2 (for functions) 
// 		pthread_cond_signal(&obj.cond[t]); // will send signal to one of the three functions
// 		sleep(2);
// 		cout << endl;
// 		while (obj.check == 1) // to avoid spurious wake up call 
// 			pthread_cond_wait(&obj.agent_cond, &obj.mut); // will wait until signal received
// 	}
// }


//  
// Question 2 – Banker’s Algorithm
// #include<iostream>
// #include<stdlib.h>
// #include <ctime>
// #include <iomanip>
// #include <cstdlib>
// using namespace std;
// void banker_algorithm(int **, int **, int *);
// int m, n;
// int main()
// {
// 	srand(time(0));
// 	m = n = 3;
// 	int *resources = new int[m]; // Overall Resources
// 	for (int i = 0; i < m; i++)
// 		resources[i] = 10; // Allocating 10 to all resources. 

// 	int *available = new int[m]; // Resources available 
// 	int **resources_required = new int*[n];  // Maximum resources required by all processes
// 	for (int i = 0; i < n; i++)
// 	{
// 		resources_required[i] = new int[m];
// 		for (int j = 0; j < m; j++)
// 			resources_required[i][j] = rand() % 5 + 1; // Using rand function.. 
// 	}
// 	int **resources_allocated = new int*[n]; // Resources already allocated to each process
// 	for (int i = 0; i < n; i++)
// 	{
// 		resources_allocated[i] = new int[m];
// 		for (int j = 0; j < m; j++)
// 			resources_allocated[i][j] = rand() % 3;
// 	}
// 	int **resources_needed = new int*[n]; // Remaining resources required by the process
// 	for (int i = 0; i < n; i++)
// 		resources_needed[i] = new int[m];
// 	int sum;
// 	for (int i = 0; i < m; i++)
// 	{
// 		sum = 0;
// 		for (int j = 0; j < n; j++)
// 			sum = sum + resources_allocated[j][i];
// 		available[i] = resources[i] - sum; // Calculating Remaining Resources available 
// 	}

// 	for (int i = 0; i < n; i++)
// 		for (int j = 0; j < m; j++)
// 		{
// 			resources_needed[i][j] = resources_required[i][j] - resources_allocated[i][j]; // Resources needed by one process
// 			if (resources_needed[i][j] < 0)
// 				resources_needed[i][j] = 0;
// 		}
// 	// Printing all the arrays... 
// 	cout << left << setw(20) << "Overall Resources Available: " << endl
// 		<< left << setw(15) << " " << setw(5) << "A" << setw(5) << "B" << setw(5) << "C" << endl;
// 	cout << left << setw(15) << " ";
// 	for (int j = 0; j < m; j++)
// 		cout << setw(5) << resources[j];
// 	cout << endl << endl;

// 	// Max
// 	cout << left << setw(20) << "Total Resources Required: " << endl
// 		<< left << setw(15) << " " << setw(5) << "A" << setw(5) << "B" << setw(5) << "C" << endl;
// 	for (int i = 0; i < n; i++)
// 	{
// 		cout << left << setw(10) << " " << i + 1 << setw(4) << "";
// 		for (int j = 0; j < m; j++)
// 			cout << setw(5) << resources_required[i][j];
// 		cout << endl;
// 	}
// 	cout << endl << endl;

// 	// Allocation
// 	cout << left << setw(20) << "Total Resources Allocated: " << endl
// 		<< left << setw(15) << " " << setw(5) << "A" << setw(5) << "B" << setw(5) << "C" << endl;
// 	for (int i = 0; i < n; i++)
// 	{
// 		cout << left << setw(10) << " " << i + 1 << setw(4) << "";
// 		for (int j = 0; j < m; j++)
// 			cout << setw(5) << resources_allocated[i][j];
// 		cout << endl;
// 	}
// 	cout << endl << endl;
// 	cout << left << setw(20) << "Total Resources Needed: " << endl
// 		<< left << setw(15) << " " << setw(5) << "A" << setw(5) << "B" << setw(5) << "C" << endl;
// 	for (int i = 0; i < n; i++)
// 	{
// 		cout << left << setw(10) << " " << i + 1 << setw(4) << "";
// 		for (int j = 0; j < m; j++)
// 			cout << setw(5) << resources_needed[i][j];
// 		cout << endl;
// 	}
// 	cout << endl << endl;

// 	cout << left << setw(20) << "Total Resources Available: " << endl
// 		<< left << setw(15) << " " << setw(5) << "A" << setw(5) << "B" << setw(5) << "C" << endl;
// 	cout << left << setw(15) << " ";
// 	for (int j = 0; j < m; j++)
// 		cout << setw(5) << available[j];
// 	cout << endl << endl;
// 	banker_algorithm(resources_needed, resources_allocated, available);
// 	return 0;
// }

// void banker_algorithm(int **resources_needed, int **resources_allocated, int *resources_available)
// {
// 	cout << endl << "Result: ";
// 	int *work = new int[m];
// 	for (int i = 0; i < m; i++)
// 		work[i] = resources_available[i];
// 	bool *has_finished = new bool[n];
// 	for (int i = 0; i < n; i++)
// 		has_finished[i] = false;
// 	int count = 0;
// 	for (int i = 0; i < n; i++)
// 	{
// 		count = 0;
// 		for (int j = 0; j < m; j++)
// 		{
// 			if (resources_needed[i][j] <= work[j] && (has_finished[i] == false))
// 				count++;
// 		}
// 		if (count != 0)
// 		{
// 			for (int j = 0; j < m; j++)
// 				work[j] = work[j] + resources_allocated[i][j];
// 			has_finished[i] = true;
// 		}
// 	}
// 	for (int i = 0; i < n; i++)
// 	{
// 		if ((has_finished[i] == false))
// 		{
// 			cout << "Deadlock has been Detected..." << endl << endl;
// 			return;
// 		}
// 	}
// 	cout << "Deadlock has not been detected" << endl << endl;
// 	return;
// }

