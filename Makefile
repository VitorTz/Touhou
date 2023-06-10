CC := g++
CFLAGS := -Wall -Wextra -std=c++17 -pedantic
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

SRCDIR := src
BUILDDIR := build
TARGET := touhou

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
	@echo "Clean complete!"
	@mkdir build build/ecs build/math build/scene build/util build/ui

.PHONY: clean
