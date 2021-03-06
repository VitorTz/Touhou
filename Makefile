CC := g++
CFLAGS := -Wall -Wextra -std=c++17 -pedantic -O3
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

SRCDIR := src
BUILDDIR := build
TARGET := bin/touhou

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

$(TARGET): $(OBJECTS)
	@echo "Linking..."
	@$(CC) $^ -o $@ $(LDFLAGS)
	@echo "Build complete!"

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo "Cleaning..."
	@rm -rf $(BUILDDIR) $(TARGET)
	@mkdir build build/ecs build/math build/scene build/util build/ui
	@echo "Clean complete!"

.PHONY: clean
