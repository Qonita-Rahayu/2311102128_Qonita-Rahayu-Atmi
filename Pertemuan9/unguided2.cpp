#include <iostream>
#include <queue>
using namespace std;

// strung untuk menampung data
struct Pohon
{
    char data_2311102128;
    Pohon *left_2311102128;
    Pohon *right_2311102128;
    Pohon *parent_2311102128;
};

Pohon *root_2311102128;

// fungsi untuk mengecek bahwa root itu kosong atau tidak
bool isEmpty()
{
    return root_2311102128 == NULL;
}
// inisialisai kan root
void init()
{
    root_2311102128 = nullptr;
}
// untuk membuat node
void buatNode(char data)
{
    if (root_2311102128 == nullptr)
    {
        root_2311102128 = new Pohon();
        root_2311102128->data_2311102128 = data;
        root_2311102128->left_2311102128 = nullptr;
        root_2311102128->right_2311102128 = nullptr;
        cout << "Node " << data << " berhasil dibuat sebagai root." << endl;
    }
    else
    {
        cout << "Root sudah ada!" << endl;
    }
}
// insert data child ke sebelah kiri
Pohon *insertLeft(char data, Pohon *parent)
{
    if (parent == nullptr)
    {
        cout << "Node parent tidak ditemukan!" << endl;
        return nullptr;
    }

    if (parent->left_2311102128 == nullptr)
    {
        Pohon *newNode = new Pohon();
        newNode->data_2311102128 = data;
        newNode->left_2311102128 = nullptr;
        newNode->right_2311102128 = nullptr;
        parent->left_2311102128 = newNode;
        cout << "Node " << data << " berhasil ditambahkan ke child kiri " << parent->data_2311102128 << endl;
        return newNode;
    }
    else
    {
        cout << "Node kiri dari " << parent->data_2311102128 << " sudah terisi!" << endl;
        return nullptr;
    }
}
// insert data child ke sebelah kanan
Pohon *insertRight(char data, Pohon *parent)
{
    if (parent == nullptr)
    {
        cout << "Node parent tidak ditemukan!" << endl;
        return nullptr;
    }

    if (parent->right_2311102128 == nullptr)
    {
        Pohon *newNode = new Pohon();
        newNode->data_2311102128 = data;
        newNode->left_2311102128 = nullptr;
        newNode->right_2311102128 = nullptr;
        parent->right_2311102128 = newNode;
        cout << "Node " << data << " berhasil ditambahkan ke child kanan " << parent->data_2311102128 << endl;
        return newNode;
    }
    else
    {
        cout << "Node kanan dari " << parent->data_2311102128 << " sudah terisi!" << endl;
        return nullptr;
    }
}
// untuk mengupdate data node
void update(char data, Pohon *node)
{
    if (node == nullptr)
    {
        cout << "Node tidak ditemukan!" << endl;
        return;
    }

    if (node->data_2311102128 == data)
    {
        cout << "Masukkan data baru: ";
        char newData;
        cin >> newData;
        node->data_2311102128 = newData;
        cout << "Node " << data << " berhasil diubah menjadi " << newData << endl;
        return;
    }

    if (node->left_2311102128 != nullptr)
    {
        update(data, node->left_2311102128);
    }
    if (node->right_2311102128 != nullptr)
    {
        update(data, node->right_2311102128);
    }
}
// untuk mengetahui isi dari node yang diinputkan
void retrieve(Pohon *node)
{
    if (node != nullptr)
    {
        cout << "Data node: " << node->data_2311102128 << endl;
    }
    else
    {
        cout << "Node tidak ditemukan!" << endl;
    }
}
// untuk mencari node
Pohon *find(char data)
{
    queue<Pohon *> q;
    if (root_2311102128 != nullptr)
        q.push(root_2311102128);

    while (!q.empty())
    {
        Pohon *temp = q.front();
        q.pop();

        if (temp->data_2311102128 == data)
        {
            return temp;
        }

        if (temp->left_2311102128 != nullptr)
        {
            q.push(temp->left_2311102128);
        }
        if (temp->right_2311102128 != nullptr)
        {
            q.push(temp->right_2311102128);
        }
    }
    return nullptr;
}
// untuk menampilkan child
void tampilkanChild(Pohon *node)
{
    if (node == nullptr)
    {
        cout << "Node tidak ditemukan!" << endl;
        return;
    }

    if (node->left_2311102128 != nullptr)
    {
        cout << "Child kiri: " << node->left_2311102128->data_2311102128 << endl;
    }
    else
    {
        cout << "Child kiri: (tidak punya child kiri)" << endl;
    }

    if (node->right_2311102128 != nullptr)
    {
        cout << "Child kanan: " << node->right_2311102128->data_2311102128 << endl;
    }
    else
    {
        cout << "Child kanan: (tidak punya child kanan)" << endl;
    }
}
// untuk menampilkan dari yang terbesar
void tampilkanDescendant(Pohon *node)
{
    if (node == nullptr)
    {
        cout << "Node tidak ditemukan!" << endl;
        return;
    }

    if (node->left_2311102128 != nullptr)
    {
        cout << node->left_2311102128->data_2311102128 << " ";
        tampilkanDescendant(node->left_2311102128);
    }
    if (node->right_2311102128 != nullptr)
    {
        cout << node->right_2311102128->data_2311102128 << " ";
        tampilkanDescendant(node->right_2311102128);
    }
}
// untuk menampilkan dari yang terkecil
void tampilkanAscending(Pohon *node)
{
    if (node == nullptr)
    {
        return;
    }

    tampilkanAscending(node->left_2311102128);
    cout << node->data_2311102128 << " ";
    tampilkanAscending(node->right_2311102128);
}
// untuk menampilkan dari node, kiri dan kanan
void PreOrder(Pohon *node)
{
    if (node == nullptr)
    {
        return;
    }

    cout << node->data_2311102128 << " ";
    PreOrder(node->left_2311102128);
    PreOrder(node->right_2311102128);
}
// untuk menampilkan data node dari kiri, node dan kanan
void InOrder(Pohon *node)
{
    if (node == nullptr)
    {
        return;
    }

    InOrder(node->left_2311102128);
    cout << node->data_2311102128 << " ";
    InOrder(node->right_2311102128);
}
// untuk menampilkan node dari kiri, node child kanan dan node
void PostOrder(Pohon *node)
{
    if (node == nullptr)
    {
        return;
    }

    PostOrder(node->left_2311102128);
    PostOrder(node->right_2311102128);
    cout << node->data_2311102128 << " ";
}
// untuk menampilkan saudara dari root atau yang sejajar dengan node nya
void sibling(Pohon *node)
{
    if (root_2311102128 == nullptr || root_2311102128 == node)
    {
        cout << "Root node tidak memiliki sibling." << endl;
        return;
    }

    Pohon *parent = nullptr;
    Pohon *current = root_2311102128;

    queue<Pohon *> q;
    q.push(current);

    while (!q.empty())
    {
        current = q.front();
        q.pop();

        if (current->left_2311102128 == node || current->right_2311102128 == node)
        {
            parent = current;
            break;
        }

        if (current->left_2311102128 != nullptr)
        {
            q.push(current->left_2311102128);
        }
        if (current->right_2311102128 != nullptr)
        {
            q.push(current->right_2311102128);
        }
    }

    if (parent == nullptr)
    {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    if (parent->left_2311102128 != nullptr && parent->left_2311102128 != node)
    {
        cout << "Sibling: " << parent->left_2311102128->data_2311102128 << endl;
    }
    else if (parent->right_2311102128 != nullptr && parent->right_2311102128 != node)
    {
        cout << "Sibling: " << parent->right_2311102128->data_2311102128 << endl;
    }
    else
    {
        cout << "Node tidak memiliki sibling." << endl;
    }
}
// untuk menampilkan preorder, in order, post order dan sibling secara bersama
void traversalAndSibling(Pohon *node)
{
    cout << "PreOrder: ";
    if (node == nullptr)
    {
        cout << "Tree kosong" << endl;
    }
    else
    {
        PreOrder(node);
    }
    cout << endl;

    cout << "InOrder: ";
    if (node == nullptr)
    {
        cout << "Tree kosong" << endl;
    }
    else
    {
        InOrder(node);
    }
    cout << endl;

    cout << "PostOrder: ";
    if (node == nullptr)
    {
        cout << "Tree kosong" << endl;
    }
    else
    {
        PostOrder(node);
    }
    cout << endl;

    sibling(node);
}
// untuk menghapus semua subtree dari node yang diinputkan
void deleteSubtree(Pohon *&node)
{
    if (node == nullptr)
    {
        return;
    }
    // Hapus seluruh subtree dari anak kiri dan anak kanan secara rekursif
    deleteSubtree(node->left_2311102128);
    deleteSubtree(node->right_2311102128);
    // Setiap node dihapus dari memori
    delete node;
    node = nullptr;
}
// untuk menghapus sebuah node yang di inputkan
void deleteNode(char data, Pohon *&node)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->data_2311102128 == data)
    {
        if (node->left_2311102128 == nullptr && node->right_2311102128 == nullptr)
        {
            delete node;
            node = nullptr;
            cout << "Node " << data << " berhasil dihapus." << endl;
        }
        else
        {
            // Jika node memiliki anak, panggil fungsi deleteSubtree untuk menghapus subtree
            deleteSubtree(node);
            node = nullptr;
            cout << "Node " << data << " beserta subtree berhasil dihapus." << endl;
        }
        return;
    }

    deleteNode(data, node->left_2311102128);
    deleteNode(data, node->right_2311102128);
}

