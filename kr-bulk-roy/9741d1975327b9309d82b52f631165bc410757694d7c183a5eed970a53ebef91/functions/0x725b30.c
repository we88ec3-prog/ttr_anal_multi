
void FUN_00725b30(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *in_EAX;
  int *piVar3;
  int local_c;
  int local_8;
  
  uVar2 = param_2;
  iVar1 = *in_EAX;
  while (iVar1 != 0) {
    param_2 = iVar1;
    FUN_0071d780(uVar2,&param_2);
    if (iVar1 == 0) {
      local_c = 0;
      piVar3 = &local_c;
    }
    else {
      local_8 = *(int *)(iVar1 + 4);
      piVar3 = &local_8;
    }
    iVar1 = *piVar3;
  }
  return;
}

