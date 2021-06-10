//
//  main.cpp
//  BMOAulasCpp23ConstInCpp
//
//  Created by Breno Medeiros on 10/06/21.
//

#include <iostream>
#include <string>


/*Para entender é os principais usos de Const: Você tem que ler ao contrário, como o compilador faz. Por exemplo :

    -const int * A; ==> "A é um ponteiro para um int que é constante."
                        (ou, dependendo de como você prefere escrever)
     int const * A; ==> "A é um ponteiro para um const int"
                        mas ambos são os mesmos explicados no vídeo.

    -int * const A; ==> "A é um ponteiro constante para um int."
    -const int * const A; ==> "A é um ponteiro constante para um int que é constante".

EDICAO:
Conforme mencionado por simo simo nos comentários do video, 'const int * A' não significa que A realmente
 aponta para uma variável const. Significa apenas que o compilador não permitirá que você modifique o
 valor apontado por A.

Por exemplo :
    int val = 10;
    int const * a = & val;
    * a = 30; // isto NÃO irá compilar, você não tem permissão para modificar "val" através de "a".
    val = 30; // isso irá compilar.

Mesmo com :
    int val = 10;
    int val2 = 30;
    const int * const A = & val;

    A   = & val2; // NÃO irá compilar: você não pode modificar o que A aponta.
    * A = 30;     // NÃO irá compilar: você não pode modificar val através de A

    val = 30;     // isso irá compilar, val não é constante
*/


class Entidade {
private:
    int m_X, m_Y;
    int* m_Xponteiro;
    mutable int m_Xmutavel; //Significa que ele pode ser mutavel/mudar entre 'const' e 'variavel'
public:
    int GetXcomConst() const { //Usar 'const' em declaracao de metodos de uma classe, significa que no corpo desse metodo
                       // os atributos da propria classe(nesse caso 'm_X' e 'm_Y') nao podem ser alterados. Por ex:
        //m_X = 2; //Descomentar essa linha da erro, pois colocarmos o 'const' na declaracao fazemos GetX() ReadOnly
        
        m_Xmutavel = 6; //EXCESSAO DA REGRA(para fins de debug apenas): somente atributos 'mutable' podem ser mudados
        
        return m_X;
    }
    int GetXsemConst() {
        return m_X;
    }
    
    void SetX(int x) { //Nesse caso nao faz sentido(e ate inutizaria esse metodo), por 'const' afim torna-lo ReadOnly
        m_X = x;
    }
    
    //O metodo ReadOnly GetXponteiro() abaixo retorna um ponteiro constante para um int que é constante:
    const int * const GetXponteiro(int x) const {
        return m_Xponteiro;
    }
};

void PrintEntidade(const Entidade& e) { //Adicionando 'const' e '&', otimizamos o codigo pois n copiamos so pra printar
    //std::cout << e.GetXsemConst() << std::endl; //Descomentar essa linha da erro, pois sem 'const' n garantimos o ReadOnly
    std::cout << e.GetXcomConst() << std::endl;
    //E por causa disso em muitos projetos Cpp vemos esses 2 metodos acima iguais, mas um com 'const' e outro sem 'const'
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    const int MaxAge = 90;
    
    //MaxAge = 18; // Isso da erro, pois nao podemos mudar o valor de uma constante
    int* a = new int;
    *a = 2;
    std::cout << *a << std::endl;
    a = (int*)&MaxAge; //Nao é recomendado fazer isso, pois so vai funcionar em alguns casos
    std::cout << *a << std::endl;
    
    const int* aPonteiroParaIntConst = new int; //"aConst é um ponteiro para um int que é constante.
    //*a = 4; //Descomentar essa linha dara erro
    aPonteiroParaIntConst = (int*)&MaxAge;    //Nao é recomendado fazer isso, pois so vai funcionar em alguns casos
    std::cout << *aPonteiroParaIntConst << std::endl;
    
    int* const aPonteiroConstParaInt = new int;   //A é um ponteiro constante para um int.
    *aPonteiroConstParaInt = 4;
    //aPonteiroConstParaInt = (int*)&MaxAge;      //Descomentar essa linha dara erro
    
    const int * const aPonteiroConstParaIntConst = new int; //A é um ponteiro constante para um int que é constante
    //*aPonteiroConstParaIntConst = 4;            //Descomentar essa linha dara erro
    //aPonteiroConstParaIntConst = (int*)&MaxAge; //Descomentar essa linha dara erro
    
    
    Entidade e;
    e.SetX(20);
    PrintEntidade(e);
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
