SRCDIR = src
OBJDIR = build
CPP = clang++

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CPP) $(CPPFLAGS) $(CFLAGS) -Werror -c -o $@ $<

eucl.out: $(OBJDIR)/main.o
	$(CPP) $(CPPFLAGS) $(CFLAGS) -Werror -o eucl.out $^