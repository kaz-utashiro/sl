MARP  = marp --allow-local-files
TITLE = junet40th
EXT   = html pdf
ALL   = $(foreach t,$(TITLE),$(foreach e,$(EXT),$t.$e))

all: $(ALL)

$(foreach e,$(EXT),$(eval %.$e: %.md ; $(MARP) --$e $$<))

clean:
	rm -f $(ALL)
