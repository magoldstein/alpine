FROM alpine
RUN apk add vim
RUN apk add gcc
RUN apk add musl-dev
COPY hello.c /
COPY enigma.c /
