INCLUDES=

LIBLINKS=

SOURCES = \
	src/camera/camera.cpp			\
	src/event/*.cpp				\
	src/state/notshoot/idle.cpp		\
	src/state/notshoot/notshooting.cpp	\
	src/state/notshoot/configuring.cpp	\
	src/state/shoot/shooting.cpp		\
	src/state/shoot/focusing.cpp		\
	src/state/shoot/focused.cpp		\
	src/state/shoot/storing.cpp		\

EXE=bin/run

all:	clean build

build:
	mkdir -p bin
	g++ -g -o $(EXE) $(INCLUDES) $(SOURCES) $(LIBLINKS)

clean:
	rm -f $(EXE)

test:
	./$(EXE)
