#include <iostream>

#include "net.h"

using namespace jaffe;
using std::cout;
using std::string;
using std::endl;

int main(){
	JNet net;

	// ��ȡ�����ļ�����ʼ������
	net.Init("deploy.prototxt");

	return 0;
}