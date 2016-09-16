# This allows for variables set in this makefile to be exported as environment variables
# Then, we can write $$var in the makefile, and it will show as $var in the shell
export

# List of default targets
all: uut.gcc.dll uut.gcc.OPT.dll convtest.exe timetest.exe uut.ms.dll uut.ms.OPT.dll uut.int.dll uut.int.OPT.dll times.csv Rplots.pdf

# Build using GCC
uut.gcc.dll: uut.c
	gcc -c -std=c99 $^
	gcc -shared -o $@ uut.o -Wl,--out-implib,libexample_dll.a

uut.gcc.OPT.dll: uut.c
	gcc -c -std=c99 $^
	gcc -shared -o $@ uut.o -Wl,--out-implib,libexample_dll.a -O3

convtest.exe: convtest.c
	gcc -c -std=c99 $^
	gcc -o $@ convtest.o -L. -lexample_dll

timetest.exe: timetest.c
	gcc -c -std=c99 $^
	gcc -o $@ timetest.o -L. -lexample_dll

# The batch file from MSVC to configure their compiler
msenv = "$$VS140COMNTOOLS\..\..\VC\vcvarsall.bat"
# This is how we call CL.EXE, the Microsoft compiler
mscc = cmd //C $(msenv) amd64 \&\& cl
# Build using MSVC
uut.ms.dll: uut.c
	eval $$mscc $^ //Fe$@ //nologo //MD //LD

uut.ms.OPT.dll: uut.c
	eval $$mscc $^ //Fe$@ //nologo //MD //LD //Ox

# The batch file from Intel to configure their compiler
ienv = "$$ICPP_COMPILER16\bin\ipsxe-comp-vars.bat"
# This is how we call ICL.EXE, the Intel compiler
icc = cmd //C $(ienv) intel64 vs2015 quiet \&\& icl
# Build using ICC
uut.int.dll: uut.c
	eval $$icc $^ -o $@ //nologo //MD //LD

uut.int.OPT.dll: uut.c
	eval $$icc $^ -o $@ //nologo //MD //LD //O3

# Create CSV file using timetest.exe
times.csv: timetest.exe
	./$^ > $@

# Create PDF of data from generated CSV
Rplots.pdf: times.r times.csv
	C:\\PROGRA~1\\R\\R-3.2.3\\bin\\x64\\Rscript.exe $<

# Target to clean up all outputs
clean:
	rm -f *.o *.obj *.exe *.dll *.lib *.exp *.obj *.pdf *.csv