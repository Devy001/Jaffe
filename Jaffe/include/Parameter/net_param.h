//Net ����ͷ�ļ�
#ifndef NET_PARAM_H_H
#define NET_PARAM_H_H

#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "jmatch.h"

using std::string; 
using std::cout;
using std::vector;
using std::ifstream;
using std::endl;

namespace jaffe {

	class NetParameter{
	public:
		NetParameter(){
			this->layer_num = 0;
		};
		~NetParameter(){};
		// ���ò����ļ�·��
		bool setFilePath(const string filepath){
			this->filepath = filepath;
			return readParamFromText();
		};
		// ���ļ��ж�ȡ���� layer ����
		bool readParamFromText();

		int getLayerNum(){ return this->layer_num; };
		// ����ָ������λ�õ�layer����
		vector<string> getLayerParam(int idex){
			return this->layers_param[idex];
		}
	private:
		string filepath; // �ļ�·��
		string name; // ���� name
		int layer_num; // �� net �� layer ������
		vector<vector<string>> layers_param;  // ���е� layer ����

		// ��ȡ����ʱʹ��������ʽƥ��
		//bool matchString(const string line, const string key, string* s);
	};
}

#endif