/*
  main.c
  binary-tree-c

 Created by Bautista on 23/06/2020
 Copyright © 2020 Bautista. All rights reserved.
*/

/*
    Description: Just a sample binary tree date structure i made in pandemic.
*/
#include <stdio.h>
#include <stdlib.h>
#define CORTE -1

typedef struct Arbol
{
    int dato;
    struct Arbol *izq;
    struct Arbol *der;
}Treenode;
void cargarArbol(Treenode **hoja);
void crearHoja(Treenode **hoja, int num);
void mostrarArbolYDatos(Treenode *hoja, int raiz, int *div_r);

int main()
{
    Treenode *arbol=NULL;
    int raiz, div_r;
    cargarArbol(&arbol);
    raiz=arbol->dato;
    mostrarArbolYDatos(arbol, raiz, &div_r);
    printf("\nCantidad de números divisibles por la raíz: %d", div_r);
}

void cargarArbol(Treenode **hoja)
{
    int num;
    printf("Ingrese un número: ");
    scanf("%d", &num);
    while(num!=CORTE)
    {
        crearHoja(&(*hoja), num);
        printf("Ingrese un número: ");
        scanf("%d", &num);
    }
}
void crearHoja(Treenode **hoja, int num)
{
    if(num==CORTE)
    {
        return;
    }
    if((*hoja)==NULL)
    {
        (*hoja)=(Treenode*)malloc(sizeof(Treenode));
        (*hoja)->dato=num;
        (*hoja)->izq=NULL;
        (*hoja)->der=NULL;
    }
    else
    {
        if(num>(*hoja)->dato)
        {
            crearHoja(&(*hoja)->der, num);
        }
        else
        {
            crearHoja(&(*hoja)->izq, num);
        }
    }
}
void mostrarArbolYDatos(Treenode *hoja, int raiz, int *div_r)
{
    if(hoja!=NULL)
    {
        mostrarArbolYDatos(hoja->izq, raiz, div_r);
        printf(" %d ", hoja->dato);
        if(hoja->dato%raiz==0&&hoja->dato!=raiz)
        {
            (*div_r)=(*div_r)+1;
        }
        mostrarArbolYDatos(hoja->der, raiz, div_r);
    }
}
