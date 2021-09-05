#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

// 创建链表
List* Creatlist() {
	List* list = (List*)malloc(sizeof(List));
	list->head = (Node*)malloc(sizeof(Node));
	return list;
}
//链表初始化
void Initlist(List* list) {
	list->length = 0;
	list->head->data = 0;
	list->head->next = NULL;
}
//头插法
int Headinsert(List* list) {
	int n = 0;
	printf("请输入您要输入元素的个数\n");
	scanf("%d", &n);
	
	Node* oldnode = (Node*)malloc(sizeof(Node));
	printf("请输入元素\n");
	scanf("%d",&oldnode->data);
	--n;
	++(list->length);
	oldnode->next = NULL;
	list->head->next = oldnode;//让头结点指针指向最后一个结点
	
	
	while (--n) {
		
		Node* newnode = (Node*)malloc(sizeof(Node));
		printf("请输入元素\n");
		scanf("%d", &newnode->data);
		newnode->next = list->head->next;//让新结点指针域指向旧结点
		list->head->next = newnode;//让头结点指针域指向新结点
		oldnode = newnode;//新结点赋值给旧结点以便下一次，新结点重新开辟
		++(list->length);
		if (n == 0) {
			oldnode->next = NULL;//将最后一个结点的指针赋值为空
			oldnode = NULL;
			newnode = NULL;
		}
	}
	return 1;
}
	
//尾插法
int Tailinsert(List* list) {
	int n = 0;
	printf("请输入您要输入元素的个数\n");
	scanf("%d", &n);

	Node* oldnode = (Node*)malloc(sizeof(Node));
	printf("请输入元素\n");
	scanf("%d", &oldnode->data);
	--n;
	++(list->length);
	list->head->next = oldnode;//让头结点指针指向最后一个结点
	while (--n) {
		Node* newnode = (Node*)malloc(sizeof(Node));
		printf("请输入元素\n");
		scanf("%d", &newnode->data);
		oldnode->next = newnode;//前一个结点的指针域记录新结点地址
		oldnode = newnode;//新结点赋值给旧结点以便下一次，新结点重新开辟
		++(list->length);
		if (n==0) {
			oldnode->next = NULL;//将最后一个结点的指针赋值为空
			oldnode = NULL;
			newnode = NULL;
		}
	}
	return 1;
}
//判断是否是空链表
int Ifempty(List* list) {
	if (list->head->next == NULL || list->length == 0) {
		printf("是空表\n");
		return 1;
	}
	else {
		printf("链表不空\n");
		return 0;
	}
}
//清空链表
void Clearlist(List* list) {
	Node* p = NULL;
	p = list->head->next;//该指针记录首元结点
	while (p != NULL) {
		list->head = p->next;//表头指向下一结点
		free(p);
		p = list->head;//将下一结点地址赋值给p；
	}
	list->length = 0;
}
//求表长
int Getlength(List* list) {
	return list->length;
}
//销毁链表
void destroy(List* list) {
	Node* persent = NULL;
	while (list->head!=NULL) {
		persent = list->head;
			list->head = list->head->next;
		free(persent);
	}
	persent = NULL;
	list->length = 0;
}
//根据元素查找位置
int Datafindindex(List* list, int data) {
	int index = 0;
	Node* p = list->head->next;
	while (p==NULL) {
		++index;
		if (data = p->data) {
			return index;
		}
		else {
			p = p->next;
		}
	}
	printf("未找到\n");
	return 0;
}
//根据元素查找地址
Node* Datafindadderss(List* list, int data) {
	int index = 0;
	Node* p = list->head->next;
	while (p == NULL) {
		++index;
		if (data = p->data) {
			return p;
		}
		else {
			p = p->next;
		}
	}
	printf("未找到\n");
	return NULL;
}
//根据位置查找元素
int Indexfinddata(List* list, int index) {
	if (index > list->length || index <= 0) {
		printf("位置超出范围\n");
		return -1;
	}
	int n = 1;
	Node* p =list->head->next;
	while (n != index) {
		
		p = p->next;
		++n;
	}
	return p->data;
}
//根据位置查找元素地址
Node* Indexfindadderss(List* list, int index) {
	if (index > list->length || index <0) {
		printf("位置超出范围\n");
		return NULL;
	}
	int n = 0;
	Node* p = list->head;
	while (n != index) {

		p = p->next;
		++n;
	}
	return p;
}
//增加元素
int Addnode(List* list, int index, int data) {
	if (index <= 0 || index > list->length + 1) {
		printf("超出范围\n");
		return 0;
	}
	else {
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->data = data;
		newnode->next = NULL;

		Node* oldnode = NULL;//前一个结点的地址
		oldnode = Indexfindadderss(list, index - 1);
		newnode->next = oldnode->next;
		oldnode->next = newnode;
		++list->length;
		return 1;
	}
}

//删除元素
int Deletnode(List* list, int index) {
	if (index <= 0 || index > list->length ) {
		printf("超出范围\n");
		return 0;
	}
	else {
		Node* persentnode = NULL;
		Node* oldnode = NULL;//前一个结点的地址
		oldnode = Indexfindadderss(list, index - 1);
		persentnode = Indexfindadderss(list, index);
		oldnode->next = persentnode->next;
		free(persentnode);
		persentnode = NULL;
		return 1;
	}
}
//根据位置修改元素内容
int Alternodedata(List* list, int index, int data) {
	if (index <= 0 || index > list->length ) {
		printf("超出范围\n");
		return 0;
	}
	else {
		Node* persentnode = NULL;
		persentnode = Indexfindadderss(list, index);
		persentnode->data = data;
		return 1;
	}
	
}
//根据位置修改元素位置
int Alternodeindex(List* list, int oldindex, int newindex) {
	if ((oldindex <= 0 || oldindex > list->length)||(newindex <= 0 || newindex > list->length+1)) {
		printf("超出范围\n");
		return 0;
	}
	else {
		Node* persentnode = NULL;
		Node* oldnode = NULL;
		persentnode = Indexfindadderss(list, oldindex);
		oldnode = Indexfindadderss(list, oldindex - 1);//要找的前一个结点
		oldnode->next = persentnode->next;
		oldnode = Indexfindadderss(list, newindex - 1);
		persentnode->next = oldnode->next;
		oldnode->next = persentnode->next;
		return 1;	
	}
}
//打印链表所有元素
void printflist(List* list) {
	Node* p = list->head->next;
	int n = 1;
	while (p) {
		printf("第%d个结点的元素：%d  \n",n,p->data);
		++n;
		p = p->next;
	}
}
