#include <iostream>

#include "net.h"

using std::cin;
using namespace jaffe;

int main(){

	JNet<int> net;
	// ��ȡ�����ļ�����ʼ������
	net.Init("train_val.prototxt");

	cin.get();
	
	return 0;
}