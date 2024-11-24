
//--------------------------------------------------

template <typename T>
T* GameObject::get_component () {

    for (Component* comp : components_) {

        T* casted_comp = dynamic_cast<T*> (comp);
        if (casted_comp == nullptr) continue;
        return casted_comp;
    }

    return nullptr;
}

//--------------------------------------------------
