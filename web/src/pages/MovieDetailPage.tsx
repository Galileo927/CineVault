import { ArrowLeft, Check, Heart, Play, Subtitles } from "lucide-react";

import type { Movie } from "../types";

type MovieDetailPageProps = {
  movie: Movie;
  onBack: () => void;
  onPlay: () => void;
};

export function MovieDetailPage({ movie, onBack, onPlay }: MovieDetailPageProps) {
  return (
    <div className="detail-page">
      <button className="text-button" onClick={onBack}>
        <ArrowLeft size={17} />
        返回
      </button>

      <section className={`detail-hero poster-${movie.accent}`}>
        <div className="detail-poster">
          <span>{movie.title}</span>
        </div>
        <div className="detail-copy">
          <p className="eyebrow">{movie.originalTitle}</p>
          <h1>{movie.title}</h1>
          <div className="hero-meta">
            <span>{movie.year}</span>
            <span>{movie.runtime}</span>
            {movie.genres.map((genre) => (
              <span key={genre}>{genre}</span>
            ))}
          </div>
          <p>{movie.overview}</p>
          <div className="movie-tags large">
            {movie.quality.map((tag) => (
              <span key={tag}>{tag}</span>
            ))}
          </div>
          <div className="detail-actions">
            <button className="command-button" onClick={onPlay}>
              <Play size={18} />
              播放
            </button>
            <button className="icon-button" aria-label="收藏">
              <Heart size={18} />
            </button>
            <span className="detail-pill">
              <Subtitles size={16} />
              {movie.subtitleStatus === "missing" ? "无字幕" : "字幕可用"}
            </span>
            <span className="detail-pill">
              <Check size={16} />
              已入库
            </span>
          </div>
        </div>
      </section>
    </div>
  );
}
