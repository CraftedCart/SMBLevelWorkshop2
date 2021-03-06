#include "ws2common/exception/ModelLoadingException.hpp"

namespace WS2Common {
    namespace Exception {
        ModelLoadingException::ModelLoadingException() {
            message = "No ModelLoadingException message given";
        }

        ModelLoadingException::ModelLoadingException(QString message) {
            this->message = message;
        }

        ModelLoadingException* ModelLoadingException::clone() const {
            return new ModelLoadingException(*this);
        }

        void ModelLoadingException::raise() const {
            throw *this;
        }
    }
}

