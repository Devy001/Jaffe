//Net 参数头文件
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

	class JNetParameter{
	public:
		JNetParameter(){
			m_layer_num = 0;
		};
		~JNetParameter(){};
		// 设置参数文件路径
		bool SetFilePath(const string filepath){
			m_filepath = filepath;
			return ReadParamFromText();
		};
		// 从文件中读取所有 layer 参数
		bool ReadParamFromText();

		int GetLayerNum(){ return m_layer_num; };
		// 返回指定索引位置的layer参数
		vector<string> GetLayerParam(int idex){
			return m_layers_param[idex];
		}
	private:
		string m_filepath; // 文件路径
		string m_name; // 参数 name
		int m_layer_num; // 该 net 中 layer 的数量
		vector<vector<string>> m_layers_param;  // 所有的 layer 参数

		// 读取参数时使用正则表达式匹配
		//bool matchString(const string line, const string key, string* s);
	};
}

#endif