import argparse
import os
import sys
import numpy as np
import ROOT as r
import errno
from collections import OrderedDict

def main():
    
    parser = argparse.ArgumentParser(description='Process some integers.')
    parser.add_argument('--rootPath', type=str, help='path to the root file')
    parser.add_argument('--treePath', type=str, help='path to the tree inside the root file')
    args = parser.parse_args()
    rootPath = args.rootPath
    treePath = args.treePath
    
    inFile = r.TFile(rootPath,"OPEN")
    oldTree = inFile.Get(treePath)

    #Create a new file + a clone of old tree in new file
    outFile = r.TFile("trackerTarget.root", "recreate");
    newtree = oldTree.CloneTree();
    
    outFile.Write()  

if __name__ == '__main__':
    main()