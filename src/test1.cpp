
#include <queue>
#include <iostream>
#include <cassert>

#include <string>

#include <exception>
#include <string>


#include <sstream>
#include <stdexcept>
#include <iostream>
#include <limits>
#include <queue>


#include <queue>

#include <string>

#include <utility> 


#include <stdexcept>
#include <sstream>

#include <mutex>

#include <string>
#include <vector>


#include <queue>
#include <iostream>
#include <cassert>
#include "gtest/gtest.h"
#include <string>

#include <exception>
#include <string>


#include <limits>
#include <queue>

#include <mutex>

#include <string>
#include <vector>



#include <vector>
#include <mutex>


#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

std::vector<ListNode*> mergeKLists(std::vector<ListNode*>& lists) {
    if (lists.empty()) {
        return {};
    }
    if (lists.size() == 1) {
        return lists;
    }
    int mid = lists.size() / 2;
    std::vector<ListNode*> sub1_lists(lists.begin(), lists.begin() + mid);
    std::vector<ListNode*> sub2_lists(lists.begin() + mid, lists.end());
    std::vector<ListNode*> l1 = mergeKLists(sub1_lists);
    std::vector<ListNode*> l2 = mergeKLists(sub2_lists);
    return {mergeTwoLists(l1[0], l2[0])};
}

// Helper function to create a linked list from an array.
ListNode* createLinkedList(int arr[], int size) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < size; ++i) {
        ListNode* node = new ListNode(arr[i]);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

// Helper function to convert a linked list to an array.
int* linkedListToArray(ListNode* head) {
    int size = 0;
    ListNode* curr = head;
    while (curr != nullptr) {
        ++size;
        curr = curr->next;
    }

    int* arr = new int[size];
    curr = head;
    for (int i = 0; i < size; ++i) {
        arr[i] = curr->val;
        curr = curr->next;
    }

    return arr;
}

// Helper function to compare two linked lists.
bool compareLinkedLists(ListNode* l1, ListNode* l2) {
    int* arr1 = linkedListToArray(l1);
    int* arr2 = linkedListToArray(l2);

    int size1 = 0;
    while (arr1[size1] != -1) {
        ++size1;
    }

    int size2 = 0;
    while (arr2[size2] != -1) {
        ++size2;
    }

    if (size1 != size2) {
        delete[] arr1;
        delete[] arr2;
        return false;
    }

    for (int i = 0; i < size1; ++i) {
        if (arr1[i] != arr2[i]) {
            delete[] arr1;
            delete[] arr2;
            return false;
        }
    }

    delete[] arr1;
    delete[] arr2;
    return true;
}

// Unit tests for mergeKLists() function.
TEST(MergeKListsTest, EmptyLists) {
    std::vector<ListNode*> lists;

    std::vector<ListNode*> result = mergeKLists(lists);

    EXPECT_EQ(result.size(), 0);
}

TEST(MergeKListsTest, SingleList) {
    std::vector<ListNode*> lists;
    int arr1[] = {1, 2, 3};
    ListNode* list1 = createLinkedList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    lists.push_back(list1);

    std::vector<ListNode*> result = mergeKLists(lists);

    EXPECT_EQ(result.size(), 1);
    EXPECT_TRUE(compareLinkedLists(result[0], list1));
}

TEST(MergeKListsTest, MultipleLists) {
    std::vector<ListNode*> lists;
    int arr1[] = {1, 3, 5};
    ListNode* list1 = createLinkedList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    int arr2[] = {2, 4, 6};
    ListNode* list2 = createLinkedList(arr2, sizeof(arr2) / sizeof(arr2[0]));
    lists.push_back(list1);
    lists.push_back(list2);

    std::vector<ListNode*> result = mergeKLists(lists);

    EXPECT_EQ(result.size(), 1);
    int expectedArr[] = {1, 2, 3, 4, 5, 6};
    ListNode* expectedList = createLinkedList(expectedArr, sizeof(expectedArr) / sizeof(expectedArr[0]));
    EXPECT_TRUE(compareLinkedLists(result[0], expectedList));

    delete expectedList;
}

TEST(MergeKListsTest, MultipleLevels) {
    std::vector<ListNode*> lists;
    int arr1[] = {1, 3, 5};
    ListNode* list1 = createLinkedList(arr1, sizeof(arr1) / sizeof(arr1[0]));
    int arr2[] = {2, 4, 6};
    ListNode* list2 = createLinkedList(arr2, sizeof(arr2) / sizeof(arr2[0]));
    int arr3[] = {7, 8, 9};
    ListNode* list3 = createLinkedList(arr3, sizeof(arr3) / sizeof(arr3[0]));
    lists.push_back(list1);
    lists.push_back(list2);
    lists.push_back(list3);

    std::vector<ListNode*> result = mergeKLists(lists);

    EXPECT_EQ(result.size(), 1);
    int expectedArr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode* expectedList = createLinkedList(expectedArr, sizeof(expectedArr) / sizeof(expectedArr[0]));
    EXPECT_TRUE(compareLinkedLists(result[0], expectedList));

    delete expectedList;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




