SRC = $(wildcard src/*.cpp)
HDR = $(wildcard src/*.hpp)
OBJ = $(patsubst src/%.cpp, %.o, $(SRC))

all: mitosis

%.o: src/%.cpp
	g++ -c -O2 $<

$(OBJ): $(SRC) $(HDR)

mitosis: $(OBJ)
	g++ -o $@ $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.o mitosis

run: mitosis
	./mitosis

install: mitosis res
	mkdir -p /usr/local/share/mitosis/
	cp mitosis /usr/local/bin/
	cp res/* /usr/local/share/mitosis/

uninstall:
	rm /usr/local/bin/mitosis
	rm -rf /usr/local/share/mitosis

.PHONY: all clean run install uninstall
