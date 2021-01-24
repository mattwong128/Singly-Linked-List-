/***********************************
* Filename: list.c
* Author: Wong, Matthew
* Email: matt128@my.yorku.ca
* Login ID: matt128
************************************/


#include <stdio.h>
#include <stdlib.h>
#include "list.h"


List *head, *tail;


/* Display an error message. */

void prtError( char *errMsg )
{
   printf( "%s \n", errMsg );
}


/* Create an empty list. */
/* Create a dummy node to simplify insertion and deletion. */
/* After the list is created, pointers head and tail both point to the dummy node. */
/* Return NULL if a node cannot be created. */
/* Otherwise, return the pointer to the dummy node. */

List *init( )
{
   head = ( List * ) malloc( sizeof( List ) );
   if ( head == NULL ) {
      prtError( "Insufficient memory!" );
      return( NULL );
   }
   head->data = -1;
   head->next = NULL;
   tail = head;
   return ( head );
}


/* Return the content (data) of the first element right behind the dummy node. */
/* Return -1 if the list is empty. */

int getFirst()
{
   if ( head != tail )	// non-empty list
      return( head->next->data );
   else					// empty list
      return -1;
}


/* Return the content (data) of the last element at the rear of the list. */
/* Return -1 if the list is empty. */

int getLast()
{
   if ( head != tail )	// non-empty list
      return( tail->data );
   else					// empty list
      return -1;
}


/* Print the content of the list (ignoring the dummy node). */

void prtList( )
{
   List *p;
   for ( p = head->next; p != NULL; p = p->next )
        printf( "%4d", p->data );
   printf( "\n");
}



/************* DO NOT MODIFY ANYTHING ABOVE THIS LINE, *************/
/************* EXCEPT THE HEADER CONTAINING YOUR INFO **************/

/* Insert a new data element d into the list. */
/* Insert at the front of the list, right behind the dummy node. */
/* Return NULL if a new node cannot be created. */
/* Otherwise, return the pointer to the newly created node. */

List *insertFirst( int d )
{   
    if (head != NULL ) {                                //if memory is allocated
        List *node = (List*)malloc(sizeof(List)),*temp; //allocate memory for new node to be added, temp is for the swap
        temp = head->next;                              //temp points to first node
        head->next = node;                              //new node is inserted after the dummy node
        node->data = d;                                 //set values for node
        node->next = temp;
        return node;                                    //return pointer to node
   }
    
   
   return NULL;		// replace this line with your code
}



/* Insert a new data element d into the list. */
/* Insert at the end of the list. */
/* Return NULL if a new node cannot be created. */
/* Otherwise, return the pointer to the newly created node. */

List *insertLast( int d )
{   
    if (head != NULL ) {                            //if memory is allocated
        List *node = (List*)malloc(sizeof(List));   //allocate memory for new node to be added
        tail->next = node;                          //node inserted after tail
        node->data = d;                             //set values for new node
        node->next = NULL;
        tail = node;                                //new node is the new tail since it is the last node
        return node;                                //return pointer to newly added node
   }
   
   return NULL;                                     //otherwise returns null
}



/* Remove the first element of the list, i.e., the node right behind the dummy node. */
/* Return -1 if the list is empty, i.e., containing only the dummy node, */
/* and display error message "Empty list!" on the standard output. */
/* Otherwise, return the data (integer) of the node to be remove. */

int removeFirst()
{
    if(head->next != NULL){                         //if list is not empty
         List *temp = (List*)malloc(sizeof(List));  //allocate memory for temp node
         temp = head->next;                         //temp hols first node
         int num = temp->data;                      //store value of node to be returned later
         head->next = temp->next;                   //dummy node points to the second node instead of the first
         return num;                                //return value of deleted node stored in num
    }
   printf("Empty list!\n"); 
   return -1;	// replace this line with your code
}


/* Search the list for an element containing integer k. */
/* If found, return the pointer to that element.  Otherwise, return NULL. */
/* If there is more than one element containing k, return the pointer to the first encountered element. */

List *search( int k )
{
    List *p;                                            
    for(p = head->next; p != NULL; p = p->next){  //iterate through list with pointer p until it points to the last node
        if(p->data == k){                               //once last node is found return a pointer to it
            return p;
        }
    }
     
   return NULL;                                         //if not found return null
}


/*************************** END OF FILE ***************************/
