                                    //------------------------------------------------------------------------//
                                    //                  Author : Seifeldeen Mohamed Ahmed                     //
                                    //------------------------------------------------------------------------//
#include <iostream>
using namespace std;
template <class T>
class seifVector
{
private:
    int size , capacity;
    T* data;
    typedef T* iterator;
public:
/**
 * @brief Construct a new seifVector this is the default constructor
 * 
 * @param cap
 */
        //__Constructor__//
    seifVector(int cap)
    {
        //This the default constructor as we prepare our size and the capicity of the vector by giving them a default value
        capacity = cap;
        size = 0;
        data = new T[capacity];
    }
//+++++++++++++++++++++++++++++++++++++++
/**
 * @brief defining the indices and items of the vector
 * 
 * @param another_vector
 * @param n
 */
    seifVector (T* another_vector , int n)
    {
        //We here define our template (vector)
        data = new T[n];
        for (int i = 0; i < n; i++)
        {
            data[i] = another_vector[i];
        }
        size = n;
        capacity = n;
    }
//+++++++++++++++++++++++++++++++++++++++
/**
 * @brief Allowing to take copies of the vector for the others
 * 
 * @param another_vector
 */
        //__Copy Constructor__//
    seifVector (const seifVector& another_vector)
    {
        //This is for making the deal with our vector easier and can take a copy for another vectors
        data = new T[another_vector.capacity];
        for (int i = 0; i < another_vector.size; i++)
        {
            data[i] = another_vector.data[i];
        }
        size = another_vector.size;
        capacity = another_vector.capacity;
    }
//+++++++++++++++++++++++++++++++++++++++
/**
 * @brief Destroy the seifVector object
 * 
 */
        //__Destructor__//
    ~seifVector()
    {
        // This what happens at the end of the program
        delete[] data;
    }
//+++++++++++++++++++++++++++++++++++++++
/**
 * @brief Allowing to use the (=) operator for assigning vectors and it's items to each other
 * 
 * @param another_vector 
 * @return seifVector& 
 */
        //__Copy Assignment__//
    seifVector &operator=(const seifVector& another_vector)
    {
        if (this != &another_vector)
        {
            delete[] data;
            size = another_vector.size;
            capacity = another_vector.capacity;
            data = new T[capacity];
        }
        for (int i = 0; i < size; i++)
        {
            data[i] = another_vector.data[i];
        }
    }
//+++++++++++++++++++++++++++++++++++++++
/**
 * @brief Allowing to use(=) operator and making a specified memory for each vector
 * 
 * @param another_vector 
 * @return seifVector& 
 */
        //__Move Assignment__//
    seifVector &operator=(const seifVector&& another_vector)
    {
        if (this != another_vector)
        {
            delete[] data;
            size = another_vector.size;
            capacity = another_vector.capacity;
            data = another_vector.data;
            another_vector.data = nullptr;
            another_vector.size = 0;
            another_vector.capacity = 0;
        }
    }
//+++++++++++++++++++++++++++++++++++++++
        //__Access Opeartions__//
    T& operator[] (int index)
    {
        //Here we define the indices of the template(vector)
        if (index > size - 1)
        {
            cout << "Error as the index is out of range :(" << "\n";
            exit(-1);
        }
        return data[index];
    }
//+++++++++++++++++++++++++++++++++++++++
        //__Modyfying Opeartions__//
    void push_back (T item)
    {
        if (capacity > size)                            
        {
            data[size++] = item; // Here we make our size dynamic as we make it increase when we push an element 
        }
        else
        {
            cout << "Converting capacity to " << capacity*2 << endl;
            T* newdata = new T[capacity * 2]; //Making New capicity to push back successfully
            capacity *= 2;
            for (int i = 0; i < size; i++)
            {
                newdata[i] = data[i];         // We should make the new template in the memory be exactly like the old one
            }
            delete[] data;                    // getting rid of the old vector as it doesn't have our new element so we don't need it
            data = newdata;
            newdata = nullptr;
            data[size++] = item;
        }
    }
//+++++++++++++++++++++++++++++++++++++++++++
/**
 * @brief Decreasing the size by 1 to get rid of the last element
 * 
 * @return T 
 */
        //__Remove and return last element__//
    T pop_back()
    {
        if (size == 0)
        {
            cout << "Error as the vector is empty :(" << endl;
        }
        else
        {
            size--;
            return data[size];
        }
        return data[size];
    }
//+++++++++++++++++++++++++++++++++++++++++++++
        //__Iterators__//
    void erase(iterator it)
    {
        if (it > this->end()) {
            throw out_of_range("erasing an element out of bounds");
        }
        size--;
        for (auto i = it; i != this->end(); i++) {
            *i = *(i + 1);
        }
    }
        //------------------//
    void erase(iterator it1 , iterator it2)
    {
        if (it1 > this->end() || it2 > this->end() ) {
            throw out_of_range("erasing an element out of bounds");
        }
        size -= (it2+1 - it1);
        int z = 1;
        for (auto i = it1; i <= it2; i++) {

            *i = *(it2+ z);
            z++;
        }
    }
        //------------------//
    iterator begin()
    {
        return data;
    }
        //------------------//
    iterator end()
    {
        return data + size;
    }
//+++++++++++++++++++++++++++++++++++++++++++++
        //__Another Methods__//
    void clear()
    {
        delete[] data;
        data = new T[2];
        capacity = 2;
        size = 0;                    // Clearing the Vector by making size = 0 as we deletd all the cells
    }
        //------------------//
    void insert (iterator it , T element)
    {
        if (it > this->end() || it < this->begin() ) {
            throw out_of_range("inserting an element out of bounds");
        }
        size++;
        for (auto i = this->end(); i != it; i--) {

            *i = *(i-1);
        }
        *it = element;
    }
        //------------------//
    int Size()
    {
        return size;
    }
        //------------------//
    int Capacity()
    {
        return capacity;
    }
        //------------------//
    bool empty()
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }
        //------------------//
