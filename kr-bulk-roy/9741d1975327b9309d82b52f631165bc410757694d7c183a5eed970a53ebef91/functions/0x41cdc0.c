
void FUN_0041cdc0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00927cce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_8 = 0;
    FUN_004a79a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&DAT_00bccf80);
  }
  uVar6 = DAT_00fb7284 - DAT_00fb7280 >> 2;
  uVar5 = 0;
  if (uVar6 != 0) {
    do {
      piVar1 = *(int **)(DAT_00fb7280 + uVar5 * 4);
      if (((char)piVar1[2] != '\0') && (*piVar1 == param_2)) {
        iVar2 = *(int *)(*(int *)(param_1 + 0xe0) + uVar5 * 4);
        uVar3 = *(undefined4 *)(iVar2 + 0xc);
        *unaff_ESI = *(undefined4 *)(iVar2 + 8);
        uVar4 = *(undefined4 *)(iVar2 + 0x10);
        unaff_ESI[1] = uVar3;
        uVar3 = *(undefined4 *)(iVar2 + 0x14);
        unaff_ESI[2] = uVar4;
        unaff_ESI[3] = uVar3;
        ExceptionList = local_10;
        return;
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar6);
  }
  unaff_ESI[3] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[1] = 0;
  *unaff_ESI = 0;
  ExceptionList = local_10;
  return;
}

