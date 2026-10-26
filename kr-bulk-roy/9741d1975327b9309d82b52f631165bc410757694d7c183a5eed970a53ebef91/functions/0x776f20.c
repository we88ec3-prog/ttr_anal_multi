
uint FUN_00776f20(undefined4 *param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  
  uVar2 = param_1[4];
  if (uVar2 <= param_2) {
    return 0;
  }
  uVar3 = param_1[5];
  puVar4 = param_1;
  if (7 < uVar3) {
    puVar4 = (undefined4 *)*param_1;
  }
  if (0x5a < (ushort)(*(short *)((int)puVar4 + param_2 * 2) - 0xe01U)) {
    return 1;
  }
  uVar6 = param_2;
  if (uVar2 < param_2 + 1) {
    return param_2;
  }
  do {
    uVar6 = uVar6 + 1;
    if (uVar2 <= uVar6) {
      return uVar2 - param_2;
    }
    puVar4 = param_1;
    if (7 < uVar3) {
      puVar4 = (undefined4 *)*param_1;
    }
    uVar1 = *(ushort *)((int)puVar4 + uVar6 * 2);
    if (((0x5a < (ushort)(uVar1 - 0xe01)) || (uVar1 < 0xe2f)) || ((ushort)(uVar1 - 0xe40) < 5))
    goto LAB_00777009;
    iVar5 = FUN_007771e0();
    if ((iVar5 == 0) || ((ushort)(uVar1 - 0xe48) < 4)) goto LAB_00776ff8;
    if (uVar1 != 0xe3a) {
      if ((2 < (ushort)(uVar1 - 0xe4d)) && (uVar1 < 0xe5a)) goto LAB_00777009;
LAB_00776ff8:
      if (uVar1 == 0xe32) {
LAB_00777009:
        return uVar6 - param_2;
      }
    }
  } while( true );
}

