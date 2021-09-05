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

//创建链表
List*  Creatlist();
//链表初始化
void Initlist(List* list);
//头插法
int Headinsert(List* list);
//尾插法
int Tailinsert(List* list);
//判断是否是空链表
int Ifempty(List* list);
//清空链表
void Clearlist(List* list);
//求表长
int Getlength(List* list);
//销毁链表
void destroy(List* list);
//根据元素查找 位置
int Datafindindex(List* list ,int data);
//根据元素查找地址
Node* Datafindadderss(List* list ,int data);
//根据位置查找元素
int Indexfinddata(List* list ,int index);
//根据位置查找元素地址
Node* Indexfindadderss(List* list, int index);
//增加元素
int Addnode(List* list,int index,int data);
//删除元素
int Deletnode(List* list, int index);
//根据位置修改元素内容
int Alternodedata(List* list ,int index,int data);
//根据位置修改元素位置
int Alternodeindex(List* list, int oldindex, int newindex);
//打印链表所有元素
void printflist(List* list);

