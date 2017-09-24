#include <iostream>

#include "../Project/DoubleBuffer.h"

//struct to use in the double buffering
struct Data
{
	float hp;

	struct
	{
		float x;
		float y;
	} pos, dir;
};

const char* stringify(bool input);
bool AssertEqual(float a, float b);

int main()
{
	std::cout << "Starting double buffer testing" << std::endl;
	DoubleBuffer<Data> bufferedData;

	std::cout << "Initializing both copies of data" << std::endl;
	bufferedData.set() =
	{
		10,
		{0, 0},
		{1, 1}
	};
	bufferedData.swap();
	bufferedData.set() =
	{
		10,
		{0, 0},
		{1, 1}
	};

	std::cout << "Confirming the settings in the gettable buffer" << std::endl;
	std::cout << "hp: " << stringify(AssertEqual(bufferedData.get().hp, 10)) << std::endl;
	std::cout << "pos.x: " << stringify(AssertEqual(bufferedData.get().pos.x, 0)) << std::endl;
	std::cout << "pos.y: " << stringify(AssertEqual(bufferedData.get().pos.y, 0)) << std::endl;
	std::cout << "dir.x: " << stringify(AssertEqual(bufferedData.get().dir.x, 1)) << std::endl;
	std::cout << "dir.y: " << stringify(AssertEqual(bufferedData.get().dir.y, 1)) << std::endl;

	std::cout << "Changing values in the buffer" << std::endl;
	bufferedData.set().hp = 20;
	bufferedData.set().pos.x = 2;
	bufferedData.set().pos.y = 1;
	bufferedData.set().dir.x = -1;
	bufferedData.set().dir.y = 1.25;

	std::cout << "Confirming the settings have not affected the visible values" << std::endl;
	std::cout << "hp: " << stringify(AssertEqual(bufferedData.get().hp, 10)) << std::endl;
	std::cout << "pos.x: " << stringify(AssertEqual(bufferedData.get().pos.x, 0)) << std::endl;
	std::cout << "pos.y: " << stringify(AssertEqual(bufferedData.get().pos.y, 0)) << std::endl;
	std::cout << "dir.x: " << stringify(AssertEqual(bufferedData.get().dir.x, 1)) << std::endl;
	std::cout << "dir.y: " << stringify(AssertEqual(bufferedData.get().dir.y, 1)) << std::endl;

	std::cout << "Swapping buffers" << std::endl;
	bufferedData.swap();

	std::cout << "Confirming the settings have updated" << std::endl;
	std::cout << "hp: " << stringify(AssertEqual(bufferedData.get().hp, 20)) << std::endl;
	std::cout << "pos.x: " << stringify(AssertEqual(bufferedData.get().pos.x, 2)) << std::endl;
	std::cout << "pos.y: " << stringify(AssertEqual(bufferedData.get().pos.y, 1)) << std::endl;
	std::cout << "dir.x: " << stringify(AssertEqual(bufferedData.get().dir.x, -1)) << std::endl;
	std::cout << "dir.y: " << stringify(AssertEqual(bufferedData.get().dir.y, 1.25)) << std::endl;

	system("pause");
	return 0;
}

const char* stringify(bool input)
{
	return input ? "True" : "False";
}
bool AssertEqual(float a, float b)
{
	return a == b;
}