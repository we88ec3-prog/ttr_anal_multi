
int FUN_00551dd0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,float param_5,
                int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *in_ECX;
  undefined4 *puVar4;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090d90e;
  local_10 = ExceptionList;
  if (in_ECX == (undefined4 *)0x0) {
    return 0;
  }
  ExceptionList = &local_10;
  iVar2 = FUN_00891268(0x7c,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    *(undefined4 *)(iVar2 + 0x24) = 0;
    *(undefined4 *)(iVar2 + 0x28) = 0;
    *(undefined4 *)(iVar2 + 0x6c) = 0;
    *(undefined4 *)(iVar2 + 0x74) = 1;
    *(undefined4 *)(iVar2 + 0x78) = 0x1e;
    *(undefined1 *)(iVar2 + 0x2c) = 0;
  }
  local_14 = iVar2;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 0;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8 = 0xffffffff;
  }
  if ((uint)in_ECX[0x13] < 0x10) {
    puVar4 = in_ECX + 0xe;
  }
  else {
    puVar4 = (undefined4 *)in_ECX[0xe];
  }
  if (0xf < (uint)in_ECX[5]) {
    in_ECX = (undefined4 *)*in_ECX;
  }
  FUN_00550580(in_ECX,puVar4,param_2,param_4,DAT_00fb90bc * param_5);
  if (param_6 != 0) {
    iVar1 = *(int *)(param_1 + 4);
    iVar3 = FUN_0074d700(iVar1,*(undefined4 *)(iVar1 + 4),&local_14);
    if (*(int *)(param_1 + 8) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("list<T> too long");
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    *(int *)(iVar1 + 4) = iVar3;
    **(int **)(iVar3 + 4) = iVar3;
  }
  ExceptionList = local_10;
  return iVar2;
}

