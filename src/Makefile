NAME = GlidePOS

SRC = main.cpp coreLogic.cpp

OBJ = $(SRC:.cpp=.o)

WX_CXXFLAGS = $(shell wx-config --cxxflags)
WX_LDFLAGS = $(shell wx-config --libs)

CXXFLAGS = $(WX_CXXFLAGS)
LDFLAGS = $(WX_LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
