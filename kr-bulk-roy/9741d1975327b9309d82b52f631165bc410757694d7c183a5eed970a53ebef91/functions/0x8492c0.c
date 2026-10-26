
int FUN_008492c0(int param_1)

{
  int in_EAX;
  int in_ECX;
  
  if ((in_ECX != param_1) && (param_1 != in_EAX)) {
    FUN_00849460();
    return ((in_EAX - param_1) / 100) * 100 + in_ECX;
  }
  return in_ECX;
}

