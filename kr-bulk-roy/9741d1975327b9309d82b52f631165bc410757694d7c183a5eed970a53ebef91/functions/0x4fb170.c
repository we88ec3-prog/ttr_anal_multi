
void FUN_004fb170(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0xcd);
  while (cVar1 == '\0') {
    FUN_004fb170(param_1[2]);
    piVar2 = (int *)*param_1;
    _eh_vector_destructor_iterator_(param_1 + 6,0x24,5,FUN_004fa440);
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0xcd);
  }
  return;
}

