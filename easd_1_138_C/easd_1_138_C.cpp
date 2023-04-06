//1. Suatu algoritma dibutuhkan untuk menyelesaikan suatu masalah karena untuk mengelola(didalam memori (struktur data) data yang beragam (jenisnya) dengan mudah dan efisien.
//2. 2 data struktur tersebut yaitu Statik (Array) dan Dinamis(ukurannya belum tahu (bisa ditamabh atau dikurang) (linked list).
//3. Faktor-faktor yang memepengaruhi efisiensi suatu program yaitu kecepatan, penerjemahan, sistem operasi, bahasa pemrograman, ukuran yang menginput data, dan cara untuk mengelola data (struktur data) harus tepat. Dan efisiensinya Algoritma itu waktu (agoritmanya sedikit, maka waktunya semakin cepat) dan Raung (struktur data).
//4. mungkin dari 6 algoritma yang sudah dipelajari untuk keefisiensi dalam mengurutkan data yang ukurannya kecil itu Insertion sort, karena insertion sort lebih efisien jika datanya hampir semua urut dibandingakan bublesort ataupun Selection sort. Insertion sort 1x pembamdingnya.
//5. Yang termasuk quadratik itu ada bublesort, selection sort, insertion sort, sedangkan yang longlinear itu ada marge sort, shell sort,quick sort(jika n^2 maka kasusnya buruk).
//6. implementasi dari selection sort :


#include <iostream>
using namespace std;

int nila[58];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
	while (true)
	{
		cout << "masukan panjang element array : ";
		cin >> n;

		if (n <= 58)
			break;
		else
			cout << "\nMaksimum panjang array adalah 58" << endl;

	}

	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> nila[i];

	}
}

void swap(int x, int y)
{

	int temp;

	temp = nila[x];
	nila[x] = nila[y];
	nila[y] = temp;
}

void q_sort(int low, int high)
{
	int pivot, i, NW;
	if (low > high)		//Langkah Algo. No.1
		return;

	pivot = nila[low];		// langkah Algo. no.2

	i = low + 1;			//Langkah Algo. No.3
	NW = high;				// Langkah Algo.No. 4


	while (i <= NW)			// langkah Algo. No. 10
	{

		while ((nila[i] <= pivot) && (i <= high))			//Langkah Algo.No.5
		{
			i++;											//Langkah Algo. No.6
			cmp_count++;

		}
		cmp_count++;

		while ((nila[NW] > pivot) && (NW >= low)) //ngkah Algo. No.7
		{
			NW--;					//Langkah Algo. No. 8
			cmp_count++;

		}
		cmp_count++;

		if (i < NW)				//Langkah Algo. No. 9
		{
			swap(low, NW);
			mov_count++;
		}

		if (low < NW);						//Langkah Algo. No. 11
		{
			swap(low, NW);
			mov_count++;
		}

		q_sort(low, NW - 1);				//Langkah Algo. No. 12

		q_sort(NW + 1, high);				//Langkah Algo. No. 13

	}

}

void display() {
	cout << "\n----------------" << endl;
	cout << "Sorted Array" << endl;
	cout << "\-----------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << nila<< " ";
	}

	cout << "\n\nNumber of comprasion: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}

int main()
{
	input();
	q_sort(0, n - 1);			
	display();
	system("pause");

	return 0;
}