#include <iostream>

#include "net.h"

using namespace jaffe;
using std::cout;
using std::string;
using std::endl;

int main(){
	JNet net;

	// ��ȡ�����ļ�����ʼ������
	if(!net.SetFilePath("train_val.prototxt"))
		cout << "Failed to Read Net Parameter" << endl;
	net.Init();

	return 0;
}