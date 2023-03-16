POCETNI_DIREKTORIJ = $(shell pwd)
export POCETNI_DIREKTORIJ # visible in sub-makefiles

PROGRAM = program

CFLAGS = -Wall -I$(POCETNI_DIREKTORIJ)/include

OBJEKTI = main.o
MODULI = Split/mod-Split.o Zagreb/mod-Zagreb.o lab1z/mod-lab1z.o

all: $(PROGRAM)

$(PROGRAM): $(OBJEKTI) $(MODULI)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ $(LDLIBS) -o $@

main.o: main.c $(POCETNI_DIREKTORIJ)/include/header.h
	$(CC) $(CFLAGS) -c $< -o $@

$(MODULI):
	$(MAKE) -C $(dir $@)

.PHONY: brisi
brisi:
	$(MAKE) -C Zagreb brisi
	$(MAKE) -C Split brisi
	$(MAKE) -C lab1z brisi
	rm -f $(OBJEKTI) $(PROGRAM)

.PHONY: pokreni
pokreni: program
	./program
