## Docker Setup (Final)

The project is fully containerized using Docker Compose.

### Running the System

```bash
docker compose up -d
This command starts:
- PostgreSQL database container
- Student Information System application container

### Notes

- Containers communicate over a private Docker network
- Database data is persisted using Docker volumes
- PostgreSQL health checks are enabled to ensure service readiness

> **Validation:**  
> The Docker Compose configuration has been validated for the final submission.  
> All services start and restart cleanly without errors.
