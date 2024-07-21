SRC = $(wildcard src/*.cpp)
HDR = $(wildcard src/*.hpp)
OBJ = $(patsubst src/%.cpp, %.o, $(SRC))

all: mitosis

%.o: src/%.cpp
	g++ -c -O2 $<

$(OBJ): $(HDR)

mitosis: $(OBJ)
	g++ -o $@ $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system

run: all
	./mitosis

clean:
	rm -f *.o mitosis

install: all
	mkdir -p /usr/local/share/mitosis/
	cp -f mitosis /usr/local/bin/
	cp -f res/* /usr/local/share/mitosis/

uninstall:
	rm -f /usr/local/bin/mitosis
	rm -rf /usr/local/share/mitosis

.PHONY: all run clean install uninstall
