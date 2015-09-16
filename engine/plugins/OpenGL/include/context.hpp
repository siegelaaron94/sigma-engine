#ifndef SIGMAFIVE_GRAPHICS_OPENGL_CONTEXT_HPP
#define SIGMAFIVE_GRAPHICS_OPENGL_CONTEXT_HPP

#if defined(_WIN32)
#define OPENGL_PLUGIN_API __declspec(dllexport)
#else
#define OPENGL_PLUGIN_API
#endif

#include <sigmafive/graphics/context.hpp>

#include <shader.hpp>
#include <program.hpp>
#include <g_buffer.hpp>
#include <material.hpp>
#include <static_mesh.hpp>
#include <static_mesh_manager.hpp>

#include <sigmafive/factory.hpp>

#include <sigmafive/system/resource_manager.hpp>

#include <queue>

namespace sigmafive {
    namespace graphics {
        namespace opengl {
            struct static_mesh_instance {
                float4x4 model_matrix;
                boost::uuids::uuid static_mesh;
            };
            class context : public graphics::context {
            SIGMAFIVE_CLASS()
            public:
                context(system::resource_manager &resource_manager);

                virtual void make_current() override;

                virtual void resize(uint2 size) override;

                virtual void add_static_mesh(float4x4 model_matrix, boost::uuids::uuid static_mesh) override;

                virtual void render(float4x4 projection_matrix, float4x4 view_matrix) override;

                virtual void geometry_pass(float4x4 projection_matrix, float4x4 view_matrix);

                virtual void light_pass(float4x4 projection_matrix, float4x4 view_matrix);

                virtual void swap_buffers() override;

            private:
                uint2 size_;
                std::unique_ptr<g_buffer> g_buffer_;

                GLint drawFboId = 0;

                std::queue<static_mesh_instance> static_meshes_;

                opengl::material material_;
                opengl::shader vertex_shader;
                opengl::shader fragment_shader;

                opengl::vertex_array plane_vertex_array;
                opengl::index_buffer plane_index_buffer;
                opengl::vertex_buffer<graphics::static_mesh::vertex> plane_vertex_buffer;

                opengl::shader plane_vertex_shader;
                opengl::shader plane_fragment_shader;
                opengl::program plane_program;

                system::resource_manager &resource_manager_;
                opengl::static_mesh_manager static_mesh_manager_;

            };

            class context_factory : public factory<graphics::context> {
            public:
                context_factory(system::resource_manager &resource_manager);

                virtual std::unique_ptr<graphics::context> create() override;

            private:
                system::resource_manager &resource_manager_;
            };
        }
    }
}

#endif //SIGMAFIVE_GRAPHICS_OPENGL_CONTEXT_HPP