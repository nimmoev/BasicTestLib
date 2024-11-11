#include <string>
#include <vector>

#ifndef BTL_H
#define BTL_H

/// @brief A class which offers the ability to run a test function. Also contains an associated name string
class UnitTest {
protected:
    void (*testPointer)();
    std::string testName;

public:
    UnitTest(void (*testPointer)(), std::string testName);
    std::string GetTestName();
    void RunTest();
    
};

/// @brief A class which offers the ability to add UnitTests to a lists and run them with one function call.
/// Also contains all supported assertions.
class UnitTestList { 
protected:
    std::string testListName;
    std::string resultStr;
    std::vector<UnitTest> testVector;

public:
    UnitTestList();
    UnitTestList(std::string testListName, std::vector<void (*)()> functionVector, std::vector<std::string> nameVector);
    void AddTest(void (*function)(), std::string name);
    void RunTests();
    void AssertEqual(int a, int b);
    void AssertNotEqual(int a, int b);
    void AssertTrue(bool param);
    void AssertFalse(bool param);

};

#endif