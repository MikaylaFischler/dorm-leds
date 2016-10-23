/*
  Dorm LED Project: led_window_anim_cmds.cpp
  This file contains the window LED animation commands.

  These are meant to be executed using the multithreaded system.

  Created by: Michael Fischler
  10/22/2016 @ WPI
*/

/*
  Template for a Command
  std::vector<var> (*cmd)(std::vector<var>)

  std::vector<var> cmd(std::vector<var> var_stack){
    // set variables
    int i = var_stack.at(0).value;
    int t = var_stack.at(1).value;

    // run command code
    ...

    // update variables
    var_stack.at(0).value = i;
    var_stack.at(1).value = t;

    return var_stack;
  }
*/
