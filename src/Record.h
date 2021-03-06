
#include "stdafx.h"
#include "element.h"

#ifndef _RECORD_H_
#define _RECORD_H_
// #include "Queryer.h"


class Record
{
public:
    TableInfo table;
    vector<Element * > elements;
    int recordLength;

    Record(TableInfo table, vector<Element *> elements):
        table(table), elements(elements), recordLength(table.recordLength){};
    Record(TableInfo table):
        table(table),                     recordLength(table.recordLength){};

    void addElement(Element * e);
    friend ostream& operator<< (ostream& os, Record & r);

    bool validate()
    {
    	return accumulate(elements.begin(), elements.end(), false, [](bool valid, auto elementPtr)
    																{
    																	return (valid || elementPtr -> valid);
    																});
	};
    Element operator[] (string attrName)
    {
        for (size_t i = 0; i < elements.size(); i++)
        {
            if (table.attributes[i].name == attrName)
            {
                return *elements[i];
            }
        }
        return Element();
    }
};


#endif
