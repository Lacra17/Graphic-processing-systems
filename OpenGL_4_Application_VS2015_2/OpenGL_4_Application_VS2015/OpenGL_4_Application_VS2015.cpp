#pragma once
#define GLEW_STATIC
#include <iostream>
#include "glm/glm.hpp"//core glm functionality
#include "glm/gtc/matrix_transform.hpp"//glm extension for generating common transformation matrices
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_inverse.hpp"
#include "GLEW/glew.h"
#include "GLFW/glfw3.h"
#include <string>
#include "SkyBox.hpp"

#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"
#include "Shader.hpp"
#include "Camera.hpp"
#include "Model3D.hpp"
#include "Mesh.hpp"
#include "OpenGL_4_Application_VS2015.h"

gps::SkyBox mySkyBox;
gps::Shader skyboxShader;
int glWindowWidth = 1280;
int glWindowHeight = 720;
int retina_width, retina_height;
GLFWwindow* glWindow = NULL;

const GLuint SHADOW_WIDTH = 2048, SHADOW_HEIGHT = 2048;

// Positions of the point lights
glm::vec3 pointLightPositions[] = {
	glm::vec3(0.5f, 5.39, 3.59f),
	glm::vec3(0.32f, 11.77f, 2.659f),
	glm::vec3(0.5f + 30 * 1, 5.39, 3.59f),
	glm::vec3(0.32f + 30 * 1, 11.77f, 2.659f),
	glm::vec3(0.5f + 30 * 2, 5.39, 3.59f),
	glm::vec3(0.32f + 30 * 2, 11.77f, 2.659f),
	glm::vec3(0.5f + 30 * 3, 5.39, 3.59f),
	glm::vec3(0.32f + 30 * 3, 11.77f, 2.659f),
	glm::vec3(0.5f - 30, 5.39, 3.59f),
	glm::vec3(0.32f -30, 11.77f, 2.659f),
	glm::vec3(0.5f - 30*2, 5.39, 3.59f),
	glm::vec3(0.32f - 30*2, 11.77f, 2.659f),
	glm::vec3(0.5f - 30*3, 5.39, 3.59f),
	glm::vec3(0.32f - 30*3, 11.77f, 2.659f),
	glm::vec3(0.5f - 30*4, 5.39, 3.59f),
	glm::vec3(0.32f - 30*4, 11.77f, 2.659f)
};

// Delta time
GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
GLfloat lastFrame = 0.0f;  	// Time of last frame
glm::vec3 leftFrontCorner(-100.0f, 0.0f, 0.0f);
glm::vec3 rightBackCorner(200.0f, 0.0f, 0.0f);

glm::mat4 model;
GLint modelLoc;

//gps::Camera myCamera(glm::vec3(0.0f, 5.0f, 15.0f), glm::vec3(0.0f, 2.0f, -10.0f));
gps::Camera myCamera(glm::vec3(60.0f, 10.0f, 5.0f), glm::vec3(-5.0f, -10.0f, -10.0f));
float cameraSpeed = 0.8f;

bool pressedKeys[1024];
float angle = 0.0f;
float lightIntensity = 0.0f;
glm::vec3 car_coord(3.5f, 4.299998f, 5.500003f);
float angleForCar = 0.0f;
GLfloat lightAngle;

/// Camera
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
GLfloat yaw = -90.0f;	// Yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right (due to how Eular angles work) so we initially rotate a bit to the left.
GLfloat pitch = 0.0f;
GLfloat lastX = (GLfloat)(glWindowWidth / 2.0);
GLfloat lastY = (GLfloat)(glWindowHeight / 2.0);
GLfloat fov = 45.0f;
bool keys[1024];

/// OBJECTS
gps::Model3D myModelFirstHouse, myModelGardenFirstHouse, myModelRoad, myModelTree, myModelLandscape,
myModelBackYard, myModelHouseBackYard, myModelSimpleHouse, myModelHouseRoof, myModelHouseXII, myModelPool,
myModelIntersection, myModelLamp, myModelLamp11, myModelLamp12, myModelCarChass, myModelWaterPark,
myModelHouseForPark, myModelGrass, myModelArchHouse, myModelArchHouseRoof, myModelHouseContemDesign, myModelHouseContemDesignV1, myModelHouseContemDesignV0, myModelHouseContemDesignV2,
myModelHouseForTheGrass, myModelHouseWithFence, myModelWoodHouse, myModelHouseWithGrassRoof, myModelCloud,
myModelProjContempRoof, myModelProjContempField, myModelBar, myModelProjContempHouse, myModelHouseFinal,
myModelPalmPoolHouse, myModelHouseComplex, myModelPoolHouse, myModelHouseForTheGrass2;

gps::Model3D lightCube;

gps::Shader myCustomShader;
gps::Shader myCustomShader2;
gps::Shader lightShader;
gps::Shader depthMapShader;

GLuint shadowMapFBO;
GLuint depthMapTexture;

double lastCameraX = 0;
double lastCameraY = 0;
float scale_dimension = 0.5f;

GLuint verticesVBO;
GLuint verticesEBO;
GLuint objectVAO;
GLint texture;
float delta = 0;
float movementSpeed = 2; // units per second 

double lastTimeStamp = glfwGetTime();

glm::vec3 lightDir(0.0f, 50.0f, 50.0f);
GLuint lightDirLoc;
glm::vec3 lightColor;
GLuint lightColorLoc;
glm::vec3 skyBox;
GLuint skyBoxLoc;

glm::vec3 lightPos[2];
GLuint lightPosLoc;

glm::mat4 view;
GLuint viewLoc;
glm::mat4 projection;
GLuint projectionLoc;
glm::mat3 normalMatrix;
GLuint normalMatrixLoc;
glm::mat3 lightDirMatrix;
GLuint lightDirMatrixLoc;

void setPointLightForLamps();
void move_forward();
void turn_left();
void turn_right();
void move_backward();
void NightSkyBox();
void DaySkyBox();

enum CloudDirection
{
	LEFT_TO_RIGHT,
	RIGHT_TO_LEFT
};
CloudDirection cloudDirection = LEFT_TO_RIGHT;
double lastTimeStampSun = glfwGetTime();
double lastTimeStampCloud = glfwGetTime();
//movementSpeed = units per second, delta = cloud delta or sun delta  
float addDelta(double elapsedSeconds, float delta, float movementSpeed) {
	return (delta + movementSpeed * elapsedSeconds);
}
float subtractDelta(double elapsedSeconds, float delta, float movementSpeed) {
	return (delta - movementSpeed * elapsedSeconds);
}

float deltaCloud=-50.0f;

void windowResizeCallback(GLFWwindow* window, int width, int height)
{
	fprintf(stdout, "window resized to width: %d , and height: %d\n", width, height);
	//TODO
	//for RETINA display
	glfwGetFramebufferSize(glWindow, &retina_width, &retina_height);

	myCustomShader.useShaderProgram();

	//set projection matrix
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	//send matrix data to shader
	GLint projLoc = glGetUniformLocation(myCustomShader.shaderProgram, "projection");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	lightShader.useShaderProgram();

	glUniformMatrix4fv(glGetUniformLocation(lightShader.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	//set Viewport transform
	glViewport(0, 0, retina_width, retina_height);
}

void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			pressedKeys[key] = true;
		else if (action == GLFW_RELEASE)
			pressedKeys[key] = false;
	}
}

void mouseCallback(GLFWwindow* window, double xpos, double ypos)
{
	GLfloat xoffset = xpos - lastCameraX;
	GLfloat yoffset = lastCameraY - ypos; // Reversed since y-coordinates range from bottom to top
	lastCameraX = xpos;
	lastCameraY = ypos;

	GLfloat sensitivity = 0.0011f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	myCamera.rotate(yoffset, -xoffset);
}

