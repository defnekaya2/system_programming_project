
FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    libpqxx-dev \
    pkg-config\
    postgresql-client \
    make \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY ./src /app/src
COPY ./include /app/include
COPY CMakeLists.txt /app

RUN cmake .
RUN make

CMD ["./sis_app"]

