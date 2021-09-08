#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct Cnode {
	char data;
	int length;
	struct Cnode* next;

}Cnode ,*Clist;
//创建循环链表
Clist Createlist();
//清空链表
int Clearlist(Clist list );
//尾插法
int Tailinsert(Clist list,char data);
//头插法
int Headinsert(Clist list, char data);
//求链表长度
int Listlength(Clist list);
//判断链表是否为空
int Iflistemtpy(Clist list);
//根据元素查找链表的位置
int Datafindindex(Clist list ,char data);
//根据元素查找链表的地址
Cnode* Datafindaddress(Clist list ,char data);
//根据位置查找元素
char Indexfinddata(Clist list ,int index);
//根据位置查找元素地址
Cnode* Indexfindaddress(Clist list,int index);

//根据位置增加元素
int Indexadddata(Clist list ,int index);
//根据位置删除元素
int Deletdata(Clist list ,int index);
///根据位置修改元素内容
int Alterdata(Clist list ,int index,char data);
//根据位置修改元素位置
int Alterdataindex(Clist list ,int oldindex,int newindex);
//销毁循环链表
void Destroy(Clist list );
//合并两个循环链表
void combinelist(Clist list1,Clist list2);