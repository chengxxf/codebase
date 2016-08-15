#include <stdio.h>

#define UINT4 unsigned int
#define BOOL1 unsigned char


typedef int sem_t;
typedef UINT4 tMemPoolId;
typedef sem_t *   tOsixSemId;

enum {RB_SUCCESS = 0, RB_FAILURE};

enum nodecolour
{ BLACK, RED };

enum {
	RBCREATE_WITH_SEM = 0, 
	RBCREATE_NO_SEM
};

enum eRBNodeType
{ RB_EMBD_NODE = 0, RB_NOT_EMBD_NODE };

typedef void           tRBElem;

typedef unsigned int (*tRBCompareFn) (tRBElem *e1, tRBElem *e2);

typedef struct rbnode
{
    struct rbnode   *left;
    struct rbnode   *right;
    struct rbnode   *up;
    enum nodecolour colour;
    tRBElem         *key;
} tRBNode;


struct rbtree
{
    tRBCompareFn        rb_cmp;
    tOsixSemId          SemId;
    tMemPoolId          PoolId;
    tRBNode            *rb_root;
    UINT4               u4Count;
    UINT4               u4Offset;
    enum eRBNodeType    NodeType;
    BOOL1  b1MutualExclusive;
};
typedef struct rbtree  *tRBTree;

typedef struct RBNodeEmbd{
    struct RBNodeEmbd  *left;
    struct RBNodeEmbd  *right;
    struct RBNodeEmbd  *up;
    enum nodecolour    colour;
}tRBNodeEmbd;


unsigned int RBTreeRemove(tRBTree, tRBElem *);
