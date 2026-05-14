import { Heart, Sparkles } from "lucide-react";

import { MovieCard } from "../components/MovieCard";
import type { Movie } from "../types";

type LibraryPageProps = {
  movies: Movie[];
  onOpenMovie: (movie: Movie) => void;
  onPlayMovie: (movie: Movie) => void;
};

export function LibraryPage({ movies, onOpenMovie, onPlayMovie }: LibraryPageProps) {
  const continueWatching = movies.filter((movie) => movie.progress !== undefined);

  return (
    <div className="library-page">
      <section className="library-hero">
        <div>
          <p className="eyebrow">私人电影书房</p>
          <h1>我的收藏</h1>
          <div className="hero-meta">
            <span>{movies.length} 部影片</span>
            <span>Direct Play 优先</span>
            <span>SRT 字幕</span>
          </div>
        </div>
        <div className="hero-stack" aria-hidden="true">
          {movies.slice(0, 3).map((movie) => (
            <div key={movie.id} className={`mini-poster poster-${movie.accent}`} />
          ))}
        </div>
      </section>

      <section className="content-band">
        <div className="section-heading">
          <h2>继续观看</h2>
          <span>{continueWatching.length}</span>
        </div>
        <div className="continue-row">
          {continueWatching.map((movie) => (
            <button key={movie.id} className="continue-item" onClick={() => onPlayMovie(movie)}>
              <span className={`continue-poster poster-${movie.accent}`} />
              <span>
                <strong>{movie.title}</strong>
                <small>{movie.progress}%</small>
              </span>
            </button>
          ))}
        </div>
      </section>

      <section className="content-band">
        <div className="section-heading">
          <h2>电影墙</h2>
          <div className="inline-filters">
            <button className="active">
              <Sparkles size={15} />
              全部
            </button>
            <button>
              <Heart size={15} />
              收藏
            </button>
          </div>
        </div>
        <div className="poster-grid">
          {movies.map((movie) => (
            <MovieCard key={movie.id} movie={movie} onOpen={onOpenMovie} onPlay={onPlayMovie} />
          ))}
        </div>
      </section>
    </div>
  );
}
