/****************************************************************************
**
** Copyright (C) 2015-2016 Oleg Shparber
** Copyright (C) 2013-2014 Jerzy Kozera
** Contact: https://go.zealdocs.org/l/contact
**
** This file is part of Zeal.
**
** Zeal is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** Zeal is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Zeal. If not, see <https://www.gnu.org/licenses/>.
**
****************************************************************************/

#ifndef ZEAL_WIDGETUI_SEARCHEDIT_H
#define ZEAL_WIDGETUI_SEARCHEDIT_H

#include <QLineEdit>

class QCompleter;
class QEvent;
class QLabel;

namespace Zeal {
namespace WidgetUi {

class SearchEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit SearchEdit(QWidget *parent = nullptr);

    void setHideWindowFunc(std::function<void()>);
    void clearQuery();
    void selectQuery();
    void setCompletions(const QStringList &completions);

protected:
    bool event(QEvent *event) override;
    void focusInEvent(QFocusEvent *event) override;

private slots:
    void showCompletions(const QString &text);

private:
    QString currentCompletion(const QString &text) const;
    int queryStart() const;

    QCompleter *m_prefixCompleter = nullptr;
    QLabel *m_completionLabel = nullptr;
    std::function<void()> hide_window_ = []() {};
};

} // namespace WidgetUi
} // namespace Zeal

#endif // ZEAL_WIDGETUI_SEARCHEDIT_H