void do_movement()
{
	// Camera controls
	GLfloat cameraSpeed = 5.0f * deltaTime;
	if (keys[GLFW_KEY_W])
		cameraPos += cameraSpeed * cameraFront;
	if (keys[GLFW_KEY_S])
		cameraPos -= cameraSpeed * cameraFront;
	if (keys[GLFW_KEY_A])
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (keys[GLFW_KEY_D])
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	if (fov >= 1.0f && fov <= 45.0f)
		fov -= (GLfloat)yoffset;
	if (fov <= 1.0f)
		fov = 1.0f;
	if (fov >= 45.0f)
		fov = 45.0f;
}

void processMovement()
{
	if (pressedKeys[GLFW_KEY_X]) {
		angle += 0.05f;
	}

	if (pressedKeys[GLFW_KEY_Z]) {
		angle -= 0.05f;
	}

	if (pressedKeys[GLFW_KEY_W]) {
		myCamera.move(gps::MOVE_FORWARD, cameraSpeed);
	}

	if (pressedKeys[GLFW_KEY_S]) {
		myCamera.move(gps::MOVE_BACKWARD, cameraSpeed);
	}

	if (pressedKeys[GLFW_KEY_A]) {
		myCamera.move(gps::MOVE_LEFT, cameraSpeed);
	}

	if (pressedKeys[GLFW_KEY_D]) {
		myCamera.move(gps::MOVE_RIGHT, cameraSpeed);
	}

	if (glfwGetKey(glWindow, GLFW_KEY_Q))
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	if (glfwGetKey(glWindow, GLFW_KEY_E))
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	if (glfwGetKey(glWindow, GLFW_KEY_R))
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	}

	if (glfwGetKey(glWindow, GLFW_KEY_I)) {
		scale_dimension -= 0.02f;
	}

	if (glfwGetKey(glWindow, GLFW_KEY_O)) {
		scale_dimension += 0.02f;
	}

	//look up
	if (glfwGetKey(glWindow, GLFW_KEY_UP)) {
		myCamera.rotate(cameraSpeed/2, 0.0f);
	}

	//look left
	if (glfwGetKey(glWindow, GLFW_KEY_LEFT)) {
		myCamera.rotate(0.0f, cameraSpeed/2);
	}

	//look down
	if (glfwGetKey(glWindow, GLFW_KEY_DOWN)) {
		myCamera.rotate(-cameraSpeed/2, 0.0f);
	}

	//look right
	if (glfwGetKey(glWindow, GLFW_KEY_RIGHT)) {
		myCamera.rotate(0.0f, -cameraSpeed/2);
	}

	//change between day and night
	//day
	if (pressedKeys[GLFW_KEY_N]) {
		lightIntensity += 0.01f;
	}

	//night
	if (pressedKeys[GLFW_KEY_M]) {
		lightIntensity -= 0.01f;
		if (lightIntensity < -0.2)
		{
			setPointLightForLamps();
			GLint dayLoc = glGetUniformLocation(myCustomShader.shaderProgram, "day");
			myCustomShader.useShaderProgram();
			glUniform1f(dayLoc, 0.0f);
			NightSkyBox();
		}
	}

	//lights ON
	if (pressedKeys[GLFW_KEY_L])
	{
		setPointLightForLamps();
		GLint dayLoc = glGetUniformLocation(myCustomShader.shaderProgram, "day");
		myCustomShader.useShaderProgram();
		glUniform1f(dayLoc, 0.0f);

		GLint fogLoc = glGetUniformLocation(myCustomShader.shaderProgram, "fog");
		myCustomShader.useShaderProgram();
		glUniform1f(fogLoc, 0.0f);

		// Directional light
		glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.direction"), 2.2f, 10.0f, -1000.0f);
		glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.ambient"), -0.11, -0.11f, -0.11f);
		glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.diffuse"), 1.0f, 1.0f, 1.0f);
		glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.specular"), 0.5f, 0.5f, 0.5f);

		NightSkyBox();
	}

	//lights OFF - day
	if (pressedKeys[GLFW_KEY_K])
	{
		GLint dayLoc = glGetUniformLocation(myCustomShader.shaderProgram, "day");
		myCustomShader.useShaderProgram();
		glUniform1f(dayLoc, 1.0f);

		GLint fogLoc = glGetUniformLocation(myCustomShader.shaderProgram, "fog");
		myCustomShader.useShaderProgram();
		glUniform1f(fogLoc, 0.0f);

		// Directional light
		glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.direction"), 2.2f, 10.0f, -1000.0f);
		glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.ambient"), 0.5f, 0.5f, 0.5f);
		glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.diffuse"), 1.5f, 1.5f, 1.5f);
		glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.specular"), 0.5f, 0.5f, 0.5f);

		DaySkyBox();
	}

	if (pressedKeys[GLFW_KEY_T])
	{
		move_forward();
	}

	if (pressedKeys[GLFW_KEY_G])
	{
		move_backward();
	}

	if (pressedKeys[GLFW_KEY_F])
	{
		turn_left();
	}

	if (pressedKeys[GLFW_KEY_H])
	{
		turn_right();
	}

	if (pressedKeys[GLFW_KEY_V]) {

		lightAngle += 0.3f;
		if (lightAngle > 360.0f)
			lightAngle -= 360.0f;
		glm::vec3 lightDirTr = glm::vec3(glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f)) * glm::vec4(lightDir, 1.0f));
		myCustomShader.useShaderProgram();
		glUniform3fv(lightDirLoc, 1, glm::value_ptr(lightDirTr));
	}

	if (pressedKeys[GLFW_KEY_B]) {
		lightAngle -= 0.3f;
		if (lightAngle < 0.0f)
			lightAngle += 360.0f;
		glm::vec3 lightDirTr = glm::vec3(glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f)) * glm::vec4(lightDir, 1.0f));
		myCustomShader.useShaderProgram();
		glUniform3fv(lightDirLoc, 1, glm::value_ptr(lightDirTr));
	}

	if (glfwGetKey(glWindow, GLFW_KEY_P)) {
		GLint fogLoc = glGetUniformLocation(myCustomShader.shaderProgram, "fog");
		myCustomShader.useShaderProgram();
		glUniform1f(fogLoc, 1.0f);

		GLint greyLoc = glGetUniformLocation(skyboxShader.shaderProgram, "grey");
		skyboxShader.useShaderProgram();
		glUniform1f(greyLoc, 1.0f);

	}
}

bool initOpenGLWindow() {
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		return false;
	}

	glWindow = glfwCreateWindow(glWindowWidth, glWindowHeight, "OpenGL Shader Example", NULL, NULL);
	if (!glWindow) {
		fprintf(stderr, "ERROR: could not open window with GLFW3\n");
		glfwTerminate();
		return false;
	}

	// Set the required callback functions
	glfwSetWindowSizeCallback(glWindow, windowResizeCallback);
	glfwMakeContextCurrent(glWindow);

	glfwWindowHint(GLFW_SAMPLES, 4);

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	// get version info
	const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
	const GLubyte* version = glGetString(GL_VERSION); // version as a string
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	//for RETINA display
	glfwGetFramebufferSize(glWindow, &retina_width, &retina_height);

	glfwSetKeyCallback(glWindow, keyboardCallback);
	glfwSetCursorPosCallback(glWindow, mouseCallback);
	glfwSetInputMode(glWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	return true;
}

