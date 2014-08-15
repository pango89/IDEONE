#include<iostream>
using namespace std;
template<class T>
class SmartPointer
{
	T* ref;
	unsigned int* ref_count;
	public:
		SmartPointer(T* obj)
		{
			ref=obj;
			ref_count=(unsigned int*)malloc(sizeof(unsigned int));
			*ref_count=1;
		}
		SmartPointer(SmartPointer<T>& sptr)
		{
			ref=sptr.ref;
			ref_count=sptr.ref_count;
			(*ref_count)++;
		}
		SmartPointer<T>& operator=(SmartPointer<T>& sptr)
		{
			/* IF ALREADY ASSIGNED TO AN OBJECT, REMOVE ONE REFERENCE. */
			if(this==&sptr)
				return *this;
			if(*ref_count>0)
				remove();
			ref = sptr.ref;
			ref_count = sptr.ref_count;
			++(*ref_count);
			return *this;
		}
		~SmartPointer()
		{
			remove();
		}
	protected:
		void remove()
		{
			(*ref_count)--;
			if(*ref_count==0)
			{
				delete ref;
				free(ref_count);
				ref=NULL:
				ref_count=NULL:
			}
		}
};
int main()
{
	//Create objects of SmartPointer 
	return 0;
}