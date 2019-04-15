docker stop app
docker rm app

docker run ^
	--name app ^
	-p 6666:6666 ^
	-v %cd%:/opt ^
	-it app/app ^
    %*