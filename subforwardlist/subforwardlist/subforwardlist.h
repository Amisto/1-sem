#ifndef __SUBLIST_H__
#define __SUBLIST_H__



using namespace std;

//������� ������������ ������ - ��������� �� ������ � ������ � ������
struct subforwardlist
{
	int data;
	subforwardlist* next;
};

//������������� ������� ���������� // ok
bool init(subforwardlist** sfl) {

	*sfl = NULL;

	return true;
}

//���������� ������ ���������� // ok
unsigned int size(subforwardlist** sfl) {
	unsigned int size = 1;
	if ((*sfl) == NULL)
		return 0;
	else
	{
		subforwardlist* tmp = *sfl;

		while (tmp->next != NULL)
		{
			tmp = tmp->next; //� temp  ����������� ��������� �� ��������� �������
			size++;
		}

		//while ((*sfl)->next != NULL)
		//{
		//	(*sfl) = (*sfl)->next; //� temp  ����������� ��������� �� ��������� �������
		//	size++;
		//}

		return size;
	}
}

//�������� �������� � ����������� �������� // ok
int where(subforwardlist** sfl, int index) {

	int position = 0;
	subforwardlist* temp = *sfl;
	if (temp->next == NULL) {
		return (*sfl)->data;
	}
	else
	{
		while (temp->next != NULL)
		{
			if (position == index)
			{
				return temp->data;
			}
			else
			{
				temp = temp->next;
				position++;
			}
		}
	}
}


//���������� �������� � ����� ���������� // ok
bool push_back(subforwardlist** sfl, int d) {

	if (*sfl != nullptr)
	{
		subforwardlist* temp = (*sfl); //������� ��������� ���������

		while (temp->next != NULL)
		{
			temp = temp->next; //� temp  ����������� ��������� �� ��������� �������
		}
		temp->next = new subforwardlist;
		temp->next->data = d;
		temp->next->next = NULL;
	}
	else
	{
		*sfl = new subforwardlist;
		(*sfl)->data = d;
		(*sfl)->next = NULL;
	}

	return true;
}

//�������� �������� � ����� ����c����� //ok?

int pop_back(subforwardlist** sfl) {

	if (*sfl != NULL)
	{
		subforwardlist* prev = NULL; // = (*sfl);   ///->next;
		subforwardlist* cur = (*sfl);

		while (cur->next != NULL)
		{
			prev = cur;
			cur = cur->next;
		}

		int l = cur->data;
		prev->next = NULL;
		delete cur;

		return l;
	}
	else
		return 0;
}

//���������� �������� � ������ ���������� // ok
bool push_forward(subforwardlist** sfl, int d) {

	if (*sfl == NULL)
	{
		*sfl = new subforwardlist;
		(*sfl)->data = d;
		(*sfl)->next = NULL;
	}

	else
	{
		subforwardlist* temp = new subforwardlist;
		temp->data = d;
		temp->next = *sfl;
		*sfl = temp;
	}

	return true;
}

//��� pop_forward
//�������� ������� �������� ������
void pop_front(subforwardlist** sfl) {

	subforwardlist* temp = *sfl;
	*sfl = (*sfl)->next;
	delete temp;
}

//�������� �������� �� ������ ���������� // ok?
int pop_forward(subforwardlist** sfl) {

	if (*sfl != NULL)
	{
		subforwardlist* temp = *sfl;
		int f = (*sfl)->data;
		*sfl = (*sfl)->next;
		delete temp;
		return f;
	}
	else
		return 0;

}

//���������� �������� � ���������� ������� where // ok
bool push_where(subforwardlist** sfl, unsigned int where, int d) {


	if (where == 0 || *sfl == NULL)
	{
		push_forward(&(*sfl), d);
	}
	else
	{
		subforwardlist* prev = NULL;
		subforwardlist* cur = (*sfl);

		for (unsigned int i = 0; i != where; i++)
		{
			prev = cur;
			cur = cur->next;
		}

		subforwardlist* new_el = new subforwardlist;
		new_el->data = d;
		new_el->next = cur;
		prev->next = new_el;
		cur = cur->next;
	}

	return true;
}


//�������� �������� � ���������� ������� where
bool erase_where(subforwardlist** sfl, unsigned int where) {

	if (where == 0)
	{
		pop_front(&(*sfl));
	}
	else
	{
		subforwardlist* prev = NULL;
		subforwardlist* cur = (*sfl);

		for (unsigned int i = 0; i != where; i++)
		{
			prev = cur;
			cur = cur->next;
		}
		subforwardlist* next_el = cur->next;
		prev->next = next_el;
		delete cur;
	}
	return true;
}


//�������� ���������� ����������
void clear(subforwardlist** sfl) {

	if (!*sfl)
		return;
	clear(&((*sfl)->next));
	delete* sfl;
	*sfl = NULL;

}




#endif //__SUBLIST_H__