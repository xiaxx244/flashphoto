// Copyright (c) 2018 Youya Xia,  University of
// Minnesota.
#include <mingfx.h>
#include <deque>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "gtest/gtest.h"

#include "imagetools/image_editor.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/color_data.h"

using image_tools::ImageEditor;

// uses three images for testing
class RegressionTest : public ::testing::Test {
  void SetUp() override {
    image_tools::PixelBuffer* tmp1 =
    new image_tools::PixelBuffer ("resources/test1.png");
    editor1_  =  new ImageEditor (tmp1);
    image_tools::PixelBuffer* tmp2 =
    new image_tools::PixelBuffer ("resources/test2.png");
    editor2_  =  new ImageEditor (tmp2);
    image_tools::PixelBuffer* tmp3 =
    new image_tools::PixelBuffer ("resources/test3.png");
    editor3_  =  new ImageEditor (tmp3);
  }

  void TearDown() override {
    delete editor1_;
    delete editor2_;
    delete editor3_;
  }

 protected:
  ImageEditor *editor1_;
  ImageEditor *editor2_;
  ImageEditor *editor3_;
  image_tools::ConvolutionFilterBlur f_blur_;
  image_tools::ConvolutionFilterEdge f_edge_;
  image_tools::ConvolutionFilterMotionBlur f_motion_blur_;
  image_tools::ConvolutionFilterSharpen f_sharpen_;
  image_tools::FilterChannels f_channels_;
  image_tools::FilterQuantize f_quantize_;
  image_tools::FilterSaturate f_saturate_;
  image_tools::FilterThreshold f_threshold_;
  image_tools::ToolBlur t_blur_;
  image_tools::ToolCalligraphyPen t_calligraphy_pen_;
  image_tools::ToolChalk t_chalk_;
  image_tools::ToolEraser t_eraser_;
  image_tools::ToolHighlighter t_highlighter_;
  image_tools::ToolPen t_pen_;
  image_tools::ToolSprayCan t_spray_can_;
  image_tools::ToolStamp t_stamp_;
};
//  tests below for all toools by comapring
// the test images with the ground truth images)
TEST_F(RegressionTest,  toolpenTest) {
  image_tools::ColorData color1 = image_tools::ColorData(0.8, 0.2, 0.2);
  editor1_->StartStroke(t_pen_.name(), color1, 5, 688, 351);
  editor1_->SaveToFile("resources/test1_test_result_pen.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test1_test_result_pen.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test1_ground_truth_pen.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  toolcalpenTest) {
  image_tools::ColorData color1 = image_tools::ColorData(0.8, 0.2, 0.2);
  editor1_->StartStroke(t_calligraphy_pen_.name(), color1, 5, 642, 278);
  editor1_->SaveToFile("resources/test1_test_result_cal_pen.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test1_test_result_cal_pen.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test1_ground_truth_caligraphy_pen.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  toolchalkpenTest) {
  image_tools::ColorData color1 = image_tools::ColorData(0.8, 0.2, 0.2);
  t_chalk_.set_seed(100);
  editor1_->StartStroke(t_chalk_.name(), color1, 5, 679, 347);
  editor1_->SaveToFile("resources/test1_test_result_chalk_pen.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test1_test_result_chalk_pen.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test1_ground_truth_chalk.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  toolsprayTest) {
  image_tools::ColorData color1 = image_tools::ColorData(0.8, 0.2, 0.2);
  editor1_->StartStroke(t_spray_can_.name(), color1, 5, 667, 345);
  editor1_->SaveToFile("resources/test1_test_result_spray.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test1_test_result_spray.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test1_ground_truth_spray.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  ToolHighlighterTest) {
  image_tools::ColorData color1 = image_tools::ColorData(0.8, 0.2, 0.2);
  editor1_->StartStroke(t_highlighter_.name(), color1, 5, 670, 335);
  editor1_->SaveToFile("resources/test1_test_result_spray.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test1_test_result_highlighter.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test1_ground_truth_highlighter.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  ToolstampTest) {
  image_tools::ColorData color1 = image_tools::ColorData(0.8, 0.2, 0.2);
  editor1_->StartStroke(t_stamp_.name(), color1, 5, 670, 335);
  editor1_->SaveToFile("resources/test1_test_result_stamp.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test1_test_result_stamp.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test1_ground_truth_tool_stamp.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  ToolBlurTest) {
  image_tools::ColorData color1 = image_tools::ColorData(0.8, 0.2, 0.2);
  editor1_->StartStroke(t_blur_.name(), color1, 5, 670, 335);
  editor1_->SaveToFile("resources/test1_test_result_blur.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test1_test_result_blur.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test1_ground_truth_tool_blur.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  ToolEraserTest) {
  image_tools::ColorData color1 = image_tools::ColorData(0.8, 0.2, 0.2);
  editor1_->StartStroke(t_eraser_.name(), color1, 5, 670, 335);
  editor1_->SaveToFile("resources/test1_ground_truth_eraser.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test1_test_result_eraser.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test1_ground_truth_eraser.png");
  EXPECT_TRUE(tmp1 == tmp2);
}
// test all filters using the same method;
TEST_F(RegressionTest,  ThresholdTest) {
  editor2_->ApplyThresholdFilter(0.5);
  editor2_->SaveToFile("resources/test2_test_result_threshold.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test2_test_result_threshold.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test2_ground_truth_threshold.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  Channels1Test) {
  editor2_->ApplyChannelsFilter(0.5, 1.0, 1.0);
  editor2_->SaveToFile("resources/test2_test_result_channel_1.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test2_test_result_channel_1.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test2_ground_truth_channel_1.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  Channels2Test) {
  editor2_->ApplyChannelsFilter(1.0, 0.5, 1.0);
  editor2_->SaveToFile("resources/test2_test_result_channel_2.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test2_test_result_channel_2.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test2_ground_truth_channel_2.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  Channels3Test) {
  editor2_->ApplyChannelsFilter(1.0, 1.0, 0.5);
  editor2_->SaveToFile("resources/test2_test_result_channel_3.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test2_test_result_channel_3.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test2_ground_truth_channel_3.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  QuantizeTest) {
  editor2_->ApplyQuantizeFilter(5.0);
  editor2_->SaveToFile("resources/test2_test_result_quantize.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test2_test_result_quantize.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test2_ground_truth_quantize.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  SaturateTest) {
  editor2_->ApplySaturateFilter(4.0);
  editor2_->SaveToFile("resources/test2_test_result_saturate.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test2_test_result_saturate.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test2_ground_truth_saturate.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  BlurTest) {
  editor3_->ApplyBlurFilter(5.0);
  editor3_->SaveToFile("resources/test3_test_result_blur.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test3_test_result_blur.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test3_ground_truth_blur.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  EdgeTest) {
  editor3_->ApplyEdgeDetectFilter();
  editor3_->SaveToFile("resources/test3_test_result_edge.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test3_test_result_edge.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test3_ground_truth_edge.png");
  EXPECT_TRUE(tmp1 == tmp2);
}
TEST_F(RegressionTest,  SharpenTest) {
  editor3_->ApplySharpenFilter(5.0);
  editor3_->SaveToFile("resources/test3_test_result_sharpen.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test3_test_result_sharpen.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test3_ground_truth_sharpen.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  MotionTest) {
  enum BlurDir { MBLUR_DIR_N_S,  MBLUR_DIR_E_W,  MBLUR_DIR_NE_SW,
      MBLUR_DIR_NW_SE };
  editor3_->ApplyMotionBlurFilter(5.0,
    static_cast<image_tools::ConvolutionFilterMotionBlur::BlurDir>
    (MBLUR_DIR_N_S));
  editor3_->SaveToFile("resources/test3_test_result_n-s.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test3_test_result_n-s.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test3_ground_truth_n-s.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  Motion1Test) {
  enum BlurDir { MBLUR_DIR_N_S,  MBLUR_DIR_E_W,  MBLUR_DIR_NE_SW,
      MBLUR_DIR_NW_SE };
  editor3_->
  ApplyMotionBlurFilter(5.0,
    static_cast<image_tools::ConvolutionFilterMotionBlur::BlurDir>
    (MBLUR_DIR_E_W));
  editor3_->SaveToFile("resources/test3_test_result_e-w.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test3_test_result_e-w.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test3_ground_truth_e-w.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  Motion2Test) {
  enum BlurDir { MBLUR_DIR_N_S,  MBLUR_DIR_E_W,  MBLUR_DIR_NE_SW,
      MBLUR_DIR_NW_SE };
  editor3_->
  ApplyMotionBlurFilter(5.0,
    static_cast<image_tools::ConvolutionFilterMotionBlur::BlurDir>
    (MBLUR_DIR_NE_SW));
  editor3_->SaveToFile("resources/test3_test_result_ne-sw.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test3_test_result_ne-sw.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test3_ground_truth_ne-sw.png");
  EXPECT_TRUE(tmp1 == tmp2);
}

TEST_F(RegressionTest,  Motion3Test) {
  enum BlurDir { MBLUR_DIR_N_S,  MBLUR_DIR_E_W,  MBLUR_DIR_NE_SW,
      MBLUR_DIR_NW_SE };
  editor3_->ApplyMotionBlurFilter
  (5.0, static_cast<image_tools::ConvolutionFilterMotionBlur::BlurDir>
    (MBLUR_DIR_NW_SE));
  editor3_->SaveToFile("resources/test3_test_result_nw-se.png");
  image_tools::PixelBuffer tmp1 =
  image_tools::PixelBuffer("resources/test3_test_result_nw-se.png");
  image_tools::PixelBuffer tmp2 =
  image_tools::PixelBuffer("resources/test3_ground_truth_nw-se.png");
  EXPECT_TRUE(tmp1 == tmp2);
}
