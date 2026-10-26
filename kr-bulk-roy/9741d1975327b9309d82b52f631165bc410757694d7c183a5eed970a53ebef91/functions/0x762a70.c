
uint FUN_00762a70(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  uint uVar2;
  
  if (*(char *)(in_ECX + 0x140) != '\0') {
    uVar2 = 0;
    if (param_1[4] != 0) {
      do {
        puVar1 = param_1;
        if (7 < (uint)param_1[5]) {
          puVar1 = (undefined4 *)*param_1;
        }
        if (*(ushort *)((int)puVar1 + uVar2 * 2) < 0x30) {
          return 0;
        }
        puVar1 = param_1;
        if (7 < (uint)param_1[5]) {
          puVar1 = (undefined4 *)*param_1;
        }
        if (0x39 < *(ushort *)((int)puVar1 + uVar2 * 2)) {
          return 0;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < (uint)param_1[4]);
    }
  }
  if (*(int *)(in_ECX + 0x144) == 0) {
    uVar2 = param_1[4];
  }
  else {
    uVar2 = *(int *)(in_ECX + 0x144) - *(int *)(in_ECX + 0x118);
    if ((uint)param_1[4] < uVar2) {
      uVar2 = param_1[4];
    }
  }
  if (0 < (int)uVar2) {
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0x3ec;
    }
    FUN_00748900();
    if (7 < (uint)param_1[5]) {
      param_1 = (undefined4 *)*param_1;
    }
    FUN_00761550(in_ECX,param_1,uVar2);
    *(int *)(in_ECX + 0x14c) = *(int *)(in_ECX + 0x14c) + uVar2;
  }
  return uVar2;
}

