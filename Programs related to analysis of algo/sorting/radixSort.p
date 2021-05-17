   set autoscale                        # scale axes automatically
      unset log                              # remove any log-scaling
      unset label                            # remove any previous labels
      set xtic auto                          # set xtics automatically
      set ytic auto                          # set ytics automatically
	  set tics font "Helvetica,10"
      set title "Analysis of Complexity of Algorithms (Radix Sort)"
      set xlabel "Input Size"
      set ylabel "Time Taken"
      #set key 0.01,100
      #set label "Yield Point" at 0.003,260
      #set arrow from 0.0028,250 to 0.003,280
      set xr [1000:100000]
      set yr [0.000000:0.2]
      plot  "radixSort.txt" using 1:2 title 'Average Case' with linespoints, \
            "radixSort.txt" using 1:3 title 'Best Case'  with linespoints,\
            "radixSort.txt" using 1:4 title 'Worst Case'  with linespoints