CC ?= gcc
TARGET := Ted/Ted
INC_FLAGS := -I include -I appFrame -I utilPs -I appUtil -I docBase -I bitmap -I docBuf -I docEdit -I docFont -I docHtml -I docLayout -I docRtf -I guiInterface -I ind -I Ted -I textEncoding -I utilPs
CFLAGS := -O0 -g `pkgconf gtk+-2.0 --cflags` `pkgconf glib-2.0 --cflags` -Wno-deprecated-declarations -Wno-discarded-qualifiers -Werror
CPPFLAGS = $(INC_FLAGS) -MT $@ -MMD -MP -MF build/$*.d
SRCS := $(shell find . -path "*.c")
OBJS := $(patsubst %.c, ./build/%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)

LDFLAGS=-Wl,-O1 `pkgconf gtk+-2.0 --libs` `pkgconf glib-2.0 --libs` -lXft -lfreetype -lX11 -lm -lz -lpng -ljpeg -lpcre

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $^ -o $(TARGET) $(LDFLAGS)

./build/%.o : ./%.c
	mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

clean:
	rm -fr $(TARGET) build

-include $(DEPS)

