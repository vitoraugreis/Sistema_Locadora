# ==========================================================================================================

CC = g++
CFLAGS = -std=c++11 -Wall

TARGET = Sistema

INCLUDE_DIR = ./include
INCLUDE_CLIENTES = ./include/clientes
INCLUDE_MIDIAS = ./include/midias

SRC_DIR = ./src
SRC_CLIENTES = ./src/clientes
SRC_MIDIAS = ./src/midias

BUILD_DIR = ./build

# ==========================================================================================================

# Sistema
${TARGET}: ${BUILD_DIR}/main.o ${BUILD_DIR}/Cliente.o
	${CC} ${CFLAGS} -o ${TARGET} ${BUILD_DIR}/*.o

# main.o
${BUILD_DIR}/main.o: ${SRC_DIR}/main.cpp ${INCLUDE_CLIENTES}/Cliente.hpp
	${CC} ${CFLAGS} -I ${INCLUDE_CLIENTES}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

# Cliente.o
${BUILD_DIR}/Cliente.o: $(SRC_CLIENTES)/Cliente.cpp ${INCLUDE_CLIENTES}/Cliente.hpp
	$(CC) $(CFLAGS) -I ${INCLUDE_CLIENTES}/ -c $(SRC_CLIENTES)/Cliente.cpp -o $(BUILD_DIR)/Cliente.o