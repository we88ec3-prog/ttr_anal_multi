
int * FUN_00722800(int *param_1)

{
  int iVar1;
  char cVar2;
  int *in_EAX;
  int *piVar3;
  int local_c;
  int local_8;
  
  if (*in_EAX == 0) {
    *param_1 = 0;
    return param_1;
  }
  iVar1 = *(int *)(*in_EAX + 0x1c);
  while( true ) {
    if (iVar1 == 0) {
      *param_1 = 0;
      return param_1;
    }
    cVar2 = FUN_0071cb00();
    if (cVar2 != '\0') break;
    if (iVar1 == 0) {
      local_c = 0;
      piVar3 = &local_c;
    }
    else {
      local_8 = *(int *)(iVar1 + 0x10);
      piVar3 = &local_8;
    }
    iVar1 = *piVar3;
  }
  *param_1 = iVar1;
  return param_1;
}

