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
		philos_handler.c printer.c check_if_dead.c


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
	@printf "\n%b" "$(NO_COLOR)"
	@echo "\t\t\t\t"
	@echo "\t\t\t                                        ..;t%X8@X8@88888888Xt:"
	@echo "\t\t\t                                       ;St;t;  .  .. . .. . .tS:%:"
	@echo "\t\t\t                                  .:X88;.. .  ..   . . . . .  .;88@@%."
	@echo "\t\t\t                              ..%8t8%:     ..  ........ . .  . ..  .t8@@:"
	@echo "\t\t\t                            . S8@  ... . .  .$(IYELLOW):X8SXXt8@8:8%t$(NO_COLOR)..       .. SS%"
	@echo "\t\t\t                          ..;S8;. . .. .$(IYELLOW):S8@@@@@8;@88t:;%SS8;8tS:..:;$(NO_COLOR) ...t@%"
	@echo "\t\t\t                        .t88:.. .$(IYELLOW)%X;@ @8;%@X;8%@@:;;;:tSS:888@%@;X:.;t;$(NO_COLOR) . S@t"
	@echo "\t\t\t                        %.: ...$(IYELLOW)8@8;@S@S.X ..8%;8Xt@.@t8 t%XStt8t8%:%..8% :$(NO_COLOR). @%"
	@echo "\t\t\t      ;X%8@@8;         88S;.. $(IYELLOW)%@8;8t88:%%.;S8.;X@88Xt%:..;S8%:8X@88XX X::S;$(NO_COLOR)...X@       ;X%8@@8;  "
	@echo "\t\t\t       :@SS:%;        8;8 ...$(IYELLOW)8@.%8@;@t:@::8X.8.8::8@%t:St8S8X8@X 8X8@.:.8 X8$(NO_COLOR).. S8:      :@SS:%;  "
	@echo "\t\t\t       :%:t.%:8.     t@ . $(IYELLOW):%t;@X;X8tX::St@.X%8S8@::  SSXttXX;:%S.88X%:t@Xt:XX$(NO_COLOR). :Xt      :%:t.%:8."
	@echo "\t\t\t       @@X8.t.%     t8.. $(IYELLOW)t;: .:8 SSS.X@;% .;;88tt:.;8S:@8S8.@XX%8 8%;t%.SStt@%$(NO_COLOR)  t:8     @@X8.t.% "
	@echo "\t\t\t       8:S. S; ;   :SX....$(IYELLOW)%S;@@88.8:tXS8;%8S%.8%8@8  888ttX8.8X:S8@t@Xt@X.:S;@8$(NO_COLOR).. 8@    8:S. S; ;"
	@echo "\t\t\t       88S : @St   :8... $(IYELLOW)t::.;.;8. %8;S %8@8X8XX%%%:8t%X%@8t:.X@X:t%8 8;;:8.%%@X$(NO_COLOR) . 8t   88S : @St"
	@echo "\t\t\t       XX :;: S    X@.  $(IYELLOW):; %;8S@X%t8.@t  Xt :S%%X8:8%tS:XXtttt @ %.Xt8@t%;888@:8t$(NO_COLOR)  t8   XX :;: S "
	@echo "\t\t\t       8t%%%%8::  .8; . $(IYELLOW);8 @8t X@S;8:S.%.:@@88:tS8SXS888@  S8%8%X8.t8X@8X8t8%X.8%$(NO_COLOR) . 8;  8t%%%%8::"
	@echo "\t\t\t       ;8 .  .:t  tX . .$(IYELLOW)@@S888%%S. 8tS;; 8%X%@8%8%::888;XX;@@X8X%@@XX @; ;%8X@@.%$(NO_COLOR).. 88  ;8 .  .:t"
	@echo "\t\t\t       8X . ;.;%  %8 . $(IYELLOW)S. t;t;t8%S8%8:;:8SX%S88% %@. :8t@.X@tX8tXX@8%@:8:%%S@8@.@$(NO_COLOR).. t8  8X . ;.;%"
	@echo "\t\t\t        8SS::.8.  XS ..$(IYELLOW)S..: X%:XX8S8:;%S%t;8t8;S888@%8:.@8%S@8Xt8;t%8t8:@88;8@8 8t$(NO_COLOR)  ;%   8SS::.8."
	@echo "\t\t\t         XS@S :   @t ..$(IYELLOW)%X S8S8@:8:8@t.;8;;@:SX%SX8.@X8;8.t@@88@X@S8.8%;8@@8XttXSt:$(NO_COLOR) ..@:   XS@S : "
	@echo "\t\t\t         tXXS     X.  $(IYELLOW):X. @XXSS@t%%S;S;@.:X 8 8;8:@S8;%X.8;%8 ;tt8%8%888tX8Xt 8%S$(NO_COLOR). ..X    tXXS   "
	@echo "\t\t\t         88@S     S..  $(IYELLOW)S; t%8:88;8@@X@888 %8XS8t:. :t8%%88%@:8S@88%8@ 8S8S8%%t888$(NO_COLOR) . :S    88@S   "
	@echo "\t\t\t         @8:S     S; . $(IYELLOW);: 8X.;S8%8S8%XXS..X8:8@@@@:@8@:88X@@8@@%%88X:. @S:8 ;8 S:$(NO_COLOR) . %@    @8:S   "
	@echo "\t\t\t         %8:8     t@    $(IYELLOW)%..:8. ;%%;%.XX;@8 8S@88.;%X;:%:X%;8 XS:@X%8 .8::@@X88.St$(NO_COLOR).  S8    %8:8   "
	@echo "\t\t\t         ;8;8     S; . .$(IYELLOW)%8tX8%t:Xt;S88@t.X%. X@t8@.X:;;8@@:X@888XX@.S. @S;88.%%;$(NO_COLOR) .:@SS    ;8;8   "
	@echo "\t\t\t         t:8S      @8 ..$(IYELLOW)%% .888X8@:XX8%t@8XSS;XS:8tXX.XSt8S%S@;.S88@;@ .@tt;8.:S$(NO_COLOR).  tX     t:8S   "
	@echo "\t\t\t         ;.St      .%:  $(IYELLOW);8 .;@@8..8tX 8XX88;8X8;:t8 88@S@@tX888S  @X%8 t%@Xt. %t$(NO_COLOR).. 8S     ;.St   "
	@echo "\t\t\t         ::%;      .@@ . .$(IYELLOW)%: @88t888S%@8@;@t%tS888@ .%@8:@8;8%S%S;tSSt8X:8;..:X$(NO_COLOR). .;8      ::%;   "
	@echo "\t\t\t        ;: 8%.       8S.. $(IYELLOW)t:; ;S.8S88;.@8X8;:@S;X@t..S@X X@X@@....S8888@.S :8X$(NO_COLOR)...:@:     ;: 8%.  "
	@echo "\t\t\t        t; ;S@        S8.. $(IYELLOW):8%. %8t8StS8@XtX;8@.8%%.; X;.S8X8.8%tX8 @%  :..8S$(NO_COLOR) . t@:      t; ;S@  "
	@echo "\t\t\t        X  ;%8         88. . $(IYELLOW)%...:88%:t: tS.t. St:8@ S.t@ .S@ 8:;t@ t:@ . S@$(NO_COLOR) ..;8        X  ;%8  "
	@echo "\t\t\t        X. . X          8S . .$(IYELLOW)::. .tS@8.;X88S@8X@..S8:%:8.@@%t%@t:t88:..:@X$(NO_COLOR)...%8:        X. . X  "
	@echo "\t\t\t        8:  ::           X8:...$(IYELLOW)ttSt...S 8X8%8S8:8S;.@8%X%..8S@X@8X8;..tXS:$(NO_COLOR)..;8@          8:  ::  "
	@echo "\t\t\t        8; .:S             8X .. $(IYELLOW);88: . %88t %XX@.SXXS%@t8%X.8;@. .. XX$(NO_COLOR) .. @%:           8; .:S  "
	@echo "\t\t\t        8% .:t             :8S; . .$(IYELLOW)tXX:....:%88%S8S8SXS@S8@8X:.. :t.;;$(NO_COLOR)... 88             8% .:t  "
	@echo "\t\t\t        XS %;X               .XSX:....$(IYELLOW);  .;.. . .... . . .... ;StX;$(NO_COLOR) . .tX8t              XS %;X  "
	@echo "\t\t\t        ;8 %S;                  %88: ..  $(IYELLOW).t;@% .;...:.. t.:: ...$(NO_COLOR)  .  ;8@                 ;8 %S;  "
	@echo "\t\t\t        ;8 ::t                    ;888X..   $(IYELLOW).. ..;;t;:. t....$(NO_COLOR)  .:;@@SX:                  ;8 ::t  "
	@echo "\t\t\t        X@@SS%                       .%@88%;..  . . . . .. . .88XS;                      X@@SS%  "
	@echo "\t\t\t                                          ;S88%88@88XtS@:: ;@;"
	@echo "\t\t\t                                              ..;;;:;t;;"
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