GLuint ReadTextureFromFile(const char* file_name) {
	int x, y, n;
	int force_channels = 4;
	unsigned char* image_data = stbi_load(file_name, &x, &y, &n, force_channels);
	if (!image_data) {
		fprintf(stderr, "ERROR: could not load %s\n", file_name);
		return false;
	}

	int width_in_bytes = x * 4;
	unsigned char *top = NULL;
	unsigned char *bottom = NULL;
	unsigned char temp = 0;
	int half_height = y / 2;

	for (int row = 0; row < half_height; row++) {
		top = image_data + row * width_in_bytes;
		bottom = image_data + (y - row - 1) * width_in_bytes;
		for (int col = 0; col < width_in_bytes; col++) {
			temp = *top;
			*top = *bottom;
			*bottom = temp;
			top++;
			bottom++;
		}
	}

	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_SRGB, //GL_SRGB,//GL_RGBA,
		x,
		y,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		image_data
	);
	glGenerateMipmap(GL_TEXTURE_2D);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);

	return textureID;
}

void initFBOs()
{
	//generate FBO ID
	glGenFramebuffers(1, &shadowMapFBO);

	//create depth texture for FBO
	glGenTextures(1, &depthMapTexture);
	glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
		SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	//attach texture to FBO
	glBindFramebuffer(GL_FRAMEBUFFER, shadowMapFBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMapTexture, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

glm::mat4 computeLightSpaceTrMatrix()
{
	const GLfloat near_plane = 1.0f, far_plane = 200.0f;
	glm::mat4 lightProjection = glm::ortho(-100.0f, 100.0f, -100.0f, 100.0f, near_plane, far_plane);

	glm::vec3 lightDirTr = glm::vec3(glm::rotate(glm::mat4(1.0f), glm::radians(lightAngle), glm::vec3(0.0f, 1.0f, 0.0f)) * glm::vec4(lightDir, 1.0f));
	glm::mat4 lightView = glm::lookAt(lightDirTr, myCamera.getCameraTarget(), glm::vec3(0.0f, 1.0f, 0.0f));

	return lightProjection * lightView;
}

void initShaders()
{
	myCustomShader.loadShader("shaders/shaderStart.vert", "shaders/shaderStart.frag");
	lightShader.loadShader("shaders/lightCube.vert", "shaders/lightCube.frag");
	depthMapShader.loadShader("shaders/simpleDepthMap.vert", "shaders/simpleDepthMap.frag");
}

void initOpenGLState()
{
	glClearColor((GLclampf)0.5294117647, (GLclampf)0.8078431372, (GLclampf)0.9803921568, 1.0);
	glViewport(0, 0, retina_width, retina_height);

	glEnable(GL_DEPTH_TEST); // enable depth-testing
	glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"
	glEnable(GL_CULL_FACE); // cull face
	glCullFace(GL_BACK); // cull back face
	glFrontFace(GL_CCW); // GL_CCW for counter clock-wise

	glClearColor(0.5, 0.5, 0.5, 1.0);
}

void updateDelta(double elapsedSeconds) {
	delta = (float)(delta + movementSpeed * elapsedSeconds);
}

/// Methods for moving, scaling, rotating all the objects in the scene

void HouseAndGarden(int step)
{
	if (step == 1)
	{
		/// HOUSE
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.55f, 0.55f, 0.55f));
		model = glm::translate(model, glm::vec3(39.55f, 6.950064f, -9.40000f));

		//send matrix data to vertex shader
		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		//glBindTexture(GL_TEXTURE_2D, texture);
		myModelFirstHouse.Draw(depthMapShader);

		/// GARDEN FOR THE HOUSE
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::translate(model, glm::vec3(28.200071f, 3.0f, 5.0f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelGardenFirstHouse.Draw(depthMapShader);
	}
	else if (step == 2)
	{
		/// HOUSE
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.55f, 0.55f, 0.55f));
		model = glm::translate(model, glm::vec3(39.55f, 6.950064f, -9.40000f));

		//send matrix data to vertex shader
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		//glBindTexture(GL_TEXTURE_2D, texture);
		myModelFirstHouse.Draw(myCustomShader);

		/// GARDEN FOR THE HOUSE
		model = glm::mat4(1.0f);
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::translate(model, glm::vec3(28.200071f, 3.0f, 5.0f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelGardenFirstHouse.Draw(myCustomShader);
	}
}

void Lamps(int step)
{
	if (step == 1)
	{
		/// LAMP
		for (int j = 0; j < 4; j++)
		{
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.32f + j * 30, 3.77f, 2.659f));
			model = glm::scale(model, glm::vec3(0.025f, 0.025f, 0.025f));

			glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
				1,
				GL_FALSE,
				glm::value_ptr(model));
			normalMatrix = glm::mat3(glm::inverseTranspose(view*model));
			glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));

			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelLamp.Draw(depthMapShader);

			/// LAMP 1.1
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.32f + j * 30, 3.77f, 2.659f));
			model = glm::scale(model, glm::vec3(0.025f, 0.025f, 0.025f));

			glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
				1,
				GL_FALSE,
				glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelLamp11.Draw(depthMapShader);

			/// LAMP 1.2
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.32f + j * 30, 3.77f, 2.659f));
			model = glm::scale(model, glm::vec3(0.025f, 0.025f, 0.025f));

			glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
				1,
				GL_FALSE,
				glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelLamp12.Draw(depthMapShader);

			/// before the intersection
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.32f - (j+1) * 30, 3.77f, 2.659f));
			model = glm::scale(model, glm::vec3(0.025f, 0.025f, 0.025f));

			glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
				1,
				GL_FALSE,
				glm::value_ptr(model));
			normalMatrix = glm::mat3(glm::inverseTranspose(view*model));
			glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));

			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelLamp.Draw(depthMapShader);

			/// LAMP 1.1
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.32f - (j+1) * 30, 3.77f, 2.659f));
			model = glm::scale(model, glm::vec3(0.025f, 0.025f, 0.025f));

			glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
				1,
				GL_FALSE,
				glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelLamp11.Draw(depthMapShader);

			/// LAMP 1.2
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.32f - (j+1) * 30, 3.77f, 2.659f));
			model = glm::scale(model, glm::vec3(0.025f, 0.025f, 0.025f));

			glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
				1,
				GL_FALSE,
				glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelLamp12.Draw(depthMapShader);
		}
	}
	else if (step == 2)
	{
		/// LAMP
		for (int j = 0; j < 4; j++)
		{
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.32f + j * 30, 3.77f, 2.659f));
			model = glm::scale(model, glm::vec3(0.025f, 0.025f, 0.025f));

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

			normalMatrix = glm::mat3(glm::inverseTranspose(view*model));
			glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));

			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelLamp.Draw(myCustomShader);

			/// LAMP 1.1
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.32f + j * 30, 3.77f, 2.659f));
			model = glm::scale(model, glm::vec3(0.025f, 0.025f, 0.025f));

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelLamp11.Draw(myCustomShader);

			/// LAMP 1.2
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.32f + j * 30, 3.77f, 2.659f));
			model = glm::scale(model, glm::vec3(0.025f, 0.025f, 0.025f));

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelLamp12.Draw(myCustomShader);

			/// before the intersection
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.32f - (j+1) * 30, 3.77f, 2.659f));
			model = glm::scale(model, glm::vec3(0.025f, 0.025f, 0.025f));

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

			normalMatrix = glm::mat3(glm::inverseTranspose(view*model));
			glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));

			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelLamp.Draw(myCustomShader);

			/// LAMP 1.1
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.32f - (j+1) * 30, 3.77f, 2.659f));
			model = glm::scale(model, glm::vec3(0.025f, 0.025f, 0.025f));

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelLamp11.Draw(myCustomShader);

			/// LAMP 1.2
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.32f - (j+1) * 30, 3.77f, 2.659f));
			model = glm::scale(model, glm::vec3(0.025f, 0.025f, 0.025f));

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelLamp12.Draw(myCustomShader);
		}
	}
}

