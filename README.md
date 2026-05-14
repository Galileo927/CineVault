# CineVault

> 面向电影收藏爱好者的私人影视库与高品质播放系统  
> A private movie library and premium playback system for film collectors.

CineVault 是一款专注于 **私人电影收藏体验** 与 **稳定播放体验** 的 C++ 音视频工程项目。

它不是普通的视频文件管理器，也不是视频剪辑软件，而是希望将用户散落在本地硬盘、NAS、家庭服务器或个人云主机中的电影资源，整理成一个具有 **收藏感、仪式感和高级审美** 的私人电影书房。

CineVault 的目标不是简单地“播放一个视频文件”，而是让用户每次打开应用时，都能像走进自己的书房、打开 Steam 游戏库、翻看 PS5 光碟收藏一样，重新感受到个人电影收藏的价值。

---

## 项目愿景

很多用户拥有大量私人电影资源，但这些资源通常以冰冷的文件形式散落在硬盘、NAS 或服务器目录中：

```text
movie_2021_2160p_bluray_x265_final.mkv
film.collection.directors.cut.1080p.mp4
```

CineVault 希望把这些文件变成真正属于用户的电影收藏：

```text
沙丘 Dune
2021 · 4K HDR · 155 min · 科幻 / 冒险
继续观看 · 已收藏 · 字幕可用
```

项目的核心愿景是：

> 让用户拥有一个稳定、漂亮、有收藏感的私人电影书房。

---

## 核心定位

CineVault 面向 C 端电影收藏用户，而不是面向企业后台或专业剪辑工作流。

它关注三件事：

1. **收藏感**  
   用户打开应用时，看到的不是文件列表，而是自己的电影收藏、私人影厅和审美空间。

2. **界面审美**  
   用户愿意付费，首先是认可服务，其次是被审美打动。UI 不能像后台管理系统，必须有电影感、空间感和高级感。

3. **稳定播放**  
   播放稳定性是底线。卡顿、拖动失败、字幕错乱、播放中断都会直接破坏付费用户的信任感。

---

## 项目边界

CineVault 专注于“私人电影收藏”和“高品质播放”。

### 本项目不做

- 不做视频剪辑
- 不做多轨时间线
- 不做转场、滤镜、特效
- 不做短视频模板生成
- 不做影视资源下载
- 不做磁力搜索
- 不做盗版资源聚合
- 不把第一目标做成泛 AI 视频总结工具
- 不做传统后台管理系统风格的 UI

### 本项目重点做

- 本地 / NAS / 服务器影视目录扫描
- 电影媒体信息解析
- 高审美电影海报墙
- 电影详情页
- 在线播放
- HTTP Range 大文件流式播放
- 字幕匹配、加载与切换
- 播放进度记录
- 断点续播
- 最近观看
- 收藏 / 已看 / 未看
- 轻量化部署
- 后续扩展 HLS 转码、远程访问、多端同步

---

## 目标用户

CineVault 的目标用户不是所有人，而是以下几类用户：

- 有本地电影收藏的个人用户
- 使用 NAS / 家庭服务器 / Mac mini / Linux 服务器的用户
- 重视电影海报墙、收藏感和播放体验的用户
- 不想折腾复杂媒体服务器，但希望拥有私人影院体验的用户
- 对 UI 审美、字幕体验和播放稳定性敏感的付费用户

用户愿意付费的原因不是“这个软件能播放视频”，而是：

> 原来需要自己折腾目录、字幕、播放兼容、进度记录和海报整理；现在打开 CineVault，就像拥有了一个漂亮稳定的私人电影书房。

---

## 核心体验

### 首页：私人电影书房

首页不是文件列表，而是一个具有收藏感的电影空间。

应包含：

- 继续观看
- 最近加入
- 我的收藏
- 已看 / 未看
- 电影海报墙
- 类型筛选
- 搜索
- 电影系列 / 合集
- 4K / HDR / 蓝光收藏标识

设计参考气质：

- Steam 游戏库的收藏感
- PS5 光碟墙的陈列感
- Apple TV 的沉浸式海报视觉
- 私人书房 / 私人影厅的空间感

---

### 电影详情页：拿起一张光碟

电影详情页应该让用户感觉自己正在查看一件收藏品。

应包含：

- 电影海报
- 背景图 / 氛围图
- 中文名 / 原名
- 年份
- 片长
- 类型
- 简介
- 分辨率
- 视频编码
- 音频编码
- 字幕状态
- 播放按钮
- 继续观看位置
- 收藏 / 已看状态

---

### 播放页：稳定、克制、不打扰

播放页的第一目标是稳定播放，不是炫技。

应保证：

- 快速进入播放
- 拖动进度条可靠
- 退出自动保存进度
- 重新打开自动断点续播
- 字幕切换清晰
- 音轨信息明确
- 播放失败时给出可理解原因
- 控件需要时出现，不需要时消失
- 不用弹窗破坏观影沉浸感

