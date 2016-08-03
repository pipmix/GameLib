#include "Helpers.h"

bool IntersectsFloat(XMFLOAT4& rectA, XMFLOAT4& rectB) {
	return (rectA.z > rectB.x && rectA.x < rectB.z &&
		rectA.w > rectB.y && rectA.y < rectB.w);

	// x left 
	// y top
	// z right
	// w bottom
}
