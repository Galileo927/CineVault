PRAGMA foreign_keys = ON;

CREATE TABLE IF NOT EXISTS libraries (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    root_path TEXT NOT NULL UNIQUE,
    last_scan_at TEXT,
    status TEXT NOT NULL DEFAULT 'idle',
    created_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS movies (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    library_id INTEGER NOT NULL,
    title TEXT NOT NULL,
    original_title TEXT,
    year INTEGER,
    overview TEXT,
    poster_path TEXT,
    backdrop_path TEXT,
    file_path TEXT NOT NULL UNIQUE,
    file_size INTEGER NOT NULL DEFAULT 0,
    duration REAL,
    container TEXT,
    video_codec TEXT,
    audio_codec TEXT,
    width INTEGER,
    height INTEGER,
    fps REAL,
    bitrate INTEGER,
    status TEXT NOT NULL DEFAULT 'indexed',
    is_favorite INTEGER NOT NULL DEFAULT 0,
    is_watched INTEGER NOT NULL DEFAULT 0,
    created_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,
    updated_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (library_id) REFERENCES libraries(id) ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS playback_progress (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id TEXT NOT NULL DEFAULT 'default',
    movie_id INTEGER NOT NULL,
    position_seconds REAL NOT NULL DEFAULT 0,
    duration_seconds REAL NOT NULL DEFAULT 0,
    percentage REAL NOT NULL DEFAULT 0,
    is_finished INTEGER NOT NULL DEFAULT 0,
    updated_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,
    UNIQUE(user_id, movie_id),
    FOREIGN KEY (movie_id) REFERENCES movies(id) ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS subtitles (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    movie_id INTEGER NOT NULL,
    language TEXT,
    format TEXT NOT NULL,
    file_path TEXT NOT NULL,
    is_embedded INTEGER NOT NULL DEFAULT 0,
    encoding TEXT,
    title TEXT,
    created_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (movie_id) REFERENCES movies(id) ON DELETE CASCADE
);

CREATE INDEX IF NOT EXISTS idx_movies_library_id ON movies(library_id);
CREATE INDEX IF NOT EXISTS idx_movies_title ON movies(title);
CREATE INDEX IF NOT EXISTS idx_progress_movie_id ON playback_progress(movie_id);
CREATE INDEX IF NOT EXISTS idx_subtitles_movie_id ON subtitles(movie_id);
