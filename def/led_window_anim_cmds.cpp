/*
  Dorm LED Project: led_window_anim_cmds.cpp
  This file contains the window LED animation commands.

  These are meant to be executed using the multithreaded system.
  Note: First element in the var stack is to store number of complete executions (resetable).

  Created by: Michael Fischler
  10/22/2016 @ WPI
*/

/*
  Template for a Command
  std::vector<int> (*cmd)(std::vector<int>)

  std::vector<int> cmd(std::vector<int> var_stack){
    // set variables
    int i = var_stack.at(0);
    int t = var_stack.at(1);

    // run command code
    ...

    // update variables
    var_stack.at(0) = i;
    var_stack.at(1) = t;

    return var_stack;
  }
*/

/* ~~~~~~ Off Commands ~~~~~~ */

// &&& Functions for Off Commands &&&

// &&& Command Ready Functions for Off Commands &&&

/* ~~~~~~ Static Commands ~~~~~~ */

// &&& Functions for Static Commands &&&

// &&& Command Ready Functions for Animated Commands &&&

/* ~~~~~~ Animated Commands ~~~~~~ */

// &&& Functions for Animated Commands &&&

void _win_all_purple_fade(int i){
  for(int x = 0; x < WINDOW_LENGTH; x++){
    setAllWindowPixelColor(x, window_generic.Color((int)(((float)i / 150.0) * 100), 0, i));
  }

  showAllWindowStrips();
}

void _win_all_WPI_spirit(int i, short int mode){
  //uint8_t red = window_generic.Color(172, 43, 55);
  //uint8_t white = window_generic.Color(169, 176, 183);

  if(mode == 0){
    window1.setPixelColor(i, window_generic.Color(255, 21, 27));

    if(i%2 == 0){
      window2.setPixelColor(i, window_generic.Color(169, 176, 183));
    }else{
      window2.setPixelColor(i, window_generic.Color(255, 21, 27));
    }

    int modified = WINDOW_LENGTH + 9 - 1 - i;

    if(modified >= WINDOW_LENGTH){
      modified -= WINDOW_LENGTH;
    }

    window3.setPixelColor(modified, window_generic.Color(255, 21, 27));
  }else if(mode == 1){
    window1.setPixelColor(i, window_generic.Color(169, 176, 183));

    for(int j = 0; j < WINDOW_LENGTH; j++){
      if(i%2 != 0){
        window2.setPixelColor(i, window_generic.Color(169, 176, 183));
      }else{
        window2.setPixelColor(i, window_generic.Color(255, 21, 27));
      }
    }

    int modified = WINDOW_LENGTH + 9 - 1 - i;

    if(modified >= WINDOW_LENGTH){
      modified -= WINDOW_LENGTH;
    }

    window3.setPixelColor(modified, window_generic.Color(169, 176, 183));
  }

  window1.show();
  window3.show();
}

void _win_all_halloween_fade(int i){
    for(int x = 0; x < WINDOW_LENGTH; x++){
        window1.setPixelColor(x, window_generic.Color(i, (int)(((float)i / 255.0) * 50), 0));
        window2.setPixelColor(x, window_generic.Color((int)(((float)i / 255.0) * 150), 0, i));
        window3.setPixelColor(x, window_generic.Color(i, (int)(((float)i / 255.0) * 50), 0));
    }

    showAllWindowStrips();
}

unsigned long int _rand_halloween_color(){
  unsigned long int bright_orange = window_generic.Color(255, 50, 0);
  unsigned long int medium_orange = window_generic.Color(190, 37, 0);
  unsigned long int dim_orange = window_generic.Color(100, 20, 0);

  unsigned long int bright_purple = window_generic.Color(150, 0, 255);
  unsigned long int medium_purple = window_generic.Color(112, 0, 190);
  unsigned long int dim_purple = window_generic.Color(59, 0, 100);

  unsigned long int off = window_generic.Color(0,0,0);

  long int r = random(0,7);

  switch(r){
    case 0:
      return off;
    case 1:
      return bright_orange;
    case 2:
      return medium_orange;
    case 3:
      return dim_orange;
    case 4:
      return bright_purple;
    case 5:
      return medium_purple;
    case 6:
      return dim_purple;
  }
}

