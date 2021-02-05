#include <iostream>

using namespace std;

struct subvector{

    int *mas;
    unsigned int top;
    unsigned int capacity;

};

// � bool ��������� true, ���� ��� ���������
//������������� ������� �����������
bool init(subvector *qv){

    qv->mas = NULL;
    qv->top = 0;
    qv->capacity = 0;

    return true;
}

void expand(int **mas, unsigned int top, unsigned int new_cap)
{
    int* new_mas = new int[new_cap];
    for (int i = 0; i < top; i++)
        new_mas[i] = (*mas)[i];

    delete[] *mas;
    *mas = new_mas;
}


//���������� �������� � ����� �����������
//� ���������� �������������� ������ ��� �������������

bool push_back(subvector *qv, int d){

    if(qv->capacity > qv->top)
    {
        qv->top++;
        qv->mas[qv->top-1] = d;
    }
    else
    {
        expand(&(qv->mas), qv->top, 2*((qv->capacity)+1));
        qv->capacity = 2*((qv->capacity)+1);
        qv->top++;
        qv->mas[qv->top-1] = d;
    }

    return true;
}

//�������� �������� � ����� �����������; ���������� �������, ������� ��� ������
int pop_back(subvector *qv){

    if (qv->top == 0)
        return 0;

    int last = qv->mas[(qv->top)-1];

    qv->top--;

    return last;
}

//����������� capacity; �� �� �����, ��� expand

bool resize(subvector *qv, unsigned int new_capacity){

int* new_mas = new int[new_capacity];
for (int i = 0; i < qv->top; i++)
    {
        new_mas[i] = (qv->mas)[i];
    }

    qv->capacity = new_capacity;

    delete[] qv->mas;
    qv->mas = new_mas;
  return true;
}

//�������� �������������� ������
void shrink_to_fit(subvector *qv){

    if (qv->capacity == qv->top)
        return;

    if (qv->capacity > qv->top)
        {
            expand(&(qv->mas), qv->top, qv->top);
            qv->capacity = qv->top;
        }

}


//�������� ���������� �����������; ���������� ����� ��� ���� �� ��������
void clear(subvector *qv){
    qv->top = 0;
}

//�������� ��� ������������ ������; ���������������� ���������� ��� ������
void destructor(subvector *qv){
    delete[] qv->mas;
    init(qv);
}


/*
int main()
{

    return 0;
}

*/
