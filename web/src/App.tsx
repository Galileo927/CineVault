import { useMemo, useState } from "react";

import { AppShell } from "./components/AppShell";
import { LibraryPage } from "./pages/LibraryPage";
import { MovieDetailPage } from "./pages/MovieDetailPage";
import { PlayerPage } from "./pages/PlayerPage";
import { demoMovies } from "./services/api";
import type { Movie, ViewMode } from "./types";

export function App() {
  const [viewMode, setViewMode] = useState<ViewMode>("library");
  const [selectedMovieId, setSelectedMovieId] = useState(demoMovies[0].id);

  const selectedMovie = useMemo<Movie>(() => {
    return demoMovies.find((movie) => movie.id === selectedMovieId) ?? demoMovies[0];
  }, [selectedMovieId]);

  const openMovie = (movie: Movie) => {
    setSelectedMovieId(movie.id);
    setViewMode("detail");
  };

  return (
    <AppShell viewMode={viewMode} onViewModeChange={setViewMode}>
      {viewMode === "library" && (
        <LibraryPage movies={demoMovies} onOpenMovie={openMovie} onPlayMovie={(movie) => {
          setSelectedMovieId(movie.id);
          setViewMode("player");
        }} />
      )}
      {viewMode === "detail" && (
        <MovieDetailPage
          movie={selectedMovie}
          onBack={() => setViewMode("library")}
          onPlay={() => setViewMode("player")}
        />
      )}
      {viewMode === "player" && (
        <PlayerPage movie={selectedMovie} onBack={() => setViewMode("detail")} />
      )}
    </AppShell>
  );
}
