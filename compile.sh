#!/bin/sh

pdflatex --halt-on-error trd.tex

COMPILED=$?
if [ $COMPILED -eq 0 ]; then 
  rm *.log
  rm *.aux
fi