---

## 核心功能规划

### Phase 1：MVP，可演示版本

目标：跑通“目录扫描 → 海报墙 → 详情页 → 播放 → 断点续播”的核心链路。

- [ ] 指定影视目录
- [ ] 扫描本地 / 服务器电影文件
- [ ] 识别常见视频文件格式
- [ ] 使用 FFprobe 解析媒体信息
- [ ] 生成电影库列表
- [ ] 前端展示电影海报墙
- [ ] 电影详情页
- [ ] 浏览器在线播放
- [ ] HTTP Range 大文件播放
- [ ] 播放进度保存
- [ ] 断点续播
- [ ] 同目录字幕自动匹配
- [ ] 支持 SRT 字幕
- [ ] 基础本地启动脚本

---

### Phase 2：产品可用版本

目标：让普通用户愿意长期使用。

- [ ] 更完整的电影库扫描
- [ ] 增量扫描
- [ ] 文件变更检测
- [ ] 电影搜索
- [ ] 最近观看
- [ ] 收藏列表
- [ ] 已看 / 未看
- [ ] 电影详情元数据编辑
- [ ] 海报手动修正
- [ ] ASS 字幕支持
- [ ] 字幕切换
- [ ] 字幕延迟调整
- [ ] 多音轨信息展示
- [ ] 播放失败原因提示
- [ ] 系统日志页面
- [ ] 初始化配置页面

---

### Phase 3：小商业级版本

目标：达到可以让早期用户付费试用的程度。

- [ ] 一键部署体验优化
- [ ] 多用户账号
- [ ] 用户级播放历史
- [ ] 用户级收藏
- [ ] 远程访问部署指南
- [ ] HTTPS / 反向代理配置文档
- [ ] 不兼容格式识别
- [ ] HLS 转码播放
- [ ] 转码任务状态展示
- [ ] 转码缓存
- [ ] 海报墙性能优化
- [ ] 图片懒加载
- [ ] 移动端适配
- [ ] 备份与恢复
- [ ] 完整用户文档

---

## 技术栈

### 后端

- C++
- Drogon
- CMake
- SQLite，MVP 阶段优先
- PostgreSQL / MySQL，后续扩展
- RESTful API
- 多线程 / 异步任务
- 文件系统扫描
- 播放进度管理

### 音视频

- FFmpeg
- FFprobe
- HTTP Range
- HLS，后续扩展
- SRT / ASS 字幕
- Direct Play 优先
- 必要时 Remux / Transcode

### 前端

- React / Vue
- TypeScript
- 深色电影感 UI
- 海报墙
- 电影详情页
- 播放页
- 字幕与音轨控制
- 继续观看入口

### 部署

- Linux
- macOS
- 本机服务启动
- 后续可选反向代理部署
- Nginx，后续扩展
- NAS / 家庭服务器 / 云服务器部署

---

## 系统架构

```text
┌──────────────────────────────────┐
│            Web Frontend           │
│  私人影库 / 海报墙 / 播放页 / 搜索 │
└─────────────────┬────────────────┘
                  │ REST API
                  ▼
┌──────────────────────────────────┐
│        C++ Drogon Server          │
│ API / 用户 / 电影库 / 播放 / 进度  │
└─────────────────┬────────────────┘
                  │
                  ▼
┌──────────────────────────────────┐
│          Media Library            │
│  目录扫描 / 文件索引 / 增量更新    │
└─────────────────┬────────────────┘
                  │
                  ▼
┌──────────────────────────────────┐
│        FFmpeg / FFprobe Core      │
│ 元数据解析 / 字幕识别 / HLS 转码   │
└─────────────────┬────────────────┘
                  │
                  ▼
┌──────────────────────────────────┐
│       Playback Service            │
│ HTTP Range / Direct Play / HLS     │
└─────────────────┬────────────────┘
                  │
                  ▼
┌──────────────────────────────────┐
│       Database / FileSystem       │
│ 电影信息 / 字幕 / 海报 / 播放进度   │
└──────────────────────────────────┘
```

---

## 推荐项目目录结构

