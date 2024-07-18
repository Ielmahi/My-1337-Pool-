#!/bin/bash

sum=$( echo -n "$FT_NBR1 + $FT_NBR2" | tr "mrdoc" "01234" | tr \''\\"?!' "01234")
echo "obase=13; ibase=5; $sum" | bc | tr "0123456789ABC" "gtaio luSnemf"
