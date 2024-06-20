#!/bin/sh
# Build the Docker image using dockerfile_32
docker build -t my-32bit-debugger -f dockerfile_32 .

# Run the Docker container with the necessary privilege to disable ASLR
docker run -it --privileged my-32bit-debugger
