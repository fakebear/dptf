/******************************************************************************
** Copyright (c) 2014 Intel Corporation All Rights Reserved
**
** Licensed under the Apache License, Version 2.0 (the "License"); you may not
** use this file except in compliance with the License.
**
** You may obtain a copy of the License at
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
** WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**
** See the License for the specific language governing permissions and
** limitations under the License.
**
******************************************************************************/

#include "DisplayControlSet.h"
#include "XmlNode.h"

DisplayControlSet::DisplayControlSet(const std::vector<DisplayControl>& displayControl) :
    m_displayControl(displayControl)
{
}

UIntN DisplayControlSet::getCount(void) const
{
    return static_cast<UIntN>(m_displayControl.size());
}

const DisplayControl& DisplayControlSet::operator[](UIntN index) const
{
    return m_displayControl.at(index);
}

Bool DisplayControlSet::operator==(const DisplayControlSet& rhs) const
{
    return (m_displayControl == rhs.m_displayControl);
}

Bool DisplayControlSet::operator!=(const DisplayControlSet& rhs) const
{
    return !(*this == rhs);
}

UIntN DisplayControlSet::getControlIndex(Percentage brightness)
{
    for (UIntN i = 0; i < m_displayControl.size(); i++)
    {
        if (m_displayControl.at(i).getBrightness() == brightness)
        {
            return i;
        }
    }

    throw dptf_exception("Item not found in set");
}

XmlNode* DisplayControlSet::getXml(void)
{
    XmlNode* root = XmlNode::createWrapperElement("display_control_set");

    for (UIntN i = 0; i < m_displayControl.size(); i++)
    {
        root->addChild(m_displayControl[i].getXml());
    }

    return root;
}