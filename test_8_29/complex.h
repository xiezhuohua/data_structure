#pragma once
#include<stdio.h>
//����һ�������ṹ��
typedef struct {
	float real;
	float imaginary;
}Complex;
//��������ĸ���
void Scanfcomplex(Complex* p,float real,float imaginary);

//�ӷ�
Complex Addition(Complex* p, Complex* q);
//����
Complex Subtraction(Complex* p, Complex* q);
//�˷�
Complex multiplication(Complex* p, Complex* q);
//����
Complex Division(Complex* p, Complex* q);