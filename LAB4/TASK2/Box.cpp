#include <iostream>

// realistically, there shouldnt be more than 100 boxes 
const int MAX_BOXES = 100;

class Box {
    private:
        Box *children[MAX_BOXES];
        Box *parent;
        int size, boxes, id, remaining;
    public:
        Box(int _size, int _id) : children(), parent(nullptr), boxes(0), id(_id), size(_size), remaining(_size) {}
        Box(int _size, int _id, Box parent) : children(), parent(&parent), boxes(0), id(_id), size(_size), remaining(_size) {}

        int getSize() {
            return size;
        }

        int getBoxes() {
            return boxes;
        }

        int getId() {
            return id;
        }

        Box* getParentPointer() {
            return parent;
        }

        int getRemaining() {
            return remaining;
        }

        bool canAddBox(Box box) {
            if (box.getSize() < remaining) {
                return true;
            } else {
                return false;
            }
        }

        void addBox(Box box) {
            children[boxes] = &box;
            remaining -= box.getSize();
            boxes++;
        }
};

int main() {
    int size, next;
    int n_boxes = 0;
    bool repeat = false;
    Box *boxes[MAX_BOXES];
    
    std::cout << "Enter first box size: ";
    std::cin >> size;

    Box box(size, n_boxes);
    boxes[0] = &box;
    n_boxes++;

    do {
        std::cout << "Would you like to create another box? (0 or 1): ";
        std::cin >> repeat;

        if (!repeat) {
            continue;
        }

        std::cout << "\nPrinting all boxes" << std::endl;
        for (int i = 0; i < n_boxes; i++) {
            Box c = *boxes[i];


            std::cout << "Box " << c.getId() + 1 << ": " << std::endl;
            std::cout << "  Size: " << c.getSize() << std::endl;
            std::cout << "  Remaining space: " << c.getRemaining() << std::endl;

            if (c.getParentPointer() != nullptr) {
                Box p = *c.getParentPointer();
                std::cout << "  Parent: " << p.getId() + 1 << std::endl;
            }
        }


        // check for correct index
        std::cout << "\nChoose a box parent (0 for none): ";
        std::cin >> next;

        if (next == 0) {
            std::cout << "Enter box size: ";
            std::cin >> size;

            Box n(size, n_boxes);
            boxes[n_boxes] = &n;
            n_boxes++;
        } else {
            Box chosen = *boxes[next - 1];

            std::cout << "Enter box size: ";
            std::cin >> size;

            Box n(size, n_boxes);

            if (chosen.canAddBox(n)) {
                chosen.addBox(n);
                boxes[n_boxes] = &n;
                n_boxes++;
            } else {
                std::cout << chosen.getSize() << " " << chosen.getRemaining() << std::endl;
                std::cout << n.getSize() << " " << n.getRemaining() << std::endl;
            }
        }

        //decrement chosen, to account for array position
        //next--;

        // Box chosen = *boxes[next];






    } while (repeat == true);

    return 0;
}

    // do {
    //     std::cout << "Would you like to create another box? (0 or 1): ";
    //     std::cin >> repeat;

    //     if (!repeat) {
    //         continue;
    //     }

    //     std::cout << "\nPrinting all boxes" << std::endl;
    //     for (int i = 0; i < n_boxes; i++) {
    //         Box c = *boxes[i];
    //         std::cout << "Box " << i + 1 << ": " << std::endl;
    //         std::cout << "  Size: " << c.getSize() << std::endl;
    //         std::cout << "  Remaining space: " << c.getRemainingSpace() << std::endl;
    //     }


    //     // check for correct index
    //     std::cout << "\nChoose a box parent (0 for none): ";

    //     std::cin >> next;
    //     //decrement chosen, to account for array position
    //     next--;

    //     Box chosen = *boxes[next];

    //     std::cout << "Enter box size: ";
    //     std::cin >> size;

    //     std::cout << size << std::endl;

    //     Box n(size);

    //     if (chosen.canAddBox(n)) {
    //         chosen.addBox(n);
    //         boxes[n_boxes] = &n;
    //         n_boxes++;
    //     } else {
    //         std::cout << "Size must be less than " << chosen.getRemainingSpace() << "!" << std::endl;
    //     }
    // } while (repeat == true);

    // for (int i = 0; i < n_boxes; i++) {
    //     Box b = *boxes[i];
    //     std::cout << b.getRemainingSpace() << std::endl;
    // }
