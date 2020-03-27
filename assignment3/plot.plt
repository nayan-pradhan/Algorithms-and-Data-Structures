# CH-231-A
# a3 p2a, b, c cpp 
# Nayan Man Singh Pradhan 
# n.pradhan@jacobs-university.de

set terminal png size 1920,1080
set output "plot.png"
set title "Time Complexity of Selection Sort"
# Line width of the axes
set border linewidth 0.25
# Line styles
set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 0.5
set style line 2 linecolor rgb '#dd181f' linetype 1 linewidth 0.5
set style line 3 linecolor rgb '#00ff00' linetype 1 linewidth 0.5
set xlabel "n"
set ylabel "Time Taken"

plot "data.txt" using 1:2 with lines linestyle 1 title "Average Array",\
    "data.txt" using 1:3 with lines linestyle 2 title "Worst Case",\
    "data.txt" using 1:4 with lines linestyle 3 title "Best Case"