#include "ClientObject.Hxx"

namespace nk {

    void ClientObject::RerenderBase() {
		Rerender();
		isNeedRerender = false;
	}

    void ClientObject::UpdateBase(const sf::Event& event) {

		if (!isActivated) return;
		Update(event);

	}

	void ClientObject::LateUpdateBase(const sf::Event& event) {

		if (!isActivated) return;
		LateUpdate(event);

	}

	void ClientObject::DrawBase(sf::RenderTarget& target, sf::RenderStates states) {
	
		if (!isActivated) return;

		if (isNeedRerender) {
			RerenderBase();
		}

		draw(target, CombineRenderStates(RenderState, states));

	}

	sf::RenderStates ClientObject::CombineRenderStates(const sf::RenderStates& s1, const sf::RenderStates& s2) {

		sf::RenderStates combined;

		combined.transform = s1.transform * s2.transform;
		combined.texture = s1.texture ? s2.texture : s1.texture;
		combined.shader = s2.shader ? s2.shader : s1.shader;
		combined.blendMode = s2.blendMode != sf::BlendAlpha ? s2.blendMode : s1.blendMode;

		return combined;

	}

	void ClientObject::SetActive(bool active) {
		isActivated = active;
	}

	void ClientObject::SetNeedRerender(bool needRerender) {
		isNeedRerender = true;
	}

	bool ClientObject::IsActive() const {
		return isActivated;
	}

	bool ClientObject::IsNeedRerender() const {
		return isNeedRerender;
	}

}