// Copyright (c) 2018 Youya Xia, University of
// Minnesota.
#include <mingfx.h>
#include <deque>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "gtest/gtest.h"


#include "imagetools/image_editor.h"
#include "mia/command_line_processor.h"
#include "imagetools/pixel_buffer.h"

using image_tools::CommandLineProcessor;
using image_tools::ImageEditor;

// unit test for CommandLineProcessor;
class CommandLineProcessorTest : public ::testing::Test {
  void SetUp() override {
    commands_ = new CommandLineProcessor();
  }

  void TearDown() override {
    delete commands_;
  }


 protected:
  CommandLineProcessor *commands_;
};
/**test various correct commands by comapring their values with
the correct images that should appear after the sipposed commands*/
TEST_F(CommandLineProcessorTest, mutlicommands) {
  std::string test1[] =
  {"./build/bin/mia", "./resources/test4.png", "./resources/unit1.png"};
  std::string test2[] =
  {"./build/bin/mia", "./resources/test4.png", "-threshold", "0.5",
  " ./resources/unit2.png"};
  std::string test3[] =
  {"./build/bin/mia", "./resources/test4.png", "-threshold", "0.5",
  "-edgedetect", "./resources/unit3.png"};
  commands_->ProcessCommandLine_V2(3, test1);
  commands_->ProcessCommandLine_V2(5, test2);
  commands_->ProcessCommandLine_V2(6, test3);
  image_tools::PixelBuffer newimage =
  image_tools::PixelBuffer("resources/unit1.png");
  image_tools::PixelBuffer* image =
  new image_tools::PixelBuffer("resources/test4.png");
  image_tools::ImageEditor* filters = new ImageEditor(image);
  EXPECT_TRUE(newimage == *image);
  filters->ApplyThresholdFilter(0.5);
  filters->SaveToFile("resources/truth2.png");
  image_tools::PixelBuffer newimage3 =
  image_tools::PixelBuffer("resources/unit2.png");
  image_tools::PixelBuffer newimage2 =
  image_tools::PixelBuffer("resources/truth2.png");
  EXPECT_TRUE(newimage2 == newimage3);
  filters->ApplyEdgeDetectFilter();
  filters->SaveToFile("resources/truth3.png");
  image_tools::PixelBuffer newimage4 =
  image_tools::PixelBuffer("resources/unit3.png");
  image_tools::PixelBuffer newimage5 =
  image_tools::PixelBuffer("resources/truth3.png");
  EXPECT_TRUE(newimage4 == newimage5);
}
//  test comamnds when it miss input;
TEST_F(CommandLineProcessorTest, inputissue) {
  std::string forgetinput[] =
  {"mia", "-threshold", "0.5", "out.png"};
  commands_->ProcessCommandLine_V2(4, forgetinput);
  EXPECT_EQ("invalid input\n" + commands_->ErrorMessage(),
  commands_->GetMessage());
}
//  test commands when it misses the output;
TEST_F(CommandLineProcessorTest, outputissue) {
  std::string forgetoutput[] =
  {"mia", "resources/test4.png", "-threshold", "0.5", "out"};
  commands_->ProcessCommandLine_V2(4, forgetoutput);
  EXPECT_EQ("invalid input\n" + commands_->ErrorMessage(),
  commands_->GetMessage());
}
//  test the commands when it misses the parameter for the filter;
TEST_F(CommandLineProcessorTest, forgetparameter) {
  std::string forgetpara[] = {"mia",
  "resources/test4.png", "-threshold", "out.png"};
  try {
    commands_->ProcessCommandLine_V2(4, forgetpara);
  } catch(std::string msg) {
    EXPECT_EQ(msg, commands_->ErrorMessage());
  }
}

//  test the commands when input image is not exists;
TEST_F(CommandLineProcessorTest, filenotexists) {
  std::string forgetfile[] = {"mia",
  "a.png", "-edgedetect", "out.png"};
  commands_->ProcessCommandLine_V2(4, forgetfile);
  EXPECT_EQ("invalid input\n" + commands_->ErrorMessage(),
  commands_->GetMessage());
}