void _win_all_halloween_sparkle_randomize(){
  // randomly assign each pixel :D
  for(int x = 0; x < WINDOW_LENGTH; x++){
    window1.setPixelColor(x, _rand_halloween_color());
    window2.setPixelColor(x, _rand_halloween_color());
    window3.setPixelColor(x, _rand_halloween_color());
  }

  showAllWindowStrips();
}

void _win_all_halloween_sparkle_fade(int i){
  // fade with absolute value since so many different values

  for(int x = 0; x < WINDOW_LENGTH; x++){
    unsigned long int color = window1.getPixelColor(x);

    unsigned int red = redFromColor(color);
    unsigned int green = greenFromColor(color);
    unsigned int blue = blueFromColor(color);

    if(red == 0){
      // is off, randomly pick a color
      long int r = random(0,2);
      if(r == 0){
        window1.setPixelColor(x, window_generic.Color(
          1,
          0,
          2));
      }else{
        window1.setPixelColor(x, window_generic.Color(
          5,
          1,
          0));
      }
    }else if(green == 0){
      // was purple
      window1.setPixelColor(x, window_generic.Color(
        abs(red + (int)(((float)i / 255.0) * 150) - 150),
        0,
        abs(blue + i - 255)));
    }else if(blue == 0){
      // was orange
      window1.setPixelColor(x, window_generic.Color(
        abs(red + i - 255),
        abs(green + (int)(((float)i / 255.0) * 50) - 50),
        0));
    }
  }

  for(int x = 0; x < WINDOW_LENGTH; x++){
    unsigned long int color = window2.getPixelColor(x);

    unsigned int red = redFromColor(color);
    unsigned int green = greenFromColor(color);
    unsigned int blue = blueFromColor(color);

    if(red == 0){
      // is off, randomly pick a color
      long int r = random(0,2);
      if(r == 0){
        window2.setPixelColor(x, window_generic.Color(
          1,
          0,
          2));
      }else{
        window2.setPixelColor(x, window_generic.Color(
          5,
          1,
          0));
      }
    }else if(green == 0){
      // was purple
      window2.setPixelColor(x, window_generic.Color(
        abs(red - (int)(((float)i / 255.0) * 150)),
        0,
        abs(blue - i)));
    }else if(blue == 0){
      // was orange
      window2.setPixelColor(x, window_generic.Color(
        abs(red - i),
        abs(green - (int)(((float)i / 255.0) * 50)),
        0));
    }
  }

  for(int x = 0; x < WINDOW_LENGTH; x++){
    unsigned long int color = window3.getPixelColor(x);

    unsigned int red = redFromColor(color);
    unsigned int green = greenFromColor(color);
    unsigned int blue = blueFromColor(color);

    if(red == 0){
      // is off, randomly pick a color
      long int r = random(0,2);
      if(r == 0){
        window3.setPixelColor(x, window_generic.Color(
          1,
          0,
          2));
      }else{
        window3.setPixelColor(x, window_generic.Color(
          5,
          1,
          0));
      }
    }else if(green == 0){
      // was purple
      window3.setPixelColor(x, window_generic.Color(
        abs(((float)red/150.0)*255.0 - (float)i),
        0,
        abs(blue - i)));
    }else if(blue == 0){
      // was orange
      window3.setPixelColor(x, window_generic.Color(
        abs(red - i),
        abs(green - (int)(((float)i / 255.0) * 50)),
        0));
    }
  }

  showAllWindowStrips();
}

