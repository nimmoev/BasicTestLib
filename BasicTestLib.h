#ifndef BTL_H
#define BTL_H

#include <iostream>
#include <string>
#include <vector>

extern bool g_BTL_Debug;
extern const std::string successStr;

class UnitTest;
class UnitTestList;

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
    UnitTestList(std::string testListName, std::vector<UnitTest> testVector);
    UnitTestList(std::string testListName, std::vector<void (*)()> functionVector, std::vector<std::string> nameVector);
    void AddTest(void (*function)(), std::string name);
    void RunTests();
    void AssertEqual(std::string a, std::string b);
    void AssertEqual(int a, int b);
    void AssertEqual(std::vector<std::string> a, std::vector<std::string> b);
    void AssertEqual(std::vector<int> a, std::vector<int> b);
    void AssertNotEqual(std::string a, std::string b);
    void AssertNotEqual(int a, int b);
    void AssertNotEqual(std::vector<std::string> a, std::vector<std::string> b);
    void AssertNotEqual(std::vector<int> a, std::vector<int> b);
    void AssertTrue(bool param);
    void AssertFalse(bool param);

};

std::string GetStringVectorAsString(std::vector<std::string> strVector);
std::string GetIntVectorAsString(std::vector<int> intVector);

#endif