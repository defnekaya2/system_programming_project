# Docker Research – Week 1

## Containers
This project will use two Docker containers:
- PostgreSQL database container
- C++ application container

## PostgreSQL Container
- Official PostgreSQL Docker image will be used
- Environment variables will define user, password, and database
- Data persistence will be provided via Docker volumes

## Networking
- Containers will communicate over a Docker bridge network
- Application container will connect to PostgreSQL using service name

## Volumes
- Named volume will be used for PostgreSQL data storage

## Next Steps (Week 2)
- Create docker-compose.yml
- Implement container startup
