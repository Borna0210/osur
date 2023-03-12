CFLAGS = -Wall -I$(POCETNI_DIREKTORIJ)/include

OBJEKTI = Split.o
MODULI = Ulice/mod-Dioklecijanova.o
MODUL = mod-Split.o

$(MODUL): $(OBJEKTI) $(MODULI)
	$(LD) -r $^ $(LDFLAGS) -o $@ 

Split.o: Split.c $(POCETNI_DIREKTORIJ)/include/header.h
	$(CC) $(CFLAGS) -o $@ -c $<


.PHONY: $(MODULI)
$(MODULI):
	$(MAKE) -C $(dir $@)

# brisanje
.PHONY: brisi
brisi:
	$(MAKE) -C Ulice brisi
	rm -f $(OBJEKTI) $(MODUL)