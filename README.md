# Matching + Johnson's weighting + Augmenting Paths

## Build

The project uses CMake to instrument the build process. To build the current project you can enter the following line on
your command line:

```bash
cmake -DCMAKE_BUILD_TYPE=Release -Bbuild/Release
```

Then

```bash
cmake --build build/Release
```

## Run

Three different binaries are going to be generated at ``build/Release``. They are:

- **graph_generator**: used to generate valid test instances
- **minPerfMatchWeight**: used to find out the weight of the minimum perfect match of some valid instance
- **maxMatchWeight**: used to find out the weight of the maximum match of some valid instance

### Minimum Perfect Match

Ex:

```
./build/Release/minPerfMatchWeight < ./lab/analysis/data/test.dat
```

It should output
``
2
``

### Maximum Match

Ex:

```
./build/Release/maxMatchWeight < ./lab/analysis/data/test.dat
```

It should output
``
10
``

## Tests

There are scripts for automating tests and runtime evaluations at ``./lab``. You can tune them and replicate the
experiments reported at the document in `./doc`


_Have a good one :), Garren_