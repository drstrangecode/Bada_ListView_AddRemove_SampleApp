#ifndef _MAINFORM_H_
#define _MAINFORM_H_

#include <FBase.h>
#include <FUi.h>
#include <FGraphics.h>
#include <FApp.h>

class MainForm : public Osp::Ui::Controls::Form,
        public Osp::Ui::IActionEventListener,
        public Osp::Ui::Controls::IListViewItemEventListener,
        public Osp::Ui::Controls::IListViewItemProvider {

        // Construction
    public:
		MainForm(void);
        virtual ~MainForm(void);
        bool Initialize(void);

        static const int ID_FORMAT_STRING = 100;
        static const int ID_FORMAT_BITMAP = 101;

        static const int ACTION_ID_ADD_ITEM = 101;
        static const int ACTION_ID_DELETE_LAST_ITEM = 102;

        // Implementation
    protected:
        Osp::Ui::Controls::ListView *pListView;

    public:
        virtual result OnInitializing(void);
        virtual result OnTerminating(void);

        // IActionEventListener
        virtual void OnActionPerformed(const Osp::Ui::Control & source, int actionId);

        // IListViewItemEventListener
        virtual void
        OnListViewContextItemStateChanged(Osp::Ui::Controls::ListView &listView,
                                                 int itemIndex,
                                                 int elementId,
                                                 Osp::Ui::Controls::ListContextItemStatus state);
        virtual void
        OnListViewItemStateChanged(Osp::Ui::Controls::ListView &listView,
                                          int itemIndex,
                                          int elementId,
                                          Osp::Ui::Controls::ListItemStatus state);

        virtual void OnListViewItemSwept(Osp::Ui::Controls::ListView &listView,
                                                int itemIndex,
                                                Osp::Ui::Controls::SweepDirection direction);

        virtual void OnListViewItemLongPressed(Osp::Ui::Controls::ListView & listView,
                                                      int  itemIndex,
                                                      int  elementId,
                                                      bool & invokeListViewItemCallback);

        // IListViewItemProvider
        virtual int GetItemCount();
        virtual Osp::Ui::Controls::ListItemBase* CreateItem(int itemIndex,
                                                            int itemWidth);
        virtual bool DeleteItem(int itemIndex,
                                Osp::Ui::Controls::ListItemBase* pItem,
                                int itemWidth);
};

#endif	//_MAINFORM_H_
