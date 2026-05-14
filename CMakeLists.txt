cmake_minimum_required(VERSION 3.20)

project(CineVault VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Drogon CONFIG REQUIRED)

add_executable(cinevault_server
    server/main.cpp
    server/controllers/HealthController.cpp
    server/controllers/LibraryController.cpp
    server/controllers/MovieController.cpp
    server/controllers/PlaybackController.cpp
    server/controllers/SubtitleController.cpp
    server/services/LibraryService.cpp
    server/services/MovieService.cpp
    server/services/PlaybackService.cpp
    server/services/ProgressService.cpp
    server/services/SubtitleService.cpp
    media_core/MediaProbe.cpp
    media_core/FFmpegRunner.cpp
    media_core/CompatibilityChecker.cpp
    media_core/HlsGenerator.cpp
    library/FileScanner.cpp
    library/LibraryIndexer.cpp
    library/MovieMatcher.cpp
    library/MetadataManager.cpp
    playback/RangeRequestHandler.cpp
    playback/StreamService.cpp
    playback/DirectPlayService.cpp
    playback/ProgressTracker.cpp
    subtitle/SubtitleMatcher.cpp
    subtitle/SubtitleParser.cpp
    subtitle/SubtitleConverter.cpp
    subtitle/EncodingDetector.cpp
    database/DBManager.cpp
    database/MovieRepository.cpp
    database/ProgressRepository.cpp
    database/SubtitleRepository.cpp
)

target_include_directories(cinevault_server PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(cinevault_server PRIVATE
    Drogon::Drogon
)
