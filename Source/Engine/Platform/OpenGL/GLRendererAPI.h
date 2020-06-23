#pragma once

#include "Renderer/RendererAPI.h"

namespace Ultra {

class GLRendererAPI: public RendererAPI {
public:
	virtual void Load() override;

	virtual void Clear() override;
	virtual void DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray) override;

	virtual void SetClearColor(const glm::vec4 &color) override;
	virtual void SetViewport(const int32_t x, const int32_t y, const uint32_t width, const uint32_t height) override;
};

}
