#include "net_param.h"

namespace jaffe {

	bool NPisleft(char c){
		return c == '{';
	}

	bool NPisright(char c){
		return c == '}';
	}

	bool JNetParameter::ReadParamFromText(){
		// ���ļ�
		ifstream fin;
		fin.open(m_filepath);
		if (!fin.is_open()){
			cout << "Failed to Open Net Parameter Prototxt" << endl;
			return false;
		}

		// ���ж�ȡ����
		string line;
		bool enter_layer = false;
		int idex = 0;
		int left = 0;
		string str_temp = "";
		int i_temp = 0;
		vector<string> layer_param_temp;
		while (getline(fin, line)){
			// ��ֹͬһ layer �и����λ����ͬ����������
			if (!enter_layer){
				matchString(line, "name:", &m_name);

				if (matchString(line, "input:", &str_temp)){
					m_input.push_back(str_temp);
				}

				if (line.find("input_shape:") != string::npos){
					//������
				}

				if (matchInt(line, "input_dim:", &i_temp)){
					m_input_dim.push_back(i_temp);
				}

				matchBool(line, "force_backward:", 
					&m_force_backward);

				if (line.find("state:") != string::npos){
					//������
				}

				matchBool(line, "debug_info:", &m_debug_info);
				
				if (line.find("layer") != string::npos){
					enter_layer = true;
					m_layer_num++;
					if (line.find("{") != string::npos)
						left += count_if(line.begin(), 
						line.end(), NPisleft);
					continue;
				}
			}
			// ���� layer ����
			else{
				layer_param_temp.push_back(line);
				if (line.find("{") != string::npos)
					left += count_if(line.begin(), line.end(), NPisleft);
				if (line.find("}") != string::npos)
					left -= count_if(line.begin(), line.end(), NPisright);
				if (left == 0){
					layer_param_temp.pop_back();//���һ����}����Ҫ����Ϊ��һ��"{"ûҪ
					m_layers_param.push_back(layer_param_temp);//�� layer �������� layers_param �� 
					layer_param_temp.clear();
					enter_layer = false;
				}
			}
		}

		fin.close();
		return true;
	}
} // namespace jaffe