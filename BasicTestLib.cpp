#include "BasicTestLib.h"

// Debug flag, set to true to see which tests run
bool g_BTL_Debug = false;
const std::string successStr = "S";

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

UnitTestList::UnitTestList(std::string testListName, std::vector<UnitTest> testVector) {
    this->testListName = testListName;
    this->resultStr.clear();
    this->testVector = testVector;
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
        this->resultStr.clear();
        if (g_BTL_Debug) { 
            std::cout << this->testVector.at(i).GetTestName() << std::endl;
        }
        this->testVector.at(i).RunTest();
        if (resultStr.empty()) {
            std::cout << this->testVector.at(i).GetTestName() << ": Assertion not called" << std::endl;
        }
        else if (resultStr != successStr) {
            std::cout << this->testVector.at(i).GetTestName() << ": " << resultStr << std::endl;                
        }
        else {
            continue;
        }
        failedTests++;
    }
    std::cout << "------------------------" << std::endl;
    std::cout << this->testVector.size() << " tests completed." << std::endl;
    std::cout << failedTests << " tests failed." << std::endl << std::endl;
}

// Produce error message during RunTests() when a != b.
void UnitTestList::AssertEqual(std::string a, std::string b) { 
    if (a == b) {
        this->resultStr = successStr;
        return;
    }
    this->resultStr = "AssertEqual: " + a + " != " + b;
}

// Produce error message during RunTests() when a != b.
void UnitTestList::AssertEqual(int a, int b) {
    if (a == b) {
        this->resultStr = successStr;
        return;
    }
    this->resultStr = "AssertEqual: " + std::to_string(a) + " != " + std::to_string(b);
}

// Produce error message during RunTests() when a != b.
void UnitTestList::AssertEqual(std::vector<std::string> a, std::vector<std::string> b) {
    if (a.size() != b.size()) { 
        this->resultStr = "AssertEqual: a.size() != b.size()";
        return;
    }
    for (int i = 0; i < a.size(); i++) { 
        if (a.at(i) != b.at(i)) { 
            this->resultStr = "AssertEqual: a[" + std::to_string(i) + "] != b[" + std::to_string(i) + "]: " + a.at(i) + " != " + b.at(i);
            return;
        }
    }
    this->resultStr = successStr;
}

// Produce error message during RunTests() when a != b.
void UnitTestList::AssertEqual(std::vector<int> a, std::vector<int> b) {
    if (a.size() != b.size()) { 
        this->resultStr = "AssertEqual: " + GetIntVectorAsString(a) + " != " + GetIntVectorAsString(b);
        return;
    }
    for (int i = 0; i < a.size(); i++) { 
        if (a.at(i) != b.at(i)) { 
            this->resultStr = "AssertEqual: " + GetIntVectorAsString(a) + " != " + GetIntVectorAsString(b);
            return;
        }
    }
    this->resultStr = successStr;
}

// Produce error message during RunTests() when a == b.
void UnitTestList::AssertNotEqual(std::string a, std::string b) {
    if (a != b) { 
        this->resultStr = successStr;
        return;
    }
    this->resultStr = "AssertNotEqual: " + a + " == " + b;
}

// Produce error message during RunTests() when a == b.
void UnitTestList::AssertNotEqual(int a, int b) {
    if (a != b) { 
        this->resultStr = successStr;
        return;
    }
    this->resultStr = "AssertNotEqual: " + std::to_string(a) + " == " + std::to_string(b);
}

// Produce error message during RunTests() when a != b.
void UnitTestList::AssertNotEqual(std::vector<std::string> a, std::vector<std::string> b) {
    if (a.size() != b.size()) { 
        this->resultStr = successStr;
        return;
    }
    for (int i = 0; i < a.size(); i++) { 
        if (a.at(i) != b.at(i)) { 
            this->resultStr = successStr;
            return;
        }
    }
    this->resultStr = "AssertNotEqual: " + GetStringVectorAsString(a) + " == " + GetStringVectorAsString(b);    
}

// Produce error message during RunTests() when a != b.
void UnitTestList::AssertNotEqual(std::vector<int> a, std::vector<int> b) {
    if (a.size() != b.size()) { 
        this->resultStr = successStr;
        return;
    }
    for (int i = 0; i < a.size(); i++) { 
        if (a.at(i) != b.at(i)) { 
            this->resultStr = successStr;
            return;
        }
    }
    this->resultStr = "AssertNotEqual: " + GetIntVectorAsString(a) + " == " + GetIntVectorAsString(b);
}

// Produce error message during RunTests() when param != true.
void UnitTestList::AssertTrue(bool param) {
    if (param == true) {
        this->resultStr = successStr;
        return;
    }
    this->resultStr = "AssertTrue: " + std::to_string(param) + " != true";
}

// Produce error message during RunTests() when param != false.
void UnitTestList::AssertFalse(bool param) {
    if (param == false) {
        this->resultStr = successStr;
        return;
    }
    this->resultStr = "AssertFalse: " + std::to_string(param) + " != false";
}

// Parse strVector into a single string result.
std::string GetStringVectorAsString(std::vector<std::string> strVector) { 
    std::string result = "{";
    if (strVector.empty()) { 
        return "{}";
    }
    for (int i = 0; i < strVector.size() - 1; i++) { 
        result += strVector.at(i) + ",";
    }
    result += strVector.at(strVector.size() - 1) + "}";
    return result;
}

// Parse intVector into a single string result.
std::string GetIntVectorAsString(std::vector<int> intVector) {
    std::string result = "{";
    if (intVector.empty()) { 
        return "{}";
    }
    for (int i = 0; i < intVector.size() - 1; i++) { 
        result += std::to_string(intVector.at(i)) + ",";
    }
    result += std::to_string(intVector.at(intVector.size() - 1));
    result += "}";
    return result;
}