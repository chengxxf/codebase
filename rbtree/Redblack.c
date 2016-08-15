#include "Redblack.h"

tRBNode rb_null = { &rb_null, &rb_null, &rb_null, BLACK, NULL };

#define RBNULL (&rb_null)



static tRBNode     *
rb_successor (tRBNode * x)
{
    tRBNode            *y;

    if (x->right != RBNULL)
    {
        /* If right is not NULL then go right one and
 *          ** then keep going left until we find a node with
 *                   ** no left pointer.
 *                            */
        for (y = x->right; y->left != RBNULL; y = y->left);
    }
    else
    {
        /* Go up the tree until we get to a node that is on the
 *          ** left of its parent (or the root) and then return the
 *                   ** parent.
 *                            */
        y = x->up;
        while (y != RBNULL && x == y->right)
        {
            x = y;
            y = y->up;
        }
    }
    return (y);
}

/*
 * ** Rotate our tree thus:-
 * **
 * **             X        rb_left_rotate(X)--->            Y
 * **           /   \                                     /   \
 * **          A     Y     <---rb_right_rotate(Y)        X     C
 * **              /   \                               /   \
 * **             B     C                             A     B
 * **
 * ** N.B. This does not change the ordering.
 * **
 * ** We assume that neither X or Y is NULL
 * */

static void
rb_left_rotate (tRBNode ** rootp, tRBNode * x)
{
    tRBNode            *y;

    /*
 *      * Preconditions:
 *           *  (x!=RBNULL);
 *                *  (x->right!=RBNULL);
 *                     */

    y = x->right;                /* set Y */

    /* Turn Y's left subtree into X's right subtree (move B) */
    x->right = y->left;

    /* If B is not null, set it's parent to be X */
    if (y->left != RBNULL)
        y->left->up = x;

    /* Set Y's parent to be what X's parent was */
    y->up = x->up;

    /* if X was the root */
    if (x->up == RBNULL)
    {
        *rootp = y;
    }
    else
    {
        /* Set X's parent's left or right pointer to be Y */
        if (x == x->up->left)
        {
            x->up->left = y;
        }
        else
        {
            x->up->right = y;
        }
    }

    /* Put X on Y's left */
    y->left = x;

    /* Set X's parent to be Y */
    x->up = y;
}


static void
rb_right_rotate (tRBNode ** rootp, tRBNode * y)
{
    tRBNode            *x;

    /*
 *      * Preconditions
 *           * (y!=RBNULL);
 *                * (y->left!=RBNULL);
 *                     */

    x = y->left;                /* set X */

    /* Turn X's right subtree into Y's left subtree (move B) */
    y->left = x->right;

    /* If B is not null, set it's parent to be Y */
    if (x->right != RBNULL)
        x->right->up = y;

    /* Set X's parent to be what Y's parent was */
    x->up = y->up;

    /* if Y was the root */
    if (y->up == RBNULL)
    {
        *rootp = x;
    }
    else
    {
        /* Set Y's parent's left or right pointer to be X */
        if (y == y->up->left)
        {
            y->up->left = x;
        }
        else
        {
            y->up->right = x;
        }
    }

    /* Put Y on X's right */
    x->right = y;

    /* Set Y's parent to be X */
    y->up = x;
}

static void rb_delete_fix (tRBNode ** rootp, tRBNode * x)
{
    tRBNode            *w;

    while (x != *rootp && x->colour == BLACK)
    {
        if (x == x->up->left)
        {
            w = x->up->right;
            if (w->colour == RED)
            {
                w->colour = BLACK;
                x->up->colour = RED;
                rb_left_rotate (rootp, x->up);
                w = x->up->right;
            }

            if (w->left->colour == BLACK && w->right->colour == BLACK)
            {
                w->colour = RED;
                x = x->up;
            }
            else
            {
                if (w->right->colour == BLACK)
                {
                    w->left->colour = BLACK;
                    w->colour = RED;
                    rb_right_rotate (rootp, w);
                    w = x->up->right;
                }

                w->colour = x->up->colour;
                x->up->colour = BLACK;
                w->right->colour = BLACK;
                rb_left_rotate (rootp, x->up);
                x = *rootp;
            }
        }
        else
        {
            w = x->up->left;
            if (w->colour == RED)
            {
                w->colour = BLACK;
                x->up->colour = RED;
                rb_right_rotate (rootp, x->up);
                w = x->up->left;
            }

            if (w->right->colour == BLACK && w->left->colour == BLACK)
            {
                w->colour = RED;
                x = x->up;
            }
            else
            {
                if (w->left->colour == BLACK)
                {
                    w->right->colour = BLACK;
                    w->colour = RED;
                    rb_left_rotate (rootp, w);
                    w = x->up->left;
                }

                w->colour = x->up->colour;
                x->up->colour = BLACK;
                w->left->colour = BLACK;
                rb_right_rotate (rootp, x->up);
                x = *rootp;
            }
        }
    }

    x->colour = BLACK;
}

static void rb_delete(tRBNode ** rootp, tRBNode * z, tRBTree rbinfo)
{
    tRBNode            *x, *y;
    enum nodecolour     yColour;

    if (z->left == RBNULL || z->right == RBNULL)
        y = z;
    else
        y = rb_successor (z);

    if (y->left != RBNULL)
        x = y->left;
    else
        x = y->right;

    x->up = y->up;

    if (y->up == RBNULL)
    {
        *rootp = x;
    }
    else
    {
        if (y == y->up->left)
            y->up->left = x;
        else
            y->up->right = x;
    }

    yColour = y->colour;
    if (y != z)
    {
        /* if root node */
        if (z->up == RBNULL)
        {
            *rootp = y;
        }

        /* make y point to parent of z */
        y->up = z->up;

        /* make parent of z pt to y */
        if (z->up->left == z)
        {
            z->up->left = y;
        }
        else
        {
            z->up->right = y;
        }

        /* make the chldrn of z pt to y */
        z->left->up = y;
        z->right->up = y;

        /* make y point to chldrn of z */
        y->left = z->left;
        y->right = z->right;

        y->colour = z->colour;
    }
    if (yColour == BLACK)
        rb_delete_fix (rootp, x);


}
