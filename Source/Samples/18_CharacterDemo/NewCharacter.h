#pragma once

#include <Urho3D/Input/Controls.h>
#include <Urho3D/Scene/LogicComponent.h>
#include <SDL/SDL_scancode.h>
#include <PhotoCamera.h>

using namespace Urho3D;

/*
	This character should be a revised version of the default character,
	with new animations, models, etc.
	TODO:
	-Tie inventory to the character
	-Switch items
	-Look to IK demo to add IK to legs
	-Force first person (eventually)

*/

// Seems to go up in 2^x
const unsigned CTRL_FORWARD = 1;
const unsigned CTRL_BACK = 2;
const unsigned CTRL_LEFT = 4;
const unsigned CTRL_RIGHT = 8;
const unsigned CTRL_JUMP = 16;
const unsigned CTRL_TAKESNAP = 32;
const unsigned CTRL_APERTUREHOLD = 64;


// Movement value consts
const float MOVE_FORCE = 0.8f;
const float INAIR_MOVE_FORCE = 0.02f;
const float BRAKE_FORCE = 0.2f;
const float JUMP_FORCE = 7.0f;
const float YAW_SENSITIVITY = 0.1f;
const float INAIR_THRESHOLD_TIME = 0.1f;

/// Character component, responsible for physical movement according to controls, as well as animation.
class NewCharacter : public LogicComponent {
	URHO3D_OBJECT(NewCharacter, LogicComponent);

public:
	///Construct.
	explicit NewCharacter(Context* context);

	/// Register object factory and attributes.
	static void RegisterObject(Context* context);

	/// Handle startup. Called by LogicComponent base class.
	void Start() override;
	/// Handle physics world update. Called by LogicComponent base class.
	void FixedUpdate(float timeStep) override;

	/// Movement controls. Assigned by the main program each frame.
	Controls controls_;

	// Adds a camera to the node
	void setupCamera(Node* parentNode, Node* copyTransformsNode);

	Node* camera;
	Node* itemBoneNodeR;

private:
	/// Handle physics collision event.
	void HandleNodeCollision(StringHash eventType, VariantMap& eventData);

	/// Grounded flag for movement.
	bool onGround_;
	/// Jump flag.
	bool okToJump_;
	/// In air timer. Due to possible physics inaccuracy, character can be off ground for max. 1/10 second and still be allowed to move.
	float inAirTimer_;

	bool okToSnapPhoto = true;
};