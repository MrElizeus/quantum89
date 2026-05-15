APP = quantum89

CORE_SRC = \
	src/core/quantum.c \
	src/core/photons.c

TI_SRC = \
	src/ti/main.c \
	src/ti/ui.c \
	src/ti/screens.c

TEST_SRC = tests/test_quantum.c

PC_CC = gcc
TI_CC = tigcc

PC_CFLAGS = -Wall -Wextra -O2
TI_CFLAGS = -O2 -Wall

.PHONY: all test send gui check clean dirs

all: dirs
	$(TI_CC) $(TI_CFLAGS) -o $(APP) $(TI_SRC) $(CORE_SRC)
	mv -f $(APP).89z build/

test: dirs
	$(PC_CC) $(PC_CFLAGS) $(CORE_SRC) $(TEST_SRC) -lm -o build/test_quantum
	./build/test_quantum

send: all
	tilp --calc=ti89t --cable=DirectLink --port=1 --no-gui build/$(APP).89z

gui:
	tilp

check:
	@echo "Tools:"
	@which gcc || true
	@which make || true
	@which tigcc || true
	@which tilp || true
	@echo ""
	@echo "USB:"
	@lsusb | grep -i "0451\|Texas" || true

dirs:
	mkdir -p build

clean:
	rm -f build/*
	rm -f *.89z *.o
