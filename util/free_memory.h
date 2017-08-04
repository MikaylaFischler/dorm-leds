// MemoryFree library based on code posted here:
// http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1213583720/15
// Extended by Matthew Murdoch to include walking of the free list.
// Re-formatted and simplified for this use case by Michael Fischler

#ifndef FREE_MEMORY_H_
#define FREE_MEMORY_H_

int freeMemory();

int mem_available = 0;

#endif
