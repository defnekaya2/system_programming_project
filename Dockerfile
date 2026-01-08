# -------- BUILD STAGE --------
FROM ubuntu:22.04 AS builder


FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    pkg-config \
    libpqxx-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY ./src /app/src
COPY ./include /app/include
COPY CMakeLists.txt /app

RUN cmake .
RUN make

CMD ["./sis_app"]

