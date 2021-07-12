

// FIFO – Page Replacement Algorithm C++ Implementation 
// #include<iostream>
// #include<iomanip>
// #include<conio.h>
// #include<cstdlib>
// using namespace std;
// const int max = 100;
// class fifo
// {
// private:
// 	int frame[10], mrstr[max];
// 	int f, r, tot, nof, fault;
// public:
// 	fifo()
// 	{
// 		f = r = -1;
// 		fault = 0;
// 	}
// 	void getdata();
// 	void push();
// 	void dis();
// };
// void fifo::getdata()
// {
// 	int i = 0, size_of_array;
// 	cout << "\n\t\tFIFO - Page Replacement Algorithm\n";
// 	cout << "\nEnter frame size: ";
// 	cin >> nof;
// 	cout << "Enter the number of Pages: "; cin >> size_of_array; 
// 	cout << "\nEnter the page numbers: ";
// 	for (i = 0; i < size_of_array; i++)
// 		cin >> mrstr[i];
// 	tot = i - 1;
// }
// void fifo::push()
// {
// 	int x, i, flag = 0;
// 	for (i = 0; i < nof; i++)
// 		frame[i] = -1;
// 	cout << "\nThe Page Frames are: \tNo.of Page Faults";
// 	for (i = 0; i < tot; i++)
// 	{
// 		x = mrstr[i];
// 		for (int j = 0; j < nof; j++)
// 		{
// 			if (frame[j] == x)
// 			{
// 				flag = 1;
// 				break;
// 			}
// 			else
// 				flag = 0;
// 		}
// 		if (flag == 0)
// 		{
// 			if (r == nof - 1)
// 			{
// 				++f;
// 				r = ++r%nof;
// 				frame[r] = x;
// 			}
// 			else
// 				frame[++r] = x;
// 			fault++;
// 			dis();
// 		}
// 	}
// 	cout << "\n\nTotal Page Faults: " << fault;
// }
// void fifo::dis()
// {
// 	int i = 0;
// 	cout << "\n------------ \n";
// 	while (i < nof)
// 	{
// 		cout << " | " << frame[i] << "  ";
// 		i++;
// 	}
// 	cout << " | " << fault;
// }
// int main()
// {
// 	fifo fp;
// 	system("cls");
// 	fp.getdata();
// 	fp.push();
// 	cout << endl << endl;
// 	system("pause");
// }




//  


// 	Optimal Page Replacement Algorithm C++ Implementation 
// #include<iostream>
// using namespace std;
// class pra
// {
// 	int    frame[50], frame1[50][2], pn[50], n, cnt, p, fs;
// public:
// 	pra();
// 	void init();
// 	void getdata();
// 	void optimal();
// };
// pra::pra()
// {
// 	int i;
// 	for (i = 0; i < fs; i++)
// 	{
// 		frame[i] = -1;
// 	}
// 	for (i = 0; i < fs; i++)
// 	{
// 		frame1[i][0] = -1;
// 		frame1[i][1] = 0;
// 	}
// 	p = 0;
// 	cnt = 0;
// }
// void pra::init()
// {
// 	int i;
// 	for (i = 0; i < fs; i++)
// 	{
// 		frame[i] = -1;
// 	}
// 	for (i = 0; i < fs; i++)
// 	{
// 		frame1[i][0] = -1;
// 		frame1[i][1] = 0;
// 	}
// 	p = 0;
// 	cnt = 0;
// }
// void pra::getdata()
// {
// 	cout << "\nEnter frame size: ";
// 	cin >> fs;
// 	cout << "\nEnter the number of pages: ";
// 	cin >> n;
// 	cout << "\nEnter the page numbers: ";
// 	for (int i = 0; i < n; i++)
// 	{
// 		cin >> pn[i];
// 	}
// }
// void pra::optimal()
// {
// 	init();
// 	int pi1 = 0, pi = 0, fault = 0, flag = 0, flag1 = 0, i, j, k, fn, max = 0, ind = 0;
// 	cnt = 0, p = 0;
// 	for (i = 0; i < n; i++)
// 	{
// 		j = 0;
// 		if (ind > fs - 1)
// 			ind = 0;
// 		fault = 1;
// 		max = 0;
// 		while (j < fs)
// 		{
// 			if (frame[j] == -1)
// 			{
// 				fault = 1;
// 				fn = j;
// 				goto l1;
// 			}
// 			j++;
// 		}
// 		j = 0;
// 		while (j < fs)
// 		{
// 			k = 0;
// 			while (k < fs)
// 			{
// 				if (frame[k] == pn[pi])
// 				{
// 					fault = 0;
// 					goto l1;
// 				}
// 				k++;
// 			}
// 			flag = 0;
// 			flag1 = 0;
// 			pi1 = pi;
// 			while (pi1 < n)
// 			{
// 				if (frame[j] == pn[pi1 + 1] && pi1 + 1 < max)
// 				{
// 					break;
// 				}
// 				if (frame[j] == pn[pi1 + 1] && pi1 + 1 > max)
// 				{
// 					max = pi1 + 1;
// 					fn = j;
// 					flag1 = 1;
// 					break;
// 				}
// 				pi1++;
// 			}
// 			pi1 = pi;
// 			if (flag1 == 0)
// 			{
// 				pi1 = pi;
// 				while (pi1 < n)
// 				{
// 					if (frame[j] == pn[pi1 + 1])
// 					{
// 						flag = 1;
// 						break;
// 					}
// 					pi1++;
// 				}
// 				if (flag == 0)
// 				{
// 					fn = j;
// 					goto l1;
// 				}
// 			}
// 			j++;
// 		}
// 	l1:
// 		if (fault == 1)
// 		{
// 			frame[fn] = pn[pi];
// 			cnt++;
// 		}
// 		cout << "\nElement is: " << pn[pi] << "-->";
// 		pi++;
// 		for (k = 0; k < fs; k++)
// 		{
// 			cout << "\t" << frame[k];
// 		}
// 		if (fault == 1)
// 			cout << "\t\tPage Fault";
// 		else
// 			cout << "\t\tNo Page Fault";
// 	}
// 	cout << "\n\n\nTotal number of page faults: " << cnt;
// }
// int main()
// {
// 	pra p;
// 	int  j, fault = 0, i, pi, k, fn, ind = 0, ans, ch;
// 	p.getdata();
// 	p.optimal();
// 	cout << endl << endl;
// 	system("pause");
// 	return 0;
// }

 

