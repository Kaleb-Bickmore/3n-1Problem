#include <iostream> 
#include <fstream>

/*
* This is The algorithm given in the paper.
* inputs:
* n - some integer greater than 0 but less than 1000000
*/
int proposedAlgorithm(int n) {
	 if (n == 1) {
		 return 1;
	 }
	 if (n % 2 == 0) {
		 n = n / 2;
	 }
	 else {
		 n = 3 * n + 1;
	 }
	 return 1 + proposedAlgorithm(n);
}
/*
* This determines the maximum cycle in a given period.
* inputs:
* start - the beginning index of our period, i
* end -  the ending index of our period, j 
*/
int maximumCycleLength(const int start, const int end) {
	int max = -1;
	for (int i = 0; i <= (end-start); i++) {
		int temp = proposedAlgorithm(start + i);
		if (temp > max) {
			max = temp;
			
		}
	}
	return max;
}
/*
* This is the driver function. It opens a file output.txt relative to the path
* of the executable. it then will go by twos and find the max cycle length of 
* the given periods. if there is an odd number of entries it will just omit the last entry.
* inputs:
* argc - the number of inputs given to the driver function
* argv[] - the character array of all the inputs given to the driver function
*/
int main(int argc, char *argv[]) {
	std::ofstream myfile;
	if (argc < 3) {
		std::cout << "you need at least 2 inputs.\n";
		return 0;
	}
	else {
		myfile.open("output.txt");
		for (int i = 1; i < argc-1; i += 2) {
			if (argv[i] > argv[i + 1]) {
				std::cout << argv[i] << " is not less than " << argv[i + 1] << "... skipping this set.\n";
			}
			else {
				myfile << argv[i] << " " << argv[i + 1] << " " << maximumCycleLength(atoi(argv[i]), atoi(argv[i + 1])) << std::endl;
			}
			
		}
		myfile.close();
	}
	


}