#pragma once

#include <string>

#include <msgpack.hpp>

namespace gym_client
{
template <class T>
struct Request
{
    Request(const std::string &method, std::shared_ptr<T> param) : method(method), param(param) {}

    std::string method;
    std::shared_ptr<T> param;
    MSGPACK_DEFINE_MAP(method, param)
};

struct MakeParam
{
    std::string env_name;
    std::string env_type;
    int num_envs;
    MSGPACK_DEFINE_MAP(env_name, env_type, num_envs);
};

struct ResetParam
{
    int x;
    MSGPACK_DEFINE_MAP(x);
};

struct StepParam
{
    std::vector<std::vector<int>> actions;
    bool render;
    MSGPACK_DEFINE_MAP(actions, render);
};

struct MakeResponse
{
    std::string result;
    MSGPACK_DEFINE_MAP(result);
};

struct ResetResponse
{
    std::vector<std::vector<float>> observation;
    MSGPACK_DEFINE_MAP(observation);
};

struct StepResponse
{
    std::vector<std::vector<float>> observation;
    std::vector<std::vector<float>> reward;
    std::vector<std::vector<bool>> done;
    MSGPACK_DEFINE_MAP(observation, reward, done);
};
}