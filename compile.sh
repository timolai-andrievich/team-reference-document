#!/bin/sh

pdflatex --halt-on-error trd.tex
pdflatex --halt-on-error trd.tex # Recompile to include the table of contents

COMPILED=$?
if [ $COMPILED -eq 0 ]; then 
  rm *.toc 
  rm *.log
  rm *.aux
fi
