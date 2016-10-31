NAME = game

SRC =   main.cpp \
        Graphic.cpp \

OBJ = $(SRC:.cpp=.o)

CXX = g++ -g

CFLAGS = -W -Wall -Werror -lsfml-graphics -lsfml-window -lsfml-system #-L/usr/local/lib/libtgui.so -ltgui           

all: $(NAME)

.cpp.o:
	@$(CXX) $(CFLAGS) -c $< -o $@
	@printf " \033[34m[Compilation]\033[39m %s\n" $<

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all
