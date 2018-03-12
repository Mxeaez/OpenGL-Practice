#include "Renderer.h"
#include <GL\glew.h>
#include "Math.h"

void Renderer::Render(Entity entity, Shader shader)
{
	Model model = entity.GetTexturedModel().GetModel();

	glBindVertexArray(model.GetVaoID());

	glm::mat4 transformationMatrix = Math::CreateTransformationMatrix(entity.GetPosition(), entity.GetRotX(), entity.GetRotY(), entity.GetRotZ(), entity.GetScale());
	shader.LoadTransformationMatrix(transformationMatrix);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glDrawElements(GL_TRIANGLES, model.GetVertexCount(), GL_UNSIGNED_INT, nullptr);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

}
