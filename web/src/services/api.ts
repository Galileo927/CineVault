import type { Movie } from "../types";

const API_BASE_URL = import.meta.env.VITE_API_BASE_URL ?? "";

export async function fetchMovies(): Promise<Movie[]> {
  const response = await fetch(`${API_BASE_URL}/api/movies`);
  if (!response.ok) {
    throw new Error(`Movie list request failed with ${response.status}`);
  }

  const data = await response.json();
  return data.movies ?? [];
}

export const demoMovies: Movie[] = [
  {
    id: "1",
    title: "沙丘",
    originalTitle: "Dune",
    year: 2021,
    runtime: "155 min",
    genres: ["科幻", "冒险"],
    quality: ["4K", "HDR", "AAC"],
    progress: 64,
    subtitleStatus: "available",
    overview: "保罗踏上厄拉科斯，在沙与香料之间面对家族命运。",
    accent: "amber"
  },
  {
    id: "2",
    title: "银翼收藏",
    originalTitle: "Blade Archive",
    year: 1982,
    runtime: "117 min",
    genres: ["科幻", "黑色电影"],
    quality: ["1080p", "H.264"],
    subtitleStatus: "embedded",
    overview: "雨夜、霓虹和复制人的记忆被收藏进私人影库。",
    accent: "red"
  },
  {
    id: "3",
    title: "海边放映",
    originalTitle: "Coastal Screening",
    year: 2019,
    runtime: "101 min",
    genres: ["剧情"],
    quality: ["Blu-ray", "SRT"],
    progress: 18,
    subtitleStatus: "available",
    overview: "一次迟到的重逢，让旧胶片重新亮起。",
    accent: "green"
  },
  {
    id: "4",
    title: "午夜影院",
    originalTitle: "Midnight Hall",
    year: 1976,
    runtime: "132 min",
    genres: ["悬疑", "惊悚"],
    quality: ["HD", "AAC"],
    subtitleStatus: "missing",
    overview: "老影院最后一场放映，观众名单里出现了不存在的人。",
    accent: "violet"
  }
];
