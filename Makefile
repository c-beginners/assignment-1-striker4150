CPP = g++
CPPFLAGS = -g
PROGS = palindrome.exe

# Cross-OS clean
ifdef OS
	RM = del /Q
else
	RM = rm -f
endif

.PHONY: all clean

all: $(PROGS)

palindrome.exe: palindrome.cpp
	$(CPP) $(CPPFLAGS) -o palindrome.exe palindrome.cpp

clean:
	$(RM) palindrome.exe