
bool FUN_006f7710(void)

{
  double *in_EAX;
  double *in_ECX;
  
  if (*(int *)(in_ECX + 1) != *(int *)(in_EAX + 1)) {
    return false;
  }
  switch(*(int *)(in_ECX + 1)) {
  case 0:
    return true;
  default:
    return *(int *)in_ECX == *(int *)in_EAX;
  case 3:
    break;
  }
  if (*in_EAX != *in_ECX) {
    return false;
  }
  return true;
}

