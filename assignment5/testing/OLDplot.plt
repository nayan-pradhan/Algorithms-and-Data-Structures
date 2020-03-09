# CH-231-A
# a5 plt 
# Nayan Man Singh Pradhan 
# n.pradhan@jacobs-university.de

set terminal png size 1920,1080
set output "plot.png"
set title "Time Complexity"
# Line width of the axes
set border linewidth 0.25
# Line styles

set logscale y
set logscale x

set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 0.5
set style line 2 linecolor rgb '#dd181f' linetype 1 linewidth 0.5
set style line 3 linecolor rgb '#00ff00' linetype 1 linewidth 0.5
set style line 4 linecolor rgb '#9932CC' linetype 1 linewidth 0.5
set xlabel "k"
set ylabel "Time Taken in nanoseconds"

plot "data.txt" using 1:2 with lines linestyle 1 title "Naive Recursive",\
    "data.txt" using 1:3 with lines linestyle 3 title "Bottom Up",\
    "data.txt" using 1:4 with lines linestyle 2 title "Closed Form",\
    "data.txt" using 1:5 with line linestyle 4 title "Matrix Form"