player:main.o setData.o
	g++ -o player main.o setData.o
	rm *.o	
main.o:main.cpp
	g++ -c main.cpp

setData.o:setData.cpp
	g++ -c setData.cpp

clean:
	rm *.o player
r:
	mv player ..
