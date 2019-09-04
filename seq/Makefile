
TARGETS := reverse-complement

.PHONY: all
all:
	$(foreach TARGET,$(TARGETS),$(MAKE) -C $(TARGET))

.PHONY: clean
clean:
	$(foreach TARGET,$(TARGETS),$(MAKE) -C $(TARGET) clean)
