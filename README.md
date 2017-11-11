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
sudo apt-get install build-essential 
```

**cURL support**, in order to be able to fecth data from RESTful services

```
curl 7.47.0 (libcurl/7.47.0 GnuTLS/3.4.10 zlib/1.2.8 libidn/1.32 librtmp/2.3)
```

If you have not installed any cURL library, please do it:

```
sudo apt-get install curl libcurl4-gnutls-dev
```

open source **JSON parser**: <a href="https://github.com/zserge/jsmn">JSMN</a>(buld informations present on its github page, but added also in the Makefile for this project). 
I've already packed source files for this last requirement into lib/jsmn folder, so there is no need to download it.

### Installing and running

1) clone or download the repository to your local machine:

```
git clone git@github.com:pnkfb9/hivejobs_assignment_2.git
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

## Authors

**Fabio Pancot** - *development* - [pnkfb9](https://github.com/pnkfb9)
