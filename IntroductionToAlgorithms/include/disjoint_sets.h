#ifndef DISJOINT_SETS_H
#define DISJOINT_SETS_H

#define NumSets 100

typedef int DisjSet[ NumSets + 1];
typedef int SetType;
typedef int ElementType;

void Initialize( DisjSet S );
void SetUnion( DisjSet S, SetType Root1, SetType Root2 );
SetType Find( ElementType X, DisjSet S);


#endif
