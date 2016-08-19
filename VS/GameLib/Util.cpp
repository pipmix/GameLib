#include "Util.h"

F2 Util::GetDistanceVector2d(F2 position, F2 target) {

	F2 temp;
	temp.x = target.x - position.x;
	temp.y = target.y - position.y;
	return temp;
}

F2 Util::BasicTween(F2& position, F2 target, F1 ease) {

	F2 distance = GetDistanceVector2d(position, target);
	F2 velocity;
	velocity.x = distance.x * ease;
	velocity.y = distance.y * ease;
	position.x += velocity.x;
	position.y += velocity.y;

	return position;

}


bool Util::CollidePointRect(int x, int y, RECT& r) {

	return( NumberInRange(x, r.left, r.right)		&&		NumberInRange(y, r.top, r.bottom)		);


	//return((		((x) >= min(r.left, r.right)) && ((x) <= max(r.left, r.right)))			&&		(((y) >= min(r.top, r.bottom)) && ((y) <= max(r.top, r.bottom))		));
}


bool Util::NumberInRange(int num, int minNum, int maxNum){

	return(		((num) >= min(minNum, maxNum))		 &&		((num) <= max(minNum, maxNum))		);



	

}

bool Util::CollidePointRect(XMFLOAT2 point, RECT& r) {

	return((		((point.x) >= min(r.left, r.right)) && ((point.x) <= max(r.left, r.right))		)			&&		(((point.y) >= min(r.top, r.bottom)) && ((point.y) <= max(r.top, r.bottom))		));

}



float Util::GetAngle(XMFLOAT2& velocity) {

	return atan2(velocity.y, velocity.x);

}

float Util::GetLength(XMFLOAT2& vector) {

	return sqrt(vector.x * vector.x + vector.y * vector.y);
}


void Util::SetLength(XMFLOAT2& velocity, float length) {
	float angle = atan2(velocity.y, velocity.x);

	velocity.x = cos(angle) * length;
	velocity.y = sin(angle) * length;
}

void Util::SetAngle(XMFLOAT2& vector, float angle) {

	float length = GetLength(vector);
	vector.x = cos(angle) * length;
	vector.y = sin(angle) * length;

}

void Util::Add(XMFLOAT2& dest, XMFLOAT2 source) {

	dest.x += source.x;
	dest.y += source.y;

}


void Util::Subtract(XMFLOAT2& dest, XMFLOAT2 source) {

	dest.x -= source.x;
	dest.y -= source.y;

}