void Trees(int step)
{
	if (step == 1)
	{
		glm::mat4 translateMatrix = glm::mat4(1.0f);
		glm::mat4 rotateMatrix = glm::mat4(1.0f);
		glm::mat4 scaleMatrix = glm::mat4(1.0f);
		glm::mat4  scaleVarMatrix = glm::mat4(1.0f);

		for (int j = 0; j < 5; j++)
		{
			model = glm::mat4(1.0f);
			scaleMatrix = glm::scale(model, glm::vec3(2.35f, 2.35f, 2.35f));
			translateMatrix = glm::translate(model, glm::vec3(5 + j*(10), 1.61f, 5.0f));
			scaleVarMatrix = glm::scale(model, glm::vec3(scale_dimension, scale_dimension, scale_dimension));

			model = scaleMatrix * translateMatrix*scaleVarMatrix;

			glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
				1,
				GL_FALSE,
				glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelTree.Draw(depthMapShader);

			model = glm::mat4(1.0f);
			scaleMatrix = glm::scale(model, glm::vec3(2.35f, 2.35f, 2.35f));
			translateMatrix = glm::translate(model, glm::vec3(5 - j*(13), 1.61f, 5.0f));
			scaleVarMatrix = glm::scale(model, glm::vec3(scale_dimension, scale_dimension, scale_dimension));

			model = scaleMatrix * translateMatrix*scaleVarMatrix;

			glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
				1,
				GL_FALSE,
				glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelTree.Draw(depthMapShader);
		}
	}
	else if (step == 2)
	{
		glm::mat4 translateMatrix = glm::mat4(1.0f);
		glm::mat4 rotateMatrix = glm::mat4(1.0f);
		glm::mat4 scaleMatrix = glm::mat4(1.0f);
		glm::mat4  scaleVarMatrix = glm::mat4(1.0f);

		for (int j = 0; j < 5; j++)
		{
			model = glm::mat4(1.0f);
			scaleMatrix = glm::scale(model, glm::vec3(2.35f, 2.35f, 2.35f));
			translateMatrix = glm::translate(model, glm::vec3(5 + j*(10), 1.61f, 5.0f));
			scaleVarMatrix = glm::scale(model, glm::vec3(scale_dimension, scale_dimension, scale_dimension));

			model = scaleMatrix * translateMatrix*scaleVarMatrix;

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelTree.Draw(myCustomShader);


			model = glm::mat4(1.0f);
			scaleMatrix = glm::scale(model, glm::vec3(2.35f, 2.35f, 2.35f));
			translateMatrix = glm::translate(model, glm::vec3(5 - j*(13), 1.61f, 5.0f));
			scaleVarMatrix = glm::scale(model, glm::vec3(scale_dimension, scale_dimension, scale_dimension));

			model = scaleMatrix * translateMatrix*scaleVarMatrix;

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelTree.Draw(myCustomShader);
		}
	}
}

void Road(int step)
{
	if (step == 1)
	{
		glm::mat4 translateMatrix = glm::mat4(1.0f);
		glm::mat4 rotateMatrix = glm::mat4(1.0f);
		glm::mat4 scaleMatrix = glm::mat4(1.0f);
		glm::mat4 scaleVarMatrix = glm::mat4(1.0f);

		for (int i = 0; i < 50; i++)
		{
			model = glm::mat4(1.0f);
			translateMatrix = glm::translate(model, glm::vec3(700, 356.246368, 384 - i * 473));
			scaleMatrix = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));
			rotateMatrix = glm::rotate(model, -glm::radians(90.0f), glm::vec3(0, 1, 0));

			model = scaleMatrix*rotateMatrix*translateMatrix;

			glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
				1,
				GL_FALSE,
				glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelRoad.Draw(depthMapShader);

			model = glm::mat4(1.0f);
			translateMatrix = glm::translate(model, glm::vec3(700, 356.246368, 2240 + i * 473));
			scaleMatrix = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));
			rotateMatrix = glm::rotate(model, -glm::radians(90.0f), glm::vec3(0, 1, 0));

			model = scaleMatrix*rotateMatrix*translateMatrix;

			glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
				1,
				GL_FALSE,
				glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelRoad.Draw(depthMapShader);

			//dreapta
			model = glm::mat4(1.0f);
			translateMatrix = glm::translate(model, glm::vec3(-1220.90033, 356.3f, -316.310089 - i * 300));
			scaleMatrix = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));

			model = scaleMatrix*translateMatrix;

			glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
				1,
				GL_FALSE,
				glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelRoad.Draw(depthMapShader);

			//stanga
			model = glm::mat4(1.0f);
			translateMatrix = glm::translate(model, glm::vec3(-1220.90033, 356.3f, 516.0f + 1200.100010f + i * 300));
			scaleMatrix = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));

			model = scaleMatrix*translateMatrix;

			glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
				1,
				GL_FALSE,
				glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelRoad.Draw(depthMapShader);
		}
	}
	else if (step == 2)
	{
		glm::mat4 translateMatrix = glm::mat4(1.0f);
		glm::mat4 rotateMatrix = glm::mat4(1.0f);
		glm::mat4 scaleMatrix = glm::mat4(1.0f);
		glm::mat4 scaleVarMatrix = glm::mat4(1.0f);

		for (int i = 0; i < 50; i++)
		{
			model = glm::mat4(1.0f);
			translateMatrix = glm::translate(model, glm::vec3(700, 356.246368, 384 - i * 473));
			scaleMatrix = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));
			rotateMatrix = glm::rotate(model, -glm::radians(90.0f), glm::vec3(0, 1, 0));

			model = scaleMatrix*rotateMatrix*translateMatrix;

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelRoad.Draw(myCustomShader);

			model = glm::mat4(1.0f);
			translateMatrix = glm::translate(model, glm::vec3(700, 356.246368, 2240 + i * 473));
			scaleMatrix = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));
			rotateMatrix = glm::rotate(model, -glm::radians(90.0f), glm::vec3(0, 1, 0));

			model = scaleMatrix*rotateMatrix*translateMatrix;

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelRoad.Draw(myCustomShader);

			//dreapta
			model = glm::mat4(1.0f);
			translateMatrix = glm::translate(model, glm::vec3(-1220.90033, 356.3f, -316.310089 - i * 300));
			scaleMatrix = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));

			model = scaleMatrix*translateMatrix;

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelRoad.Draw(myCustomShader);

			//stanga
			model = glm::mat4(1.0f);
			translateMatrix = glm::translate(model, glm::vec3(-1220.90033, 356.3f, 516.0f + 1200.100010f + i * 300));
			scaleMatrix = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));

			model = scaleMatrix*translateMatrix;

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
			glActiveTexture(GL_TEXTURE0);
			glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
			myModelRoad.Draw(myCustomShader);
		}
	}
}

void Intersection(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-12.210184, 3.559997, 7.0f));
		model = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelIntersection.Draw(depthMapShader);
	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-12.210184, 3.559997, 7.0f));
		model = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelIntersection.Draw(myCustomShader);
	}
}

void move_forward()
{
	car_coord += glm::vec3(sin(angleForCar) / 10, 0.0f, cos(angleForCar) / 10);
}

void move_backward()
{
	car_coord -= glm::vec3(sin(angleForCar) / 10, 0.0f, cos(angleForCar) / 10);
}

void turn_left()
{
	angleForCar += 0.05f;
}

