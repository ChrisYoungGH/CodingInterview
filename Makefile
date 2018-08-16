CC:=g++

UTIL_DIR:=Utilities
TEST_DIR:=${DIR}

SRCS:=$(wildcard ${UTIL_DIR}/*.cc) $(f)
OBJS:=${SRCS:.cc=.o}

TARGET:=a.out

CFLAGS:=-std=c++11 -I${UTIL_DIR}

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} ${CFLAGS} $^ -o $@

%.o: %.cc
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${TARGET} *.o
