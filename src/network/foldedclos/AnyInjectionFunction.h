/*
 * Copyright 2016 Hewlett Packard Enterprise Development LP
 *
 * Licensed under the Apache License, Version 2.0 (the 'License');
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef NETWORK_FOLDEDCLOS_ANYINJECTIONFUNCTION_H_
#define NETWORK_FOLDEDCLOS_ANYINJECTIONFUNCTION_H_

#include <prim/prim.h>

#include <string>
#include <vector>

#include "event/Component.h"
#include "network/InjectionFunction.h"
#include "interface/Interface.h"

namespace FoldedClos {

class AnyInjectionFunction : public InjectionFunction {
 public:
  AnyInjectionFunction(const std::string& _name, const Component* _parent,
                       Interface* _interface, u64 _latency);
  ~AnyInjectionFunction();

 protected:
  void processRequest(
      Message* _message, InjectionFunction::Response* _response) override;
};

}  // namespace FoldedClos

#endif  // NETWORK_FOLDEDCLOS_ANYINJECTIONFUNCTION_H_