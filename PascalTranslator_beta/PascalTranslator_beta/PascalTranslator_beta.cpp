// PascalTranslator_beta.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include "expression_analysis.h"
#include "begin_stack_end.h"


int main(){
	begin_stack_end* _d = new begin_stack_end;
	(*_d).PutVariable(const_cast<char*>("VAR"), data_stack::intd);
	(*_d).PutVariable(const_cast<char*>("abcd"), data_stack::doubled);
	(*_d).PutVariable(const_cast<char*>("j"), data_stack::doubled);
	(*_d).PutVariable(const_cast<char*>("jas"), data_stack::doubled);
	expression_analysis _t(_d);

	_t.PutCodeText(const_cast<char*>("VAR=:((((2+4)+abcd)/j)+(abcd+7));"));
	_t.FindNewExpression();

	//((1+2)+(3+4)) - 2-pb   3-op  (razn = 1)  6 - brk
	//((1+2)+(3+4)+(5+6)) -  3-pb  5-op (razn = 2)  8 - brk
	//((1+2)+(3+4)+(5+6)+(7+8)) -  4-pb   7-op (razn = 3)  10 - brk
	//((1+2)+(3+4)+(5+6)+(7+8)+(9-2)) -  5-pb   9-op (razn = 4) 12 - brk

	std::cout << _t.ExpressionCheck() << '\n';

	delete _d;
	_d = NULL;

	system("PAUSE");
    return 0;
}

