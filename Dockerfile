FROM alpine:latest

RUN apk update && apk add make g++

WORKDIR /app

CMD [ "make", "&&", "make fclean" ];
