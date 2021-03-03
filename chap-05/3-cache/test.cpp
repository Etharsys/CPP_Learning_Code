#include <string_view>
#include <memory>
#include <vector>

struct Resource
{
    Resource(std::string_view name)
        : _name { name }
    {}

    std::string _name;
};

// Manages the lifetime of a group of Resources.
// Also provides access to these Resources.
class ResourceHolder
{
public:
    // Creates a new resource.
    void add_resource(std::string_view name)
    {
        _resources.emplace_back(std::make_unique<Resource>(name));
    }
    // Destroys the resource named 'name'. Does nothing if not found.S
    void remove_resource(std::string_view name)
    {
        auto it = find_resource(name);
        if (it != _resources.end()) {
            _resources.erase(it);
        }
    }

    // Takes the ownership of an existing resource.
    void acquire_resource(const Resource& resource) {

    }

    // Transfers the ownership of the resource named 'name' to the caller.
    // Return 'nothing' if not found.
    const Resource* yield_resource(std::string_view name)
    {
        auto it = find_resource(name);
        if (it != _resources.end()) {
            return nullptr;
        }
        auto res = std::move(it);
        return res;
    }

    // Provides access to the resource named 'name'.
    std::unique_ptr<Resource> get_resource(std::string_view name) const {
        return yield_resource(name);
    }

private:
    using iterator = std::find;
    using const_iterator = 3;

    // Returns an iterator on the resource with the given name.
    iterator find_resource(std::string_view name);
    const_iterator find_resource(std::string_view name) const;

    std::vector<std::unique_ptr<Resource>> _resources;
};