FROM gcc:9.2

WORKDIR /dev/temp

CMD ["make", "all"]