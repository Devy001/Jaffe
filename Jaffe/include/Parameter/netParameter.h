//Net ����ͷ�ļ�
#ifndef NETPARAMETER_H_H
#define NETPARAMETER_H_H

#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class NetParameter{
public:
	NetParameter(){
		this->layer_num = 0;
	};
	~NetParameter(){};
	// ���ò����ļ�·��
	bool SetFilePath(const string filepath){ 
		this->filepath = filepath; 
		return ReadParamFromText();
	};
	// ���ļ��ж�ȡ���� layer ����
	bool ReadParamFromText();

	int GetLayerNum(){ return this->layer_num; };
	// ����ָ������λ�õ�layer����
	vector<string> GetLayerParam(int idex){
		return this->layers_param[idex];
	}
private:
	string filepath; // �ļ�·��
	string name; // ���� name
	int layer_num; // �� net �� layer ������
	vector<vector<string>> layers_param;  // ���е� layer ����

	// ��ȡ����ʱʹ��������ʽƥ��
	bool match_s(const string line, const string key, string* s);
};

#endif