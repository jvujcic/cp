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

ll find_dir_to_delete(ll min_size_to_free, dir* d, ll current_min_size) {
    if (d->size >= min_size_to_free && d->size < current_min_size)
        current_min_size = d->size;

    for (auto subd : d->dirs)
        current_min_size = min(current_min_size, find_dir_to_delete(min_size_to_free, subd, current_min_size));

    return current_min_size;
}

int main() {
    const ll disk_space = 7'000'0000;
    const ll needed_space = 3'000'0000;

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

    ll min_size_to_free = needed_space - (disk_space - root->size);
    if (min_size_to_free < 0)
        exit(1);

    cout << find_dir_to_delete(min_size_to_free, root, root->size) << endl;

    return 0;
}
