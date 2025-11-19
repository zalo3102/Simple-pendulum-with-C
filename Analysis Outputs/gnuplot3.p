plot"Datos2.txt" using 1:2 title "Euler", \
"Datos2.txt" using 1:3 title "RK2", \
"Datos2.txt" using 1:4 title "RK4"

set xlabel "Tiempo"
set ylabel "Ángulo"
set title "h=0.01"
set xrange [0:2]
set key bottom left
replot

set terminal jpeg
set output "angulo.jpg"
replot
