# To compile
# make TARGET_LINUX=1 (Linux)
# make TARGET_WINDOWS=1 (Windows)

CPP = g++

BIN = last-outpost.exe

CPPFLAGS = -std=c++23 -Wall -g -I./include -I../my-lib/include
LDFLAGS = -std=c++23

# ----------------------------------

ifdef TARGET_LINUX
    CPPFLAGS += $(shell pkg-config --cflags sdl2 SDL2_mixer SDL2_image)
    LDFLAGS += $(shell pkg-config --libs sdl2 SDL2_mixer SDL2_image) -lm

    #BIN = last-outpost
endif

ifdef TARGET_WINDOWS
    CPPFLAGS += -I"C:\msys64\ucrt64\include\SDL2"
    LDFLAGS += -L"C:\msys64\ucrt64\lib" -lmingw32 -lSDL2main -lSDL2 -lSDL2_mixer -lSDL2_image -mwindows
endif

# ----------------------------------

SRCS := $(wildcard src/*.cpp)
#$(info Fontes: $(SRCS))

HEADERS := $(wildcard include/*.h)
#$(info Cabeçalhos: $(HEADERS))

OBJS := $(patsubst %.cpp,%.o,$(SRCS))
#$(info Objetos: $(OBJS))

# ----------------------------------

%.o: %.cpp $(HEADERS)
	$(CPP) $(CPPFLAGS) -c -o $@ $<

all: $(BIN)
	@echo "Everything compiled! yes!"   

$(BIN): $(OBJS)
	$(CPP) -o $(BIN) $(OBJS) $(LDFLAGS) 

# ----------------------------------

clean:
	-rm -rf $(BIN) $(OBJS)