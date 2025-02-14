SRCDIR = src
OBJDIR = build

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CPPFLAGS) $(CFLAGS) -Werror -c -o $@ $<

eucl.out: $(OBJDIR)/main.o
	$(CXX) $(CPPFLAGS) $(CFLAGS) -Werror -o eucl.out $^