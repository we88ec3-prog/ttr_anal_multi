
void FUN_00761550(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 in_EAX;
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if (*(char *)(param_1 + 0x141) != '\0') {
    puVar1 = (undefined4 *)
             FUN_0087dc3d(-(uint)((int)((ulonglong)param_3 * 2 >> 0x20) != 0) |
                          (uint)((ulonglong)param_3 * 2));
    if (0 < (int)param_3) {
      puVar3 = puVar1;
      for (uVar2 = param_3 >> 1; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar3 = 0x2a002a;
        puVar3 = puVar3 + 1;
      }
      for (uVar2 = (uint)((param_3 & 1) != 0); uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined2 *)puVar3 = 0x2a;
        puVar3 = (undefined4 *)((int)puVar3 + 2);
      }
    }
    FUN_00757da0(param_1 + 0x108);
    FUN_006ee0d0(param_2,in_EAX);
    FUN_00891d3d(puVar1);
    return;
  }
  FUN_00757da0(param_1 + 0x108);
  return;
}

