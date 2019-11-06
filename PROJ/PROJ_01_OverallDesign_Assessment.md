### Assessment for Project Iteration 01 - OverallDesign (Graded By: Dan Orban)

#### Total score: _14_ / _15_

Run on November 25, 08:22:43 AM.

+ Pass: Switch to correct commit.



+ Pass: Change into directory "PROJ".


### Overall Design Analysis


#### Flash Photo App Implementation

+  _0_ / _1_ : Pass: Undo / Redo has been merged correctly.

    <pre>Be sure to call SaveStateForPossibleUndo() before applying the filters.</pre>

+  _2_ / _2_ : Pass: Member variables are defined correctly.

    <pre>Recommendation: Use filter member variables to save on expensive create and delete calls.</pre>

+  _1_ / _1_ : Pass: Member variables are initialized.

    <pre>Recommendation: Make sure you initialize the max_undos_ variable</pre>

+  _2_ / _2_ : Pass: Interacting with simple filters.

    

+  _2_ / _2_ : Pass: Interacting with convolution filters.

    


#### Motion blur enums should be handled in an appropriate fashion (ex. by static casting between types or passing strings).

+  _1_ / _1_ : Pass: Motion blur is handled well.

    <pre>Recommendation: Use enumerations rather than string compare</pre>

+ Pass: Motion blur enum is in the right place.

    <pre>Recommendation: Move MBlurDir enum into Filter Convolution Motion Blur class.</pre>


#### Overall Design

+  _1_ / _1_ : Pass: Objects are initialized correctly.

    

+  _1_ / _1_ : Pass: Objects are destructed correctly.

    

+  _2_ / _2_ : Pass: Memory Management: Pointers and references are used correctly.

    

+  _2_ / _2_ : Pass: Overall Comments.

    

#### Total score: _14_ / _15_

