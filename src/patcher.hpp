#include <Geode/Geode.hpp>

using namespace geode::prelude;
#define mod geode::Mod::get()

void _patch(void *address, const geode::ByteVector &data);
void* to_addr(uintptr_t addr);

void toggle_ac_level_kick_bypass(bool enabled);
void toggle_icon_bypass(bool enabled);
void toggle_noclip(bool enabled);
void toggle_practice_music(bool enabled);
void toggle_slider_limit(bool enabled);
void toggle_ignore_esc(bool enabled);
void toggle_object_bypass(bool enabled);
void toggle_song_bypass(bool enabled);
