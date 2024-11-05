#include <iostream>

#include "BasicTestLib.h"

UnitTestList::UnitTestList() { 
    this->resultStr.clear();
    this->functionVector.clear();
    this->nameVector.clear();
}

UnitTestList::UnitTestList(std::vector<void (*)()> functionVector, std::vector<std::string> nameVector) {
    this->resultStr.clear();
    this->functionVector = functionVector;
    this->nameVector = nameVector;
}

// Append a test function to the UnitTestList. Functions cannot have any parameters.
void UnitTestList::AddTest(void (*function)(), std::string name) {
    this->functionVector.push_back(function);
    this->nameVector.push_back(name);
}

// Run the series of tests in in the UnitTestList.
void UnitTestList::RunTests() {
    int failedTests = 0;
    for (int i = 0; i < functionVector.size(); i++) {
        this->functionVector.at(i)();
        if (!this->resultStr.empty()) {
            std::cout << nameVector.at(i) << ": " << resultStr << std::endl;
            resultStr.clear();
            failedTests++;
        }
    }
    std::cout << "--------------------" << std::endl;
    std::cout << "Ran " << functionVector.size() << " tests." << std::endl;
    std::cout << failedTests << " tests failed." << std::endl;
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