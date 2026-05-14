# Architecture

CineVault is organized around one MVP path: scan owned media, index it, present it as a movie library, stream it reliably, and save playback progress.

## Runtime Layers

- `web/`: React user interface for the library, movie details, and player.
- `server/`: Drogon HTTP API, request validation, and response shaping.
- `library/`: filesystem scanning and library indexing.
- `media_core/`: FFprobe/FFmpeg process integration and compatibility checks.
- `playback/`: direct play, HTTP Range parsing, stream responses, and progress tracking.
- `subtitle/`: same-directory subtitle matching and later subtitle parsing/conversion.
- `database/`: SQLite connection and repository boundaries.

## MVP Rule

Controllers should stay thin. Business behavior belongs in services, persistence belongs in repositories, and media process details stay inside `media_core/`.

## Local Development

The project is scoped for local development first. Keep generated data under `data/`, sample media under `media/`, C++ build output under `build/`, and frontend dependencies under `web/node_modules/`.
