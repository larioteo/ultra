﻿#pragma once

#include <entt/entt.hpp>
#include <glm/glm.hpp>

#include "Omnia/Utility/UUID.h"

#include "Ultra.pch"
#include "Ultra/Core.h"
#include "Ultra/Scene/SceneCamera.h"

namespace Ultra {

class ScriptableEntity;

}

enum class Components {
    Identifier,
    Tag,
    Transform,
    Camera,
    NativeScript,
    Sprite
};

namespace Ultra::Component {

// Descriptive Components
struct Identifier {
    Identifier() = default;
    Identifier(UUID<string> rhs): ID(rhs) {}
    ~Identifier() = default;

    // Accessors
    operator string() { return ID; }

    // Comparision
    bool operator==(const string &rhs) { return (ID == rhs); }
    bool operator==(const UUID<string> &rhs) { return (ID == rhs); }

    // Modifiers
    void operator=(UUID<string> right) {
        AppLogTrace("[Ultra::Component::Identifier]: ", "Overriding '", ID, "' to '", right, "'!");
        ID = right;
    }

private:
    // Properties
    UUID<string> ID;
};

struct Tag {
    // Default
    Tag() = default;
    Tag(const string &tag): mTag { tag } {}
    Tag(const Tag &other): mTag { other.mTag } {}
    ~Tag() = default;

    // Accessors
    operator string &() { return mTag; }
    operator const string &() const { return mTag; }
    operator const char *() const { return mTag.c_str(); }

    // Comparision
    bool operator ==(string &right) const { return (mTag == right); }
    bool operator ==(const string &right) const { return (mTag == right); }

    // Mutators
    void operator =(string &right) { mTag = right; }

private:
    // Properties
    string mTag;
};

// Dimensional Components
struct Transform {
    glm::mat4 mTransform { 1.0f };

    Transform() = default;
    Transform(const glm::mat4 &transform): mTransform(transform) {}
    Transform(const Transform &) = default;
    ~Transform() = default;

    operator glm::mat4 &() { return mTransform; }
    operator const glm::mat4 &() const { return mTransform; }
};

// Game Components
struct Camera {
    SceneCamera mCamera;
    bool Primary = false;
    bool FixedAspectRatio = false;
    SceneCamera::ProjectionType ProjectionType = SceneCamera::ProjectionType::Orthographic;

    Camera() = default;
    Camera(const Camera &) = default;
    //Camera(const glm::mat4 &projection): Camera(projection) {}
    ~Camera() = default;

    operator int &() { return *reinterpret_cast<int *>(&ProjectionType); }
    Camera &operator =(const SceneCamera::ProjectionType &type) {
        ProjectionType = type;
        mCamera.SetProjectionType(type);
        return *this;
    }

    //operator const glm::mat4 &() { return Camera.GetProjection(); }
    //operator const glm::mat4 &() const { return Camera.GetProjectionMatrix(); }
};

struct Environment {

};

struct Light {
    glm::vec3 Direction { 1.0f };
    glm::vec3 Radiance { 1.0f };

    float Multiplier = 1.0f;
};

struct Mesh {
    bool Data;
};

struct Sound {
    // Default
    Sound() = default;
    Sound(const string &source): Source { source } {}
    Sound(const Sound &other): Source { other.Source } {}
    ~Sound() = default;

    // Accessors
    operator string &() { return Source; }
    operator const string &() const { return Source; }
    operator const char *() const { return Source.c_str(); }

    // Modifiers
    void operator =(string &right) { Source = right; }
    bool operator ==(string &right) const { return (Source == right); }

private:
    // Properties
    string Source;
};

// Logic Components
struct NativeScript {
    ScriptableEntity *Instance = nullptr;

    NativeScript() = default;
    ~NativeScript() = default;

    template<typename T = ScriptableEntity>    ScriptableEntity *Load() { return new T(); }
    template<typename T = ScriptableEntity>    void Unload() { delete (T *)Instance; Instance = nullptr; }

    ScriptableEntity *(*Load2)();
    void (*Unload2)(NativeScript *);

    template<typename T>
    void Bind() {
        Load2 = []() { return static_cast<ScriptableEntity *>(new T()); };
        Unload2 = [](NativeScript *nsc) { delete nsc->Instance; nsc->Instance = nullptr; };
    }
};

// Render Components
struct Sprite {
    glm::vec4 Color { 1.0f };

    Sprite() = default;
    Sprite(const Sprite &) = default;
    Sprite(const glm::vec4 &color): Color(color) {}

    operator glm::vec4 &() { return Color; }
    operator const glm::vec4 &() const { return Color; }
};

}