void _win_1_snow(int i, int left_spacing, int right_spacing){
  // let it snooww
  // let it snowwwww
  // let it snowwwwwwwwww
  int rightBottom = 9;
  int rightTop = 40;
  int leftTop = 50;
  int leftBottom = 80;

  // 39 pixels
  int leftFullLength = 41;
  // 40 pixels
  int rightFullLength = 41;

  unsigned long int off = window_generic.Color(0,0,0);
  unsigned long int on  = window_generic.Color(150,150,150);
  unsigned long int left = window_generic.Color(150,0,0);
  unsigned long int right = window_generic.Color(0,150,0);

  int a = 40 - abs(40 - i % 80);

  // handle top and bottom for christmas
  // left top
  for (int x = leftTop - 4; x < leftTop; x++) {
    int rel_index = x - leftTop + 4;

    if (rel_index < a % leftFullLength) {
      window1.setPixelColor(x, left);
    } else {
      window1.setPixelColor(x, off);
    }
  }

  // right top
  for (int x = rightTop + 1; x <= rightTop + 5; x++) {
    int rel_index = x - 6;

    if (rel_index < a % rightFullLength) {
      window1.setPixelColor(x, right);
    } else {
      window1.setPixelColor(x, off);
    }
  }

  // left bottom
  for (int x = 4; x >= 0; x--) {
    int rel_index = x + 35;

    if (rel_index < a % rightFullLength) {
      window1.setPixelColor(x, left);
    } else {
      window1.setPixelColor(x, off);
    }
  }

  // right bottom
  for (int x = 5; x < rightBottom; x++) {
    int rel_index = x - 5;

    if (rel_index < a % rightFullLength) {
      window1.setPixelColor(x, right);
    } else {
      window1.setPixelColor(x, off);
    }
  }

  // set each right pixel
  for (int x = rightBottom; x <= rightTop; x++) {
    int rel_index = x - rightBottom;

    if (rel_index % right_spacing == (800 - i) % right_spacing) {
      window1.setPixelColor(x, on);
    } else {
      if (x - 4 < a % rightFullLength) {
        window1.setPixelColor(x, right);
      } else {
        window1.setPixelColor(x, off);
      }
    }
  }

  // set each left pixel
  for (int x = leftTop; x <= leftBottom; x++){
    int rel_index = x - leftTop;

    if (rel_index % left_spacing == i % left_spacing) {
      window1.setPixelColor(x, on);
    } else {
      if (rel_index + 4 < a % leftFullLength) {
        window1.setPixelColor(x, left);
      } else {
        window1.setPixelColor(x, off);
      }
    }
  }

  window1.show();
}

void _win_2_snow(int i, int left_spacing, int right_spacing){
  // let it snooww
  // let it snowwwww
  // let it snowwwwwwwwww
  int rightBottom = 9;
  int rightTop = 40;
  int leftTop = 50;
  int leftBottom = 80;

  // 39 pixels
  int leftFullLength = 41;
  // 40 pixels
  int rightFullLength = 41;

  unsigned long int off = window_generic.Color(0,0,0);
  unsigned long int on  = window_generic.Color(150,150,150);
  unsigned long int left = window_generic.Color(0,0,150);
  unsigned long int right = window_generic.Color(0,0,150);

  int a = 40 - abs(40 - i % 80);

  // handle top and bottom for christmas
  // left top
  for (int x = leftTop - 4; x < leftTop; x++) {
    int rel_index = x - leftTop + 4;

    if (rel_index < a % leftFullLength) {
      window2.setPixelColor(x, left);
    } else {
      window2.setPixelColor(x, off);
    }
  }

  // right top
  for (int x = rightTop + 1; x <= rightTop + 5; x++) {
    int rel_index = x - 6;

    if (rel_index < a % rightFullLength) {
      window2.setPixelColor(x, right);
    } else {
      window2.setPixelColor(x, off);
    }
  }

  // left bottom
  for (int x = 4; x >= 0; x--) {
    int rel_index = x + 35;

    if (rel_index < a % rightFullLength) {
      window2.setPixelColor(x, left);
    } else {
      window2.setPixelColor(x, off);
    }
  }

  // right bottom
  for (int x = 5; x < rightBottom; x++) {
    int rel_index = x - 5;

    if (rel_index < a % rightFullLength) {
      window2.setPixelColor(x, right);
    } else {
      window2.setPixelColor(x, off);
    }
  }

  // set each right pixel
  for (int x = rightBottom; x <= rightTop; x++) {
    int rel_index = x - rightBottom;

    if (rel_index % right_spacing == (800 - i) % right_spacing) {
      window2.setPixelColor(x, on);
    } else {
      if (x - 4 < a % rightFullLength) {
        window2.setPixelColor(x, right);
      } else {
        window2.setPixelColor(x, off);
      }
    }
  }

  // set each left pixel
  for (int x = leftTop; x <= leftBottom; x++){
    int rel_index = x - leftTop;

    if (rel_index % left_spacing == i % left_spacing) {
      window2.setPixelColor(x, on);
    } else {
      if (rel_index + 4 < a % leftFullLength) {
        window2.setPixelColor(x, left);
      } else {
        window2.setPixelColor(x, off);
      }
    }
  }

  window2.show();
}

