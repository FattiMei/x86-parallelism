#include <stdio.h>
#include <x86intrin.h>


#define ITERATIONS 10000


// function to be tested
extern int foo();


unsigned long long cycles[ITERATIONS];



int main(){
	for(int i = 0; i < ITERATIONS; ++i){
		unsigned long long start_time = __rdtsc();
			foo();
		cycles[i] = __rdtsc() - start_time;
	}


	// all the IO code is at the end of the program, to not interfere with the measurements
	printf("trial,cycles\n");
	for(int i = 0; i < ITERATIONS; ++i){
		printf("%d,%llu\n", i, cycles[i]);
	} 


	return 0;
}
