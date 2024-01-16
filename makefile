# ==========================================================================================================

CC = g++
CPPFLAGS = -std=c++11 -Wall

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
${TARGET}: ${BUILD_DIR}/main.o ${BUILD_DIR}/SistemaClientes.o ${BUILD_DIR}/Cliente.o ${BUILD_DIR}/Midia.o
	${CC} ${CPPFLAGS} -o ${TARGET} ${BUILD_DIR}/*.o

# main.o
${BUILD_DIR}/main.o: ${SRC_DIR}/main.cpp ${INCLUDE_CLIENTES}/SistemaClientes.hpp ${INCLUDE_MIDIAS}/Midia.hpp
	${CC} ${CPPFLAGS} -I ${INCLUDE_CLIENTES}/ -I ${INCLUDE_MIDIAS}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

# SistemaClientes.o
${BUILD_DIR}/SistemaClientes.o: ${SRC_CLIENTES}/SistemaClientes.cpp ${INCLUDE_CLIENTES}/SistemaClientes.hpp
	${CC} ${CPPFLAGS} -I ${INCLUDE_CLIENTES}/ -c ${SRC_CLIENTES}/SistemaClientes.cpp -o ${BUILD_DIR}/SistemaClientes.o

# Cliente.o
${BUILD_DIR}/Cliente.o: $(SRC_CLIENTES)/Cliente.cpp ${INCLUDE_CLIENTES}/Cliente.hpp
	$(CC) $(CPPFLAGS) -I ${INCLUDE_CLIENTES}/ -c $(SRC_CLIENTES)/Cliente.cpp -o $(BUILD_DIR)/Cliente.o

#Midia.o
${BUILD_DIR}/Midia.o: ${SRC_MIDIAS}/Midia.cpp ${INCLUDE_MIDIAS}/Midia.hpp
	${CC} ${CPPFLAGS} -I ${INCLUDE_MIDIAS}/ -c ${SRC_MIDIAS}/Midia.cpp -o ${BUILD_DIR}/Midia.o