# $Id: Makefile,v 1.30 2009/11/11 17:18:14 gcowan Exp $
SHELL = /bin/sh
UNAME = $(shell uname)

################
##linux
CXX          = g++
RM           = rm -f
AR           = ar cru

CXXFLAGS = -O3 -std=c++11 -Wall

GARBAGE  = $(OBJDIR)/*.o *.so

Rootfinder: Main.cpp Functions.cpp Rootfinders.cpp 
	$(CXX) $(CXXFLAGS) Main.cpp Functions.cpp Rootfinders.cpp -o Rootfinder

clean   :
	$(RM) $(GARBAGE)

cleanall:
	$(RM) $(GARBAGE)


