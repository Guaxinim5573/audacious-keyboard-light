NAME = audacious-keyboard-light
INSTALL_DIR = /usr/bin/

all: build install

build:
	gcc -o $(NAME) main.c

install:
	sudo cp $(NAME) $(INSTALL_DIR)$(NAME)

uninstall:
	sudo rm $(INSTALL_DIR)$(NAME)
