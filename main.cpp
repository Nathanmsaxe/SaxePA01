/*
 * main.cpp
 *
 *  Created on: Aug 23, 2022
 *      Author: Nathan Saxe
 */

#include <iostream>
#include <string>

using namespace std;

struct Student{
	string studentName;

	int studentID;
};
struct LLnode{

	LLnode * fwdPtr;

	Student theData;
};

void push_front(LLnode*&, Student);
void push_back(LLnode*&, Student);
int list_length(LLnode*);
Student retrieve_front(LLnode*);
Student retrieve_back(LLnode*);
void display_nodes(LLnode*);


int main() {
//cout << "TEST" << endl;
	LLnode * theLLHeader1 = nullptr;

	Student temp;
	temp.studentName = "student1";
	temp.studentID = 11111;
	cout << "Main:  number of nodes in empty list " << list_length(theLLHeader1) << endl;
	cout << "Main:  contents of LL1 nodes" << endl;
	display_nodes(theLLHeader1);

	push_front (theLLHeader1, temp);

//	push_front (theLLHeader2, {"Charlie",78901});	// not all compilers support this
	cout << "Main:  number of nodes in list after 1 push - " << list_length(theLLHeader1) << endl;
	cout << "Main:  contents of list after 1 push " << endl;
	display_nodes(theLLHeader1);
	temp.studentName = "student2";
	temp.studentID = 22222;
	push_back (theLLHeader1, temp);
	temp.studentName = "student3";
	temp.studentID = 33333;
	push_front (theLLHeader1, temp);
	temp.studentName = "student4";
	temp.studentID = 44444;
	push_back (theLLHeader1, temp);
	cout << "Main:  number of nodes after 4 pushes - " << list_length(theLLHeader1) << endl;
	cout << "Main:  contents of list after 4 pushes " << endl;
	display_nodes (theLLHeader1);
	temp = retrieve_front(theLLHeader1);
	cout << "Main:  retrieve front: " << temp.studentName << " " << temp.studentID << endl;
	temp = retrieve_back(theLLHeader1);
	cout << "Main:  retrieve back: " << temp.studentName << " " << temp.studentID << endl;
	cout << endl;

	LLnode * theLLHeader2 = nullptr;
	temp.studentName = "Adam";
	temp.studentID = 15555;
	push_front (theLLHeader2, temp);
	temp.studentName = "Betty";
	temp.studentID = 25555;
	push_front (theLLHeader2, temp);
	temp.studentName = "Charlie";
	temp.studentID = 35555;
	push_front (theLLHeader2, temp);
	temp.studentName = "Donna";
	temp.studentID = 45555;
	push_back (theLLHeader2, temp);
	temp.studentName = "Earnie";
	temp.studentID = 55555;
	push_back (theLLHeader2, temp);
	temp.studentName = "Felicity";
	temp.studentID = 65555;
	push_back (theLLHeader2, temp);
	cout << "Main:  contents of LL2 nodes" << endl;
	display_nodes (theLLHeader2);

	return 0;
}

int list_length(LLnode * p){
	int counter = 0;
	if(p!=nullptr){
		while(p != nullptr){
			counter++;
			p = p->fwdPtr;
		}
	}
	else{
		return counter;
	}

	return counter;

}

void push_front(LLnode * &llh, Student data){
	LLnode * newNode = new LLnode;
	LLnode * temp = llh;
	newNode->theData = data;
	newNode->fwdPtr = temp;
	llh = newNode;

}
void push_back(LLnode * &llh, Student data){
	LLnode* newNode = new LLnode;

	newNode->theData = data;

	newNode->fwdPtr = nullptr;

	if(llh == nullptr){
		llh = newNode;
	}
	else{
		LLnode *last = llh;
		while(last->fwdPtr!=nullptr){
			last = last->fwdPtr;
		}
		last->fwdPtr = newNode;
	}
}

Student retrieve_front(LLnode * p){
	if(p == nullptr){
		throw 'A';
	}
	else{
		return p->theData;
	}

}
Student retrieve_back(LLnode * p){
	while(p->fwdPtr!=nullptr){
		p = p->fwdPtr;
	}
	return p->theData;
}
void display_nodes(LLnode * p){
	int counter = 0;
		if(p!=nullptr){
			while(p != nullptr){
				counter++;
				cout << "node " << counter << " address -> " << p << " Student Name:" << p->theData.studentName << " Student ID: " << p->theData.studentID << endl;
				p = p->fwdPtr;
			}
		}
		else{
			cout << "Empty List" << endl;
		}
}
