## Docker Setup (Week 3)

The project uses Docker Compose for local development.
PostgreSQL runs with a persistent volume and environment variables defined in a .env file.
Containers can be started using docker compose up.

## Environment Variables

The application container uses environment variables for
database connection configuration.

Example variables:
- POSTGRES_HOST
- POSTGRES_DB
- POSTGRES_USER
- POSTGRES_PASSWORD


## Installation Status (Week 3)

At this stage, the project structure and build configuration are prepared.
Full deployment using Docker Compose will be completed in the next phase.

Prerequisites:
- Ubuntu
- Docker
- Docker Compose
- C++ compiler


## Week 4-Finalization
First, clone the project repository:
git clone https://github.com/defnekaya2/system_programming_project.git
cd system_programming_project

Make sure Docker is running on your system. Then pull the required Docker images and start the containers using Docker Compose:
docker compose pull
docker compose up -d

After starting the system, verify that the containers are running:
docker ps

The application container and the PostgreSQL database container should be listed as running.

To stop and remove the containers, use:
docker compose down
