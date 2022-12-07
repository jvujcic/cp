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

bool ls_match(string input) {
    regex rgx = regex("^\\$ ls");
    return regex_match(input, rgx);
}

bool cd_match(string input, string& dir) {
    regex rgx = regex("^\\$ cd\\s(.*)$");
    smatch sm;
    if (regex_match(input, sm, rgx)) {
        dir = sm[1];
        return true;
    }
    return false;
}

bool file_match(string input, string& filename, ll& filesize) {
    regex rgx = regex("^(\\d*)\\s(.*)$");
    smatch sm;
    if (regex_match(input, sm, rgx)) {
        filename = sm[2];
        filesize = stoll(sm[1]);
        return true;
    };

    return false;
}

bool dir_match(string input, string& dir) {
    regex rgx = regex("^dir\\s(.*)$");
    smatch sm;
    if (regex_match(input, sm, rgx)) {
        dir = sm[1];
        return true;
    }
    return false;
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
        string dirname, size, filename;
        ll filesize;
        if (ls_match(input)) {
        } else if (cd_match(input, dirname)) {
            if (dirname == "/")
                current_dir = root;
            else if (dirname == "..")
                current_dir = current_dir->parent;
            else {
                dir* d = new dir{.name = dirname};
                current_dir = add_dir(current_dir, d);
            }
        } else if (file_match(input, filename, filesize)) {
            file f = file{.name = filename, .size = filesize};
            add_file(current_dir, f);
        } else if (dir_match(input, dirname)) {
        }
    }

    calculate_size(root);
    cout << sum_sizes_less_than(max_size, root) << endl;

    return 0;
}
