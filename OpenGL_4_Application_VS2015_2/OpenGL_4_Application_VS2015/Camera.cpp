#include "Camera.hpp"

namespace gps {


	Camera::Camera(glm::vec3 cameraPosition, glm::vec3 cameraTarget) {
		Camera::cameraPosition = cameraPosition;
		Camera::cameraTarget = cameraTarget;
		cameraDirection = glm::normalize(cameraTarget - cameraPosition);
		cameraRightDirection = glm::cross(cameraDirection, glm::vec3(0.0f, 1.0f, 0.0f));
	}

	void Camera::move(MOVE_DIRECTION direction, float speed) {
		switch (direction) {
		case MOVE_FORWARD:
			Camera::cameraPosition += cameraDirection * speed;
			break;
		case MOVE_BACKWARD:
			Camera::cameraPosition -= cameraDirection * speed;
			break;
		case MOVE_LEFT:
			cameraPosition -= cameraRightDirection * speed;
			break;
		case MOVE_RIGHT:
			cameraPosition += cameraRightDirection * speed;
			break;
		}
	}

	glm::mat4 Camera::getViewMatrix()
	{
		return glm::lookAt(cameraPosition, cameraPosition + cameraDirection, glm::vec3(0.0f, 1.0f, 0.0f));
	}

	glm::vec3 Camera::getCameraTarget()
	{
		return cameraTarget;
	}

	void Camera::rotate(float pitch, float yaw) {
		glm::mat4 rotationMatrix = glm::mat4(1.0f);
		glm::vec4 cameraDirectionPoint = glm::vec4(cameraDirection, 1.0f);

		rotationMatrix = glm::rotate(rotationMatrix, yaw, glm::vec3(0.0f, 1.0f, 0.0f));
		rotationMatrix = glm::rotate(rotationMatrix, pitch, cameraRightDirection);

		cameraDirectionPoint = rotationMatrix * cameraDirectionPoint;
		glm::normalize(cameraDirectionPoint);

		cameraDirection = (glm::vec3)cameraDirectionPoint;
		cameraRightDirection = glm::cross(cameraDirection, glm::vec3(0.0f, 1.0f, 0.0f));
	}
}
