#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct Cnode {
	char data;
	int length;
	struct Cnode* next;

}Cnode ,*Clist;
//����ѭ������
Clist Createlist();
//�������
int Clearlist(Clist list );
//β�巨
int Tailinsert(Clist list,char data);
//ͷ�巨
int Headinsert(Clist list, char data);
//��������
int Listlength(Clist list);
//�ж������Ƿ�Ϊ��
int Iflistemtpy(Clist list);
//����Ԫ�ز��������λ��
int Datafindindex(Clist list ,char data);
//����Ԫ�ز�������ĵ�ַ
Cnode* Datafindaddress(Clist list ,char data);
//����λ�ò���Ԫ��
char Indexfinddata(Clist list ,int index);
//����λ�ò���Ԫ�ص�ַ
Cnode* Indexfindaddress(Clist list,int index);

//����λ������Ԫ��
int Indexadddata(Clist list ,int index);
//����λ��ɾ��Ԫ��
int Deletdata(Clist list ,int index);
///����λ���޸�Ԫ������
int Alterdata(Clist list ,int index,char data);
//����λ���޸�Ԫ��λ��
int Alterdataindex(Clist list ,int oldindex,int newindex);
//����ѭ������
void Destroy(Clist list );
//�ϲ�����ѭ������
void combinelist(Clist list1,Clist list2);