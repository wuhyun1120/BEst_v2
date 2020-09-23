CC := icc
MPICC := mpiicc
LIBS := -lgsl -lgslcblas -lm -qopenmp -lchealpix -lcfitsio -lhealpix_cxx
#CFLAGS := -g -O3 -Wall -xCORE-AVX512 -qopt-zmm-usage=high -restrict	# for cosmosx
CFLAGS := -g -O3 -Wall -xMIC-AVX512 -restrict		# for KNL
OPT_RPT_FLAGS := -qopt-report=5 -qopt-report-file=icc_opt

# CC := gcc
# LIBS := -lgsl -lgslcblas -lm -fopenmp
# CFLAGS := -g -O2 -I. -Wall

C_INCLUDE_PATH = /nfs/software/healpix_cxx/3.50/include/healpix_cxx
export C_INCLUDE_PATH

COM_CFILES := array_tools.c
COM_OBJFILES := $(COM_CFILES:%.c=%.o)
OBJDIR := objects
SRCDIR := .
OPT_RPTS := $(COM_CFILES:%.c=opt_reports/icc_opt_%)

VPATH = .:objects:codes

main: $(OBJDIR)/main.o $(COM_OBJFILES:%=$(OBJDIR)/%) $(SRCDIR)/init.h
	$(CC) $(CFLAGS) -I$(SRCDIR) $^ -o $@ $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/init.h
	$(CC) $(CFLAGS) -I$(SRCDIR) -c $< -o $@ $(LIBS)

opt_rpt: $(OPT_RPTS)

opt_reports/icc_opt_%: $(SRCDIR)/%.c $(SRCDIR)/init.h
	$(CC) $(CFLAGS) -qopt-report=5 -qopt_report_file=$@ -I$(SRCDIR) -c $< -o $(@:opt_reports/icc_opt_%=$(OBJDIR)/%.o) $(LIBS)

clean:
	rm -f $(OBJDIR)/*.o $(OPT_RPTS)
