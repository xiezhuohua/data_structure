#pragma once
#include<stdio.h>
typedef struct Node {
	struct Node* pion;
	int data;
	struct Node* next;
}Node ,*List;

//����˫ѭ������
void Create();
//�������
void Clear(List* list);

//��������
void desroy(List* list );
//�ж������Ƿ�Ϊ��\
int IFemtpy(List* list);
//��������
int Getlength(List* list);

//����Ԫ����λ��
int Datafindindex(List* list,int data);
//����Ԫ�����ַ
Node* Datafindadderss(List* list,int data);
//����λ����Ԫ��
int Indexfinddata(List* list,int index);
//����λ�����ַ
Node* Indexfindadderss(List* list,int index);
//����Ԫ��
int Adddata(List* list,int index,int data);
//ɾ��Ԫ��
int Deteldata(List* list,int index);
//�޸�Ԫ��
int Alterdata(List* list,int index,int data);
//�޸�Ԫ��λ��
int Alterdataindex(List* list,int oldindex,int newindex);
//ͷ�巨
void Haedinput(List* list);

//β�巨
void Tailinput(List* list);
