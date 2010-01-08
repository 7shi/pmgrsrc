TARGET = httpget

OBJECTS = \
	main.o \
	ffcaddress.o \
	ffchttp.o \
	ffcurl.o \
	ffcsocket.o

all: $(TARGET)

win32:
	i386-mingw32-g++ -o $(TARGET).exe *.cpp -lwsock32

$(TARGET): $(OBJECTS)
	g++ -o $(TARGET) $(OBJECTS)

.cpp.o:
	g++ -c $<

clean:
	rm -f *.o *core $(TARGET) $(TARGET).exe
