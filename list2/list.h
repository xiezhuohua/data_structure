#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct  Node* next;
}Node;

typedef struct List {
	Node* head;
	int length;
}List;

//��������
List*  Creatlist();
//�����ʼ��
void Initlist(List* list);
//ͷ�巨
int Headinsert(List* list);
//β�巨
int Tailinsert(List* list);
//�ж��Ƿ��ǿ�����
int Ifempty(List* list);
//�������
void Clearlist(List* list);
//���
int Getlength(List* list);
//��������
void destroy(List* list);
//����Ԫ�ز��� λ��
int Datafindindex(List* list ,int data);
//����Ԫ�ز��ҵ�ַ
Node* Datafindadderss(List* list ,int data);
//����λ�ò���Ԫ��
int Indexfinddata(List* list ,int index);
//����λ�ò���Ԫ�ص�ַ
Node* Indexfindadderss(List* list, int index);
//����Ԫ��
int Addnode(List* list,int index,int data);
//ɾ��Ԫ��
int Deletnode(List* list, int index);
//����λ���޸�Ԫ������
int Alternodedata(List* list ,int index,int data);
//����λ���޸�Ԫ��λ��
int Alternodeindex(List* list, int oldindex, int newindex);
//��ӡ��������Ԫ��
void printflist(List* list);

