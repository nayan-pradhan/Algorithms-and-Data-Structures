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
set xlabel "n"
set ylabel "Time Taken in nanoseconds"

plot "naive.txt" using 1:2 with lines linestyle 1 title "Naive Recursive",\
    "bottom.txt" using 1:2 with lines linestyle 3 title "Bottom Up",\
    "closed.txt" using 1:2 with lines linestyle 2 title "Closed Form",\
    "matrix.txt" using 1:2 with line linestyle 4 title "Matrix Form" 