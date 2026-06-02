CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    username VARCHAR(255) UNIQUE NOT NULL,
    password_hash VARCHAR(255) NOT NULL,
    role VARCHAR(20) NOT NULL DEFAULT 'STUDENT'
);

CREATE TABLE assignments (
    id SERIAL PRIMARY KEY,
    title VARCHAR(200),
    description TEXT,
    submission_deadline TIMESTAMP,
    review_deadline TIMESTAMP,
    created_by INT
);

CREATE TABLE submissions (
    id SERIAL PRIMARY KEY,
    assignment_id INT,
    author_id INT,
    code_content TEXT
);

CREATE TABLE peer_reviews (
    id SERIAL PRIMARY KEY,
    submission_id INT,
    reviewer_id INT,
    comments TEXT,
    suggested_grade FLOAT
);