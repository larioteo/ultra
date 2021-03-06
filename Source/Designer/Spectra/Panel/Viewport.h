﻿#pragma once

#include "Ultra/Core.h"
#include "Ultra/Renderer/Framebuffer.h"
#include "Ultra/Renderer/Texture.h"
#include "Ultra/Scene/Entity.h"
#include "Ultra/Scene/Components.h"

namespace Ultra {

class ViewportPanel {
public:
    ViewportPanel();
    ViewportPanel(FramebufferProperties &properties);

    void Update();
    void Resize(uint32_t width, uint32_t height) { Buffer->Resize(width, height, false); }
    void Reload();

    bool IsActive() { return Active; }
    bool IsEnabled() { return Enabled; }

    void BindBuffer() { Buffer->Bind(); }
    void UnbindBuffer() { Buffer->Unbind(); }

    void Activate() { Active = true; }
    void Deactivate() { Active = false; }
    void Enable() { Enabled = true; }
    void Disable() { Enabled = false; }

    void SetContext(Entity &entity);
    void SetGizmoType(int type);

private:
    bool Active = true;
    bool Enabled = true;
    int mGizmoType = -1;

    Entity mContext;
    Reference<Texture2D> Context;
    Reference<Framebuffer> Buffer;

    glm::vec2 ViewportSize = { 1.0f, 1.0f }; // ToDo: Since ImGui v.179 it is importand that the size is above zero, otherwize nothing will be visible.
};

}
