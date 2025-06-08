FROM ubuntu:20.04
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY src/ /app/src/
COPY include/ /app/include/

RUN g++ src/main.cpp -o shapes
ENTRYPOINT ["./shapes"]
