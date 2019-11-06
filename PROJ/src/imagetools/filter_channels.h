/**
This file is part of the CSCI-3081W Project Support Code, which was developed
at the University of Minnesota.

This code is to be used for student coursework.  It is not an open source
project.
Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
Minnesota.

Original Author(s) of this File:
  Seth Johnson, 2/15/15, University of Minnesota

Author(s) of Significant Updates/Modifications to the File:
  ...
*/

#ifndef IMAGETOOLS_FILTER_CHANNELS_H_
#define IMAGETOOLS_FILTER_CHANNELS_H_

#include <stdio.h>
#include "imagetools/filter.h"

namespace image_tools {

/** @brief Filter one or more of the RGB channels, scaling each by the specified
 amount.  Scale factors of 1.0 have no affect.  Less than 1.0 "turns down" the
 intensity of the corresponding channel, and greater than 1.0 "turns up" the
 intensity.
 */
class FilterChannels : public Filter {
 public:
  FilterChannels(float r, float g, float b);
  FilterChannels();
  virtual ~FilterChannels();

  ColorData CalculateFilteredPixel(const PixelBuffer &buffer, int x,
                                           int y) override;

  float red_scale_factor();
  void set_red_scale_factor(float s);

  float green_scale_factor();
  void set_green_scale_factor(float s);

  float blue_scale_factor();
  void set_blue_scale_factor(float s);

 private:
  float red_;   /**< Red scaling factor  */
  float green_; /**< Green scaling factor  */
  float blue_;  /**< Blue scaling factor  */
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_CHANNELS_H_