/**
 * @brief Resizing our vector by making a new vector with the new size
 * 
 * @return int 
 */
    int resize()        
    {
        capacity *= 2;
        T* new_size = new T[2 * capacity];
        for (int i = 0; i < size; i++)
        {
            new_size[i] = data[i];
        }
        delete[] data;
        data = new_size;
        new_size = nullptr;
        return capacity;
    }
//+++++++++++++++++++++++++++++++++++++++++++++
        //__Comparison operations_//
    bool operator==(const seifVector<T>& another_vector)
    {
        if (size != another_vector.size) // We here compare the sizes 
        {
            return false;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (data[i] != another_vector.data[i]) // if any element of a vector doesn't equal to the other elemnth in the other vector so 
                {                                      // they don't equal even they have the same size
                    return false;
                }   
            }
            return true;
        }
    }
        //------------------//
    bool operator<(const seifVector<T>& another_vector)                  
    {
        if (size < another_vector.size)
        {
            return true;
        }
        else if (size > another_vector.size)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if (data[i] > another_vector.data[i])
                {
                    return false;
                }   
            }
            return true;
        }
    }
//+++++++++++++++++++++++++++++++++++++++++++++
/**
 * @brief Printing our vector in a nice form
 * 
 * @param out 
 * @param v 
 * @return ostream& 
 */
        //__Friends__//
    friend ostream& operator<< (ostream& out , seifVector<T> v)
    {
        // We use this to print our template like printing a vector
        cout << "Vector: [ ";   
        for (int i = 0; i < v.size; i++)
        {
            cout << v[i] << " ";
        }
        cout << "]\n";
        return out;
    }
};
//_____________________________________________________________
int main()
{
    int cap;
    cout << "Enter the capacity you want for the vector: ";
    cin >> cap;
    seifVector <int> seif(cap);
    int choice;
    while (true)
    {
        cout << "1- Push_back a value\n2- Pop_back a value\n3- Insert a value\n"
        <<"4- Erase a one value by position\n5- Erase a range of values with two iterators\n6- Clear the vector\n"
        <<"7- Print vector's elements\n8- Get the size of the vector\n9- Exit\n\n\n";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter the element: ";
                int ele;cin >> ele;
                seif.push_back((int)ele);
                break;
            //___________________________________
            case 2:
                seif.pop_back();
                break;
            //___________________________________
            case 3:
                int i,element;
                cout << "Enter the element: ";
                cin >> element;
                cout << "Enter the position: ";
                cin >> i;
                seif.insert(seif.begin() + i , element);
                break;
            //___________________________________
            case 4:
                cout << "Enter the position of the element you want to delete: ";
                int pos;cin >> pos;
                seif.erase(seif.begin() + pos);
                break;
            //___________________________________
            case 5:
                int x,y;
                cout << "Enter the range you want to delete from x to y: ";
                cin >> x >> y;
                seif.erase(seif.begin() + x , seif.begin() + y);
                break;
            //___________________________________
            case 6:
                seif.clear();
                break;
            //___________________________________
            case 7:
                cout << seif;
                break;
            //___________________________________
            case 8:
                cout << "Size --> " << seif.Size() << endl << endl;
                break;
            //___________________________________
            case 9:
                cout << "GoodBye :)";
                exit(0);
            //___________________________________
            default:
                cout << "Invalid choice\n";
        }
    }
}