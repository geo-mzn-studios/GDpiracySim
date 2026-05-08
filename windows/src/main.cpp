#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/utils/web.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init())
            return false;

        if (Mod::get()->getSettingValue<bool>("pirate")) {
            geode::createQuickPopup(
                "Pirate detected!",
                "<cy>Online features</c> have been <cr>disabled</c>. Please consider purchasing the <cg>full version</c> as it really helps us to continue developing <cl>Geometry Dash</c>!",
                "OK :(",
                "Get Full",
                [](FLAlertLayer*, bool btn2) {
                    if (btn2) {
                        geode::utils::web::openLinkInBrowser(
                            "https://store.steampowered.com/app/322170/Geometry_Dash"
                        );
                    }
                }
            );
        }

        return true;
    }
};
