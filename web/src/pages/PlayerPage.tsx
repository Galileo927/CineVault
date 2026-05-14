import { ArrowLeft, Maximize2, Pause, Settings, Subtitles, Volume2 } from "lucide-react";

import type { Movie } from "../types";

type PlayerPageProps = {
  movie: Movie;
  onBack: () => void;
};

export function PlayerPage({ movie, onBack }: PlayerPageProps) {
  return (
    <div className="player-page">
      <button className="text-button" onClick={onBack}>
        <ArrowLeft size={17} />
        返回
      </button>

      <section className="player-stage">
        <div className={`screen poster-${movie.accent}`}>
          <div className="screen-title">
            <span>{movie.title}</span>
            <small>{movie.originalTitle}</small>
          </div>
        </div>
        <div className="player-controls">
          <button className="icon-button primary" aria-label="暂停">
            <Pause size={18} />
          </button>
          <div className="seek-track">
            <span style={{ width: `${movie.progress ?? 0}%` }} />
          </div>
          <span className="timecode">{movie.progress ?? 0}%</span>
          <button className="icon-button" aria-label="字幕">
            <Subtitles size={18} />
          </button>
          <button className="icon-button" aria-label="音量">
            <Volume2 size={18} />
          </button>
          <button className="icon-button" aria-label="设置">
            <Settings size={18} />
          </button>
          <button className="icon-button" aria-label="全屏">
            <Maximize2 size={18} />
          </button>
        </div>
      </section>
    </div>
  );
}
