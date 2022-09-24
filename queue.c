/*
 * Developed by R. E. Bryant, 2017
 * Extended to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{ //if q is null return null if not set first and last element to null and size to 0
      queue_t*q=malloc(sizeof(queue_t));

      if(q==NULL)
      return NULL;//no allocate space

      q->head=NULL;
      q->tail=NULL;
      q->size=0;

      return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if(q!=NULL)//q cannot b null for free space
    {
      while(q->head!=NULL)
      {
        list_ele_t*curr= q->head;//temporary q to head
        q->head=q->head->next;//same as node.next
        curr->next=NULL; //next lines frees all storage used by queue

        free(curr->value);
        free(curr);
        //curr=NULL;
      }

      q->tail=NULL;//updates
      q->size=0;
      free(q);
    }
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
  list_ele_t*curr;

  if(q==NULL)//queue is empty return false, s cannot be inserted
  return false;

  curr=malloc(sizeof(list_ele_t)); //store s

  if(curr==NULL)
  return false;//mem allocation is good if not return false

  curr->value=(char*)malloc(strlen(s)+1);//allocate mem for value of curr

  if(curr->value==NULL)//above line not good, delete mem; therefore return false
  {
  free(curr);
  return false;
  }

  strcpy(curr->value,s);//copy s to curr
  curr->next=q->head; //next of curr to head of queue
  q->head=curr;//head=curr

  if(q->tail==NULL) //queue is empty, tail to curr
  {
    q->tail=curr;
  }

    q->size++;//added so size+1
    return true;//inserted to return true
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
  list_ele_t*curr;

  if(q==NULL)//queue doesnt exist return false, s cannot be inserted
  return false;

  curr=malloc(sizeof(list_ele_t)); //store s

  if(curr==NULL)
  return false;//mem allocation is good if not return false

  curr->value=(char*)malloc(strlen(s)+1);//allocate mem for value of curr

  if(curr->value==NULL)//above line not good, delete mem; therefore return false
  {
  free(curr);
  return false;
  }

  curr->next=NULL;
  strcpy(curr->value,s);//copy value of s to curr

  if(q->tail==NULL) //queue is empty, head=curr
  {
    q->head=curr;
  }
  else
  {
  q->tail->next=curr;//tail.next=curr
  }

  q->tail=curr;//tail=curr
  q->size++;//inserted so size+1
  return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
  if(q!=NULL && q->head!=NULL)//queue is not null and has elements
  {
    list_ele_t*curr=q->head;//curr=head
    q->head=q->head->next;//curr.head.next

    if(sp!=NULL)//check if sp is NULL
    {
      if(strlen(curr->value)< bufsize)//if length < bufsize, copy entire string intp sp
      strncpy(sp, curr->value, bufsize);
      else
      {
        strncpy(sp, curr->value, bufsize-1);//if not <bufsize copy bufsize-1 chars into
        sp[bufsize-1]='\0';
      }
    }

    free(curr->value);//free mem
    free(curr);//free curr
    q->size--;//size-1 bc removed head
    return true;//true
  }

  return false; // did not remove, return false
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
  if(q!=NULL)
  return q->size;

  return 0;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
  if(q!=NULL && q->head!=NULL && q->size>1)//queue not null, not empty, more than 1 element
  {
    list_ele_t*curr=q->head; //curr=head
    list_ele_t*next=NULL;
    list_ele_t*previous=NULL;

    while(curr!=NULL)//while elements r still in queue
    {
      next=curr->next; //next is set to current element in queue
      curr->next=previous;// next element after current is set to previous
      previous=curr;//previous is the current element
      curr=next;//current is next element
    }
    q->tail=q->head; //the tail element is now the head
    q->head=previous;// head element is now the previous (head=tail)
  }
}
