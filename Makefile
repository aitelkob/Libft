# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/25 10:58:08 by yait-el-          #+#    #+#              #
#    Updated: 2021/01/26 16:01:41 by yait-el-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################### Make Makefile  beautiful
BLACK           := $(shell tput -Txterm setaf 0)
RED             := $(shell tput -Txterm setaf 1)
GREEN           := $(shell tput -Txterm setaf 2)
YELLOW          := $(shell tput -Txterm setaf 3)
LIGHTPURPLE     := $(shell tput -Txterm setaf 4)
PURPLE          := $(shell tput -Txterm setaf 5)
BLUE            := $(shell tput -Txterm setaf 6)
WHITE           := $(shell tput -Txterm setaf 7)
RESET           := $(shell tput -Txterm setaf 9)
####################### Project Name

NAME = libft.a

######################DIR

CHILDDIR	:= string
CHILDDIR	+= memory
CHILDDIR	+= put
CHILDDIR	+= checker
CHILDDIR	+= list
CHILDDIR	+= tools
#--------------------
INCSDIR     = include
#------------------
SRCSDIR         = src
OBJSDIR         = obj

#########################

SRC			:= string/ft_strcat.c
SRC			+= string/ft_strchr.c
SRC         += string/ft_strclr.c
SRC         += string/ft_strcmp.c
SRC         += string/ft_strcpy.c
SRC         += string/ft_strdel.c
SRC         += string/ft_strdup.c
SRC         += string/ft_striter.c
SRC         += string/ft_striteri.c
SRC         += string/ft_strjoin.c
SRC         += string/ft_strlcat.c
SRC         += string/ft_strlcpy.c
SRC         += string/ft_strlen.c
SRC         += string/ft_strmap.c
SRC         += string/ft_strmapi.c
SRC         += string/ft_strncasecmp.c
SRC         += string/ft_strncat.c
SRC         += string/ft_strncpy.c
SRC         += string/ft_strnew.c
SRC         += string/ft_strnstr.c
SRC         += string/ft_strrchr.c
SRC         += string/ft_strrev.c
SRC         += string/ft_strsplit.c
SRC         += string/ft_strstr.c
SRC         += string/ft_strsub.c
SRC         += string/ft_strtrim.c

SRC			+= memory/ft_memalloc.c
SRC         += memory/ft_memccpy.c
SRC         += memory/ft_memchr.c
SRC         += memory/ft_memcmp.c
SRC         += memory/ft_memcpy.c
SRC         += memory/ft_memcpynull.c
SRC         += memory/ft_memdel.c
SRC         += memory/ft_memmove.c
SRC         += memory/ft_memset.c

SRC			+=list/ft_lstadd.c
SRC         +=list/ft_lstdel.c
SRC         +=list/ft_lstdelone.c
SRC         +=list/ft_lstiter.c
SRC         +=list/ft_lstmap.c
SRC         +=list/ft_lstnew.c
SRC         +=list/ft_lstsize.c
SRC         +=list/ft_lstsplit.c

SRC			+= checker/ft_isalnum.c
SRC         += checker/ft_isalpha.c
SRC         += checker/ft_isascii.c
SRC         += checker/ft_isblank.c
SRC         += checker/ft_iscntrl.c
SRC         += checker/ft_isdigit.c
SRC         += checker/ft_isgraph.c
SRC         += checker/ft_islower.c
SRC         += checker/ft_isprime.c
SRC         += checker/ft_isprint.c
SRC         += checker/ft_ispunct.c
SRC         += checker/ft_isspace.c
SRC         += checker/ft_isupper.c
SRC         += checker/ft_isxdigit.c

SRC			+= put/ft_putchar.c
SRC         += put/ft_putchar_fd.c
SRC         += put/ft_putendl.c
SRC         += put/ft_putendl_fd.c
SRC         += put/ft_putnbr.c
SRC         += put/ft_putnbr_base.c
SRC         += put/ft_putnbr_fd.c
SRC         += put/ft_putstr.c
SRC         += put/ft_putstr_fd.c

SRC			+= tools/ft_atoi.c
SRC         += tools/ft_atoi_base.c
SRC         += tools/ft_bzero.c
SRC         += tools/ft_charinword.c
SRC         += tools/ft_itoa.c
SRC         += tools/ft_list_size.c
SRC         += tools/ft_split_whitespaces.c
SRC         += tools/ft_sqrt.c
SRC         += tools/ft_tolower.c
SRC         += tools/ft_toupper.c
SRC         += tools/get_next_line.c
SRC         += tools/upper_case.c
SRC         += tools/get_next_line.c

INCS        := include/libft.h

########## for D-bug
print-%  : ; @echo $* = $($*)
############################

################################################same tricks make work essay

D_SRCS           = $(addsuffix /, $(SRCSDIR))
DI_SRCS          = $(foreach dir,$(CHILDDIR),$(D_SRCS)$(dir))
D_OBJS           = $(addsuffix /, $(OBJSDIR))
C_OBJS           = $(addprefix $(D_OBJS),  $(SRC:.c=.o))
C_INCS           = $(foreach include, $(INCSDIR), -I$(include))
C_CHILDDIR       = $(foreach dir, $(CHILDDIR),$(D_OBJS)$(dir))

################# Compilation flags
CC              = gcc
RM              = rm -rf
CFLAGS          = $(C_INCS) -Wall -Wextra -Werror
#----------------->>>>>>>>>>>>>>>>START<<<<<<<<<<<<<-------------------#

$(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
	@echo "$(PURPLE)**********>>>Compiling : $(RESET) $(LIGHTPURPLE)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJSDIR) $(C_CHILDDIR) $(NAME)

$(NAME):$(C_OBJS)
	@ar rc $(NAME) $(C_OBJS)
	@ranlib $(NAME)
	@echo "$(RED)\n***********>>>Building : $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)

$(C_CHILDDIR):
	@mkdir -p $(C_CHILDDIR)


clean:
	@echo "$(GREEN)**********   Deleting all object from $(NAME) **********\n$(RESET)"
	@$(RM) $(C_OBJS)

fclean: clean
	@echo "$(GREEN)**********   Deleting $(NAME) **********\n$(RESET)"
	@$(RM) $(NAME)
	@$(RM) $(OBJSDIR)

re: fclean all
.PHONY: all clean fclean re
