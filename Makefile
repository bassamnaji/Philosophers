PURPLE = \033[1;35m
BLUE   = \033[1;34m
WHITE   = \033[1;37m
LIGHT_BLUE  = \033[1;36m
GREEN    = \033[1;32m
RED = \033[1;31m
BYELLOW  = \033[1;33m
IYELLOW  = \033[3;33m
NO_COLOR    = \033[m


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
		philos_handler.c printer.c


#These are the .c files for your project
SRC_NAME =  $(addprefix $(SRC_DIR), $(C_FILES))

#These are the .o files that will be created for your project
OBJ_NAME = $(addprefix $(OBJ_DIR), ${C_FILES:%.c=%.o})

#mention the compilation flags here
CFLAG = -Wall -Wextra -Werror

#Here is the the source directory for .c files of your project
SRC_DIR = ./philo/

#Here is the the objects directory for .c files of your project
OBJ_DIR = ./objs/

#Here is the Executable file's name
NAME = philos

all: header $(OBJ_NAME)
	@gcc -pthread $(OBJ_NAME) -o $(NAME)
	@echo "\t$(NO_COLOR)[$(GREEN)✓$(NO_COLOR)]   $(IYELLOW)Compilation Is Done\n$(NO_COLOR)"
	@echo "$(BYELLOW)⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡"
	@echo "$(BYELLOW)⚡\t\t\t\t\t\t\t\t\t$(BYELLOW)READY\t\t\t\t\t\t\t\t\t\t$(BYELLOW)⚡"
	@echo "$(BYELLOW)⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡⚡$(NO_COLOR)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@gcc ${CFLAG} -pthread -c $< -o $@ 

header:
	@printf "\n%b" "$(LIGHT_BLUE)"
	@echo "\t\t\t\t"
	@echo "\t\t\t\t       ░                    ░                                   ▐               "
	@echo "\t\t\t\t         ░                                                      ▐               "
	@echo "\t\t\t\t           ░░                                                   ░               "
	@echo "\t\t\t\t              ░ ░                                                               "
	@echo "\t\t\t\t       ░░░░░         ░░                                        ░                "
	@echo "\t\t\t\t         ░░   ░                                               ░                 "
	@echo "\t\t\t\t       ░░   ░     ░░░                                                           "
	@echo "\t\t\t\t      ░ ░     ░                                                                 "
	@echo "\t\t\t\t    ░░ ░░                                                                       "
	@echo "\t\t\t\t  ░  ░                                                                          "
	@echo "\t\t\t\t      ░░░░░░                                                                    "
	@echo "\t\t\t\t  ░               ░░░                           ▄▓▄▄▄▄▄▄▄                       "
	@echo "\t\t\t\t░░  ░░               ░░░░░               ▄   ▄▓▓▀▀▒░░░░░▒▓▓████▓                "
	@echo "\t\t\t\t     ░ ░░░░             ▄▄▀ ▄▓▀     ▄▄▓▀  ▄▓███████▓▒▒▒▒░███████▌               "
	@echo "\t\t\t\t     ░░             ▄▓██▓▄███    ▄██▓▄▓████████████▓▒▄▓▓████████▌               "
	@echo "\t\t\t\t  ░░             ▓██████████  ▄███████████████████████████▀▒▓▓▄▒▒               "
	@echo "\t\t\t\t            ░ ░▄███████████▌▄██████▓█▓▓▓▓█████████████▀▒▓██ ▄▄ ▀▌               "
	@echo "\t\t\t\t               ▐███████████▓███▒▒▒████████████████▀▓▓████▌ ▒▒▒▒ ▐               "
	@echo "\t\t\t\t                ▀██████████████▓▓█████████████▒▒▒▓█████▀▐ ▒░▒    ▌              "
	@echo "\t\t\t\t                  ▐████████████████████████████████▀    ░ ▀▒▒   ▐               "
	@echo "\t\t\t\t                    ███████████▒▓██████████████▀           ▒▒▄                  "
	@echo "\t\t\t\t                    ▐█████████▀▀▀▓▓▓██████▀▀              ▐▀                    "
	@echo "\t\t\t\t                      ███████         ▀▀                      ▀                 "
	@echo "\t\t\t\t                      ▀████░▌                             ▄▄  ▄                 "
	@echo "\t\t\t\t                        ▒▒▒▓                              ▒    ▄                "
	@echo "\t\t\t\t                        ▐▒▒▒▄                              ▐   ▐▄▄▓▓▓▓▓▓▓▓▓▓▓▓  "
	@echo "\t\t\t\t                         ▀▒▒▒▒░▒░          ▄            ▄▒      ███▓▒▒▓▓▓▓▓▓▓▓▌ "
	@echo "\t\t\t\t                       ▄▄▄▄█▄▒▒▒▒▄▄▄    ▄░             ▒▒ ▄▄▓▓▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  "
	@echo "\t\t\t\t            ▄▓████████████████▓▒▒░▒▒░░░░            ▄▓▓▓▓▒▓▓▓▓██████████▓▓▓▓▓▓  "
	@echo "\t\t\t\t            ████████████████████▓▒▒▒▒▒          ▄▄▓▓▓██████████████████▓▓▓▓▓▓▒▓ "
	@echo "\t\t\t\t             █████████████████████▓▒▒▄      ▄▄████████████████████████▓▓▓▓▓▓▓▓▓ "
	@echo "\t\t\t\t              ██████████████████████▒▒░ ▄▓█████████████████████████▓▓▓▓▓▓▓▓▓▓▓▓▓"
	@echo "\t\t\t\t               █████████████████████████████████████████████████▓▓▓▓▓█▓▓▓▒▓▓▓▓▓▓"
	@echo "\t\t\t\t                █████████████████▓▓▓█████████████████████████▓▓███████▓▓▓▒▓▓▓▓▓█"
	@echo "\t\t\t\t                 ██████████████████▓▓████████████████████████████████▓▒▓▓▓██████"
	@echo "\t\t\t\t                  ██████████████████▓▓████████████████████████████▓▓████████████"
	@echo
	@printf "\n%b" "$(PURPLE)"
	@echo
	@echo "   ▄███████▄    ▄█    █▄     ▄█   ▄█        ▄██████▄     ▄████████  ▄██████▄     ▄███████▄    ▄█    █▄       ▄████████    ▄████████    ▄████████ "
	@echo "  ███    ███   ███    ███   ███  ███       ███    ███   ███    ███ ███    ███   ███    ███   ███    ███     ███    ███   ███    ███   ███    ███ "
	@echo "  ███    ███   ███    ███   ███▌ ███       ███    ███   ███    █▀  ███    ███   ███    ███   ███    ███     ███    █▀    ███    ███   ███    █▀  "
	@echo "  ███    ███  ▄███▄▄▄▄███▄▄ ███▌ ███       ███    ███   ███        ███    ███   ███    ███  ▄███▄▄▄▄███▄▄  ▄███▄▄▄      ▄███▄▄▄▄██▀   ███        "
	@echo "▀█████████▀  ▀▀███▀▀▀▀███▀  ███▌ ███       ███    ███ ▀███████████ ███    ███ ▀█████████▀  ▀▀███▀▀▀▀███▀  ▀▀███▀▀▀     ▀▀███▀▀▀▀▀   ▀███████████ "
	@echo "  ███          ███    ███   ███  ███       ███    ███          ███ ███    ███   ███          ███    ███     ███    █▄  ▀███████████          ███ "
	@echo "  ███          ███    ███   ███  ███▌    ▄ ███    ███    ▄█    ███ ███    ███   ███          ███    ███     ███    ███   ███    ███    ▄█    ███ "
	@echo " ▄████▀        ███    █▀    █▀   █████▄▄██  ▀██████▀   ▄████████▀   ▀██████▀   ▄████▀        ███    █▀      ██████████   ███    ███  ▄████████▀  "
	@echo "                                 ▀                                                                                       ███    ███              "
	@echo
	@printf "\t$(LIGHT_BLUE)AUTHORS\t\t:\t$(PURPLE)%b\n" "$(AUTHOR)"
	@printf "\t$(LIGHT_BLUE)Intra Login\t:\t$(PURPLE)%b\n" "$(Intra_Login)"
	@printf "\t$(LIGHT_BLUE)NAME\t\t:\t$(PURPLE)%b\n" "$(PROJECT_NAME)"
	@printf "\t$(LIGHT_BLUE)DATE\t\t:\t$(PURPLE)%b\n\n" "$(DATE)"
	@echo "\t$(BYELLOW)LOADING...$(RED)\n"
	@mkdir -p $(OBJ_DIR)
clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re