void _win_3_snow(int i, int left_spacing, int right_spacing){
  // let it snooww
  // let it snowwwww
  // let it snowwwwwwwwww
  int rightBottom = 9;
  int rightTop = 40;
  int leftTop = 50;
  int leftBottom = 80;

  // 39 pixels
  int leftFullLength = 41;
  // 40 pixels
  int rightFullLength = 41;

  unsigned long int off = window_generic.Color(0,0,0);
  unsigned long int on  = window_generic.Color(150,150,150);
  unsigned long int left = window_generic.Color(0,150,0);
  unsigned long int right = window_generic.Color(150,0,0);

  int a = 40 - abs(40 - i % 80);

  // handle top and bottom for christmas
  // left top
  for (int x = leftTop - 4; x < leftTop; x++) {
    int rel_index = x - leftTop + 4;

    if (rel_index < a % leftFullLength) {
      window3.setPixelColor(x, left);
    } else {
      window3.setPixelColor(x, off);
    }
  }

  // right top
  for (int x = rightTop + 1; x <= rightTop + 5; x++) {
    int rel_index = x - 6;

    if (rel_index < a % rightFullLength) {
      window3.setPixelColor(x, right);
    } else {
      window3.setPixelColor(x, off);
    }
  }

  // left bottom
  for (int x = 4; x >= 0; x--) {
    int rel_index = x + 35;

    if (rel_index < a % rightFullLength) {
      window3.setPixelColor(x, left);
    } else {
      window3.setPixelColor(x, off);
    }
  }

  // right bottom
  for (int x = 5; x < rightBottom; x++) {
    int rel_index = x - 5;

    if (rel_index < a % rightFullLength) {
      window3.setPixelColor(x, right);
    } else {
      window3.setPixelColor(x, off);
    }
  }

  // set each right pixel
  for (int x = rightBottom; x <= rightTop; x++) {
    int rel_index = x - rightBottom;

    if (rel_index % right_spacing == (800 - i) % right_spacing) {
      window3.setPixelColor(x, on);
    } else {
      if (x - 4 < a % rightFullLength) {
        window3.setPixelColor(x, right);
      } else {
        window3.setPixelColor(x, off);
      }
    }
  }

  // set each left pixel
  for (int x = leftTop; x <= leftBottom; x++){
    int rel_index = x - leftTop;

    if (rel_index % left_spacing == i % left_spacing) {
      window3.setPixelColor(x, on);
    } else {
      if (rel_index + 4 < a % leftFullLength) {
        window3.setPixelColor(x, left);
      } else {
        window3.setPixelColor(x, off);
      }
    }
  }

  window3.show();
}

// &&& Command Ready Functions for Animated Commands &&&

// Every LED fades in and out a with calm purple
// Initial input var_stack : std::vector<int> stack{0,0,1}
std::vector<int> win_all_purple_fade(std::vector<int> var_stack){
  // set variables
  int fec = var_stack.at(0);
  int i = var_stack.at(1);
  short int increasing = var_stack.at(2);

  // run command code
  _win_all_purple_fade(i);

  if(increasing == 1){
    if(i == 150){
      i--;
      increasing = 0;
    }else{
      i++;
    }
  }else{
    if(i == 0){
      i++;
      increasing = 1;
      fec++;
    }else{
      i--;
    }
  }

  // update variables
  var_stack.at(0) = fec;
  var_stack.at(1) = i;
  var_stack.at(2) = increasing;

  return var_stack;
}

// A spirited display for my college, WPI
// Initial input var_stack : std::vector<int> stack{0,0,0}
std::vector<int> win_all_WPI_spirit(std::vector<int> var_stack){
  // set variables
  int fec = var_stack.at(0);
  int i = var_stack.at(1);
  short int mode = var_stack.at(2);

  // run command code
  _win_all_WPI_spirit(i, mode);

  if(mode == 0){
    if(i + 1 == WINDOW_LENGTH){
      i = 0;
      mode = 1;
      window2.show();
    }else{
      i++;
    }
  }else if(mode == 1){
    if(i + 1 == WINDOW_LENGTH){
      i = 0;
      mode = 0;
      window2.show();
      fec++;
    }else{
      i++;
    }
  }

  // update variables
  var_stack.at(0) = fec;
  var_stack.at(1) = i;
  var_stack.at(2) = mode;

  return var_stack;
}

