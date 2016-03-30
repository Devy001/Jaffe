#include "net.h"

namespace jaffe {

	template <typename Dtype>
	bool JNet<Dtype>::Init(const string filename){
		SetFilePath(filename);

		// �������� layer �� type ������ͳ�Ʋ�ͬ���� layer ����
		for (int i = 0; i < m_param->GetLayerNum(); i++){
			JLayer<Dtype> layer_param_temp;
			layer_param_temp.SetSharedParam(
				m_param->GetLayerParam(i));
			if (layer_param_temp.GetType() == "Data")
				m_data_layer_num++;
			if (layer_param_temp.GetType() == "Convolution")
				m_convolution_layer_num++;
		}

		// Ϊ���в�ͬ���� layer �����ڴ�ռ�
		m_convolution_layers = new JConvolutionLayer<Dtype>[m_convolution_layer_num];
		m_data_layers = new JDataLayer<Dtype>[m_data_layer_num];
		m_pooling_layers = new JPoolingLayer<Dtype>[m_pooling_layer_num];

		// �ֱ��������� layer �Ĳ���
		int i_convolution_layer_idex = 0;
		int i_data_layer_idex = 0;
		int i_pooling_layer_idex = 0;
		for (int i = 0; i < m_param->GetLayerNum(); i++){
			JLayer layer_param_temp;
			layer_param_temp.SetSharedParam(
				m_param->GetLayerParam(i));
			if (layer_param_temp.GetType() == "Data"){
				m_data_layers[i_data_layer_idex].Init(
					m_param->GetLayerParam(i));
				m_layers.push_back(
					&m_data_layers[i_data_layer_idex]);
				i_data_layer_idex++;
			}
			if (layer_param_temp.GetType() == "Convolution"){
				m_convolution_layers[i_convolution_layer_idex].Init(
					m_param->GetLayerParam(i));
				m_layers.push_back(
					&m_convolution_layers[i_convolution_layer_idex]);
				i_convolution_layer_idex++;
			}
			if (layer_param_temp.GetType() == "Pooling"){
				m_pooling_layers[i_pooling_layer_idex].Init(
					m_param->GetLayerParam(i));
				m_layers.push_back(
					&m_pooling_layers[i_pooling_layer_idex]);
				i_pooling_layer_idex++;
			}
			//if (layer_param_temp.GetType() == "ReLU"){
			//	m_conv_layers[i_relu_layer_idex].Init(
			//		m_param->GetLayerParam(i));
			//	m_layers.push_back(
			//		&m_conv_layers[i_relu_layer_idex]);
			//	i_relu_layer_idex++;
			//}
			//if (layer_param_temp.GetType() == "LRN"){
			//	m_conv_layers[conv_layer_idex].Init(
			//		m_param->GetLayerParam(i));
			//	m_layers.push_back(
			//		&m_conv_layers[conv_layer_idex]);
			//	conv_layer_idex++;
			//}
			//if (layer_param_temp.GetType() == "InnerProduct"){
			//	m_conv_layers[conv_layer_idex].Init(
			//		m_param->GetLayerParam(i));
			//	m_layers.push_back(
			//		&m_conv_layers[conv_layer_idex]);
			//	conv_layer_idex++;
			//}
			//if (layer_param_temp.GetType() == "Dropout"){
			//	m_conv_layers[conv_layer_idex].Init(
			//		m_param->GetLayerParam(i));
			//	m_layers.push_back(
			//		&m_conv_layers[conv_layer_idex]);
			//	conv_layer_idex++;
			//}
			//if (layer_param_temp.GetType() == "Softmax"){
			//	m_conv_layers[conv_layer_idex].Init(
			//		m_param->GetLayerParam(i));
			//	m_layers.push_back(
			//		&m_conv_layers[conv_layer_idex]);
			//	conv_layer_idex++;
			//}
		}

		for (int i = 0; i < m_layers.size(); i++){
			m_layers.at(i)->Show();
		}

		return true;
	}

	template <typename Dtype>
	bool JNet<Dtype>::SetFilePath(const string filename){
		// ���ļ��ж�ȡ���� layer ����
		if (m_param->SetFilePath(filename))
			return true;

		cout << "Failed to Read Deploy Prototxt" << endl;
		return false;
	}
} // namespace jaffe