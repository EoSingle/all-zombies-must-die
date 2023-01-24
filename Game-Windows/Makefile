CC=g++
CFLAGS=-std=c++11 -Wall
TARGET=main
TARGET_TESTS=program_tests
LIBS=-Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

BUILD_DIR    = ./build
SRC_DIR    = ./src
INCLUDE_DIR  = ./include
TEST_DIR = ./tests
COVERAGE_DIR = ./coverage
DOC_DIR = ./documentation/html

all: ${BUILD_DIR}/${TARGET}

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/main.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Player.o ${BUILD_DIR}/Enemy.o ${BUILD_DIR}/Bullet.o ${BUILD_DIR}/MusicPlayer.o
	${CC} ${CFLAGS} -o ${TARGET} ${BUILD_DIR}/*.o ${LIBS}

${BUILD_DIR}/main.o: ${BUILD_DIR}/Game.o ${BUILD_DIR}/Player.o ${BUILD_DIR}/Enemy.o ${BUILD_DIR}/Bullet.o ${BUILD_DIR}/MusicPlayer.o ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

${BUILD_DIR}/Game.o: ${SRC_DIR}/Game.cpp ${INCLUDE_DIR}/Game.hpp ${BUILD_DIR}/Player.o ${BUILD_DIR}/Enemy.o ${BUILD_DIR}/Bullet.o ${BUILD_DIR}/Spawner.o ${BUILD_DIR}/TextPop.o ${BUILD_DIR}/MusicPlayer.o ${BUILD_DIR}/Menu.o ${BUILD_DIR}/PauseMenu.o ${BUILD_DIR}/GameOver.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/Game.cpp -o ${BUILD_DIR}/Game.o

${BUILD_DIR}/Player.o: ${SRC_DIR}/Player.cpp ${INCLUDE_DIR}/Player.hpp ${BUILD_DIR}/Health.o ${BUILD_DIR}/Gun.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/Player.cpp -o ${BUILD_DIR}/Player.o

${BUILD_DIR}/Enemy.o: ${SRC_DIR}/Enemy.cpp ${INCLUDE_DIR}/Enemy.hpp ${BUILD_DIR}/Health.o ${BUILD_DIR}/Player.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/Enemy.cpp -o ${BUILD_DIR}/Enemy.o

${BUILD_DIR}/Bullet.o: ${SRC_DIR}/Bullet.cpp ${INCLUDE_DIR}/Bullet.hpp
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/Bullet.cpp -o ${BUILD_DIR}/Bullet.o

${BUILD_DIR}/Gun.o: ${SRC_DIR}/Gun.cpp ${INCLUDE_DIR}/Gun.hpp
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/Gun.cpp -o ${BUILD_DIR}/Gun.o

${BUILD_DIR}/Health.o: ${SRC_DIR}/Health.cpp ${INCLUDE_DIR}/Health.hpp
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/Health.cpp -o ${BUILD_DIR}/Health.o

${BUILD_DIR}/Spawner.o: ${SRC_DIR}/Spawner.cpp ${INCLUDE_DIR}/Spawner.hpp ${BUILD_DIR}/Player.o ${BUILD_DIR}/Enemy.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/Spawner.cpp -o ${BUILD_DIR}/Spawner.o

${BUILD_DIR}/TextPop.o: ${SRC_DIR}/TextPop.cpp ${INCLUDE_DIR}/TextPop.hpp
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/TextPop.cpp -o ${BUILD_DIR}/TextPop.o
	
${BUILD_DIR}/MusicPlayer.o: ${SRC_DIR}/MusicPlayer.cpp ${INCLUDE_DIR}/MusicPlayer.hpp
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/MusicPlayer.cpp -o ${BUILD_DIR}/MusicPlayer.o

${BUILD_DIR}/Menu.o: ${SRC_DIR}/Menu.cpp ${INCLUDE_DIR}/Menu.hpp
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/Menu.cpp -o ${BUILD_DIR}/Menu.o

${BUILD_DIR}/PauseMenu.o: ${SRC_DIR}/PauseMenu.cpp ${INCLUDE_DIR}/PauseMenu.hpp
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/PauseMenu.cpp -o ${BUILD_DIR}/PauseMenu.o

${BUILD_DIR}/GameOver.o: ${SRC_DIR}/GameOver.cpp ${INCLUDE_DIR}/GameOver.hpp
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/GameOver.cpp -o ${BUILD_DIR}/GameOver.o


tests: all ${TEST_DIR}/main_testes.o ${TEST_DIR}/TesteGame.o #${TEST_DIR}/TestePlayer.o ${TEST_DIR}/TesteEnemy.o ${TEST_DIR}/TesteBullet.o ${TEST_DIR}/TesteHealth.o ${TEST_DIR}/TesteTextPop.o ${TEST_DIR}/TesteMusicPlayer.o ${TEST_DIR}/TesteMenu.o ${TEST_DIR}/TestePauseMenu.o ${TEST_DIR}/TesteGameOver.o
	${CC} ${CFLAGS} -o ${TARGET_TESTS} ${BUILD_DIR}/Game.o ${BUILD_DIR}/Player.o ${BUILD_DIR}/Enemy.o ${BUILD_DIR}/Bullet.o ${BUILD_DIR}/Gun.o ${BUILD_DIR}/Health.o ${BUILD_DIR}/Spawner.o ${BUILD_DIR}/TextPop.o ${BUILD_DIR}/MusicPlayer.o ${BUILD_DIR}/Menu.o ${BUILD_DIR}/PauseMenu.o ${BUILD_DIR}/GameOver.o ${TEST_DIR}/*.o ${LIBS}

${TEST_DIR}/main_testes.o: ${TEST_DIR}/main_testes.cpp
	${CC} ${CFLAGS} -I${TEST_DIR}/include -I${INCLUDE_DIR} -c ${TEST_DIR}/main_testes.cpp -o ${TEST_DIR}/main_testes.o

${TEST_DIR}/TesteGame.o : ${TEST_DIR}/TesteGame.cpp
	${CC} ${CFLAGS} -I${TEST_DIR}/include -I${INCLUDE_DIR} -c ${TEST_DIR}/TesteGame.cpp -o ${TEST_DIR}/TesteGame.o

#${TEST_DIR}/TestePlayer.o : ${TEST_DIR}/TestePlayer.cpp
#	${CC} ${CFLAGS} -I${TEST_DIR}/include -c ${TEST_DIR}/TestePlayer.cpp -o ${TEST_DIR}/TestePlayer.o

#${TEST_DIR}/TesteEnemy.o : ${TEST_DIR}/TesteEnemy.cpp
#	${CC} ${CFLAGS} -I${TEST_DIR}/include -c ${TEST_DIR}/TesteEnemy.cpp -o ${TEST_DIR}/TesteEnemy.o

#${TEST_DIR}/TesteBullet.o : ${TEST_DIR}/TesteBullet.cpp
#	${CC} ${CFLAGS} -I${TEST_DIR}/include -c ${TEST_DIR}/TesteBullet.cpp -o ${TEST_DIR}/TesteBullet.o

#${TEST_DIR}/TesteHealth.o : ${TEST_DIR}/TesteHealth.cpp
#	${CC} ${CFLAGS} -I${TEST_DIR}/include -c ${TEST_DIR}/TesteHealth.cpp -o ${TEST_DIR}/TesteHealth.o

#${TEST_DIR}/TesteTextPop.o : ${TEST_DIR}/TesteTextPop.cpp
#	${CC} ${CFLAGS} -I${TEST_DIR}/include -c ${TEST_DIR}/TesteTextPop.cpp -o ${TEST_DIR}/TesteTextPop.o

#${TEST_DIR}/TesteMusicPlayer.o : ${TEST_DIR}/TesteMusicPlayer.cpp
#	${CC} ${CFLAGS} -I${TEST_DIR}/include -c ${TEST_DIR}/TesteMusicPlayer.cpp -o ${TEST_DIR}/TesteMusicPlayer.o

#${TEST_DIR}/TesteMenu.o : ${TEST_DIR}/TesteMenu.cpp
#	${CC} ${CFLAGS} -I${TEST_DIR}/include -c ${TEST_DIR}/TesteMenu.cpp -o ${TEST_DIR}/TesteMenu.o

#${TEST_DIR}/TestePauseMenu.o : ${TEST_DIR}/TestePauseMenu.cpp
#	${CC} ${CFLAGS} -I${TEST_DIR}/include -c ${TEST_DIR}/TestePauseMenu.cpp -o ${TEST_DIR}/TestePauseMenu.o

#${TEST_DIR}/TesteGameOver.o : ${TEST_DIR}/TesteGameOver.cpp
#	${CC} ${CFLAGS} -I${TEST_DIR}/include -c ${TEST_DIR}/TesteGameOver.cpp -o ${TEST_DIR}/TesteGameOver.o

run_tests: tests
	./${TEST_DIR}/${TARGET_TESTS}

run: all
	./${TARGET}

documentation:
	doxygen Doxyfile

coverage: run_tests
	gcovr -r . --exclude="third_party/doctest.h"
	gcovr -r . --exclude="third_party/doctest.h" -b	

html_coverage:
	gcovr -r . --exclude="third_party/doctest.h" -b --html --html-details -o ${COVERAGE_DIR}/coverage.html

clean:
	rm -f ${BUILD_DIR}/*.o
	rm -f ${TEST_DIR}/*.o ${TEST_DIR}/*.gcda ${TEST_DIR}/*.gcno ${TARGET_TESTS}
	rm -f ${COVERAGE_DIR}/*