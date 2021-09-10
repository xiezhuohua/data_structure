#define _CRT_SECURE_NO_WARNINGS 1
#include"dlist.h"

//创建双循环链表
void Create() {
	List list = (Node*)malloc(sizeof(Node));
	list->next = list;
	list->pion = list;
	list->data = 0;
}
//请空链表
void Clear(List list) {
	Node* p = list;
	Node* q = list->next;
	while (q!=list) {
		p = q;
		q = q->next;
		free(p);
	}
	p = NULL;
	q = NULL;

}

//销毁链表
void desroy(List list) {
	Node* head = list;
	
	Node* p = list;
;
	do {
		
		list = list->next;
		free(p);
		p = list;
	} while (p!=head);
	head = NULL;
	p = NULL;
	list = NULL;
}
//判断链表是否为空
int IFemtpy(List list){
	if (list->next == list && list->pion ==list) {
		printf("链表为空\n");
		return 1;
	}
	else {
		printf("链表不为空\n");
		return -1;
	}
}
//求链表长度
int Getlength(List list) {
	Node* p = list;
	int i = 0;
	do
	{
		++i;
		p = p->next;
	} while (p!= list);
	p = NULL;
	return i;
}

//根据元素求位置
int Datafindindex(List list, int data) {
	Node* p = list;
	int index = 0;
	do
	{
		if (p->data == data) {
			return index;
		}
		else {
			p = p->next;
		}
		++index;		
	} while (p != list);
	p = NULL;//没找到
	return 0;
}
//根据元素求地址
Node* Datafindadderss(List list, int data) {
	Node* p = list;
	int index = 0;
	do
	{
		if (p->data == data) {
			return p;
		}
		else {
			p = p->next;
		}
		++index;
	} while (p != list);
	p = NULL;//没找到
	return NULL;
}
//根据位置求元素
int Indexfinddata(List list, int index) {
	int length = Getlength(list);
	if (index > length || index < 1) {
		printf("超范围\n");
	}
	Node* p = list->next;
	++index;
	while (--index || p != list) {
		p = p->next;
	}
	if (index == 0) {
		return p->data;
	}
	else {
		printf("没有找到\n");
		return -1;
	}

}
//根据位置求地址
Node* Indexfindadderss(List list, int index) {
	int length = Getlength(list);
	if (index > length || index < 0) {
		printf("超范围\n");
	}
	Node* p = list->next;
	++index;
	while (--index || p != list) {
		p = p->next;
	}
	if (index == 0) {
		return p;
	}
	else {
		printf("没有找到\n");
		return NULL;
	}

}
//增加元素
int Adddata(List list, int index, int data) {
	int  f = Indexfinddata(list, index);
	if (f==-1) {
		printf("无法增加\n");
		return -1;
	}
	else {
		Node* now = (Node*)malloc(sizeof(Node));
		now->data = data;
		Node* prior = Indexfindadderss(list, index - 1);//上一个结点
		prior->next->pion = now;
		now->next = prior->next;
		prior->next = now;
		now->pion = prior;
		return 1;
	}
}
//删除元素
int Deteldata(List list, int index) {
	int  f = Indexfinddata(list, index);
	if (f == -1) {
		printf("无法增加\n");
		return -1;
	}
	else {
		Node* now = Indexfindadderss(list, index);
		now->pion->next = now->next;
		now->next->pion = now->pion;
		return 1;
	}
}
//修改元素
int Alterdata(List list, int index, int data) {
	int  f = Indexfinddata(list, index);
	if (f == -1) {
		printf("无法增加\n");
		return -1;
	}
	else {
		Node* now = Indexfindadderss(list, index);
		now->data = data;
		return 1;
	}
}
//修改元素位置
int Alterdataindex(List list, int oldindex, int newindex) {
		int  f = Indexfinddata(list, oldindex);
		if (f == -1||newindex>Getlength(list)+1||newindex<1) {
			printf("无法增加\n");
			return -1;
		}
		else {
			Node* old = Indexfindadderss(list, oldindex);
			old->pion->next = old->next;
			old->next->pion = old->pion;
			Node* new = Indexfindadderss(list, oldindex);
			new->pion = old;
			old->pion = new->pion;
			old->next = new;
			new->pion = old;
			return 1;
		}
}
//头插法
void Haedinput(List list) {
	printf("请输入要插入的个数\n");
	int n = 0;
	scanf("%d",&n);
	Node* new = (Node* )malloc(sizeof(Node));
	
	printf("请输入元素\n");
	scanf("%d",&new->data);
	list->next = new;
	new->pion = list;
	new->next = list;
	--n;
	do
	{
		new = (Node*)malloc(sizeof(Node));
		printf("请输入元素\n");
		scanf("%d", &new->data);
		list->next->pion = new;
		new->next = list->next;
		list->next = new;
		new->pion = list;

	} while (--n);
	//old = NULL;
	new = NULL;

}

//尾插法
void Tailinput(List list) {
	printf("请输入要插入的个数\n");
	int n = 0;
	scanf("%d", &n);
	Node* new = (Node*)malloc(sizeof(Node));
	Node* old  = list;
	
	do
	{
		new = (Node*)malloc(sizeof(Node));
		printf("请输入元素\n");
		scanf("%d", &new->data);
		old->next = new;
		new->pion = old;
		new->next = old;
		old = new;
	} while (--n);
	old = NULL;
	new = NULL;
}
