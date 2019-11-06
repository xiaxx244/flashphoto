### Assessment for Project Iteration 02 - Automated (Graded By: Dan Orban)

#### Total score: _82.5_ / _85_

Run on December 14, 19:19:18 PM.


#### System Files and PROJ Directory Structure

+ Pass: Check that directory "/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/_proj_materials" exists.

+ Pass: Setup grading environment.



+  _3_ / _3_ : Pass: Check that directory "PROJ" exists.

+  _2_ / _2_ : Pass: Check that directory "PROJ/src/imagetools" exists.

+  _2_ / _2_ : Pass: Check that file "PROJ/src/imagetools/color_data.h" exists.

+  _2_ / _2_ : Pass: Check that file "PROJ/src/imagetools/Makefile" exists.


#### Set up cpplint

+ Pass: Copy directory "cpplint".



+ Pass: Check that directory "cpplint" exists.


#### Set up Project

+ Pass: Change into directory "PROJ".

+ Pass: Setup grading environment.



+  _1_ / _1_ : Pass: Ensuring code follows style guide.



+  _25_ / _25_ : Pass: Check that make compiles.



+  _3_ / _3_ : Pass: Check that file "./build/lib/libimagetools.a" exists.

+  _3_ / _3_ : Pass: Check that file "./build/bin/flashphoto" exists.

+  _3_ / _3_ : Pass: Check that file "./build/bin/mia" exists.

+  _3_ / _3_ : Pass: Check that file "./build/test/gtests" exists.


### Instructor Tests

+ Pass: Change into directory "src/tests/inst_tests".

+ Pass: Check that make compiles.



+ Pass: Change into directory "../../..".

+ Pass: Check that file "./build/test/inst_tests" exists.


#### Testing ImageIO Implementation

+  _2_ / _2_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.ImageLoadingAndSaving.




#### Testing MIA Application

+  _1_ / _1_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.StampToolAdded.



+  _1_ / _1_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.DisplayHelpMessage.



+  _2_ / _2_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.MiaCommandLineCorrect.



+  _2_ / _2_ : Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.MiaCommandLineBadInput.




### Run Student Tests

+ Pass: Check that file "./build/test/gtests" exists.

+ Pass: Get all google tests.
    26 tests found.




#### Results

+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.toolpenTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.toolcalpenTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.toolchalkpenTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.toolsprayTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.ToolHighlighterTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.ToolstampTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.ToolBlurTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.ToolEraserTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.ThresholdTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.Channels1Test.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.Channels2Test.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.Channels3Test.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.QuantizeTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.SaturateTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.BlurTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.EdgeTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.SharpenTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.MotionTest.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.Motion1Test.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.Motion2Test.



+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.Motion3Test.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.mutlicommands.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.inputissue.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.outputissue.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.forgetparameter.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.filenotexists.



+  _15_ / _15_ : Pass: 100% of the tests passed.


### Testing Mutants


#### Testing Pen Tool for failure

+ Pass: At least one test failed for Pen Tool


#### Testing Eraser Tool for failure

+ Pass: At least one test failed for Eraser Tool


#### Testing Stamp Tool for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - The stamp tool does not stamp, it slides.


#### Testing Blur Filter for failure

+ Pass: At least one test failed for Blur Filter


#### Testing Edge Detector Filter for failure

+ Pass: At least one test failed for Edge Detector Filter


#### Testing Image IO Implementaiton for failure

+ Fail: There is no test case for this mutant (since all tests pass).
   - Reason - In Mutant: Image saving and loading is not working.


#### Results

+  _12.5_ / _15_ : Fail: 66.67% of the tests passed, but the target is 80.0%.

#### Total score: _82.5_ / _85_

