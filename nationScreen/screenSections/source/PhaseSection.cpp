#include "../header/PhaseSection.h"

PhaseSection::PhaseSection(Pen* p0, Pen* p1, FontFamily* ff, StringFormat* sf0, StringFormat* sf1,
	Font* f0, Font* f1, SolidBrush* b0, SolidBrush* b1, SolidBrush* b2)
	:Section(p0, p1, ff, sf0, sf1, f0, f1, b0, b1, b2)
{
	phaseFrame = new AABox("Turn Phase");

	resBox = new AABox("Research");
	purchBox = new AABox("Purchase");
	cmBox = new AABox("Combat Move");
	ccBox = new AABox("Conduct Combat");
	ncBox = new AABox("Noncombat Move");
	mobBox = new AABox("Mobilize Units");
	incBox = new AABox("Collect Income");

	phaseFont = NULL;

	resBrushP = NULL;
	purchBrushP = NULL;
	cmBrushP = NULL;
	ccBrushP = NULL;
	ncBrushP = NULL;
	mobBrushP = NULL;
	incBrushP = NULL;

	resBrushS = NULL;
	purchBrushS = NULL;
	cmBrushS = NULL;
	ccBrushS = NULL;
	ncBrushS = NULL;
	mobBrushS = NULL;
	incBrushS = NULL;
}

PhaseSection::~PhaseSection()
{
	delete phaseFrame;

	delete resBox;
	delete purchBox;
	delete cmBox;
	delete ccBox;
	delete ncBox;
	delete mobBox;
	delete incBox;
}

void PhaseSection::configurePhaseBox(RectF& frame, int layer)
{
	phaseFrame->config(frame, layer);

	resBox->config(phaseFrame->box, layer + 1);
	resBox->box.Height = phaseFrame->box.Height / 7;
	purchBox->config(resBox->box, layer + 1);
	purchBox->box.Y += resBox->box.Height;
	cmBox->config(purchBox->box, layer + 1);
	cmBox->box.Y += purchBox->box.Height;
	ccBox->config(cmBox->box, layer + 1);
	ccBox->box.Y += cmBox->box.Height;
	ncBox->config(ccBox->box, layer + 1);
	ncBox->box.Y += ccBox->box.Height;
	mobBox->config(ncBox->box, layer + 1);
	mobBox->box.Y += ncBox->box.Height;
	incBox->config(mobBox->box, layer + 1);
	incBox->box.Y += mobBox->box.Height;
	incBox->box.Height = phaseFrame->box.GetBottom() - incBox->box.Y;
}

void PhaseSection::configDrawTools(Font* f0)
{
	phaseFont = f0;
}

void PhaseSection::configBrushes0(SolidBrush* b0, SolidBrush* b1, SolidBrush* b2, SolidBrush* b3, SolidBrush* b4, SolidBrush* b5, SolidBrush* b6)
{
	resBrushP = b0;
	purchBrushP = b1;
	cmBrushP = b2;
	ccBrushP = b3;
	ncBrushP = b4;
	mobBrushP = b5;
	incBrushP = b6;
}

void PhaseSection::configBrushes1(SolidBrush* b0, SolidBrush* b1, SolidBrush* b2, SolidBrush* b3, SolidBrush* b4, SolidBrush* b5, SolidBrush* b6)
{
	resBrushS = b0;
	purchBrushS = b1;
	cmBrushS = b2;
	ccBrushS = b3;
	ncBrushS = b4;
	mobBrushS = b5;
	incBrushS = b6;
}

void PhaseSection::drawPhaseBox(Graphics* graphics, int phase, bool res, bool dbg_boundbox, bool dbg_sections, int layers)
{
	if (dbg_boundbox) // Show bounding box
		pen = borderPen;
	else
		pen = borderlessPen;

	if (dbg_sections) // Show box names
	{
		phaseFrame->drawFrameFill(graphics, borderPen, baseTitleFont, centerFormat, textBrush, paneBrush, layers);

		resBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		purchBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		cmBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		ccBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		ncBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		mobBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
		incBox->drawFrameFill(graphics, borderPen, baseTextFont, centerFormat, textBrush, backBrush, layers);
	}
	else // Actual graphics
	{
		if (res)
			resBox->drawFrameFill(graphics, pen, phaseFont, centerFormat, textBrush, (phase == RS_PHASE ? resBrushP : resBrushS), layers);
		else
			resBox->drawBox(graphics, pen, phaseFont, centerFormat, textBrush, resBrushS, L"", layers);
		purchBox->drawFrameFill(graphics, pen, phaseFont, centerFormat, textBrush, (phase == PR_PHASE ? purchBrushP : purchBrushS), layers);
		cmBox->drawFrameFill(graphics, pen, phaseFont, centerFormat, textBrush, (phase == CM_PHASE ? cmBrushP : cmBrushS), layers);
		ccBox->drawFrameFill(graphics, pen, phaseFont, centerFormat, textBrush, (phase == CC_PHASE ? ccBrushP : ccBrushS), layers);
		ncBox->drawFrameFill(graphics, pen, phaseFont, centerFormat, textBrush, (phase == NC_PHASE ? ncBrushP : ncBrushS), layers);
		mobBox->drawFrameFill(graphics, pen, phaseFont, centerFormat, textBrush, (phase == MN_PHASE ? mobBrushP : mobBrushS), layers);
		incBox->drawFrameFill(graphics, pen, phaseFont, centerFormat, textBrush, (phase == CI_PHASE ? incBrushP : incBrushS), layers);
	}
}

REAL PhaseSection::getBoxEdge(int whichBox, int edge)
{
	AABox* tmp = phaseFrame;

	switch (whichBox)
	{
	case RS_PHASE:
		tmp = resBox;
		break;
	case PR_PHASE:
		tmp = purchBox;
		break;
	case CM_PHASE:
		tmp = cmBox;
		break;
	case CC_PHASE:
		tmp = ccBox;
		break;
	case NC_PHASE:
		tmp = ncBox;
		break;
	case MN_PHASE:
		tmp = mobBox;
		break;
	case CI_PHASE:
		tmp = incBox;
		break;
	default:
		tmp = phaseFrame;
		break;
	}

	switch (edge)
	{
	case BOX_LEFT:
		return tmp->box.GetLeft();
		break;
	case BOX_RIGHT:
		return tmp->box.GetRight();
		break;
	case BOX_TOP:
		return tmp->box.GetTop();
		break;
	case BOX_BOTTOM:
		return tmp->box.GetBottom();
		break;
	case BOX_WIDTH:
		return tmp->box.Width;
		break;
	case BOX_HEIGHT:
		return tmp->box.Height;
		break;
	default:
		return 0;
		break;
	}
}