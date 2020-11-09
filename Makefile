PREFIX ?= /usr/local
CC ?= cc

output: card.c config.h
	${CC} card.c -o card

config.h:
	cp config.def.h $@


clean:
	rm card

install: output
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	install -m 0755 card $(DESTDIR)$(PREFIX)/bin/card

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/card
