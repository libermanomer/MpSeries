RACK_DIR ?= ../..

SOURCES = $(wildcard src/*.cpp) $(wildcard src/*.c)


DISTRIBUTABLES += $(wildcard LICENSE*) res
include $(RACK_DIR)/plugin.mk
include $(RACK_DIR)/arch.mk
