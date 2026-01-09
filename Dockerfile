FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y build-essential cmake libpqxx-dev libpq-dev g++ make git && apt-get clean
WORKDIR /app
COPY CMakeLists.txt /app/
COPY include/ /app/include/
COPY src/ /app/src/
RUN cmake .
RUN make
CMD ["./sis_app"]

