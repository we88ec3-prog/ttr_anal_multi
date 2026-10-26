
int FUN_008c9af0(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined4 param_5,
                int param_6,undefined4 param_7)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_30 [20];
  undefined1 local_1c [8];
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_c;
  undefined1 local_a;
  
  uVar2 = *(uint *)(param_1 + 0x2dc);
  if (uVar2 == 0) {
    return 2;
  }
  if (uVar2 < 3) {
    iVar4 = FUN_008c8bd0(param_2,param_7);
    if (iVar4 != 0) {
      return iVar4;
    }
    iVar4 = FUN_008c9500(local_30,param_3,0,0);
  }
  else {
    if (uVar2 != 3) {
      return 2;
    }
    iVar4 = FUN_008c98b0(param_1,param_2,param_3,param_7);
  }
  if (((iVar4 == 0) && ((param_4 & 0x100000) == 0)) && (*(char *)(param_6 + 0x12) == '\a')) {
    uVar3 = **(undefined4 **)(param_1 + 0x54);
    FUN_008fbe20(local_1c);
    iVar4 = FUN_008fbff0(uVar3,param_6,local_1c,1);
    if (iVar4 != 0) {
      FUN_008fc3d0(uVar3,local_1c);
      return iVar4;
    }
    *(undefined1 *)(param_6 + 0x12) = local_a;
    *(undefined4 *)(param_6 + 8) = local_14;
    *(undefined2 *)(param_6 + 0x10) = local_c;
    FUN_008ba350(*(undefined4 *)(param_1 + 0x54),local_10);
    puVar1 = (uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x9c) + 4);
    *puVar1 = *puVar1 | 1;
    iVar4 = 0;
  }
  return iVar4;
}

