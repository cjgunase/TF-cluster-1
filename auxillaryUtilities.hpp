#ifndef AUXILLARY_UTILITIES_HPP
#define AUXILLARY_UTILITIES_HPP

#include <queue>
#include <vector>
#include <string>
#include <utility>

#include "correlation-matrix.hpp"

#include "geneData.hpp"
#include "graph.hpp"

using std::hash;
using std::pair;
using std::size_t;
using std::string;
using std::queue;
using std::vector;


typedef unsigned char u8;
typedef unsigned int  u32;

typedef double f64;

typedef const unsigned char cu8;
typedef const unsigned int  cu32;
typedef const std::size_t csize_t;
typedef const double cf64;


struct config{
  string geneListFile;
  string expressionFile;
  u8 keepTopN;
  size_t kickSize;  
  f64 threeSigma;
  f64 twoSigma;
  f64 oneSigma;
};


struct loadFromFileReturn{
  f64*UDMatrix; // upper diagonal matrix
  vector<string> genes;
};


struct addTopEdgesHelperStruct{
  struct correlationMatrix *protoGraph;
  u8 keepTopN;
  size_t startIndex;
  size_t endIndex;
};


int verifyInput(int argc, char **argv, const string geneListFile);


struct config loadConfig(const char *configFilePath);


//struct loadFromFileReturn loadFromFile(const string geneListFile);


void quickMergeEdges(vertex<geneData, f64> *toPrune,
                                                    csize_t size);

void printClusters(queue< queue<size_t> > clusters, const vector<string> &names);

void printEdges(graph<geneData, f64> *corrData);

//struct correlationMatrix sortWeights(struct correlationMatrix &protoGraph, cu8 keepTopN);

struct correlationMatrix sortWeights(struct correlationMatrix &protoGraph, cu8 keepTopN);

graph<geneData, f64>* constructGraph(const struct UDCorrelationMatrix &protoGraph, 
                      cf64 threeSigma, cf64 oneSigma, cu8 maxNumEdges);

void pruneGraph(graph<geneData, f64> *corrData, u8 keepTopN);

void sortDoubleSizeTPairHighToLow(pair<f64, size_t> *toSort, csize_t size);

void sortDoubleSizeTPairHighToLowHelper(pair<f64, size_t> *toSort, 
                csize_t leftIndex, csize_t rightIndex, csize_t endIndex, 
                                          pair<f64, size_t> *sortSpace);

void sortDoubleSizeTPairLowToHigh(pair<f64, size_t> *toSort, csize_t size);

#endif