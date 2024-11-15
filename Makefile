# Nom de la bibliothèque finale
NAME = libftprintf.a

# Fichiers sources pour ft_printf
SRC = ft_printf.c \
	printc.c \
	printd.c \
	prints.c \
	printp.c \
	printx.c \
	printu.c

# Objets correspondant aux sources
OBJ = $(SRC:.c=.o)

# Options de compilation
FLAGS = -Wall -Wextra -Werror

# Dossier de libft (si libft.a n'est pas dans le même dossier)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Cible par défaut : crée la bibliothèque
all : $(LIBFT) $(NAME)

# Compilation des fichiers objets
%.o : %.c
	gcc $(FLAGS) -c $< -o $@

# Création de la bibliothèque ft_printf avec libft
$(NAME) : $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)                 # Copie libft.a dans libftprintf.a
	ar rcs $(NAME) $(OBJ)                # Ajoute les objets de ft_printf

# Compilation de libft (supposant que libft a un Makefile)
$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

# Nettoyage des fichiers objets
clean :
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean        # Nettoie également dans libft

# Nettoyage complet
fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean       # Supprime libft.a dans libft

# Reconstruction complète
re : fclean all
