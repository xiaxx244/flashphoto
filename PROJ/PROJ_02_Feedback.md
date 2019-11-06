### Feedback for Project Iteration 02

Run on December 12, 15:13:09 PM.


#### System Files and PROJ Directory Structure

+ Pass: Check that directory "/classes/grades/Fall-2018/csci3081/dtorban/grading-scripts/_proj_materials" exists.

+ Pass: Setup grading environment.



+ Pass: Check that directory "PROJ" exists.

+ Pass: Check that directory "PROJ/src/imagetools" exists.

+ Pass: Check that file "PROJ/src/imagetools/color_data.h" exists.

+ Pass: Check that file "PROJ/src/imagetools/Makefile" exists.


#### Set up cpplint

+ Pass: Copy directory "cpplint".



+ Pass: Check that directory "cpplint" exists.


#### Set up Project

+ Pass: Change into directory "PROJ".

+ Pass: Setup grading environment.



+ Pass: Ensuring code follows style guide.



+ Pass: Check that make compiles.



+ Pass: Check that file "./build/lib/libimagetools.a" exists.

+ Pass: Check that file "./build/bin/flashphoto" exists.

+ Pass: Check that file "./build/bin/mia" exists.

+ Pass: Check that file "./build/test/gtests" exists.


### Instructor Tests

+ Pass: Change into directory "src/tests/inst_tests".

+ Pass: Check that make compiles.



+ Pass: Change into directory "../../..".

+ Pass: Check that file "./build/test/inst_tests" exists.


#### Testing ImageIO Implementation

+ Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.ImageLoadingAndSaving.




#### Testing MIA Application

+ Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.StampToolAdded.



+ Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.DisplayHelpMessage.



+ Pass: Check that a GoogleTest test passes.
    passes the test: Iteration2Test.MiaCommandLineCorrect.



+ Pass: Check that a GoogleTest test passes.
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



+ Fail: Check that a GoogleTest test passes.
    timeout occured: RegressionTest.BlurTest.
Running main() from gtest_main.cc
Note: Google Test filter = RegressionTest.BlurTest
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from RegressionTest
[ RUN      ] RegressionTest.BlurTest




+ Pass: Check that a GoogleTest test passes.
    passes the test: RegressionTest.EdgeTest.



+ Fail: Check that a GoogleTest test passes.
    timeout occured: RegressionTest.SharpenTest.
Running main() from gtest_main.cc
Note: Google Test filter = RegressionTest.SharpenTest
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from RegressionTest
[ RUN      ] RegressionTest.SharpenTest




+ Fail: Check that a GoogleTest test passes.
    timeout occured: RegressionTest.MotionTest.
Running main() from gtest_main.cc
Note: Google Test filter = RegressionTest.MotionTest
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from RegressionTest
[ RUN      ] RegressionTest.MotionTest




+ Fail: Check that a GoogleTest test passes.
    timeout occured: RegressionTest.Motion1Test.
Running main() from gtest_main.cc
Note: Google Test filter = RegressionTest.Motion1Test
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from RegressionTest
[ RUN      ] RegressionTest.Motion1Test




+ Fail: Check that a GoogleTest test passes.
    timeout occured: RegressionTest.Motion2Test.
Running main() from gtest_main.cc
Note: Google Test filter = RegressionTest.Motion2Test
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from RegressionTest
[ RUN      ] RegressionTest.Motion2Test




+ Fail: Check that a GoogleTest test passes.
    timeout occured: RegressionTest.Motion3Test.
Running main() from gtest_main.cc
Note: Google Test filter = RegressionTest.Motion3Test
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from RegressionTest
[ RUN      ] RegressionTest.Motion3Test




+ Fail: Check that a GoogleTest test passes.
    timeout occured: CommandLineProcessorTest.mutlicommands.
Running main() from gtest_main.cc
Note: Google Test filter = CommandLineProcessorTest.mutlicommands
[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from CommandLineProcessorTest
[ RUN      ] CommandLineProcessorTest.mutlicommands




+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.inputissue.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.outputissue.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.forgetparameter.



+ Pass: Check that a GoogleTest test passes.
    passes the test: CommandLineProcessorTest.filenotexists.



+ Fail: 73.08% of the tests passed, but the target is 100%.

