#include "Renderer.h"
#include <GL\glew.h>
#include "Math.h"

void Renderer::Render(Entity entity, Shader shader)
{
	TexturedModel texturedModel = entity.GetTexturedModel();
	Model model = texturedModel.GetModel();
	ModelTexture texture = texturedModel.GetTexture();

	glBindVertexArray(model.GetVaoID());

	glm::mat4 transformationMatrix = Math::CreateTransformationMatrix(entity.GetPosition(), entity.GetRotX(), entity.GetRotY(), entity.GetRotZ(), entity.GetScale());
	shader.LoadTransformationMatrix(transformationMatrix);
	shader.LoadSpecularVariables(texture.GetReflectivity(), texture.GetDamper());

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glDrawElements(GL_TRIANGLES, model.GetVertexCount(), GL_UNSIGNED_INT, nullptr);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

}
