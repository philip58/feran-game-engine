#pragma once

namespace fr
{
	class ShaderImplementation
	{
	public:	
		virtual void Bind() = 0;

		virtual ~ShaderImplementation() {};
	};
}