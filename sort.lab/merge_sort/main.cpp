#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

int a[1000000];


// ����������� �������������� ��������������� ������� ����� ������� ���� ���������������
void Merge(int *a, int l, int m, int r){

int i = 0, j = 0, k = 0;
int size_l = m - l + 1;
int size_r = r - m;

//������� ��������� �������

int* temp_l = new int[size_l];
int* temp_r = new int[size_r];

//�������� ������� � ��� �������

for (i = 0; i < size_l; i++){
          temp_l[i] = a[l + i];
}

for (j = 0; j < size_r; j++){
          temp_r[j] = a[m + 1 + j];
}

//��������� ������� ��� ������ � ������� ��������; ������� arr[l ... r];

i = 0;
j = 0;
k = 1; //��� ��������������� �������;

while (i < size_l && j < size_r){

    if (temp_l[i] <= temp_r[j]){

        a[k] = temp_l[i];
        i++;
    }
    else {

        a[k] = temp_r[j];
        j++;
    }
    k++;
}

//�������� ���������� �� temp_l ��������, ���� ����

while (i < size_l){

    a[k] = temp_l[i];
    i++;
    k++;
}

//�������� ���������� �������� �� temp_r, ���� ����

while (j < size_r){

    a[k] = temp_r[j];
    j++;
    k++;
}

delete [] temp_l;
delete [] temp_r;

}

void merge_sort(int *a, int l, int r){

int m = (l + r)/2;

if (l < r){
merge_sort(a, l, m);
merge_sort(a, m + 1, r);
Merge(a, l, m, r);

}
}


int main()
{

int p = 10;
//while (n <= 1000000){
    int a[p];
    //srand( time (0));
    for (int i=0; i < p; i++){
    //a[i]=rand();
    cin >> a[i];
    }
//auto begin = chrono::high_resolution_clock::now();

merge_sort(a, 0, p - 1);

/*auto end = chrono::high_resolution_clock::now();
cout << chrono::duration_cast <chrono::milliseconds>(end-begin).count()<< " ";
cout << endl;

    p += 10000;
}*/

for (int i = 0; i < p; i++){
    cout << a[i] << " ";
}

    return 0;
}
