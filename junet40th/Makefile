MARP=marp --allow-local-files
TITLE=junet40th

ALL=$(TITLE).html $(TITLE).pdf
all: $(ALL)

%.html: %.md
	$(MARP) $<

%.pdf: %.md
	$(MARP) --pdf $<

clean:
	rm -f $(ALL)
