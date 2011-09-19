/*=========================================================================

  Program:   ITK-SNAP
  Module:    $RCSfile: Filename.cxx,v $
  Language:  C++
  Date:      $Date: 2010/10/18 11:25:44 $
  Version:   $Revision: 1.12 $
  Copyright (c) 2011 Paul A. Yushkevich

  This file is part of ITK-SNAP

  ITK-SNAP is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

=========================================================================*/

#include "ZoomInspector.h"
#include "ui_ZoomInspector.h"

#include "GlobalUIModel.h"
#include "SliceWindowCoordinator.h"
#include "QtWidgetActivator.h"
#include "QtDoubleSpinboxCoupling.h"
#include <vnl/vnl_math.h>


ZoomInspector::ZoomInspector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ZoomInspector)
{
  ui->setupUi(this);
}

ZoomInspector::~ZoomInspector()
{
  delete ui;
}


void ZoomInspector::SetModel(GlobalUIModel *model)
{
  // Set the model
  m_Model = model;

  /*
  AddListener(model->GetSliceCoordinator(),
              SliceWindowCoordinator::LinkedZoomUpdateEvent(),
              this, &ZoomPanModeToolbox::OnZoomChangeInSliceView);
  */

  new QtWidgetActivator(ui->inZoom,
                        new SNAPUIFlag(model, UIF_LINKED_ZOOM));

  // Couple zoom widget to the linked zoom level
  new QtDoubleSpinboxCoupling(
        ui->inZoom,
        model->GetSliceCoordinator()->GetCommonZoomFactorModel());
}

void ZoomInspector::on_chkLinkedZoom_stateChanged(int state)
{
  m_Model->GetSliceCoordinator()->SetLinkedZoom(state == Qt::Checked);
}

void ZoomInspector::on_btnResetViews_clicked()
{
  m_Model->GetSliceCoordinator()->ResetViewToFitInAllWindows();
}