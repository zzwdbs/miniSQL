#include <string>
using std::string;
#include <vector>
using std::vector

#include "element.h"

#ifndef _INDEXMANAGER_H_
#define _INDEXMANAGER_H_

// template <class T>
class IndexQuery
{
    Element lowerBound;
    Element upperBound;
    bool hasLowerBound;
    bool hasUpperBound;
    bool lowerBoundIncluded;
    bool upperBoundIncluded;
    // bool OneValueOnly_lowerBound;
};

class IndexManager
{
private:
    string indexDir = "data/index/";
public:
    // IndexManager();
    // ~IndexManager();

    bool createIndex(IndexInfo indexInfo);
    bool dropIndex(IndexInfo indexInfo);
    bool dopAllIndexFromTable(string tableName);
    bool insertIntoIndex(IndexInfo index, Element value, int offset);
    // template <class T>
    bool deleteFromIndex(IndexInfo index, Element value);

    vector<int> queryIndex(IndexInfo index, IndexQuery query);

};

#endif
