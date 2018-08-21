//
//  main.cpp
//  Sudoku
//
//  Created by Frida on 8/7/18.
//  Copyright © 2018 Frida. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int matriz[10][10], num,sumaCua=0, limiteR=3, limiteC=3, col=0, cont=0, renglonTres=0, parar = 0;
    bool contador=true;
 
    for(int i = 0; i < 9; i++){
        for(int c = 0; c < 9; c++){
            cin >> num;
            matriz[i][c] = num;
        }
    }
    
    do{
        for(int r=renglonTres; r<limiteR; r++){
            for(int c=col; c<limiteC; c++){
                sumaCua+=matriz[r][c];
            }
        }
        
        if(sumaCua==45){
            col+=3;
            limiteC+=3;
            sumaCua=0;
            cont++;
            contador=true;
            
            if(cont==3){
                cont=0;
                col=0;
                limiteC=3;
                limiteR+=3;
                renglonTres+=3;
                parar++;
            }
        }
        
        else
            contador=false;
    }while(contador ==true && parar <3);
    
    
    if(contador==true){
    
        int sumaLineas = 0, sumaTotalLineas = 0;
        bool sumaL = true;
    
        for(int i = 0; i < 9; i++){
            for(int c = 0; c <9; c++){
            sumaLineas += matriz[i][c];
            }
            if(sumaLineas != 45){
                sumaL = false;
                break;
            }
            else{
                sumaTotalLineas += sumaLineas;
                sumaL = true;
            }
            sumaLineas = 0;
        }
    
        if (sumaL){
            int sumaColumnas = 0, sumaTotalColumnas = 0;
            bool sumaC = true;
            for(int i = 0; i < 9; i++){
                for(int c = 0; c <9; c++){
                    sumaColumnas += matriz[c][i];
                }
                if(sumaColumnas != 45){
                    sumaC = false;
                    break;
                }
                else{
                    sumaTotalColumnas += sumaColumnas;
                    sumaC = true;
                }
                sumaColumnas = 0;
            }
        
            if(sumaC){
                if(sumaTotalColumnas == sumaTotalLineas)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
            }
        
            else
                cout << "NO" << endl;
        }
    
        else
            cout << "NO" << endl;
    }
    
    else{
        cout << "NO" << endl;
    }
 
    return 0;
}
