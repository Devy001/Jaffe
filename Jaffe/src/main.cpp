#include <iostream>

#include "net.h"

using namespace jaffe;
using std::cout;
using std::string;
using std::endl;

int main(){
	Net net;

	// ��ȡ�����ļ�����ʼ������
	if(!net.setFilePath("train_val.prototxt"))
		cout << "Failed to Read Net Parameter" << endl;
	net.init();

	return 0;
}