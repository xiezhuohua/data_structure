#pragma once
#include<stdio.h>
typedef struct Node {
	struct Node* pion;
	int data;
	struct Node* next;
}Node ,*List;

//创建双循环链表
void Create();
//请空链表
void Clear(List* list);

//销毁链表
void desroy(List* list );
//判断链表是否为空\
int IFemtpy(List* list);
//求链表长度
int Getlength(List* list);

//根据元素求位置
int Datafindindex(List* list,int data);
//根据元素求地址
Node* Datafindadderss(List* list,int data);
//根据位置求元素
int Indexfinddata(List* list,int index);
//根据位置求地址
Node* Indexfindadderss(List* list,int index);
//增加元素
int Adddata(List* list,int index,int data);
//删除元素
int Deteldata(List* list,int index);
//修改元素
int Alterdata(List* list,int index,int data);
//修改元素位置
int Alterdataindex(List* list,int oldindex,int newindex);
//头插法
void Haedinput(List* list);

//尾插法
void Tailinput(List* list);
