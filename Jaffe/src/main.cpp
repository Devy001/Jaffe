#include <iostream>

#include "Net.h"

using namespace std;

int main(){
	Net net;

	// ��ȡ�����ļ�����ʼ������
	if(!net.SetFilePath("train_val.prototxt"))
		cout << "Failed to Read Net Parameter" << endl;
	net.Init();

	return 0;
}