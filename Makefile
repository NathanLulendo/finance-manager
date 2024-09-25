CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude

# Directories
SRCDIR = src
INCDIR = include
BUILDDIR = build

# Executable name
EXEC = $(BUILDDIR)/finance_manager

# Source files
SRCFILES = $(SRCDIR)/main.cpp $(SRCDIR)/FinanceManager.cpp $(SRCDIR)/Transaction.cpp $(SRCDIR)/FileManager.cpp
OBJFILES = $(SRCFILES:.cpp=.o)

# Build rule
$(EXEC): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build
clean:
	rm -f $(OBJFILES) $(EXEC)
