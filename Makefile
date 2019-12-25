CXX = g++
CXXFLAGS = -Wall -g -std=c++11


play: poker_test.o game.o deck.o player.o card.o
	$(CXX) $(CXXFLAGS) poker_test.o game.o deck.o player.o card.o -o play
poker_test.o: poker_test.cpp game.hpp

game.o: game.cpp deck.hpp player.hpp

deck.o: deck.cpp card.hpp

player.o: player.cpp card.hpp

card.o: card.cpp

.PHONY: clean
clean:
	rm -f play *.o
