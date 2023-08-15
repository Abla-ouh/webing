#SRCS		= multiClients/main.cpp multiClients/Client.cpp multiClients/HTTPServer.cpp multiClients/Server.cpp
CONFIG_PARSE = ./utils/configParse/

SRCS = main.cpp Client.cpp HTTPServer.cpp Request.cpp\
		$(CONFIG_PARSE)configFile.cpp\
		$(CONFIG_PARSE)serverClass.cpp\
		$(CONFIG_PARSE)configFile_utils.cpp

NAME		= webserv
CC	= clang++
CXX = clang++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME)	: $(OBJS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re:	fclean all
