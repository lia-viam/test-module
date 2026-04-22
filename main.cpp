
#include "bseye.hpp"

#include <coroutine>
#include <iostream>
#include <memory>
#include <vector>

#include <viam/sdk/common/exception.hpp>
#include <viam/sdk/common/instance.hpp>
#include <viam/sdk/log/logging.hpp>
#include <viam/sdk/registry/registry.hpp>

struct promise;

struct coroutine : std::coroutine_handle<promise>
{
    using promise_type = ::promise;
};

struct promise
{
    coroutine get_return_object() { return {coroutine::from_promise(*this)}; }
    std::suspend_always initial_suspend() noexcept { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    void return_void() {}
    void unhandled_exception() {}
};

struct S
{
    int i;
    coroutine f()
    {
        std::cout << i;
        co_return;
    }
};


void good()
{
    coroutine h = [](int i) -> coroutine // make i a coroutine parameter
    {
        std::cout << i;
        co_return;
    }(0);
    // lambda destroyed
    h.resume(); // no problem, i has been copied to the coroutine
                // frame as a by-value parameter
    h.destroy();
}


int main(int argc, char** argv) try {

    // Every Viam C++ SDK program must have one and only one Instance object which is created before
    // any other SDK objects and stays alive until all of them are destroyed.
    viam::sdk::Instance inst;

    // Write general log statements using the VIAM_SDK_LOG macro.
    VIAM_SDK_LOG(info) << "Starting up bullseye-test module";

    viam::sdk::Model model("38d7fa87-0f0f-44db-ab05-11f487e80997", "bullseye-test", "bseye");

	good();


    auto mr = std::make_shared<viam::sdk::ModelRegistration>(
        viam::sdk::API::get<viam::sdk::Sensor>(),
        model,
        [](viam::sdk::Dependencies deps, viam::sdk::ResourceConfig cfg) {
            return std::make_unique<bullseye_test::Bseye>(deps, cfg);
        },
        &bullseye_test::Bseye::validate);



    std::vector<std::shared_ptr<viam::sdk::ModelRegistration>> mrs = {mr};
    auto my_mod = std::make_shared<viam::sdk::ModuleService>(argc, argv, mrs);
    my_mod->serve();

    return EXIT_SUCCESS;
} catch (const viam::sdk::Exception& ex) {
    std::cerr << "main failed with exception: " << ex.what() << "\n";
    return EXIT_FAILURE;
}
