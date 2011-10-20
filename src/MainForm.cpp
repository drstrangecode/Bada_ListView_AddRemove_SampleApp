#include "MainForm.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::App;

MainForm::MainForm(void) {
}

MainForm::~MainForm(void) {
}

bool MainForm::Initialize() {
    // Construct an XML form
    Construct(L"IDF_MAINFORM");

    return true;
}

result MainForm::OnInitializing(void) {
    result r = E_SUCCESS;

    pListView = static_cast<ListView *> (GetControl(L"IDC_LISTVIEW"));
    pListView->SetItemProvider(*this);
    pListView->AddListViewItemEventListener(*this);
    pListView->SetSweepEnabled(false);

    GetFooter()->AddActionEventListener(*this);

    return r;
}

result MainForm::OnTerminating(void) {
    result r = E_SUCCESS;

    return r;
}

// IActionEventListener
void MainForm::OnActionPerformed(const Control & source, int actionId) {
	switch (actionId) {
	case ACTION_ID_ADD_ITEM:
		pListView->RefreshList(pListView->GetItemCount(), LIST_REFRESH_TYPE_ITEM_ADD);
		break;
	case ACTION_ID_DELETE_LAST_ITEM:
		pListView->RefreshList(pListView->GetItemCount()-1, LIST_REFRESH_TYPE_ITEM_REMOVE);
		break;
	}
}

// IListViewItemEventListener
void MainForm::OnListViewContextItemStateChanged(Osp::Ui::Controls::ListView &listView,
                                              int itemIndex,
                                              int elementId,
                                              Osp::Ui::Controls::ListContextItemStatus state) {
}

void MainForm::OnListViewItemStateChanged(Osp::Ui::Controls::ListView &listView,
                                       int itemIndex,
                                       int elementId,
                                       Osp::Ui::Controls::ListItemStatus state) {
}

void MainForm::OnListViewItemSwept(Osp::Ui::Controls::ListView &listView,
                                int itemIndex,
                                Osp::Ui::Controls::SweepDirection direction) {
}

void MainForm::OnListViewItemLongPressed(Osp::Ui::Controls::ListView & listView,
                                             int  itemIndex,
                                             int  elementId,
                                             bool & invokeListViewItemCallback) {
}

// IListViewItemProvider
int MainForm::GetItemCount() {
    return 0;
}

Osp::Ui::Controls::ListItemBase* MainForm::CreateItem(int itemIndex, int itemWidth) {

    String text;
    text.Format(100, L"SimpleItem #%d", itemIndex);

	AppResource * res = Application::GetInstance()->GetAppResource();
	Bitmap * pBitmap = res->GetBitmapN(L"itemicon.png",
			                           BITMAP_PIXEL_FORMAT_ARGB8888);

	SimpleItem * pItem = new SimpleItem();

	pItem->Construct(Dimension(itemWidth, 100), LIST_ANNEX_STYLE_DETAILED);
	pItem->SetElement(text, pBitmap);

	delete pBitmap;

    return pItem;

}

bool MainForm::DeleteItem(int itemIndex,
                       Osp::Ui::Controls::ListItemBase* pItem,
                       int itemWidth) {
	/* pItem is not deleted here */
	return false;
}
