all: doc test

clean:
	rm -rf test/*.o 

doc: doxyfile
	doxygen doxyfile

CXX=g++
OPT=-std=c++0x
INC=-I./include

test: test/forwardingstream.o \
		 test/Histogram.o \
		 test/logstream.o \
		 test/maputil.o \
		 test/serialize.o \
		 test/Singleton.o \
		 test/Sqlite.o \
		 test/socketstream.o \
		 test/stringutil.o \
		 test/teestream.o \
		 test/tokenizer.o
#test/bijection.o \

.cc.o:
	$(CXX) $(OPT) $(INC) $< -o $@

test/Sqlite.o: test/Sqlite.cc
	$(CXX) $(OPT) $(INC) $< -o $@ -lsqlite3

