# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourgeo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 18:34:29 by mbourgeo          #+#    #+#              #
#    Updated: 2023/11/27 03:12:49 by mbourgeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	= all

PRIM_SRCS	=	main.c ray_tracing.c initialize.c operate_mlx.c \
				color_convert.c vec_operations.c utils.c tests.c \
				color_display.c geom_operations.c ray_compute.c \
				ppm_example.c objects.c random.c
PRIM_SRCDIR	=	src
PRIM_PATH	=	$(addprefix $(PRIM_SRCDIR)/, $(PRIM_SRCS))
PRIM_OBJDIR	=	obj
PRIM_OBJS	=	$(patsubst $(PRIM_SRCDIR)/%, $(PRIM_OBJDIR)/%, $(PRIM_PATH:.c=.o))

DEP_DIR		=	dep
PRIM_DEP	=	$(patsubst $(PRIM_OBJDIR)/%.o, $(DEP_DIR)/%.d, $(PRIM_OBJS))

HEADER_SRCS	=	ray_tracing.h mlx.h
HEADER_DIR	=	inc
HEADER_PATH	=	$(addprefix $(HEADER_DIR)/, $(HEADER_SRCS))

NAME		=	ray_tracing
CC			=	gcc
RM			=	rm -rvf
MK			=	mkdir -p
#DEBUG		=	-g3 -fsanitize=address
DEBUG		=	-g3
CFLAGS		=	-Wall -Wextra -Werror
DFLAGS		=	-MMD -MF
COPTIONS	=	-lXext -lX11 -lm
CLIBS		=	-Ilib/mlx -Llib/mlx -lmlx_Linux

#################################

all:		$(NAME)

$(NAME):	$(PRIM_OBJS) | lib/mlx/libmlx_Linux.a Makefile
				$(CC) $^ $(CLIBS) -o $@ $(COPTIONS)

-include $(PRIM_DEP)
$(PRIM_OBJDIR)/%.o:		$(PRIM_SRCDIR)/%.c | $(PRIM_OBJDIR) $(DEP_DIR) $(HEADER_PATH)
							$(CC) $(CFLAGS) $(DEBUG) $(DFLAGS) $(DEP_DIR)/$*.d -c $< -o $@

lib/mlx/libmlx_Linux.a:
				$(MAKE) -C lib/mlx all

$(PRIM_OBJDIR) $(DEP_DIR):		;
				@$(MK) $@

clean:		;
				@$(MAKE) clean -C lib/mlx
				@$(RM) $(PRIM_OBJDIR) $(DEP_DIR)

fclean:		clean
				@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
