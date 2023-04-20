#include "Physical.h"

void Physical::AddToRenderList(RenderList& list)
{
	list.Rects.push_back(m_Body);
}

