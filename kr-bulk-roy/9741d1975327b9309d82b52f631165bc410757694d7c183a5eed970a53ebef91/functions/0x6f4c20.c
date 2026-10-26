
undefined4 FUN_006f4c20(int param_1)

{
  int iVar1;
  int iVar2;
  int *unaff_EDI;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  code *local_14;
  int *local_10;
  int local_c;
  
  local_c = *unaff_EDI;
  local_10 = &local_24;
  local_1c = 0;
  local_18 = 0;
  local_24 = param_1;
  local_14 = FUN_006f70e0;
  iVar1 = FUN_006fe990(local_c);
  if (iVar1 == 0) {
    iVar1 = *unaff_EDI;
    local_24 = *(int *)(iVar1 + 8) + -0x10;
    local_20 = 0xffffffff;
    iVar2 = FUN_006fe770(FUN_006f5a50,&local_24,local_24 - *(int *)(iVar1 + 0x20));
    if (*(uint *)(*(int *)(iVar1 + 0x14) + 8) <= *(uint *)(iVar1 + 8)) {
      *(uint *)(*(int *)(iVar1 + 0x14) + 8) = *(uint *)(iVar1 + 8);
    }
    if (iVar2 == 0) {
      return 0;
    }
  }
  FUN_006f47a0(unaff_EDI,param_1);
  return 1;
}

