#pragma once
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <memory>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;

	SceneNode();
	void attachChild(Ptr child);
	Ptr detatchChild(const SceneNode& node);

	void update(sf::Time dt);
	sf::Vector2f getWorldPosition() const;
	sf::Transform getWorldTransform() const;

private:
	virtual void updateCurrent(sf::Time dt);
	virtual void updateChildren(sf::Time dt);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::vector<Ptr> mChildren;
	SceneNode* mParent;
};