void turn_right()
{
	angleForCar -= 0.05f;
}

void Car(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, car_coord);
		model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
		model = glm::rotate(model, -glm::radians(90.0f), glm::vec3(1, 0, 0));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 0, 1));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 0, 1));
		model = glm::rotate(model, angleForCar, glm::vec3(0, 0, 1));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelCarChass.Draw(depthMapShader);
	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, car_coord);
		model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
		model = glm::rotate(model, -glm::radians(90.0f), glm::vec3(1, 0, 0));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 0, 1));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 0, 1));
		//model = glm::rotate(model, angle, glm::vec3(0, 1, 0)); se da peste  cap
		model = glm::rotate(model, angleForCar, glm::vec3(0, 0, 1));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelCarChass.Draw(myCustomShader);
	}
}

void HouseAndBackYard(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-7.099996, 2.5f, 2.4f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelBackYard.Draw(depthMapShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-4.661982f, 3.77861f, -0.31f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseBackYard.Draw(depthMapShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-5.71f - 0.057f, 4.88561f + 0.41f, -1.25f + 1.2f + 0.899f));
		model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseRoof.Draw(depthMapShader);
	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-7.099996, 2.5f, 2.4f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelBackYard.Draw(myCustomShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-4.661982f, 3.77861f, -0.31f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseBackYard.Draw(myCustomShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-5.71f - 0.057f, 4.88561f + 0.41f, -1.25f + 1.2f + 0.899f));
		model = glm::scale(model, glm::vec3(0.6f, 0.6f, 0.6f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseRoof.Draw(myCustomShader);
	}
}

void LandscapeAndPool(int step)
{
	if (step == 1)
	{
		/// Landscape
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(13.9f, (3.2f - 0.29f), 12.20001f));
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		model = glm::rotate(model, -glm::radians(90.0f), glm::vec3(0, 1, 0));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelLandscape.Draw(depthMapShader);

		/// POOL
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(22.2f, 4.049998f - 0.24f, 23.6f));
		model = glm::scale(model, glm::vec3(0.008f, 0.008f, 0.008f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0, 1, 0));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelPool.Draw(depthMapShader);
	}
	else if (step == 2)
	{
		/// Landscape
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(13.9f, (3.2f - 0.29f), 12.20001f));
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		model = glm::rotate(model, -glm::radians(90.0f), glm::vec3(0, 1, 0));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelLandscape.Draw(myCustomShader);

		/// POOL
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(22.2f, 4.049998f - 0.24f, 23.6f));
		model = glm::scale(model, glm::vec3(0.008f, 0.008f, 0.008f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0, 1, 0));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelPool.Draw(myCustomShader);
	}
}

void Grass(int step)
{
	if (step == 1)
	{
		glm::mat4 translateMatrix = glm::mat4(1.0f);
		glm::mat4 scaleMatrix = glm::mat4(1.0f);

		model = glm::mat4(1.0f);
		translateMatrix = glm::translate(model, glm::vec3(-9.65f, -0.05f, 6.945f));
		scaleMatrix = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));

		model = scaleMatrix*translateMatrix;

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelGrass.Draw(depthMapShader);
	}
	else if (step == 2)
	{
		glm::mat4 translateMatrix = glm::mat4(1.0f);
		glm::mat4 scaleMatrix = glm::mat4(1.0f);

		model = glm::mat4(1.0f);
		translateMatrix = glm::translate(model, glm::vec3(-9.65f, -0.05f, 6.945f));
		scaleMatrix = glm::scale(model, glm::vec3(4.0f, 4.0f, 4.0f));

		model = scaleMatrix*translateMatrix;

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelGrass.Draw(myCustomShader);
	}
}

void HouseXII(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-0.35f, 2.659999f, 0.0f));
		model = glm::scale(model, glm::vec3(0.286f, 0.286f, 0.286f));
		model = glm::translate(model, glm::vec3(49.799812f, 1.5f, 41.899f));
		model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0, 1, 0));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseXII.Draw(depthMapShader);
	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-0.35f, 2.659999f, 0.0f));
		model = glm::scale(model, glm::vec3(0.286f, 0.286f, 0.286f));
		model = glm::translate(model, glm::vec3(49.799812f, 1.5f, 41.899f));
		model = glm::scale(model, glm::vec3(1.5f, 1.5f, 1.5f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0, 1, 0));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseXII.Draw(myCustomShader);
	}
}

void ArchHouse(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(42.935995f, 2.659999f - 0.810f, 1.904033f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelArchHouse.Draw(depthMapShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(42.935995f, 2.659999f - 0.810f, 1.904033f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelArchHouseRoof.Draw(depthMapShader);
	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(42.935995f, 2.659999f - 0.810f, 1.904033f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelArchHouse.Draw(myCustomShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(42.935995f, 2.659999f - 0.810f, 1.904033f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelArchHouseRoof.Draw(myCustomShader);
	}
}

void SimpleHouse(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(59.836002f, 1.702999f, 12.1f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, -glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelSimpleHouse.Draw(depthMapShader);
	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(59.836002f, 1.702999f, 12.1f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, -glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelSimpleHouse.Draw(myCustomShader);
	}
}

void HouseContemporaryDesign(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-33.4f, 3.788f, 24.05f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseContemDesign.Draw(depthMapShader);

		/// HOUSE FOR THE GRASS
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-33.4f, 3.8f, 30.05f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, -glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseForTheGrass.Draw(depthMapShader);

	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-33.4f, 3.788f, 24.05f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseContemDesign.Draw(myCustomShader);

		/// HOUSE FOR THE GRASS
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-33.4f, 3.8f, 30.05f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, -glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseForTheGrass.Draw(myCustomShader);
	}
}

void HouseContemporaryDesignV(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-30.95f, 3.788f, -3.3f));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseContemDesignV0.Draw(depthMapShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-33.95f, 6.388f, -1.55f));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseContemDesignV1.Draw(depthMapShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-33.95f, 5.188f, -1.6f));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseContemDesignV2.Draw(depthMapShader);

	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-30.95f, 3.788f, -3.35f));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseContemDesignV0.Draw(myCustomShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-33.95f, 6.388f, -1.6f));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseContemDesignV1.Draw(myCustomShader); 

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-33.95f, 5.188f, -1.65f));
		model = glm::scale(model, glm::vec3(0.4f, 0.4f, 0.4f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseContemDesignV2.Draw(myCustomShader);
	}
}

void HouseWithFence(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-36.2f, 1.05f, 1.900001f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseWithFence.Draw(depthMapShader);

	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-36.2f, 1.05f, 1.900001f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseWithFence.Draw(myCustomShader);
	}
}

void WoodHouse(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-81.199965f, 3.85f, 2.600030f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelWoodHouse.Draw(depthMapShader);

	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-81.199965f, 3.85f, 2.600030f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelWoodHouse.Draw(myCustomShader);
	}
}

