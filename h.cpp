// #include <iostream>
// #include <iomanip>
// using namespace std;

// class Process
// {
// 	friend void Bubble_Sort(Process *, int);
// 	friend void Calculate(Process *, int);
// 	int id;
// 	static int count;
// 	int burst_time;
// 	int arrival_time;
// 	int completion_time;
// 	int turnaround_time;
// 	int waiting_time;
// public:
// 	Process() :id(count) { completion_time = turnaround_time = waiting_time = 0; count++; }
// 	void input()
// 	{
// 		cout << "Process: " << id << endl
// 			<< "Enter Arrival Time: "; cin >> arrival_time;
// 		cout << "Enter Burst Time: "; cin >> burst_time;
// 	}
// 	int getid() { return id;  }
// 	void Display();
// 	void Display_Before();
// };
// int Process::count = 1;
// void Process::Display()
// {
// 	cout << setw(15) << id << setw(15) << arrival_time << setw(15) << burst_time << setw(15) << turnaround_time << setw(15) << waiting_time;
// 	cout << endl;
// }
// void Process::Display_Before()
// {
// 	cout << setw(15) << id << setw(15) << arrival_time << setw(15) << burst_time << endl;
// }
// void Calculate(Process *, int);
// void Bubble_Sort(Process *, int);
// int main()
// {
// 	cout << endl << left << setw(30) << " " << "FIRST COME FIRST SERVE ALGORITHM" << endl << endl;
// 	Process *obj;
// 	int num;
// 	do
// 	{
// 		cout << "Enter Number of Processes: ";
// 		cin >> num;
// 	} while (num < 1);
// 	obj = new Process[num];
// 	for (int i = 0; i < num; i++)
// 		obj[i].input();
// 	// Printing Before Calculation

// 	cout << endl << endl << setw(15) << "Process ID" << setw(15) << "Arrival Time" << setw(15) << "Burst Time" << endl
// 		<< "------------------------------------------------------------------" << endl;
// 	for (int i = 0; i < num; i++)
// 		obj[i].Display_Before();

// 	Bubble_Sort(obj, num);
// 	Calculate(obj, num);

// 	// Printing After Calculation
// 	cout << endl << endl << setw(15) << "Process ID" << setw(15) << "Arrival Time" << setw(15) << "Burst Time"
// 		<< setw(15) << "Turnaround" << setw(15) << "Waiting Time" << endl
// 		<< "------------------------------------------------------------------" << endl;
// 	for (int i = 1; i < num; ++i)
// 	{
// 		for (int j = 0; j < num - i; ++j)
// 			if (obj[j].getid() > obj[j + 1].getid())
// 				swap(obj[j], obj[j + 1]);
// 	}
// 	for (int i = 0; i < num; i++)
// 		obj[i].Display();
// 	cout << endl;
// }
// void Bubble_Sort(Process *arr, int n)
// {
// 	int j;
// 	for (int i = 1; i < n; ++i)
// 	{
// 		for (j = 0; j < n - i; ++j)
// 			if (arr[j].arrival_time > arr[j + 1].arrival_time)
// 				swap(arr[j], arr[j + 1]);
// 	}
// }
// void Calculate(Process *obj, int size)
// {
// 	int total_time = 0;
// 	for (int i = 0; i < size; i++)
// 	{
// 		obj[i].completion_time = total_time + obj[i].burst_time;
// 		total_time += obj[i].burst_time;
// 		obj[i].turnaround_time = obj[i].completion_time - obj[i].arrival_time;
// 		obj[i].waiting_time = obj[i].turnaround_time - obj[i].burst_time;
// 	}
// }
// First Example Output:



// Another Example: 



//  
// SJF Algorithm Code Implementation 
// #include <iostream>
// #include <iomanip>
// using namespace std;

// class Process
// {
// 	friend void Bubble_Sort(Process *, int);
// 	friend void Calculate(Process *, int);
// 	int id; 
// 	static int count; 
// 	int burst_time; 
// 	int arrival_time; 
// 	int completion_time; 
// 	int turnaround_time; 
// 	int waiting_time; 
// public:
// 	Process() :id(count) { completion_time = turnaround_time = waiting_time = 0; count++; }
// 	void input()
// 	{
// 		cout << "Process: " << id << endl
// 			<< "Enter Arrival Time: "; cin >> arrival_time;
// 		cout << "Enter Burst Time: "; cin >> burst_time; 
// 	}
// 	int getid() { return id; }
// 	void Display(); 
// 	void Display_Before(); 
// };
// int Process::count = 1;
// void Process::Display()
// {
// 	cout << setw(15) << id << setw(15) << arrival_time << setw(15) << burst_time << setw(15) << turnaround_time << setw(15) << waiting_time;
// 	cout << endl;
// }
// void Process::Display_Before()
// {
// 	cout << setw(15) << id << setw(15) << arrival_time << setw(15) << burst_time << endl;
// }
// void Calculate(Process *, int); 
// void Bubble_Sort(Process *, int);
// int main()
// {
// 	cout << endl << left << setw(30) << " " << "SHORT JOB FIRST ALGORITHM" << endl << endl; 
// 	Process *obj;
// 	int num; 
// 	do
// 	{
// 		cout << "Enter Number of Processes: ";
// 		cin >> num; 
// 	} while (num < 1); 
// 	obj = new Process[num]; 
// 	for (int i = 0; i < num; i++)
// 		obj[i].input(); 
// 	// Printing Before Calculation

// 	cout << endl << endl << setw(15) << "Process ID" << setw(15) << "Arrival Time" << setw(15) << "Burst Time" << endl
// 		<< "------------------------------------------------------------------" << endl; 
// 	for (int i = 0; i < num; i++)
// 		obj[i].Display_Before(); 

// 	Bubble_Sort(obj, num); 
// 	Calculate(obj, num); 

// 	// Printing After Calculation
// 	cout << endl << endl << setw(15) << "Process ID" << setw(15) << "Arrival Time" << setw(15) << "Burst Time" 
// 		<< setw(15) << "Turnaround" << setw(15) << "Waiting Time" << endl
// 		<< "-----------------------------------------------------------------------" << endl;
// 	for (int i = 1; i < num; ++i)
// 	{
// 		for (int j = 0; j < num - i; ++j)
// 			if (obj[j].getid() > obj[j + 1].getid())
// 				swap(obj[j], obj[j + 1]);
// 	}
// 	for (int i = 0; i < num; i++)
// 		obj[i].Display();
// 	cout << endl;
// 	system("pause");
// }
// void Bubble_Sort(Process *arr, int n)
// {
// 	int j;
// 	for (int i = 1; i < n; ++i)
// 	{
// 		for (j = 0; j < n - i; ++j)
// 			if (arr[j].burst_time > arr[j + 1].burst_time)
// 				swap(arr[j], arr[j + 1]);
// 	}
// }
// void Calculate(Process *obj, int size)
// {
// 	int total_time = 0; 
// 	for (int i = 0; i < size; i++)
// 	{
// 		obj[i].completion_time = total_time + obj[i].burst_time;
// 		total_time += obj[i].burst_time;
// 		obj[i].turnaround_time = obj[i].completion_time - obj[i].arrival_time; 
// 		obj[i].waiting_time = obj[i].turnaround_time - obj[i].burst_time; 
// 	}
// }

