
CC              ?= gcc

export CP       := $(strip cp -f)
export MKDIR    := $(strip mkdir -p)
export RM       := $(strip rm -f)

export CC       := $(CC)
export CFLAGS   := $(strip $(CFLAGS) -std=c17 -Wall -Wextra -Wpedantic)
export CPPFLAGS := $(strip $(CPPFLAGS) -D_GNU_SOURCE -D_POSIX_C_SOURCE)
export LDFLAGS  :=
export LIBS     :=

TESTDIR  := $(strip tests)

TARGETS   := fasta

.PHONY: all
all:
	$(foreach DIR,$(TARGETS),$(MAKE) -C $(DIR))

.PHONY: clean
clean:
	$(foreach DIR,$(TARGETS),$(MAKE) -C $(DIR) clean)
