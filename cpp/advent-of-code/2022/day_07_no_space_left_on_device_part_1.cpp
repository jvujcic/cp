#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using ull = uint64_t;

struct file {
    string name;
    ll size;
};

bool operator==(const file& lhs, const file& rhs) {
    return lhs.name == rhs.name;
}

struct hash_file {
    size_t operator()(const file& f) const {
        return hash<string>()(f.name);
    }
};

struct dir;
struct hash_dir {
    size_t operator()(const dir* d) const;
};
struct comp_dir {
    bool operator()(const dir* lhs, const dir* rhs) const;
};

struct dir {
    string name;
    unordered_set<file, hash_file> files{};
    unordered_set<dir*, hash_dir, comp_dir> dirs{};
    ll size = 0;
    dir* parent = nullptr;
};

size_t hash_dir::operator()(const dir* d) const {
    return hash<string>()(d->name);
}

bool comp_dir::operator()(const dir* lhs, const dir* rhs) const {
    return lhs->name == rhs->name;
}

dir* add_dir(dir* parent, dir* child) {
    child->parent = parent;
    return *parent->dirs.insert(child).first;
}

void add_file(dir* parent, file& file) {
    parent->files.insert(file);
}

void calculate_size(dir* d) {
    d->size = accumulate(d->files.begin(), d->files.end(), 0, [](ll s, const file& f) { return f.size + s; });

    for (auto subd : d->dirs) {
        calculate_size(subd);
        d->size += subd->size;
    }
}

ll sum_sizes_less_than(ll size, dir* d) {
    ll sum = 0;

    for (auto subd : d->dirs)
        sum += sum_sizes_less_than(size, subd);

    if (d->size <= size)
        sum += d->size;

    return sum;
}

int main() {
    const ll max_size = 100'000;
    string input;
    dir* root = new dir{.name = "/"};
    dir* current_dir = root;

    getline(cin, input);
    if (input != "$ cd /")
        exit(1);

    while (getline(cin, input)) {
        char dirname[100], filename[100];
        ll filesize;
        if (input == "$ ls") {
        } else if (input == "$ cd /") {
            current_dir = root;
        } else if (input == "$ cd ..") {
            current_dir = current_dir->parent;
        } else if (sscanf(input.c_str(), "$ cd %s", dirname)) {
            dir* d = new dir{.name = dirname};
            current_dir = add_dir(current_dir, d);
        } else if (sscanf(input.c_str(), "%lld %s", &filesize, filename)) {
            file f = file{.name = filename, .size = filesize};
            add_file(current_dir, f);
        }
    }

    calculate_size(root);
    cout << sum_sizes_less_than(max_size, root) << endl;

    return 0;
}
