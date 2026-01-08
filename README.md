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

## Contribution Rules

1. Create a feature branch from develop
2. Make changes only in your feature branch
3. Push changes to your feature branch
4. Open a Pull Request to develop
5. At least one review is required before merge

---

## Pull Request Rules

- Meaningful title and description
- Must reference a related Issue
- Direct push is not allowed

## Docker Images

- Application Image: https://hub.docker.com/r/zuleyha34/sis-project-app
=======
> **Validation:**  
> The Docker Compose configuration has been validated for the final submission.  
> All services start and restart cleanly without errors.

