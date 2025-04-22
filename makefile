# Nome do executável

EXEC = jogo-da-velha

# Nome do arquivo principal (main)

MAIN = jogo-da-velha.c

# Arquivos auxiliares na pasta funcoes

FUNCOES = $(wildcard funcoes/*.c)

# Compilador e flags

CC = gcc
CFLAGS = -Wall -Wextra -g

# O que acontece ao rodar apenas o make

all: $(EXEC)

#como compilar o executável

$(EXEC): $(MAIN) $(FUNCOES)
	$(CC) $(CFLAGS) -o $(EXEC) $(MAIN) $(FUNCOES)

#limpar os arquivos que foram gerados
clean:
	rm -f $(EXEC)

#executar
run: $(EXEC)
	@./$(EXEC)

