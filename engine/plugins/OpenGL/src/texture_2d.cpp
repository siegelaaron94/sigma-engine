#include <texture_2d.hpp>
#include <assert.h>

namespace sigmafive {
    namespace graphics {
        namespace opengl {
            //TODO add mipmapping support
            texture_2d::texture_2d() {
                gl::GenTextures(1, &gl_object_); //TODO GL_CHECK_ERROR;
                //TODO this changes global state
                bind(0);
                gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MIN_FILTER, gl::NEAREST);
                gl::TexParameteri(gl::TEXTURE_2D, gl::TEXTURE_MAG_FILTER, gl::NEAREST);
            }

            texture_2d::texture_2d(texture_format format, uint2 size, pixel_format px_format, pixel_type px_type)
                    : texture_2d() {
                assert((size.x != 0 && size.y != 0) &&
                       "Can not allocate a 2D texture with a size of zero. did you mean to use a 1D texture?");
                //TODO would be best if use glTextureStorage2D from 4.5
                gl::TexImage2D(gl::TEXTURE_2D, 0, GLenum(format), size.x, size.y, 0, GLenum(px_format), GLenum(px_type),nullptr);
            }

            texture_2d::~texture_2d() {
                gl::DeleteTextures(1, &gl_object_); //TODO GL_CHECK_ERROR;
            }

            texture_2d::operator GLuint() const {
                return gl_object_;
            }

            void texture_2d::bind(unsigned int texture_unit) {
                gl::ActiveTexture(gl::TEXTURE0 + texture_unit);
                gl::BindTexture(gl::TEXTURE_2D, gl_object_); //TODO GL_CHECK_ERROR;
            }

            void texture_2d::set_pixels(uint2 size,const unsigned char *pixels) {//const std::vector<vec4_t<unsigned char>> &pixels
                //TODO this changes global state
                bind(0);
                //TODO would be best if use glTextureStorage2D from 4.5
                gl::TexImage2D(gl::TEXTURE_2D, 0, gl::RGBA, size.x, size.y, 0, gl::RGBA, gl::UNSIGNED_BYTE,pixels);
            }
        }
    }
}