# BasicTestLib

The current functionality includes:
* Two classes: UnitTestList and UnitTest
* UnitTest groups associated data with a test function
* UnitTestList has the ability to append UnitTests to its testVector and run them with RunTests()
* UnitTestList also includes basic assertion support

## Programming Guide
It is not recommended to instantiate your own objects of class UnitTest.

To implement this UnitTestList class, follow these instructions:
 1. Declare a const extern std::vector<UnitTest> in your header file.
 2. Declare an UnitTestList in your header file.
 3. Declare your test functions of type void (with no parameters) in your header file.
 4. Instantiate the const std::vector<UnitTest> with UnitTests in your source file.
    - To Instantiate a UnitTest, pass in a void pointer to your test function and a test name (std::string).
 5. Instantiate UnitTestList with a TestListName and the previous const std::vector<UnitTest> in your source file.
 6. Define all of your test functions in your source file.
    - Each test function requires a use of an assert from UnitTestList. 
