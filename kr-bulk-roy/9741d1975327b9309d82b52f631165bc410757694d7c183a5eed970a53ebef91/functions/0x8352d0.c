
void FUN_008352d0(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x51);
  while (cVar1 == '\0') {
    FUN_008352d0(param_1[2]);
    piVar2 = (int *)*param_1;
    _eh_vector_destructor_iterator_(param_1 + 4,0x10,4,FUN_00418290);
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x51);
  }
  return;
}

