/*
    This file is part of Helio Workstation.

    Helio is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Helio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helio. If not, see <http://www.gnu.org/licenses/>.
*/

//[Headers]
#include "Common.h"
//[/Headers]

#include "LabeledSettingsWrapper.h"

//[MiscUserDefs]
//[/MiscUserDefs]

LabeledSettingsWrapper::LabeledSettingsWrapper(Component *targetComponent, const String &title)
{
    addAndMakeVisible (panel = new PanelA());
    addAndMakeVisible (titleLabel = new Label (String(),
                                               TRANS("...")));
    titleLabel->setFont (Font (Font::getDefaultSerifFontName(), 21.00f, Font::plain).withTypefaceStyle ("Regular"));
    titleLabel->setJustificationType (Justification::centredLeft);
    titleLabel->setEditable (false, false, false);
    titleLabel->setColour (TextEditor::textColourId, Colours::black);
    titleLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (targetBounds = new Component());


    //[UserPreSize]
    this->targetBounds->setVisible(false);
    //[/UserPreSize]

    setSize (600, 400);

    //[Constructor]
    this->showNonOwned(targetComponent, title);
    //[/Constructor]
}

LabeledSettingsWrapper::~LabeledSettingsWrapper()
{
    //[Destructor_pre]
    //[/Destructor_pre]

    panel = nullptr;
    titleLabel = nullptr;
    targetBounds = nullptr;

    //[Destructor]
    //[/Destructor]
}

void LabeledSettingsWrapper::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void LabeledSettingsWrapper::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    panel->setBounds (5, 40, getWidth() - 10, getHeight() - 48);
    titleLabel->setBounds (8, 8, 576, 26);
    targetBounds->setBounds (12, 48, getWidth() - 24, getHeight() - 64);
    //[UserResized] Add your own custom resize handling here..
    if (this->target != nullptr)
    {
        this->target->setBounds(this->targetBounds->getBounds());
    }
    //[/UserResized]
}


//[MiscUserCode]
void LabeledSettingsWrapper::showNonOwned(Component *targetComponent, const String &title)
{
    if (this->target != nullptr)
    {
        this->removeChildComponent(this->target);
    }

    this->target = targetComponent;
    this->addAndMakeVisible(this->target);

    const int staticSpaceDelta = this->getHeight() - this->targetBounds->getHeight();
    this->setSize(this->getWidth(), this->target->getHeight() + staticSpaceDelta);

    this->titleLabel->setText(title, dontSendNotification);
}
//[/MiscUserCode]

#if 0
/*
BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="LabeledSettingsWrapper" template="../../Template"
                 componentName="" parentClasses="public Component" constructorParams="Component *targetComponent, const String &amp;title"
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="" id="563306a3a7769fb" memberName="panel" virtualName=""
             explicitFocusOrder="0" pos="5 40 10M 48M" sourceFile="../Themes/PanelA.cpp"
             constructorParams=""/>
  <LABEL name="" id="9f16871b637bd1bd" memberName="titleLabel" virtualName=""
         explicitFocusOrder="0" pos="8 8 576 26" edTextCol="ff000000"
         edBkgCol="0" labelText="..." editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default serif font" fontsize="21"
         kerning="0" bold="0" italic="0" justification="33"/>
  <GENERICCOMPONENT name="" id="a0e12bb33465d20d" memberName="targetBounds" virtualName=""
                    explicitFocusOrder="0" pos="12 48 24M 64M" class="Component"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
