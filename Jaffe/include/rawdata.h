// huangshize 2016.03.28
// === rawdata.h ===
// SyncedMemory.hpp������������洢ԭʼ����
// û��ʵ��cpu������gpu���ݵ�ͬ��

#include <cstdlib>

// Ϊָ�뿪�ٿռ�
inline void MallocHost(void** ptr, size_t size)
{
	*ptr = malloc(size);
}
// ���տռ�
inline void FreeHost(void* ptr)
{
	free(ptr);
}

class RawData {
public:
	RawData() : data_ptr_(NULL), size_(0), own_data_(false){}
	RawData(size_t size) : data_ptr_(NULL), size_(size), own_data_(false) {}
	~RawData();

	// ����RawData�����ݵĴ�С
	size_t size() { return size_; }
	//
	bool own_data() { return own_data_; }
	// ��ȡdata��ָ��
	const void* data();  
	void* mutable_data();

	void setdata(void* data);
	

	
private:
	void new_data();

	void* data_ptr_;
	size_t size_;
	bool own_data_;
};