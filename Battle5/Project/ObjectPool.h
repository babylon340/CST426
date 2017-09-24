#pragma once
#include <stack>

/*
 * ObjectPool allocates a "sufficiently large," as defined by the user, buffer
 * of bytes ahead of time and makes use placement new to minimise the overhead
 * of constructing items while still maintaining the benefits of using constructors.
 *
 * ObjectPool does not guarantee that objects are stored sequentially, nor does
 * it guard against deconstructing an already deconstructed object. 
 *
 * If the user attempts to obtain a new object when the pool is full,
 * a null pointer is returned instead.
 *
 * ObjectPool does not clean up still-existing objects. It is up to the user
 * to make sure ObjectPool is clean before it is destroyed.
 */
template <typename Type>
class ObjectPool
{
private:
	void* bytearray;
	std::stack<unsigned int> available;
	unsigned int size;
public:
	ObjectPool(unsigned int size) : bytearray(new char[sizeof(Type) * size]),
		size(size)
	{
		for (unsigned int i = size - 1; i > 0; --i)
		{
			available.push(i);
		}
		available.push(0);
	}
	~ObjectPool()
	{
		delete[] bytearray;
	}

	template <typename... Args>
	Type* Create(Args... params)
	{
		if (available.size() == 0)
		{
			return nullptr; //out of memory
		}

		unsigned int id = available.top();
		Type* ptr = reinterpret_cast<Type*>(id * sizeof(Type) + reinterpret_cast<unsigned int>(bytearray));
		new (ptr) Type(params...); //placement new
		available.pop();
		return ptr;
	}
	void Destroy(Type*& ptr)
	{
		if (available.size() != 0 &&
			reinterpret_cast<unsigned int>(ptr) >= reinterpret_cast<unsigned int>(bytearray) &&
			reinterpret_cast<unsigned int>(ptr) < (reinterpret_cast<unsigned int>(bytearray) + sizeof(Type) * size))
		{
			ptr->~Type();
			unsigned int id = (reinterpret_cast<unsigned int>(ptr) - reinterpret_cast<unsigned int>(bytearray)) / sizeof(Type);
			available.push(id);
			ptr = nullptr;
		}
	}

	unsigned int AvailableSpace() const
	{
		return available.size();
	}
};