
## Docker Setup (Week 3)

The project uses Docker Compose for local development.
PostgreSQL runs with a persistent volume and environment variables defined in a `.env` file.
Containers can be started using `docker compose up`.
## Environment Variables

The application container uses environment variables for
database connection configuration.

Example variables:
- POSTGRES_HOST
- POSTGRES_DB
- POSTGRES_USER
- POSTGRES_PASSWORD