// untuk mencari sebuah node yang di inputkan
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        }
        else
        {
            cout << "\n Data Node : " << node->data_2311102128 << endl;

            // Mencari parent
            Pohon *parent = nullptr;
            Pohon *current = root_2311102128;
            queue<Pohon *> q;
            q.push(current);

            while (!q.empty())
            {
                current = q.front();
                q.pop();

                if (current->left_2311102128 == node || current->right_2311102128 == node)
                {
                    parent = current;
                    break;
                }

                if (current->left_2311102128 != nullptr)
                {
                    q.push(current->left_2311102128);
                }
                if (current->right_2311102128 != nullptr)
                {
                    q.push(current->right_2311102128);
                }
            }
            // Menampilkan parent
            if (root_2311102128 != nullptr)
            {
                cout << " Root : " << root_2311102128->data_2311102128 << endl;
            }
            else
            {
                cout << " Root : (tidak punya root)" << endl;
            }

            // Menampilkan parent
            if (parent != nullptr)
            {
                cout << " Parent : " << parent->data_2311102128 << endl;
            }
            else
            {
                cout << " Parent : (tidak punya parent)" << endl;
            }

            // Menampilkan sibling
            if (parent != nullptr)
            {
                if (parent->left_2311102128 == node)
                {
                    if (parent->right_2311102128 != nullptr)
                        cout << " Sibling : " << parent->right_2311102128->data_2311102128 << endl;
                    else
                        cout << " Sibling : (tidak punya sibling)" << endl;
                }
                else if (parent->right_2311102128 == node)
                {
                    if (parent->left_2311102128 != nullptr)
                        cout << " Sibling : " << parent->left_2311102128->data_2311102128 << endl;
                    else
                        cout << " Sibling : (tidak punya sibling)" << endl;
                }
            }
            else
            {
                cout << " Sibling : (tidak punya sibling)" << endl;
            }

            // Menampilkan child kiri
            if (!node->left_2311102128)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left_2311102128->data_2311102128 << endl;

            // Menampilkan child kanan
            if (!node->right_2311102128)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right_2311102128->data_2311102128 << endl;
        }
    }
}
// untuk menampilkan level dari sebuah node yang di cari
void findLevel(Pohon *node, char data, int level)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->data_2311102128 == data)
    {
        cout << "Level node: " << level << endl;
        return;
    }

    findLevel(node->left_2311102128, data, level + 1);
    findLevel(node->right_2311102128, data, level + 1);
}
// Cek Size Tree
int size(Pohon *node = root_2311102128)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left_2311102128) + size(node->right_2311102128);
        }
    }
}
// Cek Height Level Tree
int height(Pohon *node = root_2311102128)
{
    if (isEmpty())
    {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left_2311102128);
            int heightKanan = height(node->right_2311102128);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}
