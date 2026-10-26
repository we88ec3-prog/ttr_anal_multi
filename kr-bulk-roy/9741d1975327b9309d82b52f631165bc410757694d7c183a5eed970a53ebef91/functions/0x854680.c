
int FUN_00854680(int param_1)

{
  int in_EAX;
  int unaff_EDI;
  
  if ((param_1 != unaff_EDI) && (unaff_EDI != in_EAX)) {
    FUN_00854ae0(param_1);
    return param_1 + ((in_EAX - unaff_EDI) / 0x14) * 0x14;
  }
  return param_1;
}

