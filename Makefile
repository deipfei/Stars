# $Id: Makefile,v 1.14 2014-06-25 17:42:27-07 - - $

MKFILE      = Makefile

COMPILECPP  = g++ -g

CPPSOURCE   = main.cpp src/mainmenu.cpp src/instructions.cpp src/fireball.cpp src/Animation.cpp src/AnimatedSprite.cpp src/pipe.cpp src/background.cpp
OBJECTS     = ${CPPSOURCE:.cpp=.o}
SFML        = -o "Stars" -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

all : ${OBJECTS}
	${COMPILECPP} ${OBJECTS} ${SFML}
	- 

../%.o : %.cpp
	${COMPILECPP} -c $<

clean :
	- rm ${OBJECTS}
