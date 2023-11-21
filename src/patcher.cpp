#include <Geode/Geode.hpp>
#include "patcher.hpp"

using namespace geode::prelude;

void _patch(void *address, const geode::ByteVector &data) {
    geode::Result<geode::Patch*> result = mod->patch(address, data);
    if (result.isErr()) FLAlertLayer::create("ChillGDPS Client", "Could not load patch.", "OK");
}

void* to_addr(uintptr_t addr) {
    return reinterpret_cast<void*>(base::get() + addr);
}

void toggle_ac_level_kick_bypass(bool enabled) {
    if (enabled) {
        _patch(to_addr(0x1FD557), {0xEB, 0x0C});
        _patch(to_addr(0x1FD742), {0xC7, 0x87, 0xE0, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xC7, 0x87, 0xE4, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
        _patch(to_addr(0x1FD756), {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
        _patch(to_addr(0x1FD79A), {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
        _patch(to_addr(0x1FD7AF), {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
    } else {
        _patch(to_addr(0x1FD557), {0x74, 0x0C});
        _patch(to_addr(0x1FD742), {0x80, 0xBF, 0xDD, 0x02, 0x00, 0x00, 0x00, 0x0F, 0x85, 0x0A, 0xFE, 0xFF, 0xFF, 0x80, 0xBF, 0x34, 0x05, 0x00, 0x00, 0x00, 0x0F, 0x84, 0xFD, 0xFD, 0xFF, 0xFF});
        _patch(to_addr(0x1FD756), {0x0F, 0x84, 0xFD, 0xFD, 0xFF, 0xFF});
        _patch(to_addr(0x1FD79A), {0x0F, 0x84, 0xB9, 0xFD, 0xFF, 0xFF});
        _patch(to_addr(0x1FD7AF), {0x0F, 0x84, 0xA4, 0xFD, 0xFF, 0xFF});
    }
}

void toggle_icon_bypass(bool enabled) {
    if (enabled) {
        _patch(to_addr(0xC50A8), {0xB0, 0x01, 0x90, 0x90, 0x90});
        _patch(to_addr(0xC54BA), {0xB0, 0x01, 0x90, 0x90, 0x90});
    } else {
        _patch(to_addr(0xC50A8), {0xE8, 0x7A, 0xCD, 0x19, 0x00});
        _patch(to_addr(0xC54BA), {0xE8, 0x68, 0xC9, 0x19, 0x00});
    }
}

void toggle_noclip(bool enabled) {
    if (enabled) _patch(to_addr(0x20A23C), {0xE9, 0x79, 0x06, 0x00, 0x00});
    else _patch(to_addr(0x20A23C), {0x6A, 0x14, 0x8B, 0xCB, 0xFF});
}

void toggle_practice_music(bool enabled) {
    if (enabled) {
        _patch(to_addr(0x20C925), {0x90, 0x90, 0x90, 0x90, 0x90, 0x90});
        _patch(to_addr(0x20D143), {0x90, 0x90});
        _patch(to_addr(0x20A563), {0x90, 0x90});
        _patch(to_addr(0x20A595), {0x90, 0x90});
    }
    else {
        _patch(to_addr(0x20C925), {0x0F, 0x85, 0xF7, 0x00, 0x00, 0x00});
        _patch(to_addr(0x20D143), {0x75, 0x41});
        _patch(to_addr(0x20A563), {0x75, 0x3E});
        _patch(to_addr(0x20A595), {0x75, 0x0C});
    }
}

void toggle_slider_limit(bool enabled) {
    if (enabled) {
        _patch(to_addr(0x2E5CA), {0xEB});
        _patch(to_addr(0x2E5F8), {0xEB});
    } else {
        _patch(to_addr(0x2E5CA), {0x76});
        _patch(to_addr(0x2E5F8), {0x76});
    }
}

void toggle_ignore_esc(bool enabled) {
    if (enabled) _patch(to_addr(0x1E644C), {0x90, 0x90, 0x90, 0x90, 0x90});
    else _patch(to_addr(0x1E644C), {0xE8, 0xBF, 0x73, 0x02, 0x00});
}

void toggle_object_bypass(bool enabled) {
    if (enabled) {
        _patch(to_addr(0x73169), {0xFF, 0xFF, 0xFF, 0x7F});
        _patch(to_addr(0x856A4), {0xFF, 0xFF, 0xFF, 0x7F});
        _patch(to_addr(0x87B17), {0xFF, 0xFF, 0xFF, 0x7F});
        _patch(to_addr(0x87BC7), {0xFF, 0xFF, 0xFF, 0x7F});
        _patch(to_addr(0x87D95), {0xFF, 0xFF, 0xFF, 0x7F});
        _patch(to_addr(0x880F4), {0xFF, 0xFF, 0xFF, 0x7F});
        _patch(to_addr(0x160B06), {0xFF, 0xFF, 0xFF, 0x7F});
    } else {
        _patch(to_addr(0x73169), {0x80, 0x38, 0x01, 0x00});
        _patch(to_addr(0x856A4), {0x80, 0x38, 0x01, 0x00});
        _patch(to_addr(0x87B17), {0x80, 0x38, 0x01, 0x00});
        _patch(to_addr(0x87BC7), {0x80, 0x38, 0x01, 0x00});
        _patch(to_addr(0x87D95), {0x80, 0x38, 0x01, 0x00});
        _patch(to_addr(0x880F4), {0x80, 0x38, 0x01, 0x00});
        _patch(to_addr(0x160B06), {0x80, 0x38, 0x01, 0x00});
    }
}

void toggle_song_bypass(bool enabled) {
    if (enabled) _patch(to_addr(0x2CDF44), {0x68, 0x74, 0x74, 0x70, 0x73, 0x3A, 0x2F, 0x2F, 0x61, 0x62, 0x73, 0x6F, 0x6C, 0x6C, 0x6C, 0x75, 0x74, 0x65, 0x2E, 0x63, 0x6F, 0x6D, 0x2F, 0x61, 0x70, 0x69, 0x2F, 0x67, 0x64, 0x5F, 0x73, 0x6F, 0x6E, 0x67, 0x5F, 0x62, 0x79, 0x70, 0x61, 0x73, 0x73, 0x00});
    else _patch(to_addr(0x2CDF44), {0x68, 0x74, 0x74, 0x70, 0x3A, 0x2F, 0x2F, 0x77, 0x77, 0x77, 0x2E, 0x62, 0x6F, 0x6F, 0x6D, 0x6C, 0x69, 0x6E, 0x67, 0x73, 0x2E, 0x63, 0x6F, 0x6D, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x2F, 0x67, 0x65, 0x74, 0x47, 0x4A, 0x53, 0x6F, 0x6E, 0x67, 0x49, 0x6E, 0x66, 0x6F, 0x2E, 0x70, 0x68, 0x70, 0x00});
}
