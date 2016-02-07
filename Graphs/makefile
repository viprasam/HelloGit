CXX = g++

CFLAGS = -Wall -c

SOURCES = graph_implementation.cpp main.cpp

OBJECTS = $(SOURCES:.cpp = .o)

EXECUTABLE = test_graph

all : $(SOURCES) \
      $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS) 
	$(CXX) $(OBJECTS) -o $@

.cpp.o: $(CXX) $(CFLAGS) $< -o $@


