#include <crucible/DebugRenderer.hpp>
#include <crucible/Renderer.hpp>
#include <crucible/InternalShaders.hpp>

#include <glad/glad.h>

void DebugRenderer::init() {
    debugShader.load(InternalShaders::debug_vsh, InternalShaders::debug_fsh);
}

void DebugRenderer::renderDebugLine(vec3 v1, vec3 v2, vec3 color) {
    debugRendererFactory.vertex(v1.x, v1.y, v1.z, color.x, color.y, color.z, 0.0f, 0.0f);
    debugRendererFactory.vertex(v2.x, v2.y, v2.z, color.x, color.y, color.z, 0.0f, 0.0f);
}
// ------------------------------------------------------------------------
void DebugRenderer::renderDebugAABB(vec3 v1, vec3 v2, vec3 color) {
    //top square
    renderDebugLine(vec3(v1.x, v1.y, v1.z), vec3(v2.x, v1.y, v1.z), color);
    renderDebugLine(vec3(v1.x, v1.y, v1.z), vec3(v1.x, v1.y, v2.z), color);
    renderDebugLine(vec3(v2.x, v1.y, v1.z), vec3(v2.x, v1.y, v2.z), color);
    renderDebugLine(vec3(v1.x, v1.y, v2.z), vec3(v2.x, v1.y, v2.z), color);

    //bottom square
    renderDebugLine(vec3(v2.x, v2.y, v2.z), vec3(v1.x, v2.y, v2.z), color);
    renderDebugLine(vec3(v2.x, v2.y, v2.z), vec3(v2.x, v2.y, v1.z), color);
    renderDebugLine(vec3(v1.x, v2.y, v1.z), vec3(v1.x, v2.y, v2.z), color);
    renderDebugLine(vec3(v1.x, v2.y, v1.z), vec3(v2.x, v2.y, v1.z), color);

    //top/bottom square connections
    renderDebugLine(vec3(v1.x, v1.y, v1.z), vec3(v1.x, v2.y, v1.z), color);
    renderDebugLine(vec3(v2.x, v2.y, v2.z), vec3(v2.x, v1.y, v2.z), color);
    renderDebugLine(vec3(v2.x, v1.y, v1.z), vec3(v2.x, v2.y, v1.z), color);
    renderDebugLine(vec3(v1.x, v1.y, v2.z), vec3(v1.x, v2.y, v2.z), color);
}
// ------------------------------------------------------------------------
void DebugRenderer::renderDebugAABB(AABB aabb, vec3 color) {
    renderDebugAABB(aabb.min, aabb.max, color);
}

void DebugRenderer::renderDebugSphere(vec3 pos, float radius, vec3 color) {
    float pi = 3.141592f;

    for (int i = 0; i < 64; i++) {
        float x1 = sin(i * ((pi*2)/64)) * radius;
        float z1 = cos(i * ((pi*2)/64)) * radius;

        float x2 = sin((i+1) * ((pi*2)/64)) * radius;
        float z2 = cos((i+1) * ((pi*2)/64)) * radius;

        renderDebugLine(pos + vec3(x1, 0, z1), pos + vec3(x2, 0, z2), color);
        renderDebugLine(pos + vec3(x1, z1, 0), pos + vec3(x2, z2, 0), color);
        renderDebugLine(pos + vec3(0, z1, x1), pos + vec3(0, z2, x2), color);
    }
}

void DebugRenderer::flush(Camera cam) {
    debugRendererFactory.toMesh(debugRendererMesh);
    debugShader.bind();
    debugShader.uniformMat4("view", cam.getView());
    debugShader.uniformMat4("projection", cam.getProjection());
    debugRendererMesh.renderMode = GL_LINES;
    debugRendererMesh.render();
    debugRendererFactory.clear();
}