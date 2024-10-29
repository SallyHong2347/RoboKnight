#pragma once

#include "include/logger.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include <iostream>


void setupLogger() {
  try {
    // Create a console sink
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::info);

    // Create a file sink
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(
        "../../logs/roboknight.log", true);
    file_sink->set_level(spdlog::level::info);

    // Create a logger with both sinks
    std::vector<spdlog::sink_ptr> sinks{console_sink, file_sink};
    auto logger = std::make_shared<spdlog::logger>("multi_sink", sinks.begin(),
                                                   sinks.end());

    // Register the logger
    spdlog::register_logger(logger);
    spdlog::set_default_logger(logger);
    spdlog::set_level(spdlog::level::info); // Set global log level
  } catch (const spdlog::spdlog_ex &ex) {
    std::cerr << "Log initialization failed: " << ex.what() << std::endl;
  }
}