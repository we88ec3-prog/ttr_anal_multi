
/* WARNING: Removing unreachable block (ram,0x00552cda) */
/* WARNING: Removing unreachable block (ram,0x00552ce0) */
/* WARNING: Removing unreachable block (ram,0x00552cee) */

void FUN_00552c70(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_8;
  
  fVar1 = (float)*(int *)(param_1 + 8);
  uVar4 = *(uint *)(param_1 + 0x24);
  if (*(int *)(param_1 + 8) < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  fVar2 = (float)(int)uVar4;
  if ((int)uVar4 < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  if (*(float *)(param_1 + 0x28) < fVar1 / fVar2) {
    iVar3 = 0;
    do {
      if (0x1ffffffe < uVar4) break;
      iVar3 = iVar3 + 1;
      uVar4 = uVar4 * 2;
    } while (iVar3 < 3);
    local_8 = *(undefined4 *)(param_1 + 4);
    iVar3 = *(int *)(param_1 + 0x10);
    if (iVar3 != *(int *)(param_1 + 0x14)) {
      *(int *)(param_1 + 0x14) = iVar3;
    }
    FUN_007dcc90(*(int *)(param_1 + 0x10),&local_8);
    *(uint *)(param_1 + 0x20) = uVar4 - 1;
    *(uint *)(param_1 + 0x24) = uVar4;
    FUN_00552d90(*(undefined4 *)(param_1 + 4));
  }
  return;
}

