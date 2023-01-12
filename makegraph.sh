n=$1

# Check that the number of arguments is correct
if [ $# -ne $(( $1 * 2 + 1 )) ]; then
    echo "test.sh error: Invalid number of arguments"
    exit 1
fi

# Check that the first argument is a natural number between 1 and 9
if ! [[ $1 =~ ^[1-9][0-9]*$ ]]; then
    echo "test.sh error: First argument must be a natural number between 1 and 9"
    exit 1
fi

# Shift the arguments left by one position
shift

# Check that the remaining arguments are natural numbers between 10 and 99
for arg in "$@"; do
    if ! [[ $arg =~ ^[1-9][0-9]{1,2}$ ]] || [ $arg -lt 10 ] || [ $arg -gt 99 ]; then
        echo "test.sh error: Remaining arguments must be natural numbers between 10 and 99"
        exit 1
    fi
done

echo "arguments are correct"


# If we reach this point, the arguments are valid

datafile_number=1

#preparing plot.gp file
echo "preparing plot.gp file"
echo "# Set the output file type" > plot.gp
echo "#set terminal postscript eps enhanced color solid colortext 9" >> plot.gp
echo "set terminal png enhanced truecolor" >> plot.gp
echo "# Set the output file name" >> plot.gp
echo "set output 'gnuplot_output.png'" >> plot.gp
echo "# Set the y-axis label" >> plot.gp
echo "set ylabel \"time (seconds)\"" >> plot.gp
#setting y axis to start at 0
echo "set yrange[0:]" >> plot.gp
echo "# Now plot the data with lines and points" >> plot.gp

while (( "$#" >= 2 )); do
    echo
    echo "making the .dat file $1 permutations of a set of $2"

    #make the data?.dat file
    cd ../input_and_output
    touch data$datafile_number.dat
    rm data$datafile_number.dat
    touch data$datafile_number.dat
    for ((a=1; a<=9; a++))
    do
        TIMEFORMAT=%R
        echo "$a" > input.txt
        for ((i=1; i<=a; i++))
        do
            echo "$1 $2" >> input.txt
        done
        variable=$({ time ./run.sh >/dev/null; } 2>&1)
        variable=$(echo "$variable" | tr ',' '.')
        echo "$a $variable" >> data$datafile_number.dat
        echo "time: $variable"
    done
    mv data$datafile_number.dat ../gnuplot/data$datafile_number.dat
    cd ../gnuplot

    #add text to plot.gp
    if [ $datafile_number -eq 1 ]
    then
        echo "plot 'data$datafile_number.dat' lc $datafile_number w lp title '$1 permutations, set of $2', \\" >> plot.gp
    elif [ $# -eq 2 ]
    then
        echo "     'data$datafile_number.dat' lc $datafile_number w lp title '$1 permutations, set of $2'" >> plot.gp
        echo "exit" >> plot.gp
    else
        echo "     'data$datafile_number.dat' lc $datafile_number w lp title '$1 permutations, set of $2', \\" >> plot.gp        
    fi

    let "datafile_number=datafile_number+1"
    
    shift 2
done

echo
echo "using gnuplot"
echo
gnuplot plot.gp

echo "removing data files"
rm data?.dat
echo

echo "making the results.pdf file"
echo
pdflatex results.tex
echo
echo "removing results.log and results.aux"
rm results.log results.aux