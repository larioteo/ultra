#include "Buffer.h"
#include "Renderer.h"

#include "Platform/OpenGL/GLBuffer.h"

namespace Ultra {

VertexBuffer *VertexBuffer::Create(float *vertices, size_t size) {
	switch (Renderer::GetAPI()) {
		case RendererAPI::API::Null:		{ return nullptr; }
		case RendererAPI::API::OpenGL:		{ return new GLVertexBuffer(vertices, size); }
	}
	// Unknown RendererAPI
	return nullptr;
}

IndexBuffer *IndexBuffer::Create(uint32_t *indices, uint32_t size) {
	switch (Renderer::GetAPI()) {
		case RendererAPI::API::Null:		{ return nullptr; }
		case RendererAPI::API::OpenGL:		{ return new GLIndexBuffer(indices, size); }
	}
	// Unknown RendererAPI
	return nullptr;
}

}
