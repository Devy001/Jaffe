#include "net.h"

using namespace jaffe;

int main(){
	JNet<int> net;

	// ��ȡ�����ļ�����ʼ������
	net.Init("deploy.prototxt");

	return 0;
}