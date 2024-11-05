#include <string>
#include <vector>

#ifndef BTL_H
#define BTL_H

/// @brief A class which offers the ability to add Unit Tests to a lists and run them with one function call.
// To use, develop test functions and append all tests to the functionVector before calling RunTests(). 
// To add a test to this UnitTestList, it cannot take any parameters. 
class UnitTestList { 
protected:
    std::string resultStr;
    std::vector<void (*)()> functionVector;
    std::vector<std::string> nameVector;

public:
    UnitTestList();
    UnitTestList(std::vector<void (*)()> functionVector, std::vector<std::string> nameVector);
    void AddTest(void (*function)(), std::string name);
    void RunTests();
    void AssertEqual(int a, int b);
    void AssertNotEqual(int a, int b);
    void AssertTrue(bool param);
    void AssertFalse(bool param);

};

#endif