// Rainbow Color Wipe for first window
// Initial input var_stack : std::vector<int> stack {0,0,0}
std::vector<int> win_1_rainbow_wipe(std::vector<int> var_stack){
  // set variables
  int fec = var_stack.at(0);
  int i = var_stack.at(1);
  int color_mode = var_stack.at(2);

  // run command code
  if(color_mode % 2 != 0){
    window1.setPixelColor(i, window_generic.Color(0, 0, 0)); // Off
  }else if(color_mode == 0){
    window1.setPixelColor(i, window_generic.Color(255, 0, 0)); // Red
  }else if(color_mode == 2){
    window1.setPixelColor(i, window_generic.Color(255, 50, 0)); // Orange
  }else if(color_mode == 4){
    window1.setPixelColor(i, window_generic.Color(255, 150, 0)); // Yellow
  }else if(color_mode == 6){
    window1.setPixelColor(i, window_generic.Color(0, 255, 0)); // Green
  }else if(color_mode == 8){
    window1.setPixelColor(i, window_generic.Color(0, 255, 200)); // Sea Green
  }else if(color_mode == 10){
    window1.setPixelColor(i, window_generic.Color(0, 0, 255)); // Blue
  }else if(color_mode == 12){
    window1.setPixelColor(i, window_generic.Color(100, 0, 255)); // Indigo
  }else if(color_mode == 14){
    window1.setPixelColor(i, window_generic.Color(255, 0, 255)); // Violet
  }

  window1.show();

  i++;

  if(i == WINDOW_LENGTH){
    color_mode++;
    i = 0;

    if(color_mode == 16){
      color_mode = 0;
      fec++;
    }
  }

  // update variables
  var_stack.at(0) = fec;
  var_stack.at(1) = i;
  var_stack.at(2) = color_mode;

  return var_stack;
}

// Rainbow Color Wipe for second window
// Initial input var_stack : std::vector<int> stack {0,0,0}
std::vector<int> win_2_rainbow_wipe(std::vector<int> var_stack){
  // set variables
  int fec = var_stack.at(0);
  int i = var_stack.at(1);
  int color_mode = var_stack.at(2);

  // run command code
  if(color_mode % 2 != 0){
    window2.setPixelColor(i, window_generic.Color(0, 0, 0)); // Off
  }else if(color_mode == 0){
    window2.setPixelColor(i, window_generic.Color(255, 0, 0)); // Red
  }else if(color_mode == 2){
    window2.setPixelColor(i, window_generic.Color(255, 50, 0)); // Orange
  }else if(color_mode == 4){
    window2.setPixelColor(i, window_generic.Color(255, 150, 0)); // Yellow
  }else if(color_mode == 6){
    window2.setPixelColor(i, window_generic.Color(0, 255, 0)); // Green
  }else if(color_mode == 8){
    window2.setPixelColor(i, window_generic.Color(0, 255, 200)); // Sea Green
  }else if(color_mode == 10){
    window2.setPixelColor(i, window_generic.Color(0, 0, 255)); // Blue
  }else if(color_mode == 12){
    window2.setPixelColor(i, window_generic.Color(100, 0, 255)); // Indigo
  }else if(color_mode == 14){
    window2.setPixelColor(i, window_generic.Color(255, 0, 255)); // Violet
  }

  window2.show();

  i++;

  if(i == WINDOW_LENGTH){
    color_mode++;
    i = 0;

    if(color_mode == 16){
      color_mode = 0;
      fec++;
    }
  }

  // update variables
  var_stack.at(0) = fec;
  var_stack.at(1) = i;
  var_stack.at(2) = color_mode;

  return var_stack;
}

