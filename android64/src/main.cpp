#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/utils/web.hpp>

using namespace geode::prelude;

$on_mod(Loaded) {
    geode::log::info("Hello World!");

    if (Mod::get()->getSettingValue<bool>("pirate")) {
    geode::createQuickPopup(
    "Pirate detected!",
    "<cy>Online features</c> have been <cr>disabled</c>. Please consider purchasing the <cg>full version</c> as it really helps us to continue developing <cl>Geometry Dash</c>!",
    "OK :(",
    "Get Full",
    [](FLAlertLayer* layer, bool btn2) {
        if (btn2) {
            geode::utils::web::openLinkInBrowser(
                "https://play.google.com/store/apps/details?id=com.robtopx.geometryjump"
            );
        }
    }
    );
    }
}