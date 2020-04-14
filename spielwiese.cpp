#include <boost/log/trivial.hpp>

#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;

int main(int argc, char **argv) {

    std::string l_LogFileName = "log.txt";
    std::string l_LogLevelString = "1";

    boost::log::trivial::severity_level l_LogLevel;
    std::istringstream{l_LogLevelString} >> l_LogLevel;

	logging::add_common_attributes();
	logging::register_simple_formatter_factory< boost::log::trivial::severity_level, char >("Severity");

	logging::add_console_log(std::cout, boost::log::keywords::format = "[%TimeStamp%] (%Severity%) (%LoggerName%) : %Message%");

	auto logfile = logging::add_file_log
      (
         keywords::file_name = l_LogFileName,
         keywords::rotation_size = 10 * 1024 * 1024,
         keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
         keywords::auto_flush = true,
         keywords::format = "[%TimeStamp%] (%Severity%) (%LoggerName%) : %Message%"
      );

	logfile->locked_backend()->auto_flush(true);

	logging::core::get()->set_filter(logging::trivial::severity >= l_LogLevel);

  return 0;
}
