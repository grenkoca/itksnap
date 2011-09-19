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

#ifndef ZOOMINSPECTOR_H
#define ZOOMINSPECTOR_H

#include <QWidget>
#include <SNAPCommon.h>

class GlobalUIModel;

namespace Ui {
    class ZoomInspector;
}

class ZoomInspector : public QWidget
{
  Q_OBJECT

public:
  explicit ZoomInspector(QWidget *parent = 0);
  ~ZoomInspector();

  irisGetMacro(Model, GlobalUIModel *)

  void SetModel(GlobalUIModel *model);

private slots:

  void on_chkLinkedZoom_stateChanged(int arg1);
  void on_btnResetViews_clicked();

private:
  Ui::ZoomInspector *ui;

  GlobalUIModel *m_Model;
};

#endif // ZOOMINSPECTOR_H