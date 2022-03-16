//Nick Krisulevicz
//COSC 320 - Lab 04
//03/04/2022
//lab_04.cpp

#include "d_tnode.h"
#include "d_tnodel.h"
#include "d_except.h"
#include "d_expsym.h"
#include "inf2pstf.h"
#include "buildExpTree.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void prefixOutput(tnode<char> *exp);

int main(){
	string tree1 = "a*b";
	string tree2 = "a+b*c";
	string tree3 = "a+b*c/d-e";
	
	infix2Postfix inf1 = infix2Postfix(tree1);
	infix2Postfix inf2 = infix2Postfix(tree2);
	infix2Postfix inf3 = infix2Postfix(tree3);

	tnode<char> *bt1 = buildExpTree(inf1.postfix());
	tnode<char> *bt2 = buildExpTree(inf2.postfix());
	tnode<char> *bt3 = buildExpTree(inf3.postfix());

	cout << "Binary tree 1:" << endl;
	prefixOutput(bt1);
	cout << endl;

	cout << "Binary tree 2:" << endl;
	prefixOutput(bt2);
	cout << endl;

	cout << "Binary tree 3:" << endl;
	prefixOutput(bt3);
	cout << endl;

	cout << "--------------------" << endl;

	cout << "Post order of binary tree 1:" << endl;
	postorderOutput(bt1, " ");
	cout << endl;

	cout << "Post order of binary tree 2:" << endl;
	postorderOutput(bt2, " ");
	cout << endl;

	cout << "Post order output of binary tree 3:" << endl;
	postorderOutput(bt3, " ");
	cout << endl;

	cout << "--------------------" << endl;

	cout << "Tree 1:" << endl;
	displayTree(bt1, 1);
	cout << endl;

	cout << "Tree 2:" << endl;
	displayTree(bt2, 1);
	cout << endl;

	cout << "Tree 3:" << endl;
	displayTree(bt3, 1);
	cout << endl;

	return 0;
}

void prefixOutput(tnode<char> *exp){
	if (!exp){
		return;
	}
	cout << " " << exp->nodeValue;
	prefixOutput(exp->left);
	prefixOutput(exp->right);
}
