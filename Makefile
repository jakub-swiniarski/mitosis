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
	rm *.o mitosis

install: all
	mkdir -p /usr/local/share/mitosis/
	cp mitosis /usr/local/bin/
	cp res/* /usr/local/share/mitosis/

uninstall:
	rm /usr/local/bin/mitosis
	rm -rf /usr/local/share/mitosis

.PHONY: all run clean install uninstall
