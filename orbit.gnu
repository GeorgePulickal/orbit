#set the graph for 2D and 3D plot
set xrange [-25:25]
set yrange [-25:25]
set zrange [-20:20]
set xlabel " X "
set ylabel " Y "
set zlabel " Z "
set title "3D Orbit"
set label 1 '' at 0,0 point pointtype 7 pointsize 7
set size square

set grid ytics lt 0 lw 1 lc rgb "#bbbbbb"
set grid xtics lt 0 lw 1 lc rgb "#bbbbbb"

# filename and n=number of lines of your data 
n = 10000
#names of files to read from
file1 = 'positive_x_impulse.dat'
file2 = 'positive_x_circle.dat'
set term gif animate
set output 'orbit3D_positive_x.gif'

#make 3D plot
do for [j=1:n: 100] {
    splot file1 u 1:2:3 every ::1::j w l lw 2 title "Motion after impulse", \
          file1 u 1:2:3 every ::j::j w p pt 7 ps 2 notitle,\
          file2 u 1:2:3 every ::1::j w l lw 2 title "Circular motion", \
          file2 u 1:2:3 every ::j::j w p pt 7 ps 2 notitle 
}

#make 2D plot
set title "2D Orbit"
set term gif animate
set output 'orbit2D_positive_x.gif'
do for [j=1:n: 100] {
    plot file1 u 1:2 every ::1::j w l lw 2 title "Motion after impulse", \
          file1 u 1:2 every ::j::j w p pt 7 ps 2 notitle,\
          file2 u 1:2 every ::1::j w l lw 2 title "Circular motion", \
          file2 u 1:2 every ::j::j w p pt 7 ps 2 notitle, \
}

#change graph for energy
set xlabel "Time"
set ylabel "Energy"
set title "Kinetic Energy"
set xrange [0:10000]
set yrange [0:3000]
set label 1 '' at 0,0 point pointtype 7 pointsize 1
set term gif animate
set output 'kineticenergy_positive_x.gif'
do for [j=1:n: 100] {
    plot file1 u 7:4 every ::1::j w l lw 2 title "Motion after impulse", \
          file1 u 7:4 every ::j::j w p pt 7 ps 2 notitle,\
          file2 u 7:4 every ::1::j w l lw 2 title "Circular motion", \
          file2 u 7:4 every ::j::j w p pt 7 ps 2 notitle, \
}

#ploot potential energy
set xlabel "Time"
set ylabel "Energy"
set title "Potential Energy"
set xrange [0:10000]
set yrange [-3000:0]
set label 1 '' at 0,0 point pointtype 7 pointsize 1
set term gif animate
set output 'potentialenergy_positive_x.gif'
do for [j=1:n: 100] {
    plot file1 u 7:5 every ::1::j w l lw 2 title "Motion after impulse", \
          file1 u 7:5 every ::j::j w p pt 7 ps 2 notitle,\
          file2 u 7:5 every ::1::j w l lw 2 title "Circular motion", \
          file2 u 7:5 every ::j::j w p pt 7 ps 2 notitle, \
}

#plot total energy
set xlabel "Time"
set ylabel "Energy"
set title "Total Energy"
set xrange [0:10000]
set yrange [-2000: 0]
set label 1 '' at 0,0 point pointtype 7 pointsize 1
set term gif animate
set output 'totalenergy_positive_x.gif'
do for [j=1:n: 100] {
    plot file1 u 7:6 every ::1::j w l lw 2 title "Motion after impulse", \
          file1 u 7:6 every ::j::j w p pt 7 ps 2 notitle,\
          file2 u 7:6 every ::1::j w l lw 2 title "Circular motion", \
          file2 u 7:6 every ::j::j w p pt 7 ps 2 notitle, \
}
