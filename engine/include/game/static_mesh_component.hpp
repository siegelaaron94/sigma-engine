#ifndef SIGMAFIVE_GAME_STATIC_MESH_COMPONENT_HPP
#define SIGMAFIVE_GAME_STATIC_MESH_COMPONENT_HPP

#include <game/component.hpp>
#include <graphics/static_mesh.hpp>

namespace sigmafive {
	namespace game {
		class static_mesh_component : public game::component {
            SIGMAFIVE_OBJECT()
		public:
            typedef component_pool<static_mesh_component> pool_type;
			boost::uuids::uuid static_mesh;

			friend class boost::serialization::access;
			template <typename Archive>
			void serialize(Archive& ar, const unsigned int version) {
				ar & SIGMAFIVE_SERIALIZE_BASE(component);
                //TODO implement
			}
		};
	}
}

#endif //SIGMAFIVE_GAME_STATIC_MESH_COMPONENT_HPP