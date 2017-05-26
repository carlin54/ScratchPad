#include <iostream>

#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>    
#include <math.h>       
#include <vector>

float average(float* nums, unsigned size){
	float sum = 0;
	for(unsigned i = 0; i < size; i++){
		sum += nums[i];
	}
	return sum / (float)size;
}
float standard(float* nums, unsigned size){
	float avg = average(nums, size);
	float sum = 0;
	for(unsigned i = 0; i < size; i++){
		sum += pow(nums[i] - avg, 2.0);
	}
	return sqrt(sum / size);
}
float genRandom(){
	return ((float)rand() / (float)RAND_MAX);
}
float* generate(float (*gen)(void), unsigned genSize){
	float* iNums = new float[genSize];
	for(unsigned i = 0; i < genSize; i++){
		iNums[i] = gen();
	}
	return iNums;
}

int main(int argv, char* argc[]){
	srand (time(NULL));
	unsigned genSize = 1024*1024;
	
	float* numbers = generate_single(&genRandom, genSize);
	std::cout << "Average: " << average(singleNums, genSize) << std::endl;
	std::cout << "Standard: " << standard(singleNums, genSize) << std::endl;
	delete numbers;
	
	return 0;
}
