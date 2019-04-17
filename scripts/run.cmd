@echo off
docker stop app > nul
docker rm app > nul

docker run ^
	--name app ^
	-p 6666:6666 ^
	-v %cd%:/opt ^
	-it app/app ^
    %*
