// NovomaticTask1.cpp : Defines the entry point for the application.
//

#include "NovomaticTask1.h"
#include <vector>
#include <optional>
#include <array>
#include <string>
template<typename T>
struct Data {
	T value;

	uint8_t count;
};

constexpr size_t sizeX{ 7 };
constexpr size_t sizeY{ 3 };

template<typename T>
using Array2D = std::array < std::array<T, sizeX>, sizeY>;

template<typename T>
using CompressedDataArray = std::optional < std::vector<Data<T>> >;

template<typename T> 
CompressedDataArray<T> compressData(const Array2D<T>& input){

	size_t firstDim = 0;
	size_t secondDim = 0;
	CompressedDataArray<T> output;
	output = std::vector<Data<T>>();
	std::vector<Data<T>>& outputVector = *output;
	Data<T> countedData;
	countedData.value = NULL;
	countedData.count = 0;
	while (input.size() > firstDim)
	{
		
		while (input[firstDim].size() > secondDim)
		{
			//on new value or new row
			if (secondDim == 0)
			{
				countedData.value = input[firstDim][secondDim];
				countedData.count = 0;
			}
			if (countedData.value != input[firstDim][secondDim])
			{
				
				outputVector.push_back(Data<T>(countedData.value, countedData.count));				
				countedData.value = input[firstDim][secondDim];
				countedData.count = 0;
			}
			countedData.count++;
			secondDim++;
		}
		outputVector.push_back(Data<T>(countedData.value, countedData.count));
		countedData.value = 0;
		countedData.count = 0;
		secondDim = 0;
		firstDim++;
	}
	if (sizeof(input) <  sizeof(output))
	{
		return std::nullopt;
	}
	return outputVector;
	//return std::nullopt;
}



int main()
{
	Array2D<int> input = { { {0,0,0,1,1,2,3},{ 0,0,4,4,4,2,2 },{ 2,2,2,2,2,1,2 } } };
	CompressedDataArray<int> outputData = compressData(input);
	

	if (outputData != std::nullopt)
	{
		std::vector<Data<int>>& printableVector = *outputData;
		std::cout << "{";
		for (int i = 0; i < printableVector.size(); i++) {
			std::cout << "{" << printableVector[i].value << "," << (int)printableVector[i].count << "}";
			if (i < printableVector.size() - 1) {
				std::cout << ",";
			}
		}
		std::cout << "}" << std::endl;
	}
	else
	{
		std::cout << "Array" << std::endl;
	}

	//std::cout << printableVector << std::endl;
	return 0;
}