```text
CineVault/
├── README.md
├── CODEX.md
├── CMakeLists.txt
├── config/
│   ├── config.example.json
│   └── nginx.example.conf
│
├── server/
│   ├── main.cpp
│   ├── controllers/
│   │   ├── LibraryController.cpp
│   │   ├── MovieController.cpp
│   │   ├── PlaybackController.cpp
│   │   └── SubtitleController.cpp
│   ├── services/
│   │   ├── LibraryService.cpp
│   │   ├── MovieService.cpp
│   │   ├── PlaybackService.cpp
│   │   ├── ProgressService.cpp
│   │   └── SubtitleService.cpp
│   └── models/
│       ├── MovieInfo.h
│       ├── MediaStreamInfo.h
│       ├── PlaybackProgress.h
│       └── SubtitleInfo.h
│
├── media_core/
│   ├── MediaProbe.cpp
│   ├── MediaProbe.h
│   ├── FFmpegRunner.cpp
│   ├── FFmpegRunner.h
│   ├── CompatibilityChecker.cpp
│   ├── CompatibilityChecker.h
│   ├── HlsGenerator.cpp
│   └── HlsGenerator.h
│
├── library/
│   ├── FileScanner.cpp
│   ├── FileScanner.h
│   ├── LibraryIndexer.cpp
│   ├── LibraryIndexer.h
│   ├── MovieMatcher.cpp
│   └── MetadataManager.cpp
│
├── playback/
│   ├── RangeRequestHandler.cpp
│   ├── StreamService.cpp
│   ├── DirectPlayService.cpp
│   └── ProgressTracker.cpp
│
├── subtitle/
│   ├── SubtitleMatcher.cpp
│   ├── SubtitleParser.cpp
│   ├── SubtitleConverter.cpp
│   └── EncodingDetector.cpp
│
├── database/
│   ├── DBManager.cpp
│   ├── MovieRepository.cpp
│   ├── ProgressRepository.cpp
│   └── SubtitleRepository.cpp
│
├── web/
│   ├── package.json
│   ├── src/
│   │   ├── pages/
│   │   ├── components/
│   │   ├── services/
│   │   └── styles/
│   └── public/
│
├── scripts/
│   ├── init_db.sql
│   ├── run_server.sh
│   └── scan_library.sh
│
└── docs/
    ├── architecture.md
    ├── api.md
    ├── playback.md
    ├── ui-principles.md
    └── roadmap.md
```

---

## 播放策略

CineVault 的播放策略必须以稳定性为核心。

### 优先级

```text
Direct Play
    ↓
Direct Stream / Remux
    ↓
HLS Transcode
    ↓
清晰错误提示
```

### 第一阶段

优先保证常见格式稳定播放：

- MP4
- H.264
- AAC
- SRT 外挂字幕
- HTTP Range 请求
- 断点续播

### 第二阶段

增强兼容性：

- MKV 识别
- HEVC / H.265 识别
- AC3 / EAC3 / DTS 识别
- ASS 字幕
- 内嵌字幕轨识别
- 浏览器兼容性判断

### 第三阶段

扩展转码：

- HLS 切片
- 转码任务队列
- 转码缓存
- 多清晰度
- 硬件加速转码

---

## 商业级质量标准

CineVault 判断是否达到“小商业级”，不看功能数量，而看用户体验是否稳定可信。

### 基础标准

- [ ] 用户 30 分钟内可以完成部署
- [ ] 指定电影目录后可以自动生成影视库
- [ ] 首页不是文件列表，而是有收藏感的电影墙
- [ ] 点击播放后能稳定观看完整电影
- [ ] 拖动进度条不会卡死
- [ ] 退出后能保存播放进度
- [ ] 重新打开可以断点续播
- [ ] 字幕不会乱码或错乱
- [ ] 播放失败时有明确原因
- [ ] 页面滚动和海报加载不卡顿
- [ ] 日志能帮助定位问题
- [ ] 用户不会感觉自己在用半成品

### 核心底线

> 播放稳定性 > 界面动效 > 功能数量。

如果一个功能会破坏播放稳定性，宁可不上线。

---

## 简历描述

**CineVault 私人影视库与高品质播放系统**

基于 C++、Drogon 和 FFmpeg 独立设计并实现私人影视库与高品质播放系统，面向电影收藏场景，支持本地影视目录扫描、媒体元数据解析、电影海报墙、在线播放、字幕管理、播放进度记录与断点续播。系统围绕稳定播放体验设计，支持 HTTP Range 大文件流式播放，并通过媒体兼容性判断、播放状态管理和本地缓存机制提升长视频播放的流畅性与可靠性。

项目亮点：

- 基于 Drogon 实现 C++ 后端服务，提供影视库扫描、影片查询、播放地址获取、字幕管理和播放进度同步等 RESTful API。
- 基于 FFprobe 解析影片封装格式、视频编码、音频编码、分辨率、帧率、码率和音轨信息，完成媒体文件结构化入库。
- 实现本地影视目录扫描与增量更新机制，支持自动识别新增、删除和变更的媒体文件。
- 实现 HTTP Range 大文件流式播放，避免大体积电影文件一次性加载，提高拖动进度条和长视频播放稳定性。
- 设计播放进度记录与断点续播模块，实现用户级播放状态同步。
- 支持 SRT / ASS 字幕文件匹配、加载与切换，提升外语电影播放体验。
- 设计转码任务模块，支持后续将不兼容视频格式转换为 HLS 流，实现浏览器端稳定播放。
- 提供本地启动脚本和配置样例，支持在 macOS、Linux、NAS 或个人家庭服务器环境中运行。


---

## License

MIT License
