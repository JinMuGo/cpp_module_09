FROM alpine:latest

RUN apk update && apk add make g++

WORKDIR /app

CMD [ "sh", "-c", "make fclean && make && make fclean" ]
