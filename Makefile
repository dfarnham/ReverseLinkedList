CC     = gcc
CFLAGS = -O2 -Wall
RM     = rm -f
SRCS   = revlist.c
OBJS   = $(SRCS:.c=.o)
EXE    = revlist

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $< -o $(EXE)

test: spotless all
	@ECHO "-~-~-~-~-~-~-~-~TEST~-~-~-~-~-~-~-~-~-~-"
	@$(EXE) 9

clean:
	$(RM) $(OBJS)

spotless: clean
	$(RM) $(EXE)