void HouseWithGrassRoof(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(66.6f, 3.15f, -31.6f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, -glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseWithGrassRoof.Draw(depthMapShader);

	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(66.6f, 3.15f, -31.6f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, -glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseWithGrassRoof.Draw(myCustomShader);
	}
}

void ProjHouseContempIX(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(59.8f, 3.3f, 12.1f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, -glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelProjContempHouse.Draw(depthMapShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(59.8f, 3.3f, 12.1f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, -glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelProjContempField.Draw(depthMapShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(59.8f, 3.3f, 12.1f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, -glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelProjContempRoof.Draw(depthMapShader);

	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(59.8f, 3.3f, 12.1f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, -glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelProjContempHouse.Draw(myCustomShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(59.8f, 3.3f, 12.1f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, -glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelProjContempField.Draw(myCustomShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(59.8f, 3.3f, 12.1f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, -glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelProjContempRoof.Draw(myCustomShader);
	}
}

void HouseContempFinal(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-81.2f, 3.35f, 1.95f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseFinal.Draw(depthMapShader);

	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-81.2f, 3.35f, 1.95f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseFinal.Draw(myCustomShader);
	}
}

void HouseComplex(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-56.25f, 1.5f, 12.1f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0, 1, 0));


		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseComplex.Draw(depthMapShader);

	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-56.25f, 1.5f, 12.1f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		model = glm::rotate(model, glm::radians(180.0f), glm::vec3(0, 1, 0));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseComplex.Draw(myCustomShader);
	}
}

void PoolHouse(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-122.749957f, 2.8f, 1.9f));
		model = glm::scale(model, glm::vec3(0.7f, 0.7f, 0.7f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelPoolHouse.Draw(depthMapShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-122.749957f, 2.8f, 1.9f));
		model = glm::scale(model, glm::vec3(0.7f, 0.7f, 0.7f));
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelPalmPoolHouse.Draw(depthMapShader);

	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-122.749957f, 2.8f, 1.9f));
		model = glm::scale(model, glm::vec3(0.7f, 0.7f, 0.7f));
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelPoolHouse.Draw(myCustomShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-122.749957f, 2.8f, 1.9f));
		model = glm::scale(model, glm::vec3(0.7f, 0.7f, 0.7f));
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelPalmPoolHouse.Draw(myCustomShader);
	}
}

void House(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-42.0f, 3.7f, 22.9f));
		model = glm::scale(model, glm::vec3(0.05f, 0.05f, 0.05f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseForTheGrass2.Draw(depthMapShader);

	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-42.0f, 3.7f, 22.9f));
		model = glm::scale(model, glm::vec3(0.05f, 0.05f, 0.05f));
		model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelHouseForTheGrass2.Draw(myCustomShader);
	}
}

void Cloud(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(deltaCloud + 10, 10.0f, -20.0f));
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		normalMatrix = glm::mat3(glm::inverseTranspose(view*model));
		glUniformMatrix3fv(glGetUniformLocation(myCustomShader.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
		myModelCloud.Draw(depthMapShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(deltaCloud - 50, 10.0f, -20.0f));
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		normalMatrix = glm::mat3(glm::inverseTranspose(view*model));
		glUniformMatrix3fv(glGetUniformLocation(myCustomShader.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
		myModelCloud.Draw(depthMapShader);
	}
	else if (step == 2)
	{
		//draw the cloud - first move the cloud
		double currentTimeStamp = glfwGetTime();
		if (cloudDirection == LEFT_TO_RIGHT) {
			deltaCloud = addDelta(currentTimeStamp - lastTimeStampCloud, deltaCloud, 5);
			if (deltaCloud >= rightBackCorner.x) {
				cloudDirection = RIGHT_TO_LEFT;
			}
		}
		if (cloudDirection == RIGHT_TO_LEFT) {
			deltaCloud = subtractDelta(currentTimeStamp - lastTimeStampCloud, deltaCloud, 5);
			if (deltaCloud <= leftFrontCorner.x) {
				cloudDirection = LEFT_TO_RIGHT;
			}
		}
		lastTimeStampCloud = currentTimeStamp;
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(deltaCloud + 10, 10.0f, -20.0f));
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
		normalMatrix = glm::mat3(glm::inverseTranspose(view*model));
		glUniformMatrix3fv(glGetUniformLocation(myCustomShader.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
		myModelCloud.Draw(myCustomShader);

		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(deltaCloud - 50, 10.0f, -20.0f));
		model = glm::scale(model, glm::vec3(0.2f, 0.2f, 0.2f));
		glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
		normalMatrix = glm::mat3(glm::inverseTranspose(view*model));
		glUniformMatrix3fv(glGetUniformLocation(myCustomShader.shaderProgram, "normalMatrix"), 1, GL_FALSE, glm::value_ptr(normalMatrix));
		myModelCloud.Draw(myCustomShader);
	}
}

void Bar(int step)
{
	if (step == 1)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-101.0f, 5.2f, -6.9f));
		model = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));

		glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "model"),
			1,
			GL_FALSE,
			glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelBar.Draw(depthMapShader);

	}
	else if (step == 2)
	{
		model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(-101.0f, 5.2f, -6.9f));
		model = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));
		//model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0));

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "diffuseTexture"), 0);
		myModelBar.Draw(myCustomShader);
	}
}

/// UNIFORMS AND LIGHTS
void setTypeOfLight()
{
	glUniform3f(viewLoc, myCamera.cameraPosition.x, myCamera.cameraPosition.y, myCamera.cameraPosition.z);

	// Set material properties
	// == ==========================
	// Here we set all the uniforms for the 5/6 types of lights we have. We have to set them manually and index 
	// the proper PointLight struct in the array to set each uniform variable. This can be done more code-friendly
	// by defining light types as classes and set their values in there, or by using a more efficient uniform approach
	// by using 'Uniform buffer objects', but that is something we discuss in the 'Advanced GLSL' tutorial.
	// == ==========================
	// Directional light
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.direction"), 2.2f, 10.0f, -1000.0f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.ambient"), 0.2f, 0.2f, 0.2f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.diffuse"), 1.0f, 1.0f, 1.0f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.specular"), 0.5f, 0.5f, 0.5f);

	// SpotLight
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "spotLight.position"), car_coord.x, car_coord.y, car_coord.z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "spotLight.direction"), 0, 0.0f, 1.0f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "spotLight.ambient"), 0.0f, 0.0f, 0.0f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "spotLight.diffuse"), 1.0f, 1.0f, 1.0f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "spotLight.specular"), 1.0f, 1.0f, 1.0f);
	glUniform1f(glGetUniformLocation(myCustomShader.shaderProgram, "spotLight.cutOff"), glm::cos(glm::radians(15.5f)));
	glUniform1f(glGetUniformLocation(myCustomShader.shaderProgram, "spotLight.outerCutOff"), glm::cos(glm::radians(22.0f)));
}

