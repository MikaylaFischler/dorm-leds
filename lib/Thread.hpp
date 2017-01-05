#ifndef Thread_H
#define Thread_H

#include "Command.h"

class Thread {
  unsigned int id;
  Command* cmd;
  unsigned long int updateRate;
  unsigned long int timeSum;
public:
  Thread(unsigned int id, Command* cmd, unsigned long int t);
  ~Thread();
  unsigned int getID();
  Command* getCMD();
  unsigned long int getUpdateRate();
  unsigned long int getTimeSum();
  void addTimeSum(unsigned int dT);
  void zeroTimeSum();
};

#endif
