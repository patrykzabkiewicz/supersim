/*
 * Licensed under the Apache License, Version 2.0 (the 'License');
 * you may not use this file except in compliance with the License.
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "interface/Interface.h"

#include <factory/Factory.h>

#include <cassert>

Interface::Interface(
    const std::string& _name, const Component* _parent, u32 _id,
    const std::vector<u32>& _address, u32 _numVcs,
    const std::vector<std::tuple<u32, u32> >& _trafficClassVcs,
    Json::Value _settings)
    : Component(_name, _parent), PortedDevice(_id, _address, 1, _numVcs),
      trafficClassVcs_(_trafficClassVcs), messageReceiver_(nullptr) {}

Interface::~Interface() {}

Interface* Interface::create(
    const std::string& _name, const Component* _parent, u32 _id,
    const std::vector<u32>& _address, u32 _numVcs,
    const std::vector<std::tuple<u32, u32> >& _trafficClassVcs,
    Json::Value _settings) {
  // retrieve the type
  const std::string& type = _settings["type"].asString();

  // attempt to build the interface
  Interface* interface = factory::Factory<Interface, INTERFACE_ARGS>::create(
      type, _name, _parent, _id, _address, _numVcs, _trafficClassVcs,
      _settings);

  // check that the factory had this type
  if (interface == nullptr) {
    fprintf(stderr, "unknown interface type: %s\n", type.c_str());
    assert(false);
  }
  return interface;
}

void Interface::setMessageReceiver(MessageReceiver* _receiver) {
  assert(messageReceiver_ == nullptr);
  messageReceiver_ = _receiver;
}

MessageReceiver* Interface::messageReceiver() const {
  return messageReceiver_;
}
