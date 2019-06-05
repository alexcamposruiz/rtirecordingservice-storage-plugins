/*
 * (c) 2019 Copyright, Real-Time Innovations, Inc.  All rights reserved.
 *
 * RTI grants Licensee a license to use, modify, compile, and create derivative
 * works of the Software.  Licensee has the right to distribute object form
 * only for use with RTI products.  The Software is provided "as is", with no
 * warranty of any type, including any warranty for fitness for any purpose.
 * RTI is under no obligation to maintain or support the Software.  RTI shall
 * not be liable for any incidental or consequential damages arising out of the
 * use or inability to use the software.
 */

#ifndef RTI_RECORDER_UTILS_LOGGER_HPP_
#define RTI_RECORDER_UTILS_LOGGER_HPP_

#include "rti/config/Logger.hpp"

namespace rti { namespace recorder { namespace utils {

std::ostream& operator<< (
        std::ostream& out,
        const rti::config::Verbosity& verbosity);

class Logger {
public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
    
    static Logger& instance();

    void verbosity(rti::config::Verbosity verbosity);

    rti::config::Verbosity verbosity() const;

private:
    Logger();    

    rti::config::Verbosity _verbosity;
};


#define RTI_RECORDER_UTILS_LOG_MESSAGE(VERBOSITY, STREAM_EXP) \
    if (Logger::instance().verbosity().underlying() >= (VERBOSITY)) { \
        std::cout << STREAM_EXP << std::endl; \
    }

} } }

#endif /* RTI_RECORDER_UTILS_LOGGER_HPP_ */

