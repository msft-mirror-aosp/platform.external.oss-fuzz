/* Copyright 2021 Google LLC
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
      http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "Poco/JSON/JSON.h"
#include "Poco/JSON/Parser.h"
#include "Poco/JSON/ParserImpl.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  std::string json(reinterpret_cast<const char *>(data), size);
  Poco::JSON::Parser parser;

  Poco::Dynamic::Var result;
  try {
    result = parser.parse(json);
  } catch (Poco::Exception &e) {
    return 0;
  } catch (const std::exception &e) {
    return 0;
  }
  return 0;
}
