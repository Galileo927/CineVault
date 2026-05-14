import { Film, Library, PlayCircle, Search } from "lucide-react";
import type { ReactNode } from "react";

import type { ViewMode } from "../types";

type AppShellProps = {
  children: ReactNode;
  viewMode: ViewMode;
  onViewModeChange: (mode: ViewMode) => void;
};

export function AppShell({ children, viewMode, onViewModeChange }: AppShellProps) {
  return (
    <div className="app-shell">
      <header className="topbar">
        <button className="brand" onClick={() => onViewModeChange("library")} aria-label="CineVault">
          <Film size={22} />
          <span>CineVault</span>
        </button>

        <div className="search-box">
          <Search size={17} />
          <input placeholder="搜索电影、导演、类型" />
        </div>

        <nav className="view-tabs" aria-label="视图">
          <button className={viewMode === "library" ? "active" : ""} onClick={() => onViewModeChange("library")}>
            <Library size={17} />
            <span>影库</span>
          </button>
          <button className={viewMode === "player" ? "active" : ""} onClick={() => onViewModeChange("player")}>
            <PlayCircle size={17} />
            <span>播放</span>
          </button>
        </nav>
      </header>
      <main>{children}</main>
    </div>
  );
}
