cp input.txt ../build/input.txt
cd ../build
./checkinput1
if [ $? -ne 0 ]
then
	echo "input file invalid"
	exit 1
fi
./checkinput2
if [ $? -ne 0 ]
then
	echo "input file invalid"
	exit 1
fi
./permutations < input.txt > output.tex
pdflatex output.tex output.pdf
cp output.pdf ../input_and_output/output.pdf