
int FUN_00854600(int param_1)

{
  int in_EAX;
  int unaff_EDI;
  
  if ((param_1 != unaff_EDI) && (unaff_EDI != in_EAX)) {
    FUN_00854860(param_1);
    return param_1 + ((in_EAX - unaff_EDI) / 0x18) * 0x18;
  }
  return param_1;
}

