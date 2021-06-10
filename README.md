# Build instructions

```bash
mkdir build && cd build && cmake .. && make
```
# Usage instructions

From build directory:
```bash
./demo ../data/dog.jpg ../data/spec.txt
```

# Techincal Interview: basics of C++

Goals: 

- Compile this repo (better with cmake) to run the program ```demo```. Add the compilation file to the solution.
- Write a function in the class ```Specs``` that:
    - is called ```parseFromFile``` and takes a filename as input
    - parse a file as the one in ```data/spec.txt```. In particular:
        - it skips all the lines before the keyword ```begin```
        - it skips all the lines after the keyword ```end```
        - it reads only the values in between  ```~~``` (begin) ```!-!``` (separator) ```??``` (end). The first value is a valid width, the second is a valid height.
- Complete demo.cpp in order to:
    - accept two arguments: path to an image, path to a spec file
    - parse the spec file
    - load the image
    - resize the image to [average width of the specs, max height of the specs]
    - save the image
