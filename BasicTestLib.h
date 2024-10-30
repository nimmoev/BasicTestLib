#include <string>
#include <vector>

#ifndef BTL_H
#define BTL_H

/// @brief A class which offers the ability to add Unit Tests to a lists and run them with one function call.
// To use, create your own subclass from UnitTestList, develop test functions from that class, and append all tests to 
// the functionVector before calling RunTests(). To add a test to this UnitTestList, it must take only a UnitTestList* as a parameter. 
class UnitTestList { 
protected:
    std::string resultStr;
    std::vector<void (*)(UnitTestList *UTL)> functionVector;

public:
    UnitTestList();
    UnitTestList(std::vector<void (*)(UnitTestList *UTL)> functionVector);
    void AddTest(void (*function)(UnitTestList *UTL));
    void RunTests();
    void AssertEqual(int a, int b);
    void AssertTrue(bool param);
    void AssertFalse(bool param);

};

#endif