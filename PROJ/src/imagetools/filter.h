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

#ifndef IMAGETOOLS_FILTER_H_
#define IMAGETOOLS_FILTER_H_

#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

/** @brief The base class for image processing filters that can be used to
 modify a PixelBuffer.  The ApplyToBuffer method implements a template algorithm
 that applies to all filters, and the other methods of the class provide hooks
 for sub-classes to modify specific steps of that algorithm. */
class Filter {
 public:
  Filter();
  virtual ~Filter();

  /** @brief Applies this filter to the buffer, changing the buffer.
   This is a template method that follows a 3-step recipe:
   1. check to see if the filter works in-place, if not make a tmp copy of the
      buffer to use as the source for the calculations.
   2. loop through all pixels in the buffer using CalculateFilteredPixel to
      determine the new color for each pixel and save it in buffer.
   3. clean up by deleting the tmp buffer if one was needed.

   @param[in] buffer Both the source for the pixel data to filter and the
   destination for the result.
   */
  void ApplyToBuffer(PixelBuffer *buffer);

  /** @brief True if this filter can calculate the new filtered image without
   making a temporary copy of the input buffer.  Note that convolution-based
   filters must make a tmp copy because the new pixel color depends not just
   on the original pixel color but also on its neighbors, some of which will
   already have been overwritten if the filters were to run in place.

   The default implementation returns true; so, most simple filters will not
   need to override this method, but convolution-based filters will.
   */
  virtual bool can_calculate_in_place() const;

  /** @brief Hook for the major calculation that happens for each pixel during
   the ApplyToBuffer template.  The default implementation simply returns the
   color originally in the buffer.

   @param[in] buffer The buffer to filter
   @param[in] x X position of the pixel to filter
   @param[in] y Y position of the pixel to filter
   @return The filtered version of the color at pixel (x,y)
   */
  virtual ColorData CalculateFilteredPixel(const PixelBuffer &buffer, int x,
                                           int y);

  /** Hook for the setup step that is part of the ApplyToBuffer template.  The
   default implementation does nothing. */
  virtual void SetupFilter();

  /** Hook for the cleanup step that is part of the ApplyToBuffer template.  The
   default implementation does nothing. */
  virtual void CleanupFilter();
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_H_
