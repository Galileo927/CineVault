# Playback

Playback stability is the first product constraint.

## Priority

1. Direct Play
2. Direct Stream or Remux
3. HLS Transcode
4. Clear error message

## MVP Requirements

- Correct `206 Partial Content` responses.
- Correct `416 Range Not Satisfiable` responses.
- `Accept-Ranges`, `Content-Range`, `Content-Length`, and MIME type set explicitly.
- No claim of universal format support.
- Stable MP4 / H.264 / AAC direct play before broader container support.
