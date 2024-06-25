PROJECT      = odr

CXX          = g++
LD           = g++
RM           = rm -f


SRC_DIRS     = .
INCLUDE      = -I ../../include

SRCS         = $(wildcard $(addsuffix /*.cpp, $(SRC_DIRS)))
OBJS         = $(SRCS:.cpp=.o)
DEPENDS      = $(OBJS:.o=.d)

EXE          = $(PROJECT)
MAP          = $(PROJECT).map


#------------------------------------------------------------------------------
# flags
#

# commmon flags propagated to CFLAGS, CXXFLAGS, ASFLAGS (not LDFLAGS)
FLAGS       += $(INCLUDE)
FLAGS       += -MMD

CXXFLAGS     = $(FLAGS)
CXXFLAGS    += -std=c++11
CXXFLAGS    += -fno-exceptions
CXXFLAGS    += -fno-rtti

CXXFLAGS    += -Wall -Wextra
CXXFLAGS    += -Wctor-dtor-privacy
CXXFLAGS    += -Wcast-align -Wpointer-arith -Wredundant-decls
CXXFLAGS    += -Wshadow -Wcast-qual -Wcast-align -pedantic

LDFLAGS     += -fno-exceptions
LDFLAGS     += -fno-rtti


# Enable link-time optimizer
#CXXFLAGS += -flto
#LDFLAGS  += -flto


.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXE)

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

clean:
	$(RM) *.o
	$(RM) *.d
	$(RM) $(EXE)


-include $(DEPENDS)