// Rainbow Color Wipe for third window
// Initial input var_stack : std::vector<int> stack {0,0,0}
std::vector<int> win_3_rainbow_wipe(std::vector<int> var_stack){
  // set variables
  int fec = var_stack.at(0);
  int i = var_stack.at(1);
  int color_mode = var_stack.at(2);

  // run command code
  if(color_mode % 2 != 0){
    window3.setPixelColor(i, window_generic.Color(0, 0, 0)); // Off
  }else if(color_mode == 0){
    window3.setPixelColor(i, window_generic.Color(255, 0, 0)); // Red
  }else if(color_mode == 2){
    window3.setPixelColor(i, window_generic.Color(255, 50, 0)); // Orange
  }else if(color_mode == 4){
    window3.setPixelColor(i, window_generic.Color(255, 150, 0)); // Yellow
  }else if(color_mode == 6){
    window3.setPixelColor(i, window_generic.Color(0, 255, 0)); // Green
  }else if(color_mode == 8){
    window3.setPixelColor(i, window_generic.Color(0, 255, 200)); // Sea Green
  }else if(color_mode == 10){
    window3.setPixelColor(i, window_generic.Color(0, 0, 255)); // Blue
  }else if(color_mode == 12){
    window3.setPixelColor(i, window_generic.Color(100, 0, 255)); // Indigo
  }else if(color_mode == 14){
    window3.setPixelColor(i, window_generic.Color(255, 0, 255)); // Violet
  }

  window3.show();

  i++;

  if(i == WINDOW_LENGTH){
    color_mode++;
    i = 0;

    if(color_mode == 16){
      color_mode = 0;
      fec++;
    }
  }

  // update variables
  var_stack.at(0) = fec;
  var_stack.at(1) = i;
  var_stack.at(2) = color_mode;

  return var_stack;
}

// Have a fade in and out of orange on window 1, purple on window 2, and orange on window 3
// Initial input var_stack : std::vector<int> stack {0,0,1}
std::vector<int> win_all_halloween_fade(std::vector<int> var_stack){
    // set variables
    int fec = var_stack.at(0);
    int i = var_stack.at(1);
    int increasing = var_stack.at(2);

    // run command code
    _win_all_halloween_fade(i);

    if(increasing == 1){
        if(i == 255){
            i--;
            increasing = 0;
        }else{
            i++;
        }
    }else{
        if(i == 0){
            i++;
            increasing = 1;
            fec++;
        }else{
            i--;
        }
    }

    // update variables
    var_stack.at(0) = fec;
    var_stack.at(1) = i;
    var_stack.at(2) = increasing;

    return var_stack;
}

// Have a randomized sparkle effect of halloween colors on all windows.
// Initial input var_stack : std::vector<int> stack {0,0,0}
std::vector<int> win_all_halloween_sparkle(std::vector<int> var_stack){
  // set variables
  int fec = var_stack.at(0);
  int i = var_stack.at(1);
  int mode = var_stack.at(2);

  // run command code
  if(mode == 0){
    // randomize
    _win_all_halloween_sparkle_randomize();
    mode = 1;
  }else if(mode == 1){
    // fade for a bit
    _win_all_halloween_sparkle_fade(i);

    i++;

    if(i == 256){
      i = 0;
      mode = 0;
      fec++;
    }
  }

  // update variables
  var_stack.at(0) = fec;
  var_stack.at(1) = i;
  var_stack.at(2) = mode;

  return var_stack;
}

std::vector<int> win_snow(std::vector<int> var_stack){
  // set variables
  int fec = var_stack.at(0);
  int i = var_stack.at(1);
  int left_1 = var_stack.at(2);
  int right_1 = var_stack.at(3);
  int left_2 = var_stack.at(4);
  int right_2 = var_stack.at(5);
  int left_3 = var_stack.at(6);
  int right_3 = var_stack.at(7);
  int mode = var_stack.at(8);

  // run command code
  if(mode == 0){
    // randomize
    left_1 = random(3,8);
    right_1 = random(3,8);
    left_2 = random(3,8);
    right_2 = random(3,8);
    left_3 = random(3,8);
    right_3 = random(3,8);

    // snow fall
    _win_1_snow(i, left_1, right_1);
    _win_2_snow(i, left_2, right_2);
    _win_3_snow(i, left_3, right_3);

    mode = 1;
  }else if(mode == 1){
    // snow fall
    _win_1_snow(i, left_1, right_1);
    _win_2_snow(i, left_2, right_2);
    _win_3_snow(i, left_3, right_3);

    i++;
    // 40 for a loop one direction, 80 for a full forwards and backwards
    if(i == 800){
      i = 0;
      mode = 0;
      fec++;
    }
  }

  // update variables
  var_stack.at(0) = fec;
  var_stack.at(1) = i;
  var_stack.at(2) = left_1;
  var_stack.at(3) = right_1;
  var_stack.at(4) = left_2;
  var_stack.at(5) = right_2;
  var_stack.at(6) = left_3;
  var_stack.at(7) = right_3;
  var_stack.at(8) = mode;

  return var_stack;

}
