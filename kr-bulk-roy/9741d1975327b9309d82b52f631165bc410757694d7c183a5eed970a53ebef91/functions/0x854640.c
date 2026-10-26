
int FUN_00854640(int param_1)

{
  int in_EAX;
  int unaff_EDI;
  
  if ((param_1 != unaff_EDI) && (unaff_EDI != in_EAX)) {
    FUN_008549e0(param_1);
    return param_1 + ((in_EAX - unaff_EDI) / 0xc) * 0xc;
  }
  return param_1;
}

