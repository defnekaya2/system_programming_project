# Temel imaj
FROM ubuntu:22.04

# Güncelleme ve bağımlılıklar
RUN apt-get update && apt-get install -y \
    g++ \
    cmake \
    libpqxx-dev \
    pkg-config\
    postgresql-client \
    make \
    && rm -rf /var/lib/apt/lists/*

# Çalışma dizini
WORKDIR /app

# Source kodu kopyala
COPY ./src /app/src
COPY ./include /app/include
COPY CMakeLists.txt /app

# Build
RUN cmake .
RUN make

# Komut satırı ile çalıştır
CMD ["./sis_app"]

