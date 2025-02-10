CXX = g++

CXXFLAGS = -std=c++20 -g -Wall -Wextra -Wpedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-variadic-macros -DDEBUG -DLOCAL -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -fsanitize-address-use-after-scope

SOURCES = $(wildcard *.cpp)

OBJECTS = $(SOURCES:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

%:
	@if [ ! -f $*.cpp ]; then \
		echo "Файл $*.cpp не найден, копирую template.cpp..."; \
		cp template.cpp $*.cpp; \
	fi
	@if [ ! -f $*.o ] || [ $*.cpp -nt $*.o ]; then \
		echo "Compiling $*.cpp..."; \
		$(CXX) $(CXXFLAGS) $*.cpp -o $*.o; \
	else \
		echo "$*.o is up to date."; \
	fi
	@echo "Running $*.o..."
	./$*.o < input.txt > output.txt


clean:
	rm -f $(OBJECTS)
