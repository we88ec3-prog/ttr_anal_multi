
void FUN_00693240(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00936a1e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  uVar4 = 0;
  uVar2 = *(int *)(DAT_00fab130 + 0x5eec) - *(int *)(DAT_00fab130 + 0x5ee8) >> 2;
  if (uVar2 != 0) {
    piVar3 = (int *)(in_ECX + 0x90);
    do {
      if (3 < uVar4) break;
      iVar6 = *piVar3;
      if (*(int *)(iVar6 + 0xb0) == 0) {
        FUN_006940c0();
      }
      else if (*(int *)(iVar6 + 0xb0) == 1) {
        FUN_00694750(iVar6);
      }
      *(uint *)(iVar6 + 0xb4) = uVar4;
      *(uint *)(*(int *)(iVar6 + 0x80) + 0x194) = uVar4;
      iVar1 = *(int *)(iVar6 + 0xac);
      *(undefined4 *)(iVar1 + 0xe0) = *(undefined4 *)(iVar6 + 0xb4);
      *(undefined4 *)(iVar1 + 0xdc) = 2;
      FUN_0068b260(*(undefined4 *)(iVar6 + 0xac));
      (**(code **)(*(int *)*piVar3 + 200))();
      (**(code **)(*(int *)*piVar3 + 0x94))(1);
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (uVar4 < uVar2);
  }
  if (uVar2 < 4) {
    puVar5 = (undefined4 *)(in_ECX + 0x90 + uVar2 * 4);
    iVar6 = 4 - uVar2;
    do {
      (**(code **)(*(int *)*puVar5 + 0x94))(0);
      puVar5 = puVar5 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  ExceptionList = local_14;
  return;
}

