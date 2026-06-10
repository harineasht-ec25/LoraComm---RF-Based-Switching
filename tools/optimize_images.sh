#!/usr/bin/env bash
set -euo pipefail

# tools/optimize_images.sh
# Usage:
# 1. Install dependencies: imagemagick (convert), cwebp (from webp package), ffmpeg (optional for video)
#    macOS: brew install imagemagick webp ffmpeg
#    Ubuntu: sudo apt-get install imagemagick webp ffmpeg
# 2. Put your source images in a directory, e.g. tools/input/image1.jpg ... image4.jpg
# 3. Run: ./tools/optimize_images.sh ./tools/input
# This script will generate webp images in docs/assets/images/

INPUT_DIR=${1:-./tools/input}
OUT_DIR=./docs/assets/images
mkdir -p "$OUT_DIR"

echo "Optimizing images from $INPUT_DIR -> $OUT_DIR"

shopt -s nullglob
for src in "$INPUT_DIR"/*.{jpg,jpeg,png,JPG,JPEG,PNG}; do
  [ -e "$src" ] || continue
  base=$(basename "$src")
  name="${base%.*}"
  tmp="/tmp/${name}_tmp.jpg"
  echo "Processing $src -> $name.webp"
  # resize to max width 1600px, strip metadata, moderate quality
  convert "$src" -strip -resize 1600x -interlace Plane -quality 85 "$tmp"
  cwebp -q 80 "$tmp" -o "$OUT_DIR/${name}.webp" >/dev/null
  rm -f "$tmp"
done

echo "Done. Optimized files are in $OUT_DIR"

# Video placeholder: to optimize a video, uncomment and run the ffmpeg command below
# ffmpeg -i input.mov -c:v libx264 -crf 23 -preset medium -c:a aac -b:a 128k -movflags +faststart docs/assets/video/working_demo.mp4
