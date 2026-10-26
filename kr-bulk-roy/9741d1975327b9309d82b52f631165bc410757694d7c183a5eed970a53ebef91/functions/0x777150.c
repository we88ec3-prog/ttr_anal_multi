
bool FUN_00777150(void)

{
  short *in_EAX;
  
  if (*in_EAX == 0xe2f) {
    return true;
  }
  return *in_EAX == 0xe3f;
}

