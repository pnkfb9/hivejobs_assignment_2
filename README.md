# Hivejob's client second assignment

This is the readme file containing useful information for the user who wants to clone and run the 'second_client_assignment' executable file from this Git repository.

## Introduction

As the readme title's says, this specific source code is relative to the second of two assignments given from Hivejob's recruiter Teresa Linda, and the intended audience is the Client Company interested in the developer's job selection process.

This assignment provides that the requested executable, a Linux command line application written in the C programming language, reads the content of JSON object queried from a RESTful service upon HTTP GET from the provided <a href="https://simpleexerciseforreadingjsondata-yvgbbyqpmq.now.sh">URL</a>.


## Getting Started

The following instructions will give the user the ability to clone, build and run the command line application on the user's local machine.


### Prerequisites

First of all, the application is intended to run natively on Linux machines, so the nexts steps implicitly refers to the build steps on a Linux machine. 
The application has been developed and built over Lubuntu 16.04.3 LTS 64bit. The usage of Lubuntu instead of its more famous brother Ubuntu is due to scarce hardware resources of my personal laptop. Altough these instructions refer to Lubuntu, any Linux-based distribution should do the trick.

What's needed:

A good **C compiler**:

```
GNU GCC (personally compiled with version 5.4)
```

If you have not installed it yet, please do it:

```
$ sudo apt-get install build-essential 
```

**cURL support**, in order to be able to fecth data from RESTful services:

```
curl 7.47.0 (libcurl/7.47.0 GnuTLS/3.4.10 zlib/1.2.8 libidn/1.32 librtmp/2.3)
```

If you have not installed any cURL library, please do it:

```
$ sudo apt-get install curl libcurl4-gnutls-dev
```

open source **JSON parser**: <a href="https://github.com/zserge/jsmn">JSMN</a>(buld informations present on its github page, but added also in the Makefile for this project). 
I've already packed source files for this last requirement into lib/jsmn folder, so there is no need to download it.

### Installing and running

1) clone or download the repository to your local machine:

```
$ git clone git@github.com:pnkfb9/hivejobs_assignment_2.git
```

2) Access to the directory in which the repository has been cloned, and build it:

```
$ cd /path/to/hivejobs_assignment_2
$ make
```

3) If the build process goes well, you'll find in the build directory an executable called 'second_client_assignment' ready to be run. To run it, just type:

```
$ ./second_client_assignment
```

If you want to remove the executable, access to the build directory and type:

```
$ cd /path/to/hivejobs_assignment_2
$ make clean
```
## Problem Solution

The solution has come by working on different sub-features one after the other, selecting the sub-feature order based on the importance of them to solve the main problem.

The project structure is the following:

```
hivejobs_assignment_2/
|
 --include/
    |
    .json_facility.h
    .restful_facility.h
|
 --lib/
    |
     --jsmn/
|     
. main.c
.json_facility.c
.restful_facility.c
.Makefile
.README.md
```
Even if the assignment does not require to have different source files, I've preferred to split the needed functionalities into separate files, in order to maintain a better logical organization and hence giving better readability and understandability.

_json facility_ source file keeps a collection of useful methods used to parse JSON files.
_restful_facility_ source file keeps instead a set of methods that wraps the cURL API functions, giving a simple interface to create connections to specified URLs, bind callback functions and data types to retrieve the JSON objects.

Finally, the _main_ source file contains the actual code used to retrieve data, and its procedure is:
1. initiate a curl session
2. bind the curl session to the specified URL, sets useful parameters and binding callbacks, via open_connectio() method 
3. fetch the JSON object from URL
4. after receiving raw object in the form of a string, call to JSON parsing method that extrapolate data
5. for each object found, a new patient element is created and filled with device ID and patient ID values
6. once finished, the retrieved data are printed to the console:
```
Device result: 13010009
Patient result: MARIO_ROSSI
```

## Variations & future improvements

Even if not required by the assignment, the code should be able to fetch more than one entry from the JSON RESTful entry(actually the requirement was only to print the results from the single-object JSON string returned by the service). In fact, during the development phase I decided to spend some extra effort over the implementation of a simple linked list capable to hold a list of patients and their information(devide ID and patient ID). Unfortunately, I did not tested the feature because I ran ouf of time(to give effort also to the first assignment) and did not tried to modify the JSON object returned from the service, but I am confident that this imporvement works as expected.

Future improvements could be related to:
- write tests in order to improve reliability of the application 
- coding improvements to better check each phase's result and avoid unpredictable situations

## Authors

**Fabio Pancot** - *development* - [pnkfb9](https://github.com/pnkfb9)
