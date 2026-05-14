export type Movie = {
  id: string;
  title: string;
  originalTitle?: string;
  year?: number;
  runtime?: string;
  genres: string[];
  quality: string[];
  progress?: number;
  subtitleStatus: "available" | "missing" | "embedded";
  overview: string;
  accent: "amber" | "red" | "green" | "violet" | "steel";
};

export type ViewMode = "library" | "detail" | "player";
