struct ListNode {
  int val;
  struct ListNode *next;
} 

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {

  struct ListNode *l3 = (struct ListNode *)malloc(sizeof(struct ListNode));
  struct ListNode *head = l3;
  l3->val = 0;
  l3->next = NULL;

  if (l3 == NULL) {
    printf("Allocation Failed");
    return NULL;
  }

  int carry = 0;

  while (l2 || l1 || carry) {
    int sum = carry;
    if (l1) {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      sum += l2->val;
      l2 = l2->next;
    }
    carry = sum / 10;
    sum = sum % 10;

    l3->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l3 = l3->next;   // Point towards next node in the LInked List
    l3->val = sum;   // place sum in val
    l3->next = NULL; // reset next node
  }

  struct ListNode *result = head->next;
  free(head);
  return result;
}