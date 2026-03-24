
#include "mysensor.hpp"

#include <stdexcept>

namespace sensors2 {


Mysensor::Mysensor(const viam::sdk::Dependencies& deps, const viam::sdk::ResourceConfig& cfg)
    : Sensor(cfg.name()) {
    this->reconfigure(deps, cfg);
}


std::vector<std::string> Mysensor::validate(const viam::sdk::ResourceConfig& cfg) {
    throw std::runtime_error("\"validate\" not implemented");
}

void Mysensor::reconfigure(const viam::sdk::Dependencies& deps, const viam::sdk::ResourceConfig& cfg) {
    throw std::runtime_error("\"reconfigure\" not implemented");
}

viam::sdk::ProtoStruct Mysensor::do_command(const viam::sdk::ProtoStruct & command)
{
    throw std::logic_error("\"do_command\" not implemented");
}

std::vector<viam::sdk::GeometryConfig> Mysensor::get_geometries(const viam::sdk::ProtoStruct & extra)
{
    throw std::logic_error("\"get_geometries\" not implemented");
}

viam::sdk::ProtoStruct Mysensor::get_readings(const viam::sdk::ProtoStruct & extra)
{
    throw std::logic_error("\"get_readings\" not implemented");
}

} // namespace sensors2

