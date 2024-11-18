#include "BasicTestLib.h"

UnitTest::UnitTest(void (*testPointer)(), std::string testName) {
    this->testPointer = testPointer;
    this->testName = testName;
}

// Return a string associated with this UnitTest
std::string UnitTest::GetTestName() { 
    return this->testName;
}

// Call the function pointer in this UnitTest
void UnitTest::RunTest() {
    this->testPointer();
}

UnitTestList::UnitTestList() { 
    this->testListName.clear();
    this->resultStr.clear();
    this->testVector.clear();
}

UnitTestList::UnitTestList(std::string testListName, std::vector<void (*)()> functionVector, std::vector<std::string> nameVector) {
    this->testListName = testListName;
    this->resultStr.clear();
    for (int i = 0; i < functionVector.size(); i++) { 
        this->AddTest(functionVector.at(i), nameVector.at(i));
    }
}

// Append a UnitTest to the UnitTestList. Functions cannot have any parameters.
void UnitTestList::AddTest(void (*function)(), std::string name) {
    this->testVector.push_back(UnitTest(function, name));
}

// Run the series of tests in in the UnitTestList.
void UnitTestList::RunTests() {
    int failedTests = 0;
    std::cout << "Running " << this->testListName << "." << std::endl;
    std::cout << "------------------------" << std::endl;
    for (int i = 0; i < testVector.size(); i++) {
        this->testVector.at(i).RunTest();
        if (!this->resultStr.empty()) {
            std::cout << this->testVector.at(i).GetTestName() << ": " << resultStr << std::endl;
            this->resultStr.clear();
            failedTests++;
        }
    }
    std::cout << "------------------------" << std::endl;
    std::cout << this->testVector.size() << " tests completed." << std::endl;
    std::cout << failedTests << " tests failed." << std::endl << std::endl;

    this->resultStr.clear();
}

// Produce error message during RunTests() when a != b.
void UnitTestList::AssertEqual(int a, int b) {
    if (a != b) {
        this->resultStr = "AssertEqual: " + std::to_string(a) + " != " + std::to_string(b);
    }
}

// Produce error message during RunTests() when a == b.
void UnitTestList::AssertNotEqual(int a, int b) {
    if (a == b) { 
        this->resultStr = "AssertNotEqual: " + std::to_string(a) + " == " + std::to_string(b);
    }
}

// Produce error message during RunTests() when param != true.
void UnitTestList::AssertTrue(bool param) {
    if (!param) {
        this->resultStr = "AssertTrue: " + std::to_string(param) + " != true";
    }
}

// Produce error message during RunTests() when param != false.
void UnitTestList::AssertFalse(bool param) {
    if (param) {
        this->resultStr = "AssertFalse: " + std::to_string(param) + " != false";
    }
}