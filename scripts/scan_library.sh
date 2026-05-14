#!/usr/bin/env bash
set -euo pipefail

library_id="${1:-1}"
api_base="${CINEVAULT_API_BASE:-http://localhost:8080}"

curl -X POST "${api_base}/api/libraries/${library_id}/scan"
