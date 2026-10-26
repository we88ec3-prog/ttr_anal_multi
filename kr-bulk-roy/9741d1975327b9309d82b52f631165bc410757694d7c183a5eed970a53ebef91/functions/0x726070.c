
void FUN_00726070(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 in_EAX;
  int *piVar2;
  int *in_ECX;
  int unaff_EDI;
  int local_c;
  int local_8;
  
  if (*(char *)(unaff_EDI + 3) == '\x02') {
    FUN_0071d6a0(unaff_EDI,param_1,in_EAX,in_ECX);
  }
  iVar1 = *in_ECX;
  while (iVar1 != 0) {
    param_2 = iVar1;
    FUN_0071d780(param_1,&param_2);
    if (iVar1 == 0) {
      local_c = 0;
      piVar2 = &local_c;
    }
    else {
      local_8 = *(int *)(iVar1 + 4);
      piVar2 = &local_8;
    }
    iVar1 = *piVar2;
  }
  return;
}

