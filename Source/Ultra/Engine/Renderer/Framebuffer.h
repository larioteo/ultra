#pragma once

#include <Omnia/Core.h>

namespace Ultra {

using namespace Omnia;

struct FramebufferProperties{
    uint32_t Width;
    uint32_t Height;
    uint32_t Samples = 1;

    bool SwapChainTarget = false;
};

class Framebuffer {
public:
    virtual ~Framebuffer() = default;

    static Reference<Framebuffer> Create(const FramebufferProperties &properties);

    virtual void Bind() = 0;
    virtual void Unbind() = 0;

    virtual uint32_t GetColorAttachmentRendererID() const = 0;

    virtual const FramebufferProperties &GetProperties() const = 0;
};

}
