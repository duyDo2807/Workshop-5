#include "Orchestra.h"

Orchestra::Orchestra() : Size(0), currentSize(0), members(0) {}

Orchestra::Orchestra(int size) : Size(size), currentSize(0) {
  members = new Musician[size];
}

int Orchestra::get_current_number_of_members() { return currentSize; }

bool Orchestra::has_instrument(std::string instrument) {
  for (int i = 0; i < currentSize; i++) {
    if (members[i].get_instrument() == instrument) {
      return true;
    }
  }
  return false;
}

Musician* Orchestra::get_members() { return members; }

bool Orchestra::add_musician(Musician new_musician) {
  if (currentSize < Size) {
    members[currentSize] = new_musician;
    currentSize++;
    return true;
  }
  return false;
}

Orchestra::~Orchestra() { delete[] members; }