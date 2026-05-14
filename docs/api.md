# API

All errors should use a structured response:

```json
{
  "error": {
    "code": "NOT_IMPLEMENTED",
    "message": "This endpoint is scaffolded but not implemented yet.",
    "details": {}
  }
}
```

## Libraries

- `POST /api/libraries`
- `GET /api/libraries`
- `POST /api/libraries/{id}/scan`
- `GET /api/libraries/{id}/scan-status`

## Movies

- `GET /api/movies`
- `GET /api/movies/{id}`
- `PATCH /api/movies/{id}`
- `POST /api/movies/{id}/favorite`
- `DELETE /api/movies/{id}/favorite`

## Playback

- `GET /api/movies/{id}/stream`
- `GET /api/movies/{id}/playback`
- `PUT /api/movies/{id}/playback`

## Subtitles

- `GET /api/movies/{id}/subtitles`
- `GET /api/subtitles/{id}/content`
