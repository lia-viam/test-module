#pragma once


#include <viam/sdk/common/proto_value.hpp>
#include <viam/sdk/components/sensor.hpp>
#include <viam/sdk/config/resource.hpp>
#include <viam/sdk/module/service.hpp>

namespace bullseye_test {


class Bseye : public viam::sdk::Sensor {
public:
    Bseye(const viam::sdk::Dependencies& deps, const viam::sdk::ResourceConfig& cfg);

    static std::vector<std::string> validate(const viam::sdk::ResourceConfig& cfg);

    viam::sdk::ProtoStruct do_command(const viam::sdk::ProtoStruct & command) override;

    viam::sdk::ProtoStruct get_status() override;

    std::vector<viam::sdk::GeometryConfig> get_geometries(const viam::sdk::ProtoStruct & extra) override;

    viam::sdk::ProtoStruct get_readings(const viam::sdk::ProtoStruct & extra) override;

};

} // namespace bullseye-test

