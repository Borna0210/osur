CFLAGS = -Wall -I$(POCETNI_DIREKTORIJ)/include

OBJEKTI = Zagreb.o
MODULI = Trgovi/mod-Trgovi.o
MODUL = mod-Zagreb.o

$(MODUL): $(OBJEKTI) $(MODULI)
	$(LD) -r $^ $(LDFLAGS) -o $@ 

Zagreb.o: Zagreb.c $(POCETNI_DIREKTORIJ)/include/header.h
	$(CC) $(CFLAGS) -o $@ -c $<


.PHONY: $(MODULI)
$(MODULI):
	$(MAKE) -C $(dir $@)

# brisanje
.PHONY: brisi
brisi:
	$(MAKE) -C Trgovi brisi
	rm -f $(OBJEKTI) $(MODUL)
