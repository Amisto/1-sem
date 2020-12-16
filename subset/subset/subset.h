
#ifndef __SUBSET_H__
#define __SUBSET_H__

//nclude <iostream>

//const int POISON_VALUE = -666;

using namespace std;



//�������� ������ ������
struct subset_node {

    int key;
    subset_node* right;
    subset_node* left;

};

//������������� ������� ������
bool init(subset_node** sn) {
    *sn = NULL;

    return true;
}

////�������������
//bool exist(subset_node* sn, int k) {
//    if (sn == NULL)
//        return false;
//    if (sn->key == k)
//        return true;
//    if (k < sn->key)
//        return exist(sn->left, k);
//    else if (k > sn->key)
//        return exist(sn->right, k);
//}

//����� �������� � ������, ���������� ��������� �� ����
subset_node* find(subset_node* sn, int k) {
    if (sn == NULL)
        return NULL;
    if (sn->key == k)
        return sn;
    if (k < sn->key)
        return find(sn->left, k);
    else if (k > sn->key)
        return find(sn->right, k);
}

//���������� �������� � ������, ����� ������������ (false, ���� ������� �����������)

bool insert(subset_node** sn, int k) {
    cout << " a ";

    //���� ������ ������, �� �������
    if (!(*sn))
    {  *sn = new subset_node;
        (*sn)->key = k;
        (*sn)->right = NULL;
        (*sn)->left = NULL;
        return true;
    }
    //��� ����������, ���������� false
    if (find(*sn, k) != NULL)
        return false;
    //�� ����������� �����, ����� �������� insert
    if (k < (*sn)->key)
        return insert(&(*sn)->left, k);
    else if (k > (*sn)->key)
        return insert(&(*sn)->right, k);
}

//�������� ��������
void del_elem(subset_node* sn, int k) {
  if (sn->left == NULL)//��� ������ �������
  {
      subset_node* right = sn->right; //����������� ������
      delete sn;
      sn = right;
  }
  else if (sn->right == NULL)//��� ������� �������
  {
      subset_node* left = sn->left;
      delete sn;
      sn = left;
  }
  else//���� ��� �������
  {
      //���� ����������� ������
      subset_node* right = sn->right;
      if (right->left == NULL)//� ������� ��� ������ ������� - �� ��� �� ���� �����������
      {
          sn->key = right->key;
          sn->right = right->right;
          delete right;
      }
      else//� ������� ���� ����� ������� - ����������� ���-�� ��� �����
      //������ �������� ������������ ��������
      {
          subset_node* min_parent = right;
          while (min_parent->left->left != NULL)
          {
              min_parent = min_parent->left;
          }
          subset_node* min = min_parent->left;
          min_parent->left = min->right;
          delete min;
      }
  }

}

//���� ��������, �� ��, ������� ����
bool remove(subset_node** sn, int k) {

    if (sn == NULL)
        return false;
    if ((*sn)->key == k)
    {
        del_elem(*sn, k);
        return true;
    }        
    if (k < (*sn)->key)
        return remove(&(*sn)->left, k);
    else if (k > (*sn)->key)
        return remove(&(*sn)->right, k);

}


//���������� ��������� � ������
unsigned int size(subset_node* sn) {
    unsigned int s = 0;

    if (sn == nullptr)
        return 0;

    //if ((sn->right == NULL) & (sn->left == NULL))
    //{
    //    //if (sn->key == POISON_VALUE)
    //      //  return 0;

    //    return 1;
    //}

    else
        return size(sn->left) + size(sn->right) + 1;
}


//������ ������
unsigned int height(subset_node* sn) {
    if (sn == NULL)
        return 0;
    return (max(height(sn->right), height(sn->left)) + 1);

}

//�������� ��� ������������ ������
void destructor(subset_node* sn)
{
    if (sn == NULL);
          return;
    if (sn->left)
        destructor(sn->left);
    if (sn->right)
        destructor(sn->right);

        sn->right = NULL;
        sn->left = NULL;
        //sn->key = POISON_VALUE;
        sn = NULL;

        delete sn;
}

void visit(subset_node* sn, int* a) {
    int i = 0;
    if (sn == NULL)
        return;
    visit(sn->left, a);
    a[i] = sn->key;
    i++;

    visit(sn->right, a);
}

int* DFS(subset_node* sn) {
    int* a = new int[size(sn)];
    visit(sn, a);
    return a;
}




#endif //__SUBSET_H__