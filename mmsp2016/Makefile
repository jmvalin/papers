# Makefile to generate the dissertation from its sources.
# Requires transfig and pdflatex.

NAME = mmsp2016

PAPER_SRCS = $(NAME).tex daala.bib

FIG_SRCS =

EPS_SRCS =

FIG_TEX_SRCS =

EXTRA_FIGS = basis4.pdf bike_dering_crop.png bike_nodering_crop.png \
 block32_L0.pdf block32_L1.pdf block32_L2.pdf block32_L3.pdf \
 fruits_dering_crop.png fruits_nodering_crop.png

FIG_OBJS = $(FIG_SRCS:.fig=.pdf) \
 $(FIG_TEX_SRCS:.fig=.pdftex) $(FIG_TEX_SRCS:.fig=.pdftex_t)

PDF_OBJS = $(EPS_SRCS:.eps=.pdf)

FIG_AUXS =

all: $(NAME).pdf

$(NAME).pdf : $(PAPER_SRCS) $(FIG_OBJS) $(PDF_OBJS) $(EXTRA_FIGS) $(NAME).bbl
	pdflatex $(NAME)
	pdflatex $(NAME)

$(NAME).bbl : $(PAPER_SRCS) $(FIG_OBJS) $(PDF_OBJS) $(EXTRA_FIGS)
	@if [ $(NAME).tex -nt $(NAME).aux ] ; then \
          pdflatex $(NAME) ; \
        fi
	bibtex $(NAME)

figures : $(FIG_OBJS)

# rule to generate latex versions of the xfig figures
%.tex : %.fig
	fig2dev -L latex $< $@

%.pdf : %.eps
	epstopdf $< --outfile=$@

%.pdf : %.fig
	fig2dev -L pdf -p 0 $< $@

%.pdftex : %.fig
	fig2dev -L pdftex -p 0 $< $@

%.pdftex_t : %.fig
	fig2dev -L pdftex_t -p $(<:.fig=.pdftex) $< $@

# Make everything depend on changes in the Makefile
$(NAME).pdf $(NAME).bbl $(FIG_OBJS) $(PDF_OBJS): Makefile

.PHONY: all figures clean distclean maintainer-clean

# clean targets
clean:
	-rm $(NAME).pdf
	-rm $(FIG_OBJS)
	-rm $(FIG_AUXS)
	-rm $(PDF_OBJS)
	-rm $(NAME).aux
	-rm $(NAME).log
	-rm $(NAME).lof
	-rm $(NAME).lot
	-rm $(NAME).out
	-rm $(NAME).bbl
	-rm $(NAME).blg
	-rm $(NAME).toc

distclean: clean

maintainer-clean: distclean

maintainerclean: maintainer-clean
