
undefined4 FUN_006efef0(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00907fcc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar4 = false;
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    puVar1 = (undefined4 *)FUN_00891268(0x18,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8 = 0;
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      iVar2 = *(int *)(*param_2 + 0x18);
      if (iVar2 == 0) {
        iVar2 = *param_2 + 0x1c;
      }
      uVar3 = FUN_00431550(iVar2);
      bVar4 = true;
      puVar1[1] = 0;
      local_8 = 2;
      *puVar1 = std::numpunct<char>::vftable;
      FUN_006effc0(uVar3,1);
    }
    *param_1 = (int)puVar1;
    local_8 = 0xffffffff;
    if (bVar4) {
      FUN_00431620();
    }
  }
  ExceptionList = local_10;
  return 4;
}

