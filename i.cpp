// Code Implementation 
// Round Robin Algorithm 

// #include <iostream>
// #include <queue>
// #include <iomanip>
// using namespace std;

// class Process
// {
// 	friend void Calculate();
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
// 	int get_t() { return turnaround_time; }
// 	int get_w() { return waiting_time; }
// 	int getid() { return id; }
// 	void Display();
// 	void Display_Before();
// };
// int Process::count = 1;
// void Process::Display()
// {
// 	cout << setw(15) << id << setw(15) << arrival_time << setw(15) << turnaround_time << setw(15) << waiting_time;
// 	cout << endl;
// }
// void Process::Display_Before()
// {
// 	cout << setw(15) << id << setw(15) << arrival_time << setw(15) << burst_time << endl;
// }
// int time_slice;
// void Calculate();
// queue<Process*> Queue;
// Process *obj;
// int main()
// {
// 	cout << endl << left << setw(30) << " " << "ROUND ROBIN ALGORITHM" << endl << endl;
// 	int num;
// 	do
// 	{
// 		cout << "Enter Number of Processes: ";
// 		cin >> num;
// 	} while (num < 1);
// 	obj = new Process[num];
// 	for (int i = 0; i < num; i++)
// 		obj[i].input();
// 	for (int i = 0; i < num; i++)
// 		Queue.push(&obj[i]);
// 	cout << "Enter Time Slice for Round Robin: "; cin >> time_slice;
// 	// Printing Before Calculation

// 	cout << endl << endl << setw(15) << "Process ID" << setw(15) << "Arrival Time" << setw(15) << "Burst Time" << endl
// 		<< "------------------------------------------------------------------" << endl;
// 	for (int i = 0; i < num; i++)
// 		obj[i].Display_Before();

// 	Calculate();

// 	// Printing After Calculation
// 	cout << endl << endl << setw(15) << "Process ID" << setw(15) << "Arrival Time" << setw(15) << "Turnaround" << setw(15) << "Waiting Time" << endl
// 		<< "------------------------------------------------------------------" << endl;
// 	for (int i = 1; i < num; ++i)
// 	{
// 		for (int j = 0; j < num - i; ++j)
// 			if (obj[j].getid() > obj[j + 1].getid())
// 				swap(obj[j], obj[j + 1]);
// 	}
// 	for (int i = 0; i < num; i++)
// 		obj[i].Display();
// 	cout << endl << endl; 
// 	float avg_turnaround = 0, avg_waiting = 0;
// 	for (int i = 0; i < num; i++)
// 	{
// 		avg_turnaround += obj[i].get_t();
// 		avg_waiting += obj[i].get_w();
// 	}
// 	cout << "Average Turnaround Time: " << avg_turnaround / num << endl
// 		<< "Average Waiting Time: " << avg_waiting / num << endl;

// 	cout << endl;
// 	return 0;
// }
// void Calculate()
// {
// 	int total_time = 0;
// 	while (!Queue.empty())
// 	{
// 		Process *temp;
// 		temp = Queue.front();
// 		Queue.pop();
// 		if (temp->arrival_time > total_time)
// 			Queue.push(temp);
// 		else
// 		{
// 			if (temp->burst_time <= time_slice)
// 			{
// 				total_time = total_time + temp->burst_time;
// 				obj[temp->id - 1].completion_time = total_time;
// 				obj[temp->id - 1].turnaround_time = temp->completion_time - temp->arrival_time;
// 				obj[temp->id - 1].waiting_time = temp->turnaround_time - temp->burst_time;
// 			}
// 			else
// 			{
// 				total_time = total_time + time_slice;
// 				temp->burst_time = temp->burst_time - time_slice;
// 				Queue.push(temp);
// 			}
// 		}
// 	}
// }

// Non-Preemptive Priority Scheduling Algorithm 
// #include <iostream>
// #include <queue>
// #include <iomanip>
// using namespace std;

// class Process
// {
// 	friend void Calculate(Process *, int);
// 	friend void Bubble_Sort_Burst(Process *, int);
// 	friend void Bubble_Sort_Priority(Process *, int);
// 	int id;
// 	static int count;
// 	int burst_time;
// 	int arrival_time;
// 	int completion_time;
// 	int turnaround_time;
// 	int waiting_time;
// 	int priority; 
// public:
// 	Process() :id(count) { completion_time = turnaround_time = waiting_time = 0; count++; arrival_time = 0; }
// 	void input()
// 	{
// 		cout << "Process: " << id << endl;
// 		cout << "Enter Burst Time: "; cin >> burst_time;
// 		cout << "Enter Priority: "; cin >> priority; 
// 	}
// 	int getid() { return id; }
// 	int get_t() { return turnaround_time; }
// 	int get_w() { return waiting_time; }
// 	void Display();
// 	void Display_Before();
// };
// int Process::count = 1;
// void Process::Display()
// {
// 	cout << setw(15) << id << setw(15) << priority << setw(15) << burst_time << setw(15) << turnaround_time << setw(15) << waiting_time;
// 	cout << endl;
// }
// void Process::Display_Before()
// {
// 	cout << setw(15) << id << setw(15) << priority << setw(15) << burst_time << endl;
// }
// void Bubble_Sort_Burst(Process *, int);
// void Bubble_Sort_Priority(Process *, int);
// void Calculate(Process *, int);
// int main()
// {
// 	cout << endl << left << setw(30) << " " << "NON-PREEMPTIVE PRIORITY SCHEDULING ALGORITHM" << endl << endl; 
// 	int num;
// 	do
// 	{
// 		cout << "Enter Number of Processes: ";
// 		cin >> num;
// 	} while (num < 1);
// 	cout << "-----Higher Number means Higher Priority-----" << endl << endl; 
// 	Process *obj = new Process[num];
// 	for (int i = 0; i < num; i++)
// 		obj[i].input();
// 	// Printing Before Calculation

