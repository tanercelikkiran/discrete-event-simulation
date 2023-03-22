OBJS	= main.o Order.o Employee.o Cashier.o Barista.o Event.o CashierQueue.o BaristaQueue.o EventQueue.o InputReader.o Solutions.o
SOURCE	= main.cpp Order.cpp Employee.cpp Cashier.cpp Barista.cpp Event.cpp CashierQueue.cpp BaristaQueue.cpp EventQueue.cpp InputReader.cpp Solutions.cpp
HEADER	= Order.h Employee.h Cashier.h Barista.h Event.h CashierQueue.h BaristaQueue.h EventQueue.h InputReader.h Solutions.h
OUT	= Assignment3
CC	 = g++
FLAGS	 = -g -c -Wall

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -std=c++11

Order.o: Order.cpp
	$(CC) $(FLAGS) Order.cpp -std=c++11

Employee.o: Employee.cpp
	$(CC) $(FLAGS) Employee.cpp -std=c++11

Cashier.o: Cashier.cpp
	$(CC) $(FLAGS) Cashier.cpp -std=c++11

Barista.o: Barista.cpp
	$(CC) $(FLAGS) Barista.cpp -std=c++11

Event.o: Event.cpp
	$(CC) $(FLAGS) Event.cpp -std=c++11

CashierQueue.o: CashierQueue.cpp
	$(CC) $(FLAGS) CashierQueue.cpp -std=c++11

BaristaQueue.o: BaristaQueue.cpp
	$(CC) $(FLAGS) BaristaQueue.cpp -std=c++11

EventQueue.o: EventQueue.cpp
	$(CC) $(FLAGS) EventQueue.cpp -std=c++11

InputReader.o: InputReader.cpp
	$(CC) $(FLAGS) InputReader.cpp -std=c++11

Solutions.o: Solutions.cpp
	$(CC) $(FLAGS) Solutions.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)