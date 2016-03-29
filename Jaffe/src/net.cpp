#include <iostream>
#include <fstream>

#include "net.h"

namespace jaffe {

	bool JNet::Init(){
		// �������� layer �� type ������ͳ�Ʋ�ͬ���� layer ����
		for (int i = 0; i < m_parameter->GetLayerNum(); i++){
			JLayer layer_param_temp;
			layer_param_temp.SetSharedParam(
				m_parameter->GetLayerParam(i));
			if (layer_param_temp.GetType() == "Data")
				m_data_layer_num++;
			if (layer_param_temp.GetType() == "Convolution")
				m_conv_layer_num++;
		}

		// Ϊ���в�ͬ���� layer �����ڴ�ռ�
		m_conv_layers = new JConvolutionLayer[m_conv_layer_num];
		m_data_layers = new JDataLayer[m_data_layer_num];

		// �ֱ��������� layer �Ĳ���
		int conv_layer_idex = 0;
		int data_layer_idex = 0;
		for (int i = 0; i < m_parameter->GetLayerNum(); i++){
			JLayer layer_param_temp;
			layer_param_temp.SetSharedParam(
				m_parameter->GetLayerParam(i));
			if (layer_param_temp.GetType() == "Data"){
				m_data_layers[data_layer_idex].SetParam(
					m_parameter->GetLayerParam(i));
				m_layers.push_back(
					&m_data_layers[data_layer_idex]);
				data_layer_idex++;
			}
			if (layer_param_temp.GetType() == "Convolution"){
				m_conv_layers[conv_layer_idex].SetParam(
					m_parameter->GetLayerParam(i));
				m_layers.push_back(
					&m_conv_layers[conv_layer_idex]);
				conv_layer_idex++;
			}
		}

		//m_layers.at(0)->Show();
		//m_layers.at(1)->Show();
		//m_layers.at(2)->Show();
		//m_layers.at(3)->Show();
		//m_layers.at(4)->Show();

		return  true;
	}

	bool JNet::SetFilePath(const string filename){
		// ���ļ��ж�ȡ���� layer ����
		if (m_parameter->SetFilePath(filename))
			return true;

		return false;
	}
} // namespace jaffe