// Copyright [2018] <Copyright Youya Xia>
#include "mia/command_line_processor.h"
#include <stdlib.h>
#include <stdio.h>

namespace image_tools {

CommandLineProcessor::CommandLineProcessor() {}
CommandLineProcessor::~CommandLineProcessor() {}
// specific message displayed to users when users type wrong input styles;
std::string CommandLineProcessor::ErrorMessage() {
  std::string msg1 =
  "-usage: mia infile.png [image processing commands ...]outfile.png\n";
  std::string msg2 = "-infile.png: input image file in png format\n";
  std::string msg3 = "-outfile.png: filename to use for saving the result\n";
  std::string msg4 = "-image processing comamnds:\n";
  std::string msg5 = "-blur r:apply a gaussian blur of radius r\n";
  std::string msg6 = "-edgedetect:apply an edge detection filter\n";
  std::string msg7 = "-sharpen r:apply a sharpening filter of radius r\n";
  std::string msg8 = "-red s:scale the red channel by factor s\n";
  std::string msg9 = "-green s:scale the green channel by factor s\n";
  std::string msg10 = "-blue s:scale the blue channel by factor s\n";
  std::string msg11 = "-quantize n:quantize each color channel into n bins\n";
  std::string msg12 = "-saturate s:saturate colors by scale factor s\n";
  std::string msg13 = "-threshold c:threshold using cutoff value c\n";
  std::string msg14 =
  "-motionblur-n-s r:north-south motion blur with kernel radius r\n";
  std::string msg15 =
  "-motionblur-e-w r:east-west motion blur with kernel radius r\n";
  std::string msg16 =
  "-motionblur-ne-sw r: ne-sw motion blur with kernel radius r\n";
  std::string msg17 =
  "-motionblur-nw-se r: nw-se motion blur with kernel radius r\n";
  std::string msg = msg1 + msg2 + msg3 + msg4 + msg5 + msg6 + msg7 +
  msg8 + msg9 + msg10 + msg11 + msg12 + msg13 + msg14 + msg15 + msg16 + msg17;
  return msg;
}
// function to process the numerical error that may arised from users'IO
std::string CommandLineProcessor::IOHandler(std::string target) {
  int countnum = 0, countdot = 0;
  for (int i = 0; target[i] != '\0'; i ++) {
    if (isdigit(target[i])) {
      countnum++;
    } else if (static_cast<char>(target[i]) == '.') {
      // determine if the users wrongly types more than one dot;
      countdot++;
    }
  }
  //  handle the cases of the input argument contains other types of input
  //  other than numbers;
  if (static_cast<int>(target.length()-1) > countnum) {
    throw("invalid input\n" + ErrorMessage());
  } else if (countdot > 1 || (static_cast<int>(target.length())
  != countnum && countdot == 0)) {
    //  handle the cases when the users types arguments such as"2$5","2@5";
    throw("invalid input\n" + ErrorMessage());
  } else if (stof(target) < 0) {
    // throw error if the input numerical value is less than 0;
    throw("invalid input\n" + ErrorMessage());
  }
  return target;
}
//  exectue the users' commands when users' input are correect by calling the
//  commands from the image_editor_commands classes;
void CommandLineProcessor::ProcessIO(std::vector<ImageEditorCommand*>commands) {
  for (int i = 0; i < static_cast<int>(commands.size()); i++) {
    commands[i]->Execute();
  }
}
//  main function to get the input from the users;
//  it puts the corrects commands into the commands vector and only Execute
//  users commands when all commands are correct,otherwise,it will throw an
//  an error message to user;
void CommandLineProcessor::ProcessCommandLine(int argc, char* argv[]) {
  std::string filename = static_cast<std::string>(argv[1]);
  std::string outputfile = static_cast<std::string>(argv[argc-1]);
  if (argc < 3 || (!(mingfx::Platform::FileExists(filename))) ||
  !(outputfile.find(".png") != std::string::npos)) {
    std::cout << "invalid input\n" + ErrorMessage() << std::endl;
    message = "invalid input\n" + ErrorMessage();
  } else {
    PixelBuffer newBuffer = PixelBuffer(argv[1]);
    ImageEditor *editor_ = new ImageEditor(&newBuffer);
    editor_->LoadFromFile(argv[1]);
    std::vector<ImageEditorCommand*>commands;
    try {
      for (int i  =  2; i < argc-1;  ++i) {
        std::string change = argv[i];
        if (change.compare("-blur") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          BlurFilterCommand* blurCommand = new BlurFilterCommand
          (editor_, atof(argv[i + 1]));
          commands.push_back(blurCommand);
          i = i + 1;
        } else if (change.compare("-edgedetect") == 0) {
          EdgeFilterCommand* edgeCommand = new EdgeFilterCommand(editor_);
          commands.push_back(edgeCommand);
        } else if (change.compare("-sharpen") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          SharpenFilterCommand *sharpenCommand = new SharpenFilterCommand
          (editor_, atof(argv[i + 1]));
          commands.push_back(sharpenCommand);
          i = i + 1;
        } else if (change.compare("-red") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          ChannelsFilterCommand* channelCommand = new ChannelsFilterCommand
          (editor_, atof(argv[i + 1]), 1.0, 1.0);
          commands.push_back(channelCommand);
          i = i + 1;
        } else if (change.compare("-blue") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          ChannelsFilterCommand* channelCommand = new ChannelsFilterCommand
          (editor_, 1.0, atof(argv[i + 1]), 1.0);
          commands.push_back(channelCommand);
          i = i + 1;
        } else if (change.compare("-green") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          ChannelsFilterCommand* channelCommand = new ChannelsFilterCommand
           (editor_, 1.0, 1.0, atof(argv[i + 1]));
          commands.push_back(channelCommand);
          i = i + 1;
        } else if (change.compare("-threshold") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          ThresholdFilterCommand* thresholdCommand = new ThresholdFilterCommand
          (editor_, atof(argv[i + 1]));
          commands.push_back(thresholdCommand);
          i = i + 1;
        } else if (change.compare("-motionblur-n-s") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          MotionBlurFilterCommand* motionCommand = new MotionBlurFilterCommand
          (editor_, atof(argv[i + 1]),
          static_cast<ConvolutionFilterMotionBlur::BlurDir>(MBLUR_DIR_N_S));
          commands.push_back(motionCommand);
          i = i + 1;
        } else if (change.compare("-motionblur-e-w") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          MotionBlurFilterCommand* motionCommand = new MotionBlurFilterCommand
          (editor_, atof(argv[i + 1]),
          static_cast<ConvolutionFilterMotionBlur::BlurDir>(MBLUR_DIR_E_W));
          commands.push_back(motionCommand);
          i = i + 1;
        } else if (change.compare("-motionblur-ne-sw") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          MotionBlurFilterCommand* motionCommand = new MotionBlurFilterCommand
          (editor_, atof(argv[i + 1]),
          static_cast<ConvolutionFilterMotionBlur::BlurDir>(MBLUR_DIR_NE_SW));
          commands.push_back(motionCommand);
          i = i + 1;
        } else if (change.compare("-motionblur-nw-se") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          MotionBlurFilterCommand* motionCommand = new MotionBlurFilterCommand
          (editor_, atof(argv[i + 1]),
          static_cast<ConvolutionFilterMotionBlur::BlurDir>(MBLUR_DIR_NW_SE));
          commands.push_back(motionCommand);
          i = i + 1;
        } else if (change.compare("-quantize") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          QuantizeFilterCommand* quantizeCommand = new QuantizeFilterCommand
          (editor_, atof(argv[i + 1]));
          commands.push_back(quantizeCommand);
          i = i + 1;
        } else if (change.compare("-saturate") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          SaturateFilterCommand* saturateCommand = new SaturateFilterCommand
          (editor_, atof(argv[i + 1]));
          commands.push_back(saturateCommand);
          i = i + 1;
        } else {
          throw("invalid input\n" + ErrorMessage());
        }
      }
      ProcessIO(commands);
      editor_->SaveToFile(argv[argc-1]);
      for (int i = 0; i < static_cast<int>(commands.size()); i++) {
        commands[i] = NULL;
      }
    } catch (std::string msg1) {
      std::cerr << msg1 << std::endl;
    }
  }
}
//  main fucntion for gtest the only difference it froms the above function
//  is that it gets the commands from a string instead of a char**[] array;
void CommandLineProcessor::ProcessCommandLine_V2(int argc, std::string argv[]) {
  std::string filename = static_cast<std::string>(argv[1]);
  std::string outputfile = static_cast<std::string>(argv[argc-1]);
  if (argc < 3 ||(!(mingfx::Platform::FileExists(filename))) ||
  !(outputfile.find(".png") != std::string::npos)) {
    std::cout << "invalid input\n" + ErrorMessage() << std::endl;
    message = "invalid input\n" + ErrorMessage();
  } else {
    PixelBuffer newBuffer = PixelBuffer(argv[1]);
    ImageEditor *editor_ = new ImageEditor(&newBuffer);
    editor_->LoadFromFile(argv[1]);
    std::vector<ImageEditorCommand*>commands;
    try {
      for (int i  =  2; i < argc-1;  ++i) {
        std::string change = argv[i];
        if (change.compare("-blur") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          BlurFilterCommand* blurCommand = new BlurFilterCommand
          (editor_, stof(argv[i + 1]));
          commands.push_back(blurCommand);
          i = i + 1;
        } else if (change.compare("-edgedetect") == 0) {
          EdgeFilterCommand* edgeCommand = new EdgeFilterCommand(editor_);
          commands.push_back(edgeCommand);
        } else if (change.compare("-sharpen") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          SharpenFilterCommand *sharpenCommand = new SharpenFilterCommand
          (editor_, stof(argv[i + 1]));
          commands.push_back(sharpenCommand);
          i = i + 1;
        } else if (change.compare("-red") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          ChannelsFilterCommand* channelCommand = new ChannelsFilterCommand
          (editor_, stof(argv[i + 1]), 1.0, 1.0);
          commands.push_back(channelCommand);
          i = i + 1;
        } else if (change.compare("-blue") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          ChannelsFilterCommand* channelCommand = new ChannelsFilterCommand
          (editor_, 1.0, stof(argv[i + 1]), 1.0);
          commands.push_back(channelCommand);
          i = i + 1;
        } else if (change.compare("-green") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          ChannelsFilterCommand* channelCommand = new ChannelsFilterCommand
           (editor_, 1.0, 1.0, stof(argv[i + 1]));
          commands.push_back(channelCommand);
          i = i + 1;
        } else if (change.compare("-threshold") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          ThresholdFilterCommand* thresholdCommand = new ThresholdFilterCommand
          (editor_, stof(argv[i + 1]));
          commands.push_back(thresholdCommand);
          i = i + 1;
        } else if (change.compare("-motionblur-n-s") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          MotionBlurFilterCommand* motionCommand = new MotionBlurFilterCommand
          (editor_, stof(argv[i + 1]),
          static_cast<ConvolutionFilterMotionBlur::BlurDir>(MBLUR_DIR_N_S));
          commands.push_back(motionCommand);
          i = i + 1;
        } else if (change.compare("-motionblur-e-w") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          MotionBlurFilterCommand* motionCommand = new MotionBlurFilterCommand
          (editor_, stof(argv[i + 1]),
          static_cast<ConvolutionFilterMotionBlur::BlurDir>(MBLUR_DIR_E_W));
          commands.push_back(motionCommand);
          i = i + 1;
        } else if (change.compare("-motionblur-ne-sw") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          MotionBlurFilterCommand* motionCommand = new MotionBlurFilterCommand
          (editor_, stof(argv[i + 1]),
          static_cast<ConvolutionFilterMotionBlur::BlurDir>(MBLUR_DIR_NE_SW));
          commands.push_back(motionCommand);
          i = i + 1;
        } else if (change.compare("-motionblur-nw-se") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          MotionBlurFilterCommand* motionCommand = new MotionBlurFilterCommand
          (editor_, stof(argv[i + 1]),
          static_cast<ConvolutionFilterMotionBlur::BlurDir>(MBLUR_DIR_NW_SE));
          commands.push_back(motionCommand);
          i = i + 1;
        } else if (change.compare("-quantize") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          QuantizeFilterCommand* quantizeCommand = new QuantizeFilterCommand
          (editor_, stof(argv[i + 1]));
          commands.push_back(quantizeCommand);
          i = i + 1;
        } else if (change.compare("-saturate") == 0) {
          std::string change1 = IOHandler(argv[i + 1]);
          SaturateFilterCommand* saturateCommand = new SaturateFilterCommand
          (editor_, stof(argv[i + 1]));
          commands.push_back(saturateCommand);
          i = i + 1;
        } else {
          throw("invalid input\n" + ErrorMessage());
        }
      }
      ProcessIO(commands);
      editor_->SaveToFile(argv[argc-1]);
      for (int i = 0; i < static_cast<int>(commands.size()); i++) {
        delete commands[i];
        commands[i] = NULL;
      }
    } catch (std::string msg1) {
      std::cerr << msg1 << std::endl;
    }
  }
}
std::string CommandLineProcessor::GetMessage() {
  return message;
}

}  // namespace image_tools