// 	cout << endl << endl << setw(15) << "Process ID" << setw(15) << "Priority" << setw(15) << "Burst Time" << endl
// 		<< "------------------------------------------------------------------" << endl;
// 	for (int i = 0; i < num; i++)
// 		obj[i].Display_Before();

// 	Bubble_Sort_Burst(obj, num); 
// 	Bubble_Sort_Priority(obj, num); 
// 	Calculate(obj, num);

// 	// Printing After Calculation
// 	cout << endl << endl << setw(15) << "Process ID" << setw(15) << "Priority" << setw(15) << "Burst Time"
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
// 	cout << endl; 
// 	float avg_turnaround = 0, avg_waiting = 0;
// 	for (int i = 0; i < num; i++)
// 	{
// 		avg_turnaround += obj[i].get_t();
// 		avg_waiting += obj[i].get_w(); 
// 	}
// 	cout << "Average Turnaround Time: " << avg_turnaround / num << endl
// 		<< "Average Waiting Time: " << avg_waiting / num << endl; 
// 	return 0;
// }
// void Bubble_Sort_Burst(Process *arr, int n)
// {
// 	int j;
// 	for (int i = 1; i < n; ++i)
// 	{
// 		for (j = 0; j < n - i; ++j)
// 			if (arr[j].burst_time > arr[j + 1].burst_time)
// 				swap(arr[j], arr[j + 1]);
// 	}
// }
// void Bubble_Sort_Priority(Process *arr, int n)
// {
// 	int j;
// 	for (int i = 1; i < n; ++i)
// 	{
// 		for (j = 0; j < n - i; ++j)
// 			if (arr[j].priority < arr[j + 1].priority)
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



// Preemptive Priority Scheduling Algorithm 
// #include <iostream>
// #include <queue>
// #include <iomanip>
// using namespace std;

// class Process
// {
// 	friend void Calculate(Process *, int);
// 	friend void Bubble_Sort_Burst(Process *, int);
// 	friend void Bubble_Sort_Priority(Process *, int);
// 	int id;
// 	static int count;
// 	int burst_time;
// 	int arrival_time;
// 	int completion_time;
// 	int turnaround_time;
// 	int waiting_time;
// 	int priority; 
// public:
// 	Process() :id(count) { completion_time = turnaround_time = waiting_time = 0; count++; arrival_time = 0; }
// 	void input()
// 	{
// 		cout << "Process: " << id << endl;
// 		cout << "Enter Burst Time: "; cin >> burst_time;
// 		cout << "Enter Priority: "; cin >> priority; 
// 	}
// 	int getid() { return id; }
// 	int get_t() { return turnaround_time; }
// 	int get_w() { return waiting_time; }
// 	void Display();
// 	void Display_Before();
// };
// int Process::count = 1;
// void Process::Display()
// {
// 	cout << setw(15) << id << setw(15) << priority << setw(15) << burst_time << setw(15) << turnaround_time << setw(15) << waiting_time;
// 	cout << endl;
// }
// void Process::Display_Before()
// {
// 	cout << setw(15) << id << setw(15) << priority << setw(15) << burst_time << endl;
// }
// void Bubble_Sort_Burst(Process *, int);
// void Bubble_Sort_Priority(Process *, int);
// void Calculate(Process *, int);
// int main()
// {
// 	cout << endl << left << setw(30) << " " << "PREEMPTIVE PRIORITY SCHEDULING ALGORITHM" << endl << endl; 
// 	int num;
// 	do
// 	{
// 		cout << "Enter Number of Processes: ";
// 		cin >> num;
// 	} while (num < 1);
// 	cout << "-----Higher Number means Higher Priority-----" << endl << endl; 
// 	Process *obj = new Process[num];
// 	for (int i = 0; i < num; i++)
// 		obj[i].input();
// 	// Printing Before Calculation

// 	cout << endl << endl << setw(15) << "Process ID" << setw(15) << "Priority" << setw(15) << "Burst Time" << endl
// 		<< "------------------------------------------------------------------" << endl;
// 	for (int i = 0; i < num; i++)
// 		obj[i].Display_Before();

// 	Bubble_Sort_Burst(obj, num); 
// 	Bubble_Sort_Priority(obj, num); 
// 	Calculate(obj, num);

// 	// Printing After Calculation
// 	cout << endl << endl << setw(15) << "Process ID" << setw(15) << "Priority" << setw(15) << "Burst Time"
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
// 	cout << endl; 
// 	float avg_turnaround = 0, avg_waiting = 0;
// 	for (int i = 0; i < num; i++)
// 	{
// 		avg_turnaround += obj[i].get_t();
// 		avg_waiting += obj[i].get_w(); 
// 	}
// 	cout << "Average Turnaround Time: " << avg_turnaround / num << endl
// 		<< "Average Waiting Time: " << avg_waiting / num << endl; 
// 	return 0;
// }
// void Bubble_Sort_Burst(Process *arr, int n)
// {
// 	int j;
// 	for (int i = 1; i < n; ++i)
// 	{
// 		for (j = 0; j < n - i; ++j)
// 			if (arr[j].burst_time > arr[j + 1].burst_time)
// 				swap(arr[j], arr[j + 1]);
// 	}
// }
// void Bubble_Sort_Priority(Process *arr, int n)
// {
// 	int j;
// 	for (int i = 1; i < n; ++i)
// 	{
// 		for (j = 0; j < n - i; ++j)
// 			if (arr[j].priority < arr[j + 1].priority)
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




