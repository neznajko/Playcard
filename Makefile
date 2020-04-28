  prog = Playcard
   obj = $(prog).o
   gdb = -g
 flags = $(gdb) -std=c++1z
    cc = g++
   ext = cpp # file extension

$(prog): $(obj)
	$(cc) $(gdb) -o $@ $^

 $(obj): $(prog).$(ext)
	$(cc) $(flags) -o $@ -c $<

 .PHONY: clean debug

  clean:
	$(RM) $(prog) $(obj)

  debug: flags += -DDEBUG
  debug: $(prog)
