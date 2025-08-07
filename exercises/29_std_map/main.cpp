#include "../exercise.h"
#include <map>

// READ: `std::map` <https://zh.cppreference.com/w/cpp/container/map>
// READ: `std::unordered_map` <https://zh.cppreference.com/w/cpp/container/unordered_map>

template<class k, class v>
bool key_exists(std::map<k, v> const &map, k const &key) {
    // TODO: 实现函数
    // 提示：可以使用 `map.find(key)` 或 `map.count(key)` 来检查键是否存在
    return map.find(key) != map.end();
    // 或者
    // return map.count(key) > 0;
    // 或者
    // return map.contains(key); // C++20 引入的 contains 方法
    // 注意：如果使用 C++20，请确保编译器支持该特性。   
}

template<class k, class v>
void set(std::map<k, v> &map, k key, v value) {
    // TODO: 实现函数
    // 提示：可以直接使用 `map[key] = value;` 来设置键值对
    map[key] = value;
    // 或者
    // map.insert_or_assign(key, value); // C++17 引入的 insert_or_assign 方法
    // 注意：如果使用 C++17，请确保编译器支持该特性。
}

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    using namespace std::string_literals;

    std::map<std::string, std::string> secrets;

    set(secrets, "hello"s, "world"s);
    ASSERT(key_exists(secrets, "hello"s), "\"hello\" shoud be in `secrets`");
    ASSERT(!key_exists(secrets, "foo"s), "\"foo\" shoud not be in `secrets`");

    set(secrets, "foo"s, "bar"s);
    set(secrets, "Infini"s, "Tensor"s);
    ASSERT(secrets["hello"] == "world", "hello -> world");
    ASSERT(secrets["foo"] == "bar", "foo -> bar");
    ASSERT(secrets["Infini"] == "Tensor", "Infini -> Tensor");

    set(secrets, "hello"s, "developer"s);
    ASSERT(secrets["hello"] == "developer", "hello -> developer");

    return 0;
}
