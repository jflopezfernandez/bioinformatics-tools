
TARGETS := fasta-split

.PHONY: all
all:
	$(foreach TARGET,$(TARGETS),$(MAKE) -C $(TARGET))

.PHONY: clean
clean:
	$(foreach TARGET,$(TARGETS),$(MAKE) -C $(TARGET) clean)
