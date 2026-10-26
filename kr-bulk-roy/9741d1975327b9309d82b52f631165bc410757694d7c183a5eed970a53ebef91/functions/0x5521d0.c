
int FUN_005521d0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009296cc;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_2 == 0) {
    iVar3 = -1;
    iVar6 = param_5;
  }
  else {
    iVar3 = param_5 + -1;
    iVar6 = 0;
  }
  puVar4 = (undefined4 *)FUN_00551b80(iVar6,iVar3);
  if (puVar4 == (undefined4 *)0x0) {
    ExceptionList = local_10;
    return 0;
  }
  param_5 = FUN_00891268(0x7c,uVar2);
  if (param_5 == 0) {
    param_5 = 0;
  }
  else {
    *(undefined4 *)(param_5 + 0x24) = 0;
    *(undefined4 *)(param_5 + 0x28) = 0;
    *(undefined4 *)(param_5 + 0x6c) = 0;
    *(undefined4 *)(param_5 + 0x74) = 1;
    *(undefined4 *)(param_5 + 0x78) = 0x1e;
    *(undefined1 *)(param_5 + 0x2c) = 0;
  }
  param_1 = param_5;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  uVar5 = FUN_004f6f70();
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 1;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8 = 0xffffffff;
  }
  if (0xf < (uint)puVar4[5]) {
    puVar4 = (undefined4 *)*puVar4;
  }
  FUN_00550580(puVar4,uVar5,param_4,0,DAT_00fb90bc);
  iVar6 = *(int *)(iVar1 + 4);
  iVar3 = FUN_0074d700(iVar6,*(undefined4 *)(iVar6 + 4),&param_1);
  if (*(int *)(iVar1 + 8) != 0x3ffffffe) {
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    *(int *)(iVar6 + 4) = iVar3;
    **(int **)(iVar3 + 4) = iVar3;
    ExceptionList = local_10;
    return param_5;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("list<T> too long");
}

