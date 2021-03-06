//
// Copyright (c) 2008-2018 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once

#include "Sample.h"
#include "GunLogic.h"

namespace Urho3D
{

	class Node;
	class Scene;

}

class NewCharacter;
class Touch;

/// Moving character example.
/// This sample demonstrates:
///     - Controlling a humanoid character through physics
///     - Driving animations using the AnimationController component
///     - Manual control of a bone scene node
///     - Implementing 1st and 3rd person cameras, using raycasts to avoid the 3rd person camera clipping into scenery
///     - Defining attributes of a custom component so that it can be saved and loaded
///     - Using touch inputs/gyroscope for iOS/Android (implemented through an external file)
class CharacterDemo : public Sample {
	URHO3D_OBJECT(CharacterDemo, Sample);

public:
	/// Construct.
	explicit CharacterDemo(Context* context);
	/// Destruct.
	~CharacterDemo() override;

	/// Setup after engine initialization and before running the main loop.
	void Start() override;

	// Allows modification of engine parameters
	void Setup() override;

protected:

private:
	/// Setup rendering and viewport
	void SetupViewport();
	/// Create static scene content.
	void CreateScene();
	/// Create controllable character.
	void SetupGun();
	/// Subscribe to necessary events.
	void SubscribeToEvents();
	/// Handle application update. Set controls to character.
	void HandleUpdate(StringHash eventType, VariantMap& eventData);
	/// Handle application post-update. Update camera position after character has moved.
	void HandlePostUpdate(StringHash eventType, VariantMap& eventData);

	/// Mainly for drawing debug geom
	void HandlePostRenderUpdate(StringHash eventType, VariantMap& eventData);

	/// The controllable character component.
	//WeakPtr<KinematicDog> character_;
	/// First person camera flag.
	bool firstPerson_;

	Node* gunNode_;
	GunLogic* gunLogic_;
};
