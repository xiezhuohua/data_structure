#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LONG 100
typedef struct {
	int length;
	char data[LONG];
}List;

//��ʼ��˳���
void Clearlist(List* list);

//��˳�����
int Listlenght(List* list);

//��ȡԪ��
char Getdata(List* list, int index);

//��ȡԪ��λ��
int Listindex(List* list, char data);

//����Ԫ��
int Addata(List* list,int index,char data);

//ɾ��Ԫ��
int Delete(List* list, char data);

//�޸�Ԫ������
int Changedata(List* list, char data, int index);

//�޸�Ԫ��λ��
int Changeseat(List* list, char data,int index);
//
////˳�������
//int Sortlist(List* list);

//�ж�˳��������Ƿ�Ϊ��
int Ifdataempty(List* list,int index);

//�ͷ�˳���
void Destroy(List* list);