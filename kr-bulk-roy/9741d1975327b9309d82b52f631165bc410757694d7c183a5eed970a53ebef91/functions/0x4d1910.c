
undefined4 FUN_004d1910(void)

{
  undefined2 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int *in_ECX;
  undefined4 uVar7;
  undefined4 uVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939db8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar3 = FUN_004c7df0(in_ECX,0);
  (**(code **)(*in_ECX + 100))(uVar2);
  iVar5 = in_ECX[0x109];
  if (iVar5 == 1) {
    if ((DAT_00fdf6dc & 1) == 0) {
      local_8 = 0;
LAB_004d1a20:
      DAT_00fdf6dc = DAT_00fdf6dc | 1;
      FUN_00550820();
      _atexit((_func_4879 *)&LAB_00bce6b0);
      local_8 = 0xffffffff;
    }
LAB_004d1a39:
    uVar8 = 0x3f800000;
    uVar7 = 0;
    uVar4 = (**(code **)(*in_ECX + 0x4c))(0,0x3f800000);
    uVar1 = (undefined2)in_ECX[1];
  }
  else {
    if (iVar5 == 3) {
      if ((DAT_00fdf6dc & 1) == 0) {
        local_8 = 1;
        goto LAB_004d1a20;
      }
      goto LAB_004d1a39;
    }
    if (iVar5 != 5) goto LAB_004d1a63;
    if ((DAT_00fdf6dc & 1) == 0) {
      DAT_00fdf6dc = DAT_00fdf6dc | 1;
      local_8 = 2;
      FUN_00550820();
      _atexit((_func_4879 *)&LAB_00bce6b0);
      local_8 = 0xffffffff;
    }
    uVar8 = 0x3f800000;
    uVar7 = 0;
    uVar4 = (**(code **)(*in_ECX + 0x4c))(0,0x3f800000);
    uVar1 = (undefined2)in_ECX[1];
  }
  FUN_00551f20(uVar1,uVar4,uVar7,uVar8);
LAB_004d1a63:
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 3;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  iVar5 = FUN_004f7a70();
  puVar6 = (undefined4 *)(iVar5 + 0x1c);
  if (7 < *(uint *)(iVar5 + 0x30)) {
    puVar6 = (undefined4 *)*puVar6;
  }
  FUN_004d16e0(L"Lv.1 %s",puVar6);
  ExceptionList = local_10;
  return uVar3;
}

