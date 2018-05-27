/**
 * @file
 * @brief Header for the IOException class WS2COMMON_EXPORT
 */

#ifndef SMBLEVELWORKSHOP2_WS2COMMON_EXCEPTION_IOEXCEPTION_HPP
#define SMBLEVELWORKSHOP2_WS2COMMON_EXCEPTION_IOEXCEPTION_HPP

#include "ws2common_export.h"
#include "ws2common/exception/RuntimeException.hpp"

namespace WS2Common {
    namespace Exception {

        /**
         * @brief Exception class WS2COMMON_EXPORT for when issues arise when inputting or outputting
         *
         * Example use: When failing to read a file
         */
        class WS2COMMON_EXPORT IOException : public RuntimeException {
            public:
                IOException();
                IOException(QString message);

                IOException* clone() const override;
                void raise() const override;
        };
    }
}

#endif

