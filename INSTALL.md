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
---

## Docker Installation (Final Verification)

The application can be deployed using Docker Compose without additional configuration.

### Steps

```bash
docker compose up -d





