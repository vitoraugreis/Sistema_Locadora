CC = g++
CFLAGS = -g -Wall

TARGET = Sistema.exe

INCLUDE_DIR = ./include
SRC_DIR = ./src
BUILD_DIR = ./build

${TARGET}: ${BUILD_DIR}/Cliente.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} -o ${TARGET} ${BUILD_DIR}/*.o

main.o: ${SRC_DIR}/main.cpp ${INCLUDE_DIR}/Cliente.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

Cliente.o: $(SRC_DIR)/Cliente.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Cliente.cpp -o $(BUILD_DIR)/Cliente.o