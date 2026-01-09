CREATE TABLE IF NOT EXISTS students (
    id SERIAL PRIMARY KEY,
    name TEXT NOT NULL,
    student_number TEXT NOT NULL,
    department TEXT NOT NULL
);
