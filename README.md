# permutations-project
My first bigger project.

Done as an extra university project, and as a way for myself to prove that I can quickly learn totally new tools (Cmake, LaTeX, bash scripting, gnuplot).
This is meant to be the project's structure:

```
permutations-project/
│
├── source
│   ├── checkinput1.cpp
│   ├── checkinput2.cpp
│   ├── display_vector.cpp
│   ├── factorial.cpp
│   ├── how_many_cycles.cpp
│   ├── number_of_inversions.cpp
│   ├── main.cpp
│   └── CMakeLists.txt
│
├── build
│   └── /here you will run the command cmake ../source
│
├── input_and_output
│   ├── input.txt
│   └── run.sh
│
├── gnuplot
│   ├── makegraph.sh
│   └── results.tex
```

For instructions on how to configure the `input.txt` file and what arguments to give to the `makegraph.sh` script to produce the graph you want, see the `input_and_makegraph_instructions.txt` file.
The gist of using the project is:
 - place all the files in their appropriate directories according to the above diagram
 - run `cmake ../source` in the `build` directory, then do `make`
 - once that is done, you can try adding your own input in the `input.txt` file and then doing `./run.sh` to produce a pdf file output
 - or you can try using the `makegraph.sh` script to produce a pdf file made using LaTeX, that contains a graph plotted with gnuplot
