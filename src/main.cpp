#include <Atomic/Engine/Application.h>
#include <Atomic/Engine/EngineDefs.h>
#include <Atomic/Graphics/GraphicsDefs.h>
#include <Atomic/IO/FileSystem.h>
#include <Atomic/Resource/ResourceCache.h>

#include <UrhoUI.h>
#include "AtomicContainer.h"


using namespace Atomic;


class LiteUIApplication : public Application
{
    ATOMIC_OBJECT(LiteUIApplication, Application);
public:
    litehtml::context ctx;
    litehtml::document::ptr doc;
    AtomicContainer* container;
    SharedPtr<UrhoUI::Window> window;

    explicit LiteUIApplication(Context* ctx) : Application(ctx)
    {
    }

    void Setup() override
    {
        engineParameters_[EP_WINDOW_TITLE] = GetTypeName();
        engineParameters_[EP_HEADLESS] = false;
        engineParameters_[EP_RESOURCE_PATHS] = "CoreData;GameData";
        engineParameters_[EP_RESOURCE_PREFIX_PATHS] = context_->GetFileSystem()->GetProgramDir();
        engineParameters_[EP_FULL_SCREEN] = false;
        engineParameters_[EP_WINDOW_HEIGHT] = 1080;
        engineParameters_[EP_WINDOW_WIDTH] = 1920;
    }

    void Start() override
    {
        ctx.load_master_stylesheet(master_css);

        context_->RegisterFactory<UrhoUI::UI>();
        context_->RegisterSubsystem(context_->CreateObject<UrhoUI::UI>());

        auto ui = context_->GetSubsystem<UrhoUI::UI>();
        auto style = context_->GetResourceCache()->GetResource<XMLFile>("UI/DefaultStyle.xml");
        ui->GetRoot()->SetDefaultStyle(style);

        window = ui->GetRoot()->CreateChild<UrhoUI::Window>();
        window->SetStyleAuto();
        window->SetVisible(true);
        window->SetPosition(300, 300);
        window->SetSize(800, 600);
        window->SetTiled(true);

        container = new AtomicContainer(window);
//        doc = litehtml::document::createFromString("<html><body>Hello world</body></html>", container, &ctx);
    }

    void Stop() override
    {

    }
};

ATOMIC_DEFINE_APPLICATION_MAIN(LiteUIApplication);
