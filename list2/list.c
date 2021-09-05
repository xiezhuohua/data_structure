#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"

// ��������
List* Creatlist() {
	List* list = (List*)malloc(sizeof(List));
	list->head = (Node*)malloc(sizeof(Node));
	return list;
}
//�����ʼ��
void Initlist(List* list) {
	list->length = 0;
	list->head->data = 0;
	list->head->next = NULL;
}
//ͷ�巨
int Headinsert(List* list) {
	int n = 0;
	printf("��������Ҫ����Ԫ�صĸ���\n");
	scanf("%d", &n);
	
	Node* oldnode = (Node*)malloc(sizeof(Node));
	printf("������Ԫ��\n");
	scanf("%d",&oldnode->data);
	--n;
	++(list->length);
	oldnode->next = NULL;
	list->head->next = oldnode;//��ͷ���ָ��ָ�����һ�����
	
	
	while (--n) {
		
		Node* newnode = (Node*)malloc(sizeof(Node));
		printf("������Ԫ��\n");
		scanf("%d", &newnode->data);
		newnode->next = list->head->next;//���½��ָ����ָ��ɽ��
		list->head->next = newnode;//��ͷ���ָ����ָ���½��
		oldnode = newnode;//�½�㸳ֵ���ɽ���Ա���һ�Σ��½�����¿���
		++(list->length);
		if (n == 0) {
			oldnode->next = NULL;//�����һ������ָ�븳ֵΪ��
			oldnode = NULL;
			newnode = NULL;
		}
	}
	return 1;
}
	
//β�巨
int Tailinsert(List* list) {
	int n = 0;
	printf("��������Ҫ����Ԫ�صĸ���\n");
	scanf("%d", &n);

	Node* oldnode = (Node*)malloc(sizeof(Node));
	printf("������Ԫ��\n");
	scanf("%d", &oldnode->data);
	--n;
	++(list->length);
	list->head->next = oldnode;//��ͷ���ָ��ָ�����һ�����
	while (--n) {
		Node* newnode = (Node*)malloc(sizeof(Node));
		printf("������Ԫ��\n");
		scanf("%d", &newnode->data);
		oldnode->next = newnode;//ǰһ������ָ�����¼�½���ַ
		oldnode = newnode;//�½�㸳ֵ���ɽ���Ա���һ�Σ��½�����¿���
		++(list->length);
		if (n==0) {
			oldnode->next = NULL;//�����һ������ָ�븳ֵΪ��
			oldnode = NULL;
			newnode = NULL;
		}
	}
	return 1;
}
//�ж��Ƿ��ǿ�����
int Ifempty(List* list) {
	if (list->head->next == NULL || list->length == 0) {
		printf("�ǿձ�\n");
		return 1;
	}
	else {
		printf("������\n");
		return 0;
	}
}
//�������
void Clearlist(List* list) {
	Node* p = NULL;
	p = list->head->next;//��ָ���¼��Ԫ���
	while (p != NULL) {
		list->head = p->next;//��ͷָ����һ���
		free(p);
		p = list->head;//����һ����ַ��ֵ��p��
	}
	list->length = 0;
}
//���
int Getlength(List* list) {
	return list->length;
}
//��������
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
//����Ԫ�ز���λ��
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
	printf("δ�ҵ�\n");
	return 0;
}
//����Ԫ�ز��ҵ�ַ
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
	printf("δ�ҵ�\n");
	return NULL;
}
//����λ�ò���Ԫ��
int Indexfinddata(List* list, int index) {
	if (index > list->length || index <= 0) {
		printf("λ�ó�����Χ\n");
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
//����λ�ò���Ԫ�ص�ַ
Node* Indexfindadderss(List* list, int index) {
	if (index > list->length || index <0) {
		printf("λ�ó�����Χ\n");
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
//����Ԫ��
int Addnode(List* list, int index, int data) {
	if (index <= 0 || index > list->length + 1) {
		printf("������Χ\n");
		return 0;
	}
	else {
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->data = data;
		newnode->next = NULL;

		Node* oldnode = NULL;//ǰһ�����ĵ�ַ
		oldnode = Indexfindadderss(list, index - 1);
		newnode->next = oldnode->next;
		oldnode->next = newnode;
		++list->length;
		return 1;
	}
}

//ɾ��Ԫ��
int Deletnode(List* list, int index) {
	if (index <= 0 || index > list->length ) {
		printf("������Χ\n");
		return 0;
	}
	else {
		Node* persentnode = NULL;
		Node* oldnode = NULL;//ǰһ�����ĵ�ַ
		oldnode = Indexfindadderss(list, index - 1);
		persentnode = Indexfindadderss(list, index);
		oldnode->next = persentnode->next;
		free(persentnode);
		persentnode = NULL;
		return 1;
	}
}
//����λ���޸�Ԫ������
int Alternodedata(List* list, int index, int data) {
	if (index <= 0 || index > list->length ) {
		printf("������Χ\n");
		return 0;
	}
	else {
		Node* persentnode = NULL;
		persentnode = Indexfindadderss(list, index);
		persentnode->data = data;
		return 1;
	}
	
}
//����λ���޸�Ԫ��λ��
int Alternodeindex(List* list, int oldindex, int newindex) {
	if ((oldindex <= 0 || oldindex > list->length)||(newindex <= 0 || newindex > list->length+1)) {
		printf("������Χ\n");
		return 0;
	}
	else {
		Node* persentnode = NULL;
		Node* oldnode = NULL;
		persentnode = Indexfindadderss(list, oldindex);
		oldnode = Indexfindadderss(list, oldindex - 1);//Ҫ�ҵ�ǰһ�����
		oldnode->next = persentnode->next;
		oldnode = Indexfindadderss(list, newindex - 1);
		persentnode->next = oldnode->next;
		oldnode->next = persentnode->next;
		return 1;	
	}
}
//��ӡ��������Ԫ��
void printflist(List* list) {
	Node* p = list->head->next;
	int n = 1;
	while (p) {
		printf("��%d������Ԫ�أ�%d  \n",n,p->data);
		++n;
		p = p->next;
	}
}
