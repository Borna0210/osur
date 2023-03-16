CFLAGS = -Wall -I$(POCETNI_DIREKTORIJ)/include

OBJEKTI = lab1z.o
MODUL = mod-lab1z.o

$(MODUL): $(OBJEKTI)
	$(LD) -r $^ $(LDFLAGS) -o $@

lab1z.o: lab1z.c $(POCETNI_DIREKTORIJ)/include/header.h
	$(CC) $(CFLAGS) -o $@ -c $<


# brisanje
.PHONY: brisi
brisi:
	rm -f $(OBJEKTI) $(MODUL)
