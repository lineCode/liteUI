#include "AtomicContainer.h"
#include <Atomic/Resource/ResourceCache.h>


AtomicContainer::AtomicContainer(UIElement* element)
    : _element(element)
{

}

litehtml::uint_ptr AtomicContainer::create_font(
    const litehtml::tchar_t* faceName, int size, int weight, litehtml::font_style italic, unsigned int decoration,
    litehtml::font_metrics* fm)
{
    auto context = _element->GetContext();
    auto cache = context->GetSubsystem<ResourceCache>();
    auto font = cache->GetResource<Font>("Fonts/Anonymous Pro.ttf");
    auto face = font->GetFace(size);
    face->AddRef();

    // TODO: incomplete

    return face;
}

void AtomicContainer::delete_font(litehtml::uint_ptr hFont)
{
    ((FontFace*)hFont)->ReleaseRef();
}

int AtomicContainer::text_width(const litehtml::tchar_t* text, litehtml::uint_ptr hFont)
{
    SharedPtr<Text> text_element(new Text(_element->GetContext()));
    text_element->SetText(text);

    // TODO: incomplete

    return 0;
}

void AtomicContainer::draw_text(
    litehtml::uint_ptr hdc, const litehtml::tchar_t* text, litehtml::uint_ptr hFont, litehtml::web_color color,
    const litehtml::position& pos)
{

}

int AtomicContainer::pt_to_px(int pt)
{
    return 0;
}

int AtomicContainer::get_default_font_size() const
{
    return 16;
}

const litehtml::tchar_t* AtomicContainer::get_default_font_name() const
{
    return nullptr;
}

void AtomicContainer::draw_list_marker(litehtml::uint_ptr hdc, const litehtml::list_marker& marker)
{

}

void AtomicContainer::load_image(const litehtml::tchar_t* src, const litehtml::tchar_t* baseurl, bool redraw_on_ready)
{

}

void AtomicContainer::get_image_size(const litehtml::tchar_t* src, const litehtml::tchar_t* baseurl, litehtml::size& sz)
{

}

void AtomicContainer::draw_background(litehtml::uint_ptr hdc, const litehtml::background_paint& bg)
{

}

void AtomicContainer::draw_borders(
    litehtml::uint_ptr hdc, const litehtml::borders& borders, const litehtml::position& draw_pos, bool root)
{

}

void AtomicContainer::set_caption(const litehtml::tchar_t* caption)
{

}

void AtomicContainer::set_base_url(const litehtml::tchar_t* base_url)
{

}

void AtomicContainer::link(const std::shared_ptr<litehtml::document>& doc, const litehtml::element::ptr& el)
{

}

void AtomicContainer::on_anchor_click(const litehtml::tchar_t* url, const litehtml::element::ptr& el)
{

}

void AtomicContainer::set_cursor(const litehtml::tchar_t* cursor)
{

}

void AtomicContainer::transform_text(litehtml::tstring& text, litehtml::text_transform tt)
{

}

void AtomicContainer::import_css(litehtml::tstring& text, const litehtml::tstring& url, litehtml::tstring& baseurl)
{

}

void AtomicContainer::set_clip(
    const litehtml::position& pos, const litehtml::border_radiuses& bdr_radius, bool valid_x, bool valid_y)
{

}

void AtomicContainer::del_clip()
{

}

void AtomicContainer::get_client_rect(litehtml::position& client) const
{

}

std::shared_ptr<litehtml::element> AtomicContainer::create_element(
    const litehtml::tchar_t* tag_name, const litehtml::string_map& attributes,
    const std::shared_ptr<litehtml::document>& doc)
{
    return std::shared_ptr<litehtml::element>();
}

void AtomicContainer::get_media_features(litehtml::media_features& media) const
{
}

void AtomicContainer::get_language(litehtml::tstring& language, litehtml::tstring& culture) const
{

}

litehtml::tstring AtomicContainer::resolve_color(const litehtml::tstring& color) const
{
    return litehtml::tstring();
}
