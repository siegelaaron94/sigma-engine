#include <sigmafive/entity/entity.hpp>

namespace sigmafive {
    namespace entity {
        entity::entity() noexcept
                : entity(std::uint32_t(-1), std::uint32_t(-1)) {
        }

        entity::entity(std::uint32_t index, std::uint32_t version) noexcept
                : index(index), version(version) {
        }

        bool entity::is_valid() const noexcept {
            return index != std::uint32_t(-1) && version != std::uint32_t(-1); // TODO should this be and or?
        }

        bool entity::operator==(entity e) const noexcept {
            return index == e.index && version == e.version;
        }

        bool entity::operator!=(entity e) const noexcept {
            return !(*this == e);
        }
    }
}