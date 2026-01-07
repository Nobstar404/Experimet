#pragma once

template<typename T, size_t S>
class Vector
{
public:
	Vector()
		: m_Data[0], count(0)
	{};

	void PushBack() 
	{

	};
	
	void GetSize() { return count; }

private:
	T* m_Data[S] = nullptr;
	size_t count;
};