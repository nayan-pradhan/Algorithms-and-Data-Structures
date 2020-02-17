all: firstprogram secondprogram thirdprogram fourthprogram fifthprogram

firstprogram: p1_1.o
	g++ p1_1.o -o program1

p1_1.o: p1_1.cpp
	g++ -c p1_1.cpp

secondprogram: testStack.o
	g++ testStack.o -o program2

testStack.o: testStack.cpp Stack.h
	g++ -c testStack.cpp


thirdprogram:  testLinkedList.o
	g++ testLinkedList.o -o program3

testLinkedList.o: testLinkedList.cpp LinkedList.h
	g++ -c testLinkedList.cpp


fourthprogram: p1_4.o
	g++ p1_4.o -o program4

p1_4.o: p1_4.cpp
	g++ -c p1_4.cpp

fifthprogram: p1_5.o
	g++ p1_5.o -o program5

p1_5.o: p1_5.cpp
	g++ -c p1_5.cpp

clean: 
	rm *.o program1 program2 program3 program4 program5