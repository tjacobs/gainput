
#ifndef GAINPUTHELPERS_H_
#define GAINPUTHELPERS_H_

namespace gainput
{

	inline void HandleButton(DeviceId device, InputState& state, InputState& previousState, InputDeltaState* delta, DeviceButtonId buttonId, bool value)
	{
		state.Set(buttonId, value);

#ifdef GAINPUT_DEBUG
		if (value != previousState.GetBool(buttonId))
		{
			GAINPUT_LOG("Button changed: %d, %i\n", buttonId, value);
		}
#endif

		if (delta)
		{
			const bool oldValue = previousState.GetBool(buttonId);
			if (value != oldValue)
			{
				delta->AddChange(device, buttonId, oldValue, value);
			}
		}
	}

	inline void HandleAxis(DeviceId device, InputState& state, InputState& previousState, InputDeltaState* delta, DeviceButtonId buttonId, float value)
	{
		state.Set(buttonId, value);
		
#ifdef GAINPUT_DEBUG
		if (value != previousState.GetFloat(buttonId))
		{
			GAINPUT_LOG("Axis changed: %d, %f\n", buttonId, value);
		}
#endif

		if (delta)
		{
			const float oldValue = previousState.GetFloat(buttonId);
			if (value != oldValue)
			{
				delta->AddChange(device, buttonId, oldValue, value);
			}
		}
	}

}

#endif

