// GrafoMatriz.h
// Definicion de TDA Grafo implementado con Matriz de Adyacencia
#ifndef _GRAFOEMOCIONAL_H
#define _GRAFOEMOCIONAL_H

typedef int * pint;

#include "Vertice.h"

class GrafoMatriz {
private:
    int maxVerts;
    int numVerts;
    Vertice* verts;
    int** matAd;

public:
    GrafoMatriz();
    GrafoMatriz(int v);

    void setMaxVerts(int n);
    void setNumVerts(int n);
    void setVertice(int va, Vertice v);
    void setVertice(TipoG a, Vertice v);
    void setArco(int va, int vb);
    void setArco(int va, int vb, int v);
    void setArco(TipoG a, TipoG b);
    void setArco(TipoG a, TipoG b, int v);

    int getMaxVerts();
    int getNumVerts();
    Vertice getVertice(int va);
    Vertice getVertice(TipoG a);
    int getArco(int va, int vb);
    int getArco(TipoG a, TipoG b);

    int getNumVertice(TipoG v);
    void nuevoVertice(TipoG v);
    bool adyacente(int va, int vb);
    bool adyacente(TipoG a, TipoG b);
};

GrafoMatriz::GrafoMatriz() {
    setMaxVerts(1);
    setNumVerts(getMaxVerts());
}

GrafoMatriz::GrafoMatriz(int v) {
    setMaxVerts(v);
    setNumVerts(0);
    verts = new Vertice[v];
    matAd = new pint[v];
    for (int i = 0; i < v; i++) {
        matAd[i] = new int[v];
        for (int j = 0; j < v; j++) {
            matAd[i][j] = 0xFFFF;
        }
    }
}

void GrafoMatriz::setMaxVerts(int n) {
    maxVerts = n;
}

void GrafoMatriz::setNumVerts(int n) {
    numVerts = n;
}

void GrafoMatriz::setVertice(int va, Vertice v) {
    if ((va >= 0) && (va < getNumVerts())) {
        verts[va] = v;
    }
}

void GrafoMatriz::setVertice(TipoG a, Vertice v) {
    int va;
    va = getNumVertice(a);
    if ((va >= 0) && (va < getNumVerts())) {
        verts[va] = v;
    }
}

void GrafoMatriz::setArco(int va, int vb) {
    if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts())) {
        matAd[va][vb] = 1;
    }
}

void GrafoMatriz::setArco(int va, int vb, int v) {
    if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts())) {
        matAd[va][vb] = v;
    }
}

void GrafoMatriz::setArco(TipoG a, TipoG b) {
    int va, vb;
    va = getNumVertice(a);
    vb = getNumVertice(b);
    if ((va >= 0) && (vb >= 0)) {
        matAd[va][vb] = 1;
    }
}

void GrafoMatriz::setArco(TipoG a, TipoG b, int v) {
    int va, vb;
    va = getNumVertice(a);
    vb = getNumVertice(b);
    if ((va >= 0) && (vb >= 0)) {
        matAd[va][vb] = v;
    }
}

int GrafoMatriz::getMaxVerts() {
    return maxVerts;
}

int GrafoMatriz::getNumVerts() {
    return numVerts;
}

Vertice GrafoMatriz::getVertice(int va) {
    if ((va < 0) || (va >= getNumVerts())) {
        Vertice x;
        return x;
    } else {
        return verts[va];
    }
}

Vertice GrafoMatriz::getVertice(TipoG a) {
    int va;
    va = getNumVertice(a);
    if ((va < 0) || (va >= numVerts)) {
        Vertice x;
        return x;
    } else {
        return verts[va];
    }
}

int GrafoMatriz::getArco(int va, int vb) {
    if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts())) {
        return matAd[va][vb];
    } else {
        return -1;
    }
}

int GrafoMatriz::getArco(TipoG a, TipoG b) {
    int va, vb;
    va = getNumVertice(a);
    vb = getNumVertice(b);
    if ((va >= 0) && (vb >= 0)) {
        return matAd[va][vb];
    } else {
        return -1;
    }
}

int GrafoMatriz::getNumVertice(TipoG v) {
    int i;
    bool enc = false;

    for (i = 0; (i < getNumVerts()) && !enc;) {
        enc = verts[i].esIgualDato(v);
        if (!enc) {
            i++;
        }
    }
    return ((i < getNumVerts()) ? i : -1);
}

void GrafoMatriz::nuevoVertice(TipoG v) {
    bool existe = (getNumVertice(v) >= 0);
    if (!existe) {
        if (getNumVerts() < getMaxVerts()) {
            Vertice nv = Vertice(v, numVerts);
            verts[numVerts] = nv;
            setNumVerts(getNumVerts()+1);
        }
    }
}

bool GrafoMatriz::adyacente(int va, int vb) {
    if ((va >= 0) && (vb >= 0) && (va < getNumVerts()) && (vb < getNumVerts())) {
        return matAd[va][vb] != 0xFFFF;
    } else {
        return false;
    }
}

bool GrafoMatriz::adyacente(TipoG a, TipoG b) {
    int va, vb;
    va = getNumVertice(a);
    vb = getNumVertice(b);
    if ((va >= 0) && (vb >= 0)) {
        return (matAd[va][vb] != 0xFFFF);
    } else {
        return false;
    }
}

#endif
