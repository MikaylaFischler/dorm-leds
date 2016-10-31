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

void _win_all_wpp_fade(int i){
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
        window1.setPixelColor(i, window_generic.Color(i, (int)(((float)i / 255.0) * 50), 0));
        window2.setPixelColor(i, window_generic.Color((int)(((float)i / 255.0) * 100), 0, i));
        window3.setPixelColor(i, window_generic.Color(i, (int)(((float)i / 255.0) * 50), 0));
    }

    showAllWindowStrips();
}

// &&& Command Ready Functions for Animated Commands &&&

// Every LED fades in and out a with calm purple
// Initial input var_stack : std::vector<int> stack{0,1}
std::vector<int> win_all_wpp_fade(std::vector<int> var_stack){
  // set variables
  int fec = var_stack.at(0);
  int i = var_stack.at(1);
  short int increasing = var_stack.at(2);

  // run command code
  _win_all_wpp_fade(i);

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
    }else{
      i--;
    }
  }

  // update variables
  var_stack.at(0) = fec++;
  var_stack.at(1) = i;
  var_stack.at(2) = increasing;

  return var_stack;
}

// A spirited display for my college, WPI
// Initial input var_stack : std::vector<int> stack{0,0}
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
    }else{
      i++;
    }
  }

  // update variables
  var_stack.at(0) = fec++;
  var_stack.at(1) = i;
  var_stack.at(2) = mode;

  return var_stack;
}

// Rainbow Color Wipe for first window
// Initial input var_stack : std::vector<int> stack {0,0}
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
    }
  }

  // update variables
  var_stack.at(0) = fec++;
  var_stack.at(1) = i;
  var_stack.at(2) = color_mode;

  return var_stack;
}

// Rainbow Color Wipe for second window
// Initial input var_stack : std::vector<int> stack {0,0}
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
    }
  }

  // update variables
  var_stack.at(0) = fec++;
  var_stack.at(1) = i;
  var_stack.at(2) = color_mode;

  return var_stack;
}

// Rainbow Color Wipe for third window
// Initial input var_stack : std::vector<int> stack {0,0}
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
    }
  }

  // update variables
  var_stack.at(0) = fec++;
  var_stack.at(1) = i;
  var_stack.at(2) = color_mode;

  return var_stack;
}

// Have a fade in and out of orange on window 1, purple on window 2, and orange on window 3
// Initial input var_stack : std::vector<int> stack {0,1}
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
        }else{
            i--;
        }
    }

    // update variables
    var_stack.at(0) = fec++;
    var_stack.at(1) = i;
    var_stack.at(2) = increasing;

    return var_stack;
}
