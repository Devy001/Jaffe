#ifndef NET_H_H
#define NET_H_H

#include <string>
#include <vector>

#include "layer.h"
#include "vision_layers.h"
#include "net_param.h"
#include "data_layers.h"

using namespace std;

class Net{
public:
	Net(){
		parameter = new NetParameter;
		this->data_layer_num = 0;
		this->conv_layer_num = 0;
	};
	~Net(){
		if (this->conv_layer_num)
			delete[] this->conv_layers;
		delete [] parameter;
	};
	bool init();	// �ֱ������ layer �����ò���
	bool setFilePath(const string filename); // һ���Զ������в���
	//void Info();
	NetParameter getParame(){ return *this->parameter; };
private:
	vector<Layer*> layers;

	int data_layer_num;
	DataLayer* data_layers;

	int conv_layer_num;
	ConvolutionLayer* conv_layers;

	NetParameter* parameter;
};
#endif