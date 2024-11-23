/*
 * This content is released under the MIT License as specified in
 * https://raw.githubusercontent.com/gabime/spdlog/master/LICENSE
 */
#include "includes.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/sinks/stdout_color_sinks.h"

TEST_CASE("stdout_st", "[stdout]") {
    auto sink = std::make_shared<spdlog::sinks::stdout_sink_st>();
    auto l = std::make_unique<spdlog::logger>("test", std::move(sink));
    l->set_pattern("%+");
    l->set_level(spdlog::level::trace);
    l->trace("Test stdout_st");
}

TEST_CASE("stdout_mt", "[stdout]") {
    auto sink = std::make_shared<spdlog::sinks::stdout_sink_mt>();
    auto l = std::make_unique<spdlog::logger>("test", std::move(sink));
    l->set_pattern("%+");
    l->set_level(spdlog::level::debug);
    l->debug("Test stdout_mt");
}

TEST_CASE("stderr_st", "[stderr]") {
    auto sink = std::make_shared<spdlog::sinks::stderr_sink_st>();
    auto l = std::make_unique<spdlog::logger>("test", std::move(sink));
    l->set_pattern("%+");
    l->info("Test stderr_st");
}

TEST_CASE("stderr_mt", "[stderr]") {
    auto sink = std::make_shared<spdlog::sinks::stderr_sink_mt>();
    auto l = std::make_unique<spdlog::logger>("test", std::move(sink));
    l->set_pattern("%+");
    l->info("Test stderr_mt");
    l->warn("Test stderr_mt");
    l->error("Test stderr_mt");
    l->critical("Test stderr_mt");
}

// color loggers
TEST_CASE("stdout_color_st", "[stdout]") {
    auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_st>();
    auto l = std::make_unique<spdlog::logger>("test", std::move(sink));
    l->set_pattern("%+");
    l->info("Test stdout_color_st");
}

TEST_CASE("stdout_color_mt", "[stdout]") {
    auto sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto l = std::make_unique<spdlog::logger>("test", std::move(sink));
    l->set_pattern("%+");
    l->set_level(spdlog::level::trace);
    l->trace("Test stdout_color_mt");
}

TEST_CASE("stderr_color_st", "[stderr]") {
    auto sink = std::make_shared<spdlog::sinks::stderr_color_sink_st>();
    auto l = std::make_unique<spdlog::logger>("test", std::move(sink));
    l->set_pattern("%+");
    l->set_level(spdlog::level::debug);
    l->debug("Test stderr_color_st");
}

TEST_CASE("stderr_color_mt", "[stderr]") {
    auto sink = std::make_shared<spdlog::sinks::stderr_color_sink_mt>();
    auto l = std::make_unique<spdlog::logger>("test", std::move(sink));
    l->set_pattern("%+");
    l->info("Test stderr_color_mt");
    l->warn("Test stderr_color_mt");
    l->error("Test stderr_color_mt");
    l->critical("Test stderr_color_mt");
}

#ifdef SPDLOG_WCHAR_TO_UTF8_SUPPORT

TEST_CASE("wchar_api", "[stdout]") {
    auto l = spdlog::stdout_logger_st("wchar_logger");
    l->set_pattern("%+");
    l->set_level(spdlog::level::trace);
    l->trace(L"Test wchar_api");
    l->trace(L"Test wchar_api {}", L"param");
    l->trace(L"Test wchar_api {}", 1);
    l->trace(L"Test wchar_api {}", std::wstring{L"wstring param"});
    l->trace(std::wstring{L"Test wchar_api wstring"});
    SPDLOG_LOGGER_DEBUG(l, L"Test SPDLOG_LOGGER_DEBUG {}", L"param");
    spdlog::drop_all();
}

#endif
