// huangshize 2016.03.28

#include <string>
#include <vector>
//#include "math_functions.h"
namespace jaffe {

	template <typename DataType>
	class BLob
	{
	public:
		// ���캯��
		BLob() : data_(), diff_(), count_(0), capacity_(0) {}
		explicit Blob(const int num, const int channels, const int height,
			const int width);
		explicit Blob(const vector<int>& shape);
		// ��������
		~BLob();

		//  Reshape
		void Reshape(const int num, const int channels, const int height,
			const int width);
		void Reshape(const vector<int>& shape);
		
		//
		inline const vector<int>& shape() const { return shape_; }
		// �����index��ά�ȵ�ά����֧��indexС��0���������
		inline int shape(int index) const
		{
			return shape_[CannonicalAxisIndex(index)];
		}
		inline int CannonicalAxisIndex(int axis_index) const
		{
			if (axis_index < 0)
			{
				return axis_index + num_axes();
			}
			return axis_index;
		}
		// ��ȡ����ָ��ά�ȵ�ά��
		inline int num() const { return shape(0); }
		inline int channels() const { return shape(1); }
		inline int height() const { return shape(2); }
		inline int width() const { return shape(3); }

		inline int num_axes() const { return shape_.size(); }
		inline int count() const { return count_; }
		inline int count(int start_axis, int end_axis) const
		{
			// ��Ҫ�ж�index��Χ
			int count = 1;
			for (int i = start_axis; i < end_axis; i++)
			{
				count *= shape(i);
			}
			return count;
		}
		inline int count(int start_axis) const
		{
			// ��Ҫ�ж�index��Χ
			return count(start_axis, num_axes());
		}

		// offset ƫ����
		inline int offset(const int n, const int c = 0, const int h = 0,
			const int w = 0) const
		{
			// ��Ҫ�ж�n c h w �Ĵ�С��û�г�����Χ
			return ((n * channels() + c) * height() + h) * width() + w;
		}

		inline int offset(const vector<int>& indices) const
		{
			int offset = 0;
			for (int i = 0; i < num_axes(); i++)
			{
				offset *= shape(i);
				if (indices.size() > i)
				{
					offset += indices[i]
				}
			}
			return offset;
		}

		void CopyFrom(const Blob<DataType>& source, bool copy_diff = false, bool reshape = false);

		// ͨ��offsetƫ�������������
		inline DataType data_at(const int n, const int c, const int h, const int w) const
		{
			return data()[offset(n, c, h, w)];
		}

		inline DataType diff_at(const int n, const int c, const int h, const int w) const
		{
			return diff()[offset(n, c, h, w)];
		}

		inline DataType data_at(const vector<int>& index) const
		{
			return data()[offset(index)];
		}

		inline DataType diff_at(const vector<int>& index) const
		{
			return diff()[offset(index)];
		}

		inline const shared_ptr<RawData>& blob_data() const
		{
			return data_; 
		}
		inline const shared_ptr<RawData>& blob_diff() const
		{
			return diff_;
		}

		//
		const DataType* data() const;	// ԭblob.hpp�е�cpu_data() / gpu_data()
		const DataType* diff() const;	// ԭblob.hpp�е�cpu_diff() / gpu_diff()
		DataType* mutable_data();
		DataType* mutable_diff();

		void setdata(DataType* data);

		void Update();
		// void FromProto(..)
		// void ToProto(..)

		// �ֱ����data��diff�ľ���ֵ֮���Լ�ƽ��֮��
		DataType asum_data() const;
		DataType asum_diff() const;
		DataType sumsq_data() const;
		DataType sumsq_diff() const;

		// �漰cblas��������
		void scale_data(DataType scale_factor);
		void scale_diff(DataType scale_factor);

		//
		void ShareData(const Blob& other);
		void ShareDiff(const Blob& other);
		
		//bool ShapeEquals(const BlobProto& other);

	protected:
		shared_ptr<RawData> data_;
		shared_ptr<RawData> diff_;
		shared_ptr<RawData> shape_data_;
		vector<int> shape_;
		int count_;
		int capacity_;  // ����  ��ʱ����
	private:

	};



}