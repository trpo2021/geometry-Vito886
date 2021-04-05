CXX=g++
CFLAGS= -c -Wall -Werror
LIBG = obj/src/libgeometry
GEO = obj/src/geometry

bin/geometry.exe: $(GEO)/geometry.o $(LIBG)/counting.o $(LIBG)/checks.o 
		$(CXX) -I src -Wall -Werror -o bin/geometry.exe $(GEO)/geometry.o $(LIBG)/counting.o $(LIBG)/checks.o

$(LIBG)/counting.o: src/libgeometry/counting.cpp
		$(CXX) -I src $(CFLAGS) -MMD -o $(LIBG)/counting.o src/libgeometry/counting.cpp

$(LIBG)/checks.o: src/libgeometry/checks.cpp
		$(CXX) -I src $(CFLAGS) -MMD -o $(LIBG)/checks.o src/libgeometry/checks.cpp

$(GEO)/geometry.o: src/geometry/geometry.cpp
		$(CXX) -I src $(CFLAGS) -MMD -o $(GEO)/geometry.o src/geometry/geometry.cpp

-include geometry.d checks.d counting.d

.PHONY: clean

clean: 
	rm -rf $(GEO)/*.o $(GEO)/*.d $(LIBG)/*.o $(LIBG)/*.d bin/*.exe