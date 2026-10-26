
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0080a6f0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar3 = DAT_00fab048;
  puStack_c = &LAB_0091172d;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (DAT_00fab048 != 0) {
    puVar1 = (undefined4 *)(DAT_00fab048 + 0x5c);
    if (0xf < *(uint *)(DAT_00fab048 + 0x70)) {
      FUN_0089120c(*puVar1,uVar4);
    }
    *(undefined4 *)(iVar3 + 0x70) = 0xf;
    *(undefined4 *)(iVar3 + 0x6c) = 0;
    *(undefined1 *)puVar1 = 0;
    FUN_0089120c(iVar3,uVar4);
  }
  iVar3 = DAT_00fab04c;
  if (DAT_00fab04c != 0) {
    puVar1 = (undefined4 *)(DAT_00fab04c + 0x5c);
    if (0xf < *(uint *)(DAT_00fab04c + 0x70)) {
      FUN_0089120c(*puVar1,uVar4);
    }
    *(undefined4 *)(iVar3 + 0x70) = 0xf;
    *(undefined4 *)(iVar3 + 0x6c) = 0;
    *(undefined1 *)puVar1 = 0;
    FUN_0089120c(iVar3,uVar4);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00fab0b4);
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00fab09c);
  piVar5 = (int *)*DAT_00fab084;
  *DAT_00fab084 = (int)DAT_00fab084;
  DAT_00fab084[1] = (int)DAT_00fab084;
  _DAT_00fab088 = 0;
  if (piVar5 != DAT_00fab084) {
    do {
      piVar2 = (int *)*piVar5;
      FUN_0089120c(piVar5);
      piVar5 = piVar2;
    } while (piVar2 != DAT_00fab084);
  }
  FUN_0089120c(DAT_00fab084);
  local_8._0_1_ = 3;
  FUN_0057ffd0(*DAT_00fab074,DAT_00fab074);
  FUN_0089120c(DAT_00fab074);
  local_8._0_1_ = 4;
  FUN_0057ffd0(*DAT_00fab064,DAT_00fab064);
  FUN_0089120c(DAT_00fab064);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_0057ffd0(*DAT_00fab054,DAT_00fab054);
  FUN_0089120c(DAT_00fab054);
  if (0xf < DAT_00fab040) {
    FUN_0089120c(_DAT_00fab02c);
  }
  DAT_00fab040 = 0xf;
  _DAT_00fab03c = 0;
  _DAT_00fab02c = _DAT_00fab02c & 0xffffff00;
  ExceptionList = local_10;
  return;
}

