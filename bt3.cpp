#include<iostream>
#include<string>
using namespace std;
struct Product
{
    string name;
    int price;
    int quantity;
    friend istream& operator>>(istream &is,Product &product)
    {
        cout<<"Nhap ten: ";
        is.ignore();
        getline(is,product.name);
        cout<<"Nhap gia: ";
        is>>product.price;
        cout<<"So luong: ";
        is>>product.quantity;
        return is;
    }
    friend ostream& operator<<(ostream &os,Product &product)
    {
        os<<"Name: "<<product.name<<endl;
        os<<"Gia: "<<product.price<<endl;
        os<<"So luong: "<<product.quantity<<endl;
        return os;
    }
};
int show_menu();
void xem_san_pham(Product *products,int size);
void them_san_pham(Product* &products,int &size);

int main()
{
    int size=0;
    Product *products= new Product[size];
    while (true)
    {
       int chose=show_menu();
       switch(chose)
       {
        case 1:
        xem_san_pham(products,size);
        break;
        case 2:
        them_san_pham(products,size);
        break;
        case 3:
        cout<<"Xoa san pham";
        break;
        case 0:
        cout<<"bye bye";
        return 0;
        default:
        cout<<"Lua chon khong hop le";
        break;
       }
       cout<<"Ban co muon tiep tuc khong(0/1)";
       bool is_continue;
       cin>>is_continue;
       if(!is_continue)
       {
        cout<<"bye bye";
        break;
       }
    }
    
    
}
int show_menu()
{
     system("cls");
    int chose;
   
    cout<<"=========Menu========"<<endl;
    cout<<"1.Xem san pham"<<endl;
    cout<<"2.Them san pham"<<endl;
    cout<<"3.Xoa san pham"<<endl;
    cout<<"0.Thoat chuong trinh"<<endl;
    cout<<"Lua chon cua ban : ";
    cin>>chose;
    return chose;

}
void xem_san_pham(Product *products,int size)
{
    if(size==0)
    {
        cout<<"Chua co san pham !"<<endl;
    }
    else{
        cout<<"Danh sach san pham"<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<products[i]<<endl;
        }
    }
}void them_san_pham(Product* &products,int &size)
{
    Product new_product;
    cout<<"Nhap thong tin san pham: "<<endl;
    cin>>new_product;
     int new_size=size+1;
    Product *tmp_products=new Product[new_size];
    for(int i=0;i<size;i++)
    {
        tmp_products[i]=products[i];
    }
    tmp_products[new_size-1]=new_product;
    delete[] products;
    products=tmp_products;
    size=new_size;
    cout<<"Them san pham thanh cong!"<<endl;

}
