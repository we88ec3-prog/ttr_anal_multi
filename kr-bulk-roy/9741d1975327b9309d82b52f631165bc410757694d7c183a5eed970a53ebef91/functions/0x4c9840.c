
void FUN_004c9840(undefined1 param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  uint in_ECX;
  short sVar4;
  int *unaff_ESI;
  uint uVar5;
  undefined4 *puVar6;
  int local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00929e3c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar5 = in_ECX & 0xffff;
  local_14 = uVar5;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_8 = 0xffffffff;
  local_18 = uVar5;
  FUN_0047fdf0(&local_18);
  if (local_1c == DAT_00fb7504) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    puVar6 = (undefined4 *)(local_1c + 0x10);
    if (0xf < *(uint *)(local_1c + 0x24)) {
      puVar6 = (undefined4 *)*puVar6;
    }
  }
  if (unaff_ESI[uVar5 + 0x59] == 0) {
    iVar2 = unaff_ESI[0x2d];
    iVar1 = unaff_ESI[1];
    if ((DAT_00fdf6dc & 1) == 0) {
      DAT_00fdf6dc = DAT_00fdf6dc | 1;
      local_8 = 1;
      FUN_00550820();
      _atexit((_func_4879 *)&LAB_00bce6b0);
      local_8 = 0xffffffff;
    }
    local_18 = (**(code **)(*unaff_ESI + 0x4c))();
    if (puVar6 != (undefined4 *)0x0) {
      FUN_00551cd0();
    }
    iVar2 = FUN_00551dd0(&DAT_00fdf680,(short)iVar1,local_18,0,iVar2,0);
    unaff_ESI[(local_14 & 0xffff) + 0x59] = iVar2;
  }
  psVar3 = (short *)FUN_004ca0b0();
  sVar4 = (short)local_14;
  *psVar3 = sVar4;
  iVar2 = FUN_004ca0b0();
  *(undefined1 *)(iVar2 + 2) = param_1;
  iVar2 = FUN_004ca0b0();
  *(undefined1 *)(iVar2 + 3) = param_2;
  if ((unaff_ESI[0x100] == 0) && (sVar4 != 0x13)) {
    iVar2 = 0;
  }
  else {
    iVar2 = 1;
  }
  unaff_ESI[0x100] = iVar2;
  if ((unaff_ESI[0x101] == 0) && (sVar4 != 0x14)) {
    iVar2 = 0;
  }
  else {
    iVar2 = 1;
  }
  unaff_ESI[0x101] = iVar2;
  if ((unaff_ESI[0x102] == 0) && (sVar4 != 0x4f)) {
    iVar2 = 0;
  }
  else {
    iVar2 = 1;
  }
  unaff_ESI[0x102] = iVar2;
  ExceptionList = local_10;
  return;
}

