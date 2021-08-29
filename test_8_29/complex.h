#pragma once
#include<stdio.h>
//定义一个复数结构体
typedef struct {
	float real;
	float imaginary;
}Complex;
//输入所需的复数
void Scanfcomplex(Complex* p,float real,float imaginary);

//加法
Complex Addition(Complex* p, Complex* q);
//减法
Complex Subtraction(Complex* p, Complex* q);
//乘法
Complex multiplication(Complex* p, Complex* q);
//除法
Complex Division(Complex* p, Complex* q);