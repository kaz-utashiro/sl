all: sl

sl: sl-2023.c
	$(CC) -o $@ $< -lcurses

%: %.c
	$(CC) -o $@ $< -lcurses

clean:
	rm -f sl sl-{2010,2023}
