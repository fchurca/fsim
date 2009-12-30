fsim: fsim.cpp feng.cpp
	c++ $? -o $@ -lSGE `sdl-config --cflags` -L/usr/lib

clean:
	rm -f fsim *.o *~

debug: fsim
	./fsim

.PHONY: clean debug
