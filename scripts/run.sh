#!/bin/bash

cwd=$(pwd)

docker stop app &> /dev/null
docker rm app &> /dev/null

docker run \
	-it \
	--name app \
	-p 6666:6666 \
	-v ${cwd}:/opt \
	--privileged \
	app/app \
    "${@}"
