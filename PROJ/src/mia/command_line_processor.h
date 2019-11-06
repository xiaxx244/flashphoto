/// copyright Youya Xia,2018

#ifndef MIA_COMMAND_LINE_PROCESSOR_H_
#define MIA_COMMAND_LINE_PROCESSOR_H_
#include <stdlib.h>
#include <stdio.h>

#include <mingfx.h>
#include <string>
#include <vector>
#include <fstream>
#include "imagetools/color_data.h"
#include "imagetools/image_editor.h"
#include "imagetools/pixel_buffer.h"
#include "mia/image_editor_commands.h"
namespace image_tools {

/** @brief The  CommandLine Procssor class to handle the IO from user
(Load ,do image processing to the loaded PNG files and save the processed
images based on users'commands) */
class CommandLineProcessor{
 public:
  CommandLineProcessor();
  virtual ~CommandLineProcessor();
  enum MBlurDir { MBLUR_DIR_N_S, MBLUR_DIR_E_W, MBLUR_DIR_NE_SW,
      MBLUR_DIR_NW_SE };
  ///  the main function to process users'IO;
  void ProcessCommandLine(int argc, char* argv[]);
  ///  the function desgined for gtests;
  void ProcessCommandLine_V2(int argc, std::string argv[]);
  ///  the function to handle the input error that may arised from users'IO;
  std::string IOHandler(std::string  target);
  ///  the function to execute the commands processed from the input of users;
  void ProcessIO(std::vector<ImageEditorCommand*>commands);
  ///  the function that returns the error message to users;
  std::string ErrorMessage();
  /// get the error message of file error;
  std::string GetMessage();

 private:
  // the private variable to define the error message of file error;
  std::string message;
};

}  // namespace image_tools

#endif  // MIA_COMMAND_LINE_PROCESSOR_H_
