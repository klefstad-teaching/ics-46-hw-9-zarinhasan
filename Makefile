CXX = g++
CXXFLAGS = -ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic

DIJKSTRAS_SRCS = src/dijkstras_main.cpp src/dijkstras.cpp
LADDER_SRCS = src/ladder_main.cpp src/ladder.cpp
HEADERS = src/dijkstras.h src/ladder.h

# Output targets
DIJKSTRAS_TARGET = dijkstras
LADDER_TARGET = ladder
TEST_TARGET = test

$(DIJKSTRAS_TARGET): $(DIJKSTRAS_SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(DIJKSTRAS_SRCS) -o $(DIJKSTRAS_TARGET)

$(LADDER_TARGET): $(LADDER_SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(LADDER_SRCS) -o $(LADDER_TARGET)

clean:
	/bin/rm -f $(DIJKSTRAS_TARGET) $(LADDER_TARGET) $(TEST_TARGET)
