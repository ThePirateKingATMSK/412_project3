CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRCS = 412_project3.cpp LoadBalancer.cpp Server.cpp Request.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = loadbalancer

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

