
#include "bseye.hpp"

#include <stdexcept>

namespace bullseye_test {


Bseye::Bseye(const viam::sdk::Dependencies& deps, const viam::sdk::ResourceConfig& cfg)
    : Sensor(cfg.name()) {
    throw std::runtime_error("constructor not implemented");
}


std::vector<std::string> Bseye::validate(const viam::sdk::ResourceConfig& cfg) {
    throw std::runtime_error("\"validate\" not implemented");
}

viam::sdk::ProtoStruct Bseye::do_command(const viam::sdk::ProtoStruct & command)
{
    throw std::logic_error("\"do_command\" not implemented");
}

viam::sdk::ProtoStruct Bseye::get_status()
{
    throw std::logic_error("\"get_status\" not implemented");
}

std::vector<viam::sdk::GeometryConfig> Bseye::get_geometries(const viam::sdk::ProtoStruct & extra)
{
    throw std::logic_error("\"get_geometries\" not implemented");
}

viam::sdk::ProtoStruct Bseye::get_readings(const viam::sdk::ProtoStruct & extra)
{
    throw std::logic_error("\"get_readings\" not implemented");
}

} // namespace bullseye-test

