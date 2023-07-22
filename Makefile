TARGET = findFileApp
COMP = g++ 

PREF_SRC = ./src/
PREF_OBJ = ./obj/
PREF_LIB = ./lib/

SRC = $(wildcard $(PREF_SRC)*.cpp)
OBJ = $(patsubst $(PREF_SRC)%.cpp, $(PREF_OBJ)%.o, $(SRC))

$(TARGET) : $(OBJ) searchFileLib
	$(COMP) $(PREF_OBJ)main.o -L. $(PREF_LIB)*.a -o $(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.cpp
	mkdir -p $(PREF_OBJ)
	$(COMP) -c $< -o $@

searchFileLib : $(PREF_OBJ)searchFileLib.o
	mkdir -p $(PREF_LIB)
	ar rcs $(PREF_LIB)$@.a $(PREF_OBJ)searchFileLib.o



clear : 
	rm $(TARGET) $(PREF_OBJ)*.o $(PREF_LIB)*.a