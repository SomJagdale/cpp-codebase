 class smartPtr
{
	private:
	int *ptr;
	explicit smartPtr(int *ptrdata = NULL)
	{
		ptr = ptrdata;
	}
	~smartPtr()
	{
		delete ptr;		
	}
	
	int& operator*()()
	{
		return ptr;
	}
}