// untuk menampilkan sebuah karateristik dari sebuah pohon yang dibuat
void characteristic()
{
    cout << "Size Tree : " << size() << endl;
    cout << "Height Tree : " << height() << endl;
    cout << "Average Node of Tree : " << size() / height() << endl;
}
int main()
{
    // variable yang digunakan untuk menampung sebuah data pilih, data, parentdata, parent node, dan selectnode
    int pilih_2311102128;
    char data_2311102128, ParentData_2311102128;
    Pohon *ParentNode_2311102128;
    Pohon *selectedNode_2311102128;
    init();
    // menu
    do
    {
        cout << "\nMenu Pilihan:\n";
        cout << "1. Membuat Root\n";
        cout << "2. Insert Right\n";
        cout << "3. Insert Left\n";
        cout << "4. Retrieve\n";
        cout << "5. Update\n";
        cout << "6. Tampilkan Child\n";
        cout << "7. Tampilkan Descendant\n";
        cout << "8. Tampilkan Ascending\n";
        cout << "9. Traversal (preorder, inorder, portorder, sibling)\n";
        cout << "10. Detail tree\n";
        cout << "11. Find Level\n";
        cout << "12. Karateristik\n";
        cout << "13. Delete Node\n";
        cout << "14. Exit\n";
        cout << "Pilihan: ";
        cin >> pilih_2311102128;

        switch (pilih_2311102128)
        {
            // menambahkan sebuah root
        case 1:
            cout << "Masukkan data node root: ";
            cin >> data_2311102128;
            buatNode(data_2311102128);
            break;

        // menambahkan child ke node bagain kanan
        case 2:
            cout << "Masukkan data node parent: ";
            cin >> ParentData_2311102128;
            ParentNode_2311102128 = find(ParentData_2311102128);
            if (ParentNode_2311102128 == nullptr)
            {
                cout << "Node parent tidak ditemukan!" << endl;
                break;
            }
            cout << "Masukkan data node: ";
            cin >> data_2311102128;
            insertRight(data_2311102128, ParentNode_2311102128);
            break;
        // menambahkan child ke node bagain kiri
        case 3:
            cout << "Masukkan data node parent: ";
            cin >> ParentData_2311102128;
            ParentNode_2311102128 = find(ParentData_2311102128);
            if (ParentNode_2311102128 == nullptr)
            {
                cout << "Node parent tidak ditemukan!" << endl;
                break;
            }
            cout << "Masukkan data node: ";
            cin >> data_2311102128;
            insertLeft(data_2311102128, ParentNode_2311102128);
            break;
            // untuk menampilkan sebuah isi dari node yang diinputkan
        case 4:
            cout << "Masukkan data node yang akan diretrieve: ";
            cin >> data_2311102128;
            retrieve(find(data_2311102128));
            break;
            // untuk mengupdate sebuah node yang akan di ganti dengan node baru
        case 5:
            cout << "Masukkan data yang ingin diupdate: ";
            cin >> data_2311102128;
            update(data_2311102128, root_2311102128);
            break;
            // untuk menampilkan node child
        case 6:
            cout << "Masukkan data node: ";
            cin >> data_2311102128;
            selectedNode_2311102128 = find(data_2311102128);
            if (selectedNode_2311102128 == nullptr)
            {
                cout << "Node tidak ditemukan." << endl;
            }
            else
            {
                tampilkanChild(selectedNode_2311102128);
            }
            break;
            // Menampilkan descendant dari sebuah node
        case 7:
            cout << "Masukkan data node: ";
            cin >> data_2311102128;
            selectedNode_2311102128 = find(data_2311102128);
            if (selectedNode_2311102128 == nullptr)
            {
                cout << "Node tidak ditemukan." << endl;
            }
            else
            {
                cout << "Descendant dari node " << data_2311102128 << ": ";
                tampilkanDescendant(selectedNode_2311102128);
                cout << endl;
            }
            break;
            // Menampilkan data secara ascending
        case 8:
            tampilkanAscending(root_2311102128);
            cout << endl;
            break;
            // untuk menampilkan sebuah travesal yaitu preorder, inorder, postorder, dan sibling dari tree
        case 9:
            cout << "Masukkan data node yang ingin ditampilkan traversal dan siblingnya: ";
            cin >> data_2311102128;
            selectedNode_2311102128 = find(data_2311102128);
            if (selectedNode_2311102128 == nullptr)
            {
                cout << "Node tidak ditemukan." << endl;
            }
            else
            {
                cout << "Traversal dan Sibling dari node " << data_2311102128 << ":\n";
                traversalAndSibling(selectedNode_2311102128);
            }
            break;
            // untuk mencari sebuah node yang di inputkan
        case 10:
            cout << "Masukkan data node : ";
            cin >> data_2311102128;
            cout << "Data node " << data_2311102128 << " : " << endl;
            find(find(data_2311102128));
            break;
            // untuk menampilkan level dari tree yang telah dibuat
        case 11:
            cout << "Masukkan data node yang ingin dicari levelnya: ";
            cin >> data_2311102128;
            findLevel(root_2311102128, data_2311102128, 1);
            break;
            // untuk menampilkan karateristik dari sebuah tree
        case 12:
            cout << "Detail Tree : " << endl;
            characteristic();
            break;
            // untuk menghapus sebuah node pada tree
        case 13:
            cout << "Masukkan data node yang ingin dihapus: ";
            cin >> data_2311102128;
            deleteNode(data_2311102128, root_2311102128);
            break;
            // keluar dari program
        case 14:
            cout << "Keluar dari program.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
            break;
        }
    } while (pilih_2311102128 != 14);

    return 0;
}