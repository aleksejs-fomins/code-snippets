CXX?=g++
CFLAGS = -Wall -Wextra -pedantic -O3 -std=c++11

all: myprog

myprog: myprog.cc haha/bullshit.hh
	$(CXX) $(CFLAGS) -o $@ $< -Ihaha

clean:
	rm -rf myprog
