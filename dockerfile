FROM alpine:latest

WORKDIR /app

COPY . .

RUN apk add wget python3

RUN wget -O get-platformio.py https://raw.githubusercontent.com/platformio/platformio-core-installer/master/get-platformio.py

RUN python3 get-platformio.py

RUN mkdir -p /usr/local/bin

RUN ln -s ~/.platformio/penv/bin/platformio /usr/local/bin/platformio

RUN ln -s ~/.platformio/penv/bin/pio /usr/local/bin/pio

RUN ln -s ~/.platformio/penv/bin/piodebuggdb /usr/local/bin/piodebuggdb