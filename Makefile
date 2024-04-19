SRC = $(wildcard src/*.cpp)
HDR = $(wildcard src/*.hpp)
OBJ = $(patsubst src/%.cpp, %.o, $(SRC))

mitosis: $(OBJ)
	g++ -o $@ $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system

$(OBJ): $(SRC) $(HDR)
	g++ -c $(SRC) -O2

.PHONY: clean run install uninstall

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
