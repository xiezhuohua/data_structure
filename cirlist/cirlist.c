#define _CRT_SECURE_NO_WARNINGS 1
#include"cirlist.h"
//创建循环链表
Clist Createlist() {
	Clist list = (Clist)malloc(sizeof(Cnode));
	list->data = '\0';
	list->next = list;
	return list;
}

//清空链表
int Clearlist(Clist list) {
	Cnode* p = NULL;
	Cnode* q = NULL;
	list = list->next;
	p = list->next;
	while (p != (Cnode*)list) {
		q = p->next;
		free(p);
		p = q;
	}
	return 1;
}
//尾插法
int Tailinsert(Clist list, char data) {
	Cnode* old = NULL;
	Cnode* new = NULL;
	list->next = (Clist)old;
	list->next = (Clist)new;
	printf("请输入·你要输入元素的个数\n");
	int n = 0;
	scanf("%d",&n);

	while (n) {
		
		new = (Cnode*)malloc(sizeof(Cnode));
		printf("请输入元素\n");
		scanf("\n%c", &new->data);
		old->next = (Clist) new;
		old = new;
		--n;
	}
	list = (Clist)old;
	old = NULL;
	new = NULL;
	return 1;
}
//头插法
int Headinsert(Clist list, char data) {

	Cnode* new = NULL;
	list->next = (Clist)new;
	printf("请输入·你要输入元素的个数\n");
	int n = 0;
	scanf("%d", &n);
	
	
	while (n) {

		new = (Cnode*)malloc(sizeof(Cnode));
		printf("请输入元素\n");
		scanf("\n%c", &new->data);
		new->next = (Clist)list->next;
		list->next = (Clist)new->next;
		--n;
	}
	list = (Clist)new;

	new = NULL;
	return 1;
}
//求链表长度
int Listlength(Clist list) {
	Cnode* p = NULL;
	int lenght = 0;
	p =(Cnode*)list->next;
	p = p->next;
	while (p != (Cnode*)list->next) {
		++lenght;
		p = p->next;
	}
	return lenght;
}
//判断链表是否为空
int Iflistemtpy(Clist list) {
	if (list->next = (Cnode*)list) {
		printf("链表为空\n");
		return 1;
	}
	else {
		printf("链表不为空\n");
		return 0;
	}
}
//根据元素查找链表的位置
int Datafindindex(Clist list, char data) {
	int index = 1;
	Cnode*  p = (Cnode*)list->next;
	p = p->next;
	while (p!= (Cnode*)list->next) {
		
		if (p->data==data) {
			return index;
		}
		else {
			p = p->next;
		}
		++index;
	}
	return -1;
}
//根据元素查找链表的地址
Cnode* Datafindaddress(Clist list, char data) {
	Cnode* p = (Cnode*)list->next;
	while (p!= (Cnode*)list->next) {
		if (p->data!=data) {
			p = (Cnode*)p->next;
		}
		else {
			return p;
		}
	}
	return NULL;	
}
//根据位置查找元素
char Indexfinddata(Clist list, int index) {
	int length = Listlength(list);
	if (index<1 || index>length) {
		printf("超出范围\n");
		return '\0';
	}
	Cnode* p = (Cnode*)list->next;
	p = p->next;
	while (--index&&p!= (Cnode*)list->next) {
		p = p->next;
	}
	if (index == 0) {
		return p->data;
	}
	else {
		printf("没有找到\n");
		return '\0';
	}
}
//根据位置查找元素地址
Cnode* Indexfindaddress(Clist list, int index) {
	int length = Listlength(list);
	if (index<0 || index>length) {//包括头头结点
		printf("超出范围\n");
		return NULL;
	}
	Cnode* p = list;
	while (index!=-1 && p != (Cnode*)list->next) {
		p = p->next;
		--index;
	}
	if (index == -1) {
		return p;
	}
	else {
		printf("没有找到\n");
		return NULL;
	}
}

//根据位置增加元素
int Indexadddata(Clist list, int index) {
	Cnode* p = (Cnode*)malloc(sizeof(Cnode));
	printf("请输入元素\n");
	scanf("%c",&p->data);
	Cnode* q = Indexfindaddress(list,  index-1);
	int length = Listlength(list);
	if (index<1||index>length+1) {
		printf("超出范围\n");
		return -1;
	}
	p = q->next;
	q->next = (Clist)p;
	return 1;
}
//根据位置删除元素
int Deletdata(Clist list, int index) {
	int length = Listlength(list);
	if (index<1 || index>length ) {
		printf("超出范围\n");
		return -1;
	}
	Cnode* persent = Indexfindaddress(list, index );
	Cnode* oldnode = Indexfindaddress(list, index - 1);
	oldnode->next = persent->next;
	free(persent);
	persent = NULL;
	oldnode = NULL;
	return 1;
}
///根据位置修改元素内容
int Alterdata(Clist list, int index,char data) {
	int length = Listlength(list);
	if (index<1 || index>length) {
		printf("超出范围\n");
		return -1;
	}
	Cnode* persent = Indexfindaddress(list, index);
	printf("请输入修改后元素\n");
	scanf("%c",&persent->data);
	return 1;
}
//根据位置修改元素位置
int Alterdataindex(Clist list, int oldindex, int newindex) {
	int length = Listlength(list);
	if (oldindex<1 || oldindex>length) {
		printf("超出范围\n");
		return -1;
	}
	if (newindex<0 || newindex>length+1) {
		printf("超出范围\n");
		return -1;
	}
	Cnode* old  = Indexfindaddress(list, oldindex);
	Cnode* oldnode = Indexfindaddress(list, oldindex - 1);
	oldnode->next = old->next;
	oldnode = Indexfindaddress(list, newindex - 1);
	old->next = oldnode->next;
	oldnode->next = (Clist)old;
	return 1;
}
//销毁循环链表
void Destroy(Clist list) {
	Cnode* p = (Cnode*)list;
	int length = Listlength(list)+1;
	while (--length) {
		list = list->next;
		free(p);
		p = (Cnode*)list;
	}
	list = NULL;
	p = NULL;
}

//合并两个循环链表
void combinelist(Clist list1, Clist list2) {
	Cnode* p = list1->next;
	list1->next = list2->next->next;
	free(list2->next);
	list2->next = p;
	p = NULL;
}