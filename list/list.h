#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LONG 100
typedef struct {
	int length;
	char data[LONG];
}List;

//初始化顺序表
void Clearlist(List* list);

//求顺序表长度
int Listlenght(List* list);

//获取元素
char Getdata(List* list, int index);

//获取元素位置
int Listindex(List* list, char data);

//增加元素
int Addata(List* list,int index,char data);

//删除元素
int Delete(List* list, char data);

//修改元素内容
int Changedata(List* list, char data, int index);

//修改元素位置
int Changeseat(List* list, char data,int index);
//
////顺序表排序
//int Sortlist(List* list);

//判断顺序表数据是否为空
int Ifdataempty(List* list,int index);

//释放顺序表
void Destroy(List* list);