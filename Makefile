PURPLE = \033[1;35m
BLUE   = \033[1;34m
WHITE   = \033[1;37m
LIGHT_BLUE  = \033[1;36m
GREEN    = \033[1;32m
RED = \033[1;31m
BYELLOW  = \033[1;33m
IYELLOW  = \033[3;33m
NO_COLOR    = \033[m

#TESTER_COMMAND = #write the command you want to run the tester you have

#Mention the Authors names over here
AUTHOR = Bassam  

#Mention your username in 42 Intra
Intra_Login = Bnaji

#mention the project name here
PROJECT_NAME = PHILOSOPHERS

#write down the date you started working on your project
DATE = 26 - 02 - 2022

C_FILES = main.c error.c free_all.c ft_putstr_fd.c\
		ft_strlen.c ft_usleep.c initialize.c num_parser.c\
		philos_actions.c update_current_time.c locks_handler.c\
		philos_handler.c

# B_FILES = 

#These are the .c files for your project
SRC_NAME =  $(addprefix $(SRC_DIR), $(C_FILES))

#These are the .o files that will be created for your project
OBJ_NAME = $(addprefix $(OBJ_DIR), ${C_FILES:%.c=%.o})

#These are the .c files for your project
#BONUS_NAME =  $(addprefix $(B_DIR), $(BONUS_FILES))

#These are the .o files that will be created for your project
#B_OBJ_NAME = $(addprefix $(OBJ_DIR), ${B_FILES:%.c=%.o})

#mention the compilation flags here
CFLAG = -Wall -Wextra -Werror

#Here is the libft directory
#LIBFT_DIR = ./libft/

#Here is the libft library
#LIBFT_LIB = libft.a

#Here are all the libraries you have created
#LIBS = $(addprefix $(LIBS_DIR), *.a)

#Here is the gnl directory
#GNL_DIR = ./gnl/

#Here is the gnl library
#GNL_LIB = gnl.a

#Here is the the source directory for .c files of your project
SRC_DIR = ./philo/

#Here is the the bonus directory for .c files of your project
#B_DIR = ./bonus/

#Here is the the objects directory for .c files of your project
OBJ_DIR = ./objs/

#Here is the headers directory
#HEADERS_DIR = ./includes/

#Here is the libraries directory
#LIBS_DIR = ./libraries/

#Here is the temporary library that will be created from the source files
NAME = philos

#B_NAME = b_minishell.a

#Here is the final library that contains all the objects files needed for this project

#ALL_LIBS = $(LIBS_DIR)$(NAME) $(LIBS_DIR)${LIBFT_LIB} $(LIBS_DIR)${GNL_LIB}

# B_ALL_LIBS = $(LIBS_DIR)$(B_NAME) $(LIBS_DIR)${LIBFT_LIB} $(LIBS_DIR)${GNL_LIB}

#Here is the name of the executable file
# EXEC_NAME = philos

all: header $(OBJ_NAME)
#	@echo "\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)MINISHELL Is Done\n$(NO_COLOR)"
	@gcc $(OBJ_NAME) -o $(NAME)
	@echo "\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Compilation Is Done\n$(NO_COLOR)"
	@echo "$(GREEN)*************************************************************************"
	@echo "$(GREEN)*\t\t\t\t$(BYELLOW)READY\t\t\t\t\t$(GREEN)*"
	@echo "$(GREEN)*************************************************************************$(NO_COLOR)"

# bonus: header ${LIBFT_LIB} ${GNL_LIB} $(LIBS_DIR)$(B_NAME)
# 	@echo "\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)MINISHELL Is Done\n$(NO_COLOR)"
# 	@gcc $(B_ALL_LIBS) -lreadline -L/usr/local/Cellar/readline/8.1/lib -o $(EXEC_NAME)
# 	@echo "\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Compilation Is Done\n$(NO_COLOR)"
# 	@echo "$(GREEN)*************************************************************************"
# 	@echo "$(GREEN)*\t\t\t\t$(BYELLOW)READY\t\t\t\t\t$(GREEN)*"
# 	@echo "$(GREEN)*************************************************************************$(NO_COLOR)"

# ${LIBS_DIR}${NAME} : $(OBJ_NAME)
# 	@ar -rc ${LIBS_DIR}$(NAME) $(OBJ_NAME)
# 	@ranlib $(LIBS_DIR)$(NAME)

# ${LIBS_DIR}${B_NAME} : $(B_OBJ_NAME)
# 	@ar -rc ${LIBS_DIR}$(B_NAME) $(B_OBJ_NAME)
# 	@ranlib $(LIBS_DIR)$(B_NAME)

# ${LIBFT_LIB}:
# 	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) all && cp $(LIBFT_DIR)$(LIBFT_LIB) $(LIBS_DIR)
# 	@echo "\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)LIBFT Is Done\n"

# ${GNL_LIB}:
# 	@$(MAKE) --no-print-directory -C $(GNL_DIR) all && cp $(GNL_DIR)$(GNL_LIB) $(LIBS_DIR)
# 	@echo "\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)GNL Is Done\n"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@gcc ${CFLAG} -c $< -o $@ 

# $(OBJ_DIR)%.o : $(B_DIR)%.c
# 	@gcc -fcommon ${CFLAG} -c $< -o $@ -I/usr/local/Cellar/readline/8.1/include

header:
#	@say compile minihell
	@printf "\n%b" "$(PURPLE)"
	@echo
	@echo "\t\t██████╗     ███╗   ██╗    ███╗   ███╗"
	@echo "\t\t██╔══██╗    ████╗  ██║    ████╗ ████║"
	@echo "\t\t██████╔╝    ██╔██╗ ██║    ██╔████╔██║"
	@echo "\t\t██╔══██╗    ██║╚██╗██║    ██║╚██╔╝██║"
	@echo "\t\t██████╔╝    ██║ ╚████║    ██║ ╚═╝ ██║"
	@echo "\t\t╚═════╝     ╚═╝  ╚═══╝    ╚═╝     ╚═╝"
	@echo

	@echo "\t███╗░░░███╗██╗███╗░░██╗██╗░██████╗██╗░░██╗███████╗██╗░░░░░██╗░░░░░"
	@echo "\t████╗░████║██║████╗░██║██║██╔════╝██║░░██║██╔════╝██║░░░░░██║░░░░░"
	@echo "\t██╔████╔██║██║██╔██╗██║██║╚█████╗░███████║█████╗░░██║░░░░░██║░░░░░"
	@echo "\t██║╚██╔╝██║██║██║╚████║██║░╚═══██╗██╔══██║██╔══╝░░██║░░░░░██║░░░░░"
	@echo "\t██║░╚═╝░██║██║██║░╚███║██║██████╔╝██║░░██║███████╗███████╗███████╗"
	@echo "\t╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝╚═════╝░╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝"
	@echo
	@printf "\n%b" "$(LIGHT_BLUE)"
	@echo "\t\t                  ░░░░░░░░░░"
	@echo "\t\t             ░░░░░░░░░░░░░░░░░░░"
	@echo "\t\t          ░░░░░░░░░░░░░░░░░░░░░░░░░"
	@echo "\t\t        ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░"
	@echo "\t\t      ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄░░"
	@echo "\t\t     ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██▌░░"
	@echo "\t\t    ░░░░░░░░░░░░░░░░░░░░░░░░░░░▄▄███▀░░░░"
	@echo "\t\t   ░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░▄█░░░░"
	@echo "\t\t  ░░░░░░░░░░░░░░░░░░░░░░░░░░▄████████▀░░░░"
	@echo "\t\t  ░░░░░░░░░░░░░░░░░░░░░░░░▄█████████░░░░░░░"
	@echo "\t\t ░░░░░░░░░░░░░░░░░░░░░░░░░░▄███████▌░░░░░░░"
	@echo "\t\t ░░░░░░░░░░░░░░░░░░░░░░░░▄█████████░░░░░░░░"
	@echo "\t\t ░░░░░░░░░░░░░░░░░░░░░▄███████████▌░░░░░░░░"
	@echo "\t\t ░░░░░░░░░░░░░░░▄▄▄▄██████████████▌░░░░░░░░"
	@echo "\t\t ░░░░░░░░░░░▄▄███████████████████▌░░░░░░░░░"
	@echo "\t\t ░░░░░░░░░▄██████████████████████▌░░░░░░░░░"
	@echo "\t\t ░░░░░░░░████████████████████████░░░░░░░░░░"
	@echo "\t\t █░░░░░▐██████████▌░▀▀███████████░░░░░░░░░░"
	@echo "\t\t██░░░▄██████████▌░░░░░░░░░▀██▐█▌░░░░░░░░░░"
	@echo "\t\t ██████░█████████░░░░░░░░░░░▐█▐█▌░░░░░░░░░"
	@echo "\t\t  ▀▀▀▀░░░██████▀░░░░░░░░░░░░▐█▐█▌░░░░░░░░"
	@echo "\t\t     ░░░░▐█████▌░░░░░░░░░░░░▐█▐█▌░░░░░░░"
	@echo "\t\t      ░░░░███▀██░░░░░░░░░░░░░█░█▌░░░░░░"
	@echo "\t\t        ░▐██░░░██░░░░░░░░▄▄████████▄"
	@echo "\t\t         ██▌░░░░█▄░░░░░░▄███████████████████"
	@echo "\t\t         ▐██  ░░░██▄▄███████████████████████"
	@echo "\t\t          ▐██  ▄████████████████████████████"
	@echo "\t\t          ▄▄████████████████████████████████"
	@echo "\t\t████████████████████████████████████████████"
	@echo
	@printf "\t$(LIGHT_BLUE)AUTHORS\t\t:\t$(GREEN)%b\n\t$(LIGHT_BLUE)Intra Login\t:\t$(GREEN)%b\n\t$(LIGHT_BLUE)NAME\t\t:\t$(GREEN)%b\n\t$(LIGHT_BLUE)DATE\t\t:\t$(GREEN)%b\n\n" "$(AUTHOR)" "$(Intra_Login)" "$(PROJECT_NAME)" "$(DATE)"
	@echo "\t$(BYELLOW)LOADING...$(RED)\n"
	@mkdir -p $(OBJ_DIR)
clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re