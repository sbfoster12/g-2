#include "TTree.h"
#include "TFile.h"

using namespace std;

void moveTree(std::string inputFileName) {
  TFile* inFile = new TFile(inputFileName.c_str(),"OPEN");
	TTree* oldTree = (TTree*)(inFile->Get("TrackerTargetTree/trackerTarget"));

	// std::vector<double> *planePosXsPtr = NULL;
	// oldTree->SetBranchAddress("planePosXs", &planePosXsPtr);

	// //Deactivate all branches
	// oldTree->SetBranchStatus("*", 0);

	// //Activate only four of them
	// for ( auto & activeBranchName : {"planePosXs"} ) {
 //    	oldTree->SetBranchStatus(activeBranchName, 1);
 //  	}
   	
   	//Create a new file + a clone of old tree in new file
   	TFile* outFile = new TFile("trackerTarget.root", "recreate");
   	TTree* newtree = oldTree->CloneTree();
   	newtree->Write();
}
