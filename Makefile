# project name (generate executable with this name)
TARGET   = YAE

CC       = clang++
# compiling flags here
LDFLAGS = -lm -lGL -L/usr/X11R6/lib -lGLU -lglut -lGLEW -lXi -lXmu -lglfw

LINKER   = clang++
# linking flags here

# change these to proper directories where each file should be
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/**/*.cpp) $(wildcard $(SRCDIR)/**/**/*.cpp) $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)*/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm       = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $(OBJECTS) $(LDFLAGS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) -c $< -g -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