void initUniforms()
{
	myCustomShader.useShaderProgram();

	model = glm::mat4(1.0f);
	modelLoc = glGetUniformLocation(myCustomShader.shaderProgram, "model");
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

	view = myCamera.getViewMatrix();
	viewLoc = glGetUniformLocation(myCustomShader.shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	lightDirMatrixLoc = glGetUniformLocation(myCustomShader.shaderProgram, "lightDirMatrix");

	normalMatrix = glm::mat3(glm::inverseTranspose(view*model));
	normalMatrixLoc = glGetUniformLocation(myCustomShader.shaderProgram, "normalMatrix");
	glUniformMatrix3fv(normalMatrixLoc, 1, GL_FALSE, glm::value_ptr(normalMatrix));

	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	projectionLoc = glGetUniformLocation(myCustomShader.shaderProgram, "projection");
	glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

	//set the light direction (direction towards the light)
	lightDir = glm::vec3(0.0f, 20.0f, 1.0f);
	lightDirLoc = glGetUniformLocation(myCustomShader.shaderProgram, "lightDir");
	glUniform3fv(lightDirLoc, 1, glm::value_ptr(lightDir));

	//set light color
	lightColor = glm::vec3(1.0f, 1.0f, 1.0f); //white light
	lightColorLoc = glGetUniformLocation(myCustomShader.shaderProgram, "lightColor");
	glUniform3fv(lightColorLoc, 1, glm::value_ptr(lightColor));

	lightShader.useShaderProgram();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	myCustomShader.useShaderProgram();
	setTypeOfLight();
}

void setPointLightForLamps()
{
	myCustomShader.useShaderProgram();

	// Directional light
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.direction"), 2.2f, 10.0f, -1000.0f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.ambient"), 0.02f, 0.02f, 0.02f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.diffuse"), 0.5f, 0.5f, 0.5f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.specular"), 0.5f, 0.5f, 0.5f);

	// Point light 1
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[0].position"), pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[0].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[0].diffuse"), 1.8f, 1.8f, 1.8f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[0].specular"), 1.0f, 1.0f, 1.0f);

	// Point light 2
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[1].position"), pointLightPositions[1].x, pointLightPositions[1].y, pointLightPositions[1].z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[1].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[1].diffuse"), 0.8f, 0.8f, 0.8f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[1].specular"), 1.0f, 1.0f, 1.0f);

	// Point light 3
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[2].position"), pointLightPositions[2].x, pointLightPositions[2].y, pointLightPositions[2].z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[2].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[2].diffuse"), 0.8f, 0.8f, 0.8f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[2].specular"), 1.0f, 1.0f, 1.0f);

	// Point light 4
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[3].position"), pointLightPositions[3].x, pointLightPositions[3].y, pointLightPositions[3].z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[3].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[3].diffuse"), 0.8f, 0.8f, 0.8f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[3].specular"), 1.0f, 1.0f, 1.0f);

	// Point light 5
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[4].position"), pointLightPositions[4].x, pointLightPositions[4].y, pointLightPositions[4].z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[4].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[4].diffuse"), 1.8f, 1.8f, 1.8f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[4].specular"), 1.0f, 1.0f, 1.0f);

	// Point light 6
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[5].position"), pointLightPositions[5].x, pointLightPositions[5].y, pointLightPositions[5].z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[5].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[5].diffuse"), 0.8f, 0.8f, 0.8f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[5].specular"), 1.0f, 1.0f, 1.0f);

	// Point light 7
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[6].position"), pointLightPositions[6].x, pointLightPositions[6].y, pointLightPositions[6].z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[6].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[6].diffuse"), 0.8f, 0.8f, 0.8f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[6].specular"), 1.0f, 1.0f, 1.0f);

	// Point light 8
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[7].position"), pointLightPositions[7].x, pointLightPositions[7].y, pointLightPositions[7].z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[7].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[7].diffuse"), 0.8f, 0.8f, 0.8f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[7].specular"), 1.0f, 1.0f, 1.0f);

	//before intersection
	// Point light 9
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[8].position"), pointLightPositions[8].x, pointLightPositions[8].y, pointLightPositions[8].z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[8].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[8].diffuse"), 1.5f, 1.5f, 1.5f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[8].specular"), 1.0f, 1.0f, 1.0f);

	// Point light 10
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[9].position"), pointLightPositions[9].x, pointLightPositions[9].y, pointLightPositions[9].z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[9].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[9].diffuse"), 1.5f, 1.5f, 1.5f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[9].specular"), 1.0f, 1.0f, 1.0f);

	// Point light 11
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[10].position"), pointLightPositions[10].x, pointLightPositions[10].y, pointLightPositions[10].z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[10].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[10].diffuse"), 1.5f, 1.5f, 1.5f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[10].specular"), 1.0f, 1.0f, 1.0f);

	// Point light 12
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[11].position"), pointLightPositions[11].x, pointLightPositions[11].y, pointLightPositions[11].z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[11].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[11].diffuse"), 1.5f, 1.5f, 1.5f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[11].specular"), 1.0f, 1.0f, 1.0f);

	// Point light 13
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[12].position"), pointLightPositions[12].x, pointLightPositions[12].y, pointLightPositions[12].z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[12].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[12].diffuse"), 1.5f, 1.5f, 1.5f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[12].specular"), 1.0f, 1.0f, 1.0f);

	// Point light 14
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[13].position"), pointLightPositions[13].x, pointLightPositions[13].y, pointLightPositions[13].z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[13].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[13].diffuse"), 1.5f, 1.5f, 1.5f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[13].specular"), 1.0f, 1.0f, 1.0f);

	// Point light 15
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[14].position"), pointLightPositions[14].x, pointLightPositions[14].y, pointLightPositions[14].z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[14].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[14].diffuse"), 1.5f, 1.5f, 1.5f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[14].specular"), 1.0f, 1.0f, 1.0f);

	// Point light 16
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[15].position"), pointLightPositions[15].x, pointLightPositions[15].y, pointLightPositions[15].z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[15].ambient"), 0.05f, 0.05f, 0.05f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[15].diffuse"), 1.5f, 1.5f, 1.5f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "pointLights[15].specular"), 1.0f, 1.0f, 1.0f);

	NightSkyBox();
}

/// RENDER SCENE 

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//initialize the model matrix
	model = glm::mat4(1.0f);
	modelLoc = glGetUniformLocation(myCustomShader.shaderProgram, "model");

	processMovement();

	//initialize the view matrix
	glm::mat4 view = myCamera.getViewMatrix();
	//send matrix data to shader
	GLint viewLoc = glGetUniformLocation(myCustomShader.shaderProgram, "view");
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

	///step 1 for rendering
	depthMapShader.useShaderProgram();

	glUniformMatrix4fv(glGetUniformLocation(depthMapShader.shaderProgram, "lightSpaceTrMatrix"),
		1,
		GL_FALSE,
		glm::value_ptr(computeLightSpaceTrMatrix()));

	glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
	glBindFramebuffer(GL_FRAMEBUFFER, shadowMapFBO);
	glClear(GL_DEPTH_BUFFER_BIT);

	HouseAndGarden(1);
	HouseAndBackYard(1);
	HouseXII(1);
	ArchHouse(1);
	LandscapeAndPool(1);
	SimpleHouse(1);
	Grass(1);
	Road(1);
	Intersection(1);
	Lamps(1);
	Trees(1);
	Car(1);
	HouseContemporaryDesign(1);
	HouseContemporaryDesignV(1);
	WoodHouse(1);
	HouseWithFence(1);
	HouseWithGrassRoof(1);
	ProjHouseContempIX(1);
	HouseContempFinal(1);
	HouseComplex(1);
	PoolHouse(1);
	Cloud(1);
	House(1);
	Bar(1);

	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	/// step 2
	myCustomShader.useShaderProgram();

	//send lightSpace matrix to shader
	glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "lightSpaceTrMatrix"),
		1,
		GL_FALSE,
		glm::value_ptr(computeLightSpaceTrMatrix()));

	//send view matrix to shader
	view = myCamera.getViewMatrix();
	glUniformMatrix4fv(glGetUniformLocation(myCustomShader.shaderProgram, "view"),
		1,
		GL_FALSE,
		glm::value_ptr(view));

	////////// light ceva !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//compute light direction transformation matrix
	lightDirMatrix = glm::mat3(glm::inverseTranspose(view));
	//send lightDir matrix data to shader
	glUniformMatrix3fv(lightDirMatrixLoc, 1, GL_FALSE, glm::value_ptr(lightDirMatrix));

	glViewport(0, 0, retina_width, retina_height);
	myCustomShader.useShaderProgram();

	//bind the depth map
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, depthMapTexture);
	glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "shadowMap"), 3);

	HouseAndGarden(2);
	HouseAndBackYard(2);
	HouseXII(2);
	ArchHouse(2);
	LandscapeAndPool(2);
	SimpleHouse(2);
	Grass(2);
	Road(2);
	Intersection(2);
	Lamps(2);
	Trees(2);
	Car(2);
	HouseContemporaryDesign(2);
	HouseContemporaryDesignV(2);
	WoodHouse(2);
	HouseWithFence(2);
	HouseWithGrassRoof(2);
	ProjHouseContempIX(2);
	HouseContempFinal(2);
	HouseComplex(2);
	PoolHouse(2);
	Cloud(2);
	House(2);
	Bar(2);


	//changing between day and night
	// Directional light
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.direction"), 2.2f, 10.0f, -1000.0f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.ambient"), 0.05f + lightIntensity, 0.05f + lightIntensity, 0.05f + lightIntensity);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.diffuse"), 1.0f, 1.0f, 1.0f);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "dirLight.specular"), 0.5f, 0.5f, 0.5f);

	//changing the spotlight
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "spotLight.position"), car_coord.x, car_coord.y, car_coord.z);
	glUniform3f(glGetUniformLocation(myCustomShader.shaderProgram, "spotLight.direction"), 10 * sin(angleForCar), 0.0f, 1.0f + 10 * cos(angleForCar));

	mySkyBox.Draw(skyboxShader, view, projection);
}

