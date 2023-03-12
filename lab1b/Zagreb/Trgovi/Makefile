
CFLAGS = -Wall -I$(POCETNI_DIREKTORIJ)/include

OBJEKTI = Britanski.o Cvjetni.o
MODUL = mod-Trgovi.o

$(MODUL): $(OBJEKTI)
	$(LD) -r $^ $(LDFLAGS) -o $@

Britanski.o: Britanski.c $(POCETNI_DIREKTORIJ)/include/header.h
	$(CC) $(CFLAGS) -o $@ -c $<
Cvjetni.o: Cvjetni.c $(POCETNI_DIREKTORIJ)/include/header.h
	$(CC) $(CFLAGS) -o $@ -c $<

# brisanje
.PHONY: brisi
brisi:
	rm -f $(OBJEKTI) $(MODUL)
