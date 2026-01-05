#Student Information System
## Development Workflow
- All changes are made in feature branches
- Direct push to main and develop is disabled
- All changes are merged via Pull Requests
- Also after push operations unnecessary branches are deleted

### Branch Protection Verification

-A direct push attempt to the main branch was intentionally performed
to verify branch protection rules.
-GitHub explicitly logged the violation and allowed an admin bypass,
confirming that changes are enforced via Pull Requests.

## Branch Strategy

- main: stable release branch (protected)
- develop: active development branch
- studentX-weekY-topic: feature branches for each week and each branch deleted after their work is done.

All changes must be merged via Pull Request.
Direct pushes to main branch are not allowed.

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
