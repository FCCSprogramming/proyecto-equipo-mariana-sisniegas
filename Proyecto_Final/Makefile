CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude

SRC = src/main.cpp \
      src/persona.cpp \
      src/estudiante.cpp \
      src/curso.cpp \
      src/sistema.cpp

TARGET = ProyectoFinal

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

