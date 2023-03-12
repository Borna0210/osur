CFLAGS = -Wall -I$(POCETNI_DIREKTORIJ)/include

OBJEKTI = Dioklecijanova.o
MODUL = mod-Dioklecijanova.o

$(MODUL): $(OBJEKTI)
	$(LD) -r $^ $(LDFLAGS) -o $@

Dioklecijanova.o: Dioklecijanova.c $(POCETNI_DIREKTORIJ)/include/header.h
	$(CC) $(CFLAGS) -o $@ -c $<


# brisanje
.PHONY: brisi
brisi:
	rm -f $(OBJEKTI) $(MODUL)
