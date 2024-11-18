# BasicTestLib

The current functionality includes:
* Two classes: UnitTestList and UnitTest
* UnitTest groups associated data with a test function
* UnitTestList has the ability to append UnitTests to its testVector and run them with RunTests()
* UnitTestList also includes basic assertion support

## Programming Guide
It is not recommended to instantiate your own objects of class UnitTest.

To implement this UnitTestList class, follow these instructions:
 1. Declare an extern TestFunctionVector (std::vector<void (*)()>) in your header file.
 2. Declare an extern TestNameVector (std::vector<std::string >) in your header file.
 3. Declare an extern UnitTestList in your header file.
 4. Declare your test functions of type void (with no parameters) in header file.
 5. Instantiate TestFunctionVector with references to your test functions in your source file.
 6. Instantiate TestNameVector with a std::string of same name of each of your test functions in your source file.
 7. Define all of your test functions in your source file.
   - Each test function requires a use of an assert from UnitTestList. 

It is recommended to implement new UnitTestLists for new features rather than adding to existing UnitTestLists.