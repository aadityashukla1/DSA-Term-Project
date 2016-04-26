#include "k-means-multi.h"
#include <ctime>

int main(int argc, char *argv[]) {

	// local variables
	Cluster_set clCluster_set_instance;
	int iArg_val;
	char cPause;

	// check if there are any command line arguments
	iArg_val = argc;  
	if (iArg_val < 2) { // missing input argument
		cout << "No control file specified" << endl << endl;
		cout << "Required input format is: k-means-multi <control file name>" << endl << endl;
	}
	else { // input argument present
		// read the parameter data from the input file 
		clCluster_set_instance.Read_control_data(argv[1]);
		// next line is for testing
		//clCluster_set_instance.Read_control_data("control_iris.dat");

		//start the timer
		clock_t t = clock();
		
		// start the clustering program
		clCluster_set_instance.Execute_clustering();
		double duration = (clock() - t) / (double)CLOCKS_PER_SEC;
		cout << endl << duration;

	} // if 

	return(0);  
} // main()

