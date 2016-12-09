CXX = g++
CXXFLAGS = -pthread -std=c++11 -Wall -Werror -Wextra -pedantic

default: main

main: main.cpp budget.o cook.o deliverer.o ingredient.o recipe.o mailbox.o meal.o waiter.o buffer.h
	$(CXX) $(CXXFLAGS) -o main main.cpp budget.o meal.o cook.o deliverer.o ingredient.o recipe.o mailbox.o waiter.o

budget.o: budget.cpp budget.h buffer.h
	$(CXX) $(CXXFLAGS) -c budget.cpp

cook.o: cook.cpp cook.h buffer.h
	$(CXX) $(CXXFLAGS) -c cook.cpp

deliverer.o: deliverer.cpp deliverer.h buffer.h
	$(CXX) $(CXXFLAGS) -c deliverer.cpp

ingredient.o: ingredient.cpp ingredient.h buffer.h
	$(CXX) $(CXXFLAGS) -c ingredient.cpp

mailbox.o: mailbox.cpp mailbox.h
	$(CXX) $(CXXFLAGS) -c mailbox.cpp

meal.o: meal.cpp meal.h buffer.h
	$(CXX) $(CXXFLAGS) -c meal.cpp

recipe.o: recipe.cpp recipe.h buffer.h
	$(CXX) $(CXXFLAGS) -c recipe.cpp

waiter.o: waiter.cpp waiter.h buffer.h
	$(CXX) $(CXXFLAGS) -c waiter.cpp

run: main
	./main

clean:
	rm main *.o

.PHONY: default run clean
