import { Clock, Play, Subtitles } from "lucide-react";

import type { Movie } from "../types";

type MovieCardProps = {
  movie: Movie;
  onOpen: (movie: Movie) => void;
  onPlay: (movie: Movie) => void;
};

export function MovieCard({ movie, onOpen, onPlay }: MovieCardProps) {
  return (
    <article className="movie-card">
      <button className={`poster poster-${movie.accent}`} onClick={() => onOpen(movie)}>
        <span className="poster-title">{movie.title}</span>
        <span className="poster-meta">{movie.year}</span>
      </button>
      <div className="movie-card-body">
        <button className="movie-title" onClick={() => onOpen(movie)}>
          {movie.title}
        </button>
        <div className="movie-subtitle">{movie.originalTitle}</div>
        <div className="movie-tags">
          {movie.quality.map((tag) => (
            <span key={tag}>{tag}</span>
          ))}
        </div>
        {movie.progress !== undefined && (
          <div className="progress-row">
            <Clock size={15} />
            <div className="progress-track">
              <span style={{ width: `${movie.progress}%` }} />
            </div>
            <span>{movie.progress}%</span>
          </div>
        )}
        <div className="card-actions">
          <button className="icon-button primary" onClick={() => onPlay(movie)} aria-label={`播放 ${movie.title}`}>
            <Play size={16} />
          </button>
          <span className="subtitle-state">
            <Subtitles size={15} />
            {movie.subtitleStatus === "available" ? "SRT" : movie.subtitleStatus === "embedded" ? "内嵌" : "无字幕"}
          </span>
        </div>
      </div>
    </article>
  );
}