void LoadObjects()
{
	myModelGardenFirstHouse = gps::Model3D("objects\\HouseContempXV_LANDSCAPE.obj");
	myModelFirstHouse = gps::Model3D("objects\\Proj_HouseContemporaryXV_EXPORT.obj");
	myModelRoad = gps::Model3D("objects\\road1.obj");
	myModelIntersection = gps::Model3D("objects\\road3.obj");
	myModelTree = gps::Model3D("objects\\Tree.obj");
	myModelLandscape = gps::Model3D("objects\\LANDSCAPE.obj");
	myModelPool = gps::Model3D("objects\\SwimmingPool.obj");
	myModelBackYard = gps::Model3D("objects\\House_ContemporaryVI_Foundation-Base-Landscape.obj");
	myModelSimpleHouse = gps::Model3D("objects\\Proj_IndoorSwimmingPool.obj");
	myModelHouseBackYard = gps::Model3D("objects\\House_ContemporaryVI_FloorElevation-Fixtures-Furn-Access.obj");
	myModelHouseRoof = gps::Model3D("objects\\House_ContemporaryVI_Roofs-House_Garage.obj");
	myModelArchHouse = gps::Model3D("objects\\Arch_Bldg_AdobeHouseComplex_EXPORT_HOUSES-LANDSCAPE.obj");
	myModelArchHouseRoof = gps::Model3D("objects\\Arch_Bldg_AdobeHouseComplex_EXPORT_ROOF.obj");
	myModelHouseXII = gps::Model3D("objects\\House_ContemporaryXII.obj");
	myModelLamp = gps::Model3D("objects\\street_lamp.obj");
	myModelLamp11 = gps::Model3D("objects\\street_lamp(blender).obj");
	myModelLamp12 = gps::Model3D("objects\\street_lamp(poser).obj");
	myModelCarChass = gps::Model3D("objects\\tsupra.obj");
	myModelHouseContemDesign = gps::Model3D("objects\\House_ContemporaryDesign.obj");
	myModelHouseContemDesignV0 = gps::Model3D("objects\\MainFloor_FoundationComponent_1.obj");
	myModelHouseContemDesignV1 = gps::Model3D("objects\\RoofEntire_1.obj");
	myModelHouseContemDesignV2 = gps::Model3D("objects\\SecondFloor_1.obj");
	myModelHouseForTheGrass = gps::Model3D("objects\\HOUSE_ROOF.obj");
	myModelHouseWithFence = gps::Model3D("objects\\House22.obj");
	myModelWoodHouse = gps::Model3D("objects\\House_wAtrium01.obj");
	myModelHouseWithGrassRoof = gps::Model3D("objects\\ArchProj_HouseContemporaryX.obj");
	myModelProjContempHouse = gps::Model3D("objects\\Proj_House_ContemporaryIX_MAIN-HOUSE.obj");
	myModelProjContempField = gps::Model3D("objects\\Proj_House_ContemporaryIX.obj");
	myModelProjContempRoof = gps::Model3D("objects\\Proj_House_ContemporaryIX_ROOF.obj");
	myModelHouseFinal = gps::Model3D("objects\\House_ContemporaryDesign_FINAL.obj");
	myModelHouseComplex = gps::Model3D("objects\\House23.obj");
	myModelPoolHouse = gps::Model3D("objects\\PoolGuestHouse.obj");
	myModelPalmPoolHouse = gps::Model3D("objects\\Plant_PalmTree.obj");
	myModelCloud = gps::Model3D("objects\\cloud.obj");

	myModelHouseForTheGrass2 = gps::Model3D("objects\\house02.obj");
	myModelBar = gps::Model3D("objects\\The_bar.obj");
	myModelGrass = gps::Model3D("objects\\grassBlender.obj");
}

void DaySkyBox()
{
	std::vector<const GLchar*> faces;
	faces.push_back("textures/skybox/hills_rt.tga");
	faces.push_back("textures/skybox/hills_lf.tga");
	faces.push_back("textures/skybox/hills_up.tga");
	faces.push_back("textures/skybox/hills_dn.tga");
	faces.push_back("textures/skybox/hills_bk.tga");
	faces.push_back("textures/skybox/hills_ft.tga");

	skyboxShader.loadShader("shaders/skyboxShader.vert", "shaders/skyboxShader.frag");
	skyboxShader.useShaderProgram();

	view = myCamera.getViewMatrix();

	glUniformMatrix4fv(glGetUniformLocation(skyboxShader.shaderProgram, "view"), 1, GL_FALSE,
		glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(skyboxShader.shaderProgram, "projection"), 1, GL_FALSE,
		glm::value_ptr(projection));


	glActiveTexture(GL_TEXTURE3);
	glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "skybox"), 3);
	glBindTexture(GL_TEXTURE_CUBE_MAP, mySkyBox.GetTextureId());

	mySkyBox.Load(faces);
}

void NightSkyBox()
{
	std::vector<const GLchar*> faces;
	faces.push_back("textures/night/nightsky_rt.tga");
	faces.push_back("textures/night/nightsky_lf.tga");
	faces.push_back("textures/night/nightsky_up.tga");
	faces.push_back("textures/night/nightsky_dn.tga");
	faces.push_back("textures/night/nightsky_bk.tga");
	faces.push_back("textures/night/nightsky_ft.tga");

	skyboxShader.loadShader("shaders/skyboxShader.vert", "shaders/skyboxShader.frag");
	skyboxShader.useShaderProgram();

	view = myCamera.getViewMatrix();

	glUniformMatrix4fv(glGetUniformLocation(skyboxShader.shaderProgram, "view"), 1, GL_FALSE,
		glm::value_ptr(view));
	projection = glm::perspective(glm::radians(45.0f), (float)retina_width / (float)retina_height, 0.1f, 1000.0f);
	glUniformMatrix4fv(glGetUniformLocation(skyboxShader.shaderProgram, "projection"), 1, GL_FALSE,
		glm::value_ptr(projection));


	glActiveTexture(GL_TEXTURE3);
	glUniform1i(glGetUniformLocation(myCustomShader.shaderProgram, "skybox"), 3);
	glBindTexture(GL_TEXTURE_CUBE_MAP, mySkyBox.GetTextureId());

	mySkyBox.Load(faces);
}

int main(int argc, const char * argv[]) {

	initOpenGLWindow();
	initOpenGLState();
	initFBOs();
	initShaders();
	initUniforms();

	DaySkyBox();
	LoadObjects();

	while (!glfwWindowShouldClose(glWindow)) {
		renderScene();
		glfwPollEvents();
		do_movement();
		glfwSwapBuffers(glWindow);
	}

	//close GL context and any other GLFW resources
	glfwTerminate();
	return 0;
}