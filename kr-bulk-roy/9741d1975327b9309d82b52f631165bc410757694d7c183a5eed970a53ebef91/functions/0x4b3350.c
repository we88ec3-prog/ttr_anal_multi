
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b3350(uint param_1)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  uint uVar6;
  int iVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar3 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00936cde;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = *(ushort *)(param_1 + 2);
  iVar4 = FUN_0040f060(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *(uint *)(iVar4 + 0x94) = (uint)uVar1;
  iVar4 = FUN_0040f060();
  iVar4 = *(int *)(iVar4 + 4);
  if ((DAT_00fd8ef8 & 1) == 0) {
    DAT_00fd8ef8 = DAT_00fd8ef8 | 1;
    local_8 = 0;
    FUN_00498280();
    _atexit(FUN_00bcddd0);
    local_8 = 0xffffffff;
  }
  param_1 = (uint)*(ushort *)(iVar4 + 0x3b);
  FUN_008438c0(&param_1);
  if (in_ECX == DAT_00fd8f00) {
    iVar4 = 0;
    goto switchD_004b344f_default;
  }
  iVar4 = *(int *)(in_ECX + 0x10);
  if (*(int *)(iVar4 + 0x48) == 0) {
    FUN_0053e120();
  }
  *(int *)(iVar4 + 0x48) = *(int *)(iVar4 + 0x48) + 1;
  piVar2 = *(int **)(iVar4 + 0x40);
  if (piVar2 == (int *)0x0) goto switchD_004b344f_default;
  iVar7 = *piVar2;
  uVar5 = piVar2[1] - iVar7 >> 4;
  uVar6 = 0;
  if (uVar5 != 0) {
    do {
      if (*(short *)(iVar7 + 8) == *(short *)(iVar3 + 2)) {
        uVar8 = *(undefined1 *)(iVar7 + 0xc);
        goto LAB_004b3423;
      }
      uVar6 = uVar6 + 1;
      iVar7 = iVar7 + 0x10;
    } while (uVar6 < uVar5);
  }
  uVar8 = 0;
LAB_004b3423:
  if ((_DAT_00fdf3c0 & 1) == 0) {
    _DAT_00fdf3c0 = _DAT_00fdf3c0 | 1;
    DAT_00fdf3c4 = 0;
    _atexit((_func_4879 *)&DAT_00bcdf50);
  }
  switch(uVar8) {
  case 0:
    uVar9 = 0;
    goto LAB_004b3496;
  case 1:
    *(undefined4 *)(DAT_00fdf3c4 + 0x68) = 0xbfc90fdb;
    break;
  case 2:
    *(undefined4 *)(DAT_00fdf3c4 + 0x68) = 0x3fc90fdb;
    break;
  case 3:
    uVar9 = 0x40490fdb;
LAB_004b3496:
    *(undefined4 *)(DAT_00fdf3c4 + 0x68) = uVar9;
  }
switchD_004b344f_default:
  piVar2 = (int *)(iVar4 + 0x48);
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_0053e1d0();
  }
  if (*(int *)(iVar4 + 0x48) < 0) {
    FUN_006edb60("Stage::Release(): refCount < 0");
  }
  ExceptionList = local_10;
  return 0;
}

