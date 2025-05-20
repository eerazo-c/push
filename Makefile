# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 16:47:26 by elerazo-          #+#    #+#              #
#    Updated: 2025/02/18 20:00:07 by elerazo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		=	push_swap
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g -I Inc/ #fsanitize=address
OBJDIR		=	build
SRCSDIR		=	Src
SRCS		=	chekers.c  operate.c  push_swap.c  reverse_rotate.c \
				rotate.c  sort_cases.c  swapa.c  utils.c  push.c algrt.c

LIBFT_PATH	=	library/libft
PRINTF_PATH =	library/printf
LIBFT		=	$(LIBFT_PATH)/libft.a
PRINTF		=	$(PRINTF_PATH)/libftprintf.a

OBJS		=	$(addprefix $(OBJDIR)/, ${SRCS:.c=.o})

PURPLE		=	\033[0;33m
BLUE		=	\033[0;33m
GREEN		=	\033[0;32m
RED			=	\033[0;31m
RESET		=	\033[m

all: lib print banner $(NAME)

banner:
	@printf "%b" "$(PURPLE)\n"                                                           
	@echo "    .-''-.    .---.       .-''-.  .-------.       ____      ____..--'    ,-----.     "
	@echo "  .'_ _   \   | ,_|     .'_ _   \ |  _ _   \    .'  __ \`.  |        |  .'  .-,  '.   "
	@echo " / ( \` )   ',-./  )    / ( \` )   '| ( ' )  |   /   '  \  \ |   .-'  ' / ,-.|  \ _ \  "
	@echo ". (_ o _)  |\  '_ '\`) . (_ o _)  ||(_ o _) /   |___|  /  | |.-'.'   /;  \  '_ /  | : "
	@echo "|  (_,_)___| > (_)  ) |  (_,_)___|| (_,_).' __    _.-\`   |    /   _/ |  _\`,/ \ _/  | "
	@echo "'  \   .---.(  .  .-' '  \   .---.|  |\ \  |  |.'   _    |  .'._( )_ : (  '\_/ \   ; "
	@echo " \  \`-'    / \`-'\`-'|___\  \`-'    /|  | \ \`'   /|  _( )_  |.'  (_'o._) \ \`\"/  \  ) /  "
	@echo "  \       /   |        \\       / |  |  \    / \ (_ o _) /|    (_,_)|  '. \_/\`\`\".'   "
	@echo "   \`'-..-'    \`--------\` \`'-..-'  ''-'   \`'-'   '.(_,_).' |_________|    '-----'     "
	@echo "                                                                                     "                                                        
	@printf "%b" "\n$(RESET)"


$(OBJS): $(OBJDIR)/%.o : $(SRCSDIR)/%.c Inc/push_swap.h | $(OBJDIR)
	@printf "%-42b" "$(BLUE)compiling... $(PURPLE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@-mkdir $(OBJDIR) > /dev/null 2>&1

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@printf "%-42b" "$(BLUE)linking... $(PURPLE)$(@F)$(RESET)\n"
	@$(CC) $(CFLAGS) $^ -o $@

lib:
	@make -C $(LIBFT_PATH) > /dev/null 2>&1

print:
	@make -C $(PRINTF_PATH) > /dev/null 2>&1

fclean: banner clean
	@printf "%b" "$(BLUE)$(@)ing...$(RESET)\n"
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH) > /dev/null 2>&1
	@make fclean -C $(PRINTF_PATH) > /dev/null 2>&1

clean: banner
	@printf "%b" "$(BLUE)$(@)ing...$(RESET)\n"
	@rm -rf $(OBJDIR)
	@make fclean -C $(LIBFT_PATH) > /dev/null 2>&1
	@make fclean -C $(PRINTF_PATH) > /dev/null 2>&1

re:    fclean all

.PHONY: all banner clean fclean re lib print
