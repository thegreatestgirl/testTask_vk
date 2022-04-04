# Test task - Core Infrastructure, internship 2022 (VK)

## Part1: About project

* This project has client/server model and allows to send file from client to server with saving data on server part. Realised for Linux OS
* In this project server and client have IPv4. Data transfering work by TCP protocol in duplex mode
* Server part allows to chose port for listening (client has static port - 8080) and directory for saving receiving file (for saving to current directory you need to select: /) `the directory for saving data should be exist`
* Client part allows to chose IP address of server (at server part pproject has static ip address `0.0.0.0` for listening all input connections). Also you need to select file for sending
* PROJECT LOCATES AT `develop` BRANCH

## Part2: Build

* Build of projects realised by Makefile, which has this options:

> make/make all - build of all project: server part build at executable file 'server' and started by `./server` comand, client part build at executable file 'client' and started by `./client` comand;\
> make server - build of server part: build executable file 'server' and started by `./server` comand;\
> make client - build of client part: build executable file 'client' and started by `./client` comand;\
> make clean - clear of all executable and object (.o) files;\
> make rebuild - realize rebuild of all project: firstly calls 'make clean', secondly 'make all'.