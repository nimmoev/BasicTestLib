# BasicTestLib

The current functionality includes:
* Two classes: UnitTestList and UnitTest
* UnitTest groups associated data with a test function
* UnitTestList has the ability to append UnitTests to its testVector and run them with RunTests()
* UnitTestList also includes basic assertion support

## Programming Guide
It is not recommended to instantiate your own objects of class UnitTest.

To implement this UnitTestList class, follow these instructions:
1. Declare an extern UnitTestList in your header file
2. Declare parameter-less type test functions of void in your header file.
3. Append those test functions to a TestFunctionVector in your header file.
   - Inside each test function, call a UnitTestList assertion.
4. Append strings of names matching those test functions to a TestNameVector in your header file.
5. Declare your UnitTestList inside your source file. Initialize with a name, your TestFunctionVector, and your TestNameVector.
6. Use UnitTestList.RunTests() in your main function


