#pragma once

/*
 * The DoubleBuffer class attempts to abstract the complexities
 * of having two buffers out of the classes that require it.
 *
 * The template type is the structure that requires double buffering.
 */
template <typename Type>
class DoubleBuffer
{
private:
	Type data[2];
	bool usingFirst;
public:
	DoubleBuffer() : usingFirst(true)
	{
	}

	const Type& get() const
	{
		return data[usingFirst];
	}
	Type& set()
	{
		return data[!usingFirst];
	}
	void swap()
	{
		usingFirst = !usingFirst;